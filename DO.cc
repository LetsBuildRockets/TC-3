#include <mutex>
#include <queue>
#include <string>
#include <iostream>

#include "dask.h"
#include "conio.h"

#include "DO.h"


extern std::mutex tcpSendMutex;
extern std::queue<std::string> tcpSendBuffer;

I16 cardDO;
U32 test_out_value = 1;

U32 outputs = 0;

void initDO() {
  if ((cardDO=Register_Card(PCI_7234, 0)) <0 ) {
    printf("Register_Card error=%d\n", cardDO);
    exit(1);
  }
}

void releaseDO() {
  turnOffAllOutputs();
  Release_Card( cardDO );
}

void turnOffAllOutputs() {
  if(outputs == 0) return;
  outputs = 0;
  tcpSendMutex.lock();
  for(int i = 0; i < 32; i++){
    char buffer [4];
    sprintf(buffer,"S%02d%d\r\n", i, 0);
    std::string s(buffer);
    tcpSendBuffer.push(s);
  }
  tcpSendMutex.unlock();
  DO_WritePort(cardDO, 0, outputs);
  printf("turned all the relays off...\n");
}

bool readOutput(int channel) {
  if (channel < 0 || channel > 31) {
    printf("Cannot read channel %d! It is not a valid output channel!\n", channel);
    return false;
  }
  return (outputs >> channel) & 1U;
}

bool setOutput(int channel, bool value) {
  if (channel < 0 || channel > 31) {
    printf("Cannot write to channel %d! It is not a valid output channel!\n", channel);
    return false;
  }

  if(readOutput(channel) == value) return true;
  if(value) {
    outputs |= ((U32) 1UL) << channel;
  } else {
    outputs &= ~(((U32) 1UL) << channel);
  }
  DO_WritePort(cardDO, 0, outputs);
  char buffer [4];
  sprintf(buffer,"S%02d%d\r\n", channel, value);
  std::string s(buffer);
  tcpSendMutex.lock();
  tcpSendBuffer.push(s);
  tcpSendMutex.unlock();
  return true;
}
