#include <iostream>
#include "dask.h"
#include "conio.h"

#include "DO.h"


I16 cardDO;

bool outputs[32] = { false };

void initDO() {
  if ((cardDO=Register_Card(PCI_7234, 0)) <0 ) {
    printf("Register_Card error=%d\n", cardDO);
    exit(1);
  }
}

void releaseDO() {
  Release_Card( cardDO );
}

bool readOutput(int channel) {
  if (channel < 0 || channel > 31) {
    printf("Cannot read channel %d! It is not a valid output channel!\n", channel);
    return false;
  }
  return outputs[channel];
}

bool setOutput(int channel, bool value) {
  if (channel < 0 || channel > 31) {
    printf("Cannot write to channel %d! It is not a valid output channel!\n", channel);
    return false;
  }


  outputs[channel] = value;
  return value;
}
