#include <iostream>

#include "dask.h"
#include "conio.h"

#include "DO.h"


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
  DO_WritePort(cardDO, 0, (U32)0);
  printf("turned all the relays off...\n");
}

void loopTest() {
  DO_WritePort(cardDO, 0, test_out_value);
  test_out_value = (test_out_value*2)%((1<<31)+1);
  if(!test_out_value)
  test_out_value = 1;
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

  if(value) {
    outputs |= ((U32) 1UL) << channel;
  } else {
    outputs &= ~(((U32) 1UL) << channel);
  }
  DO_WritePort(cardDO, 0, outputs);
  return value;
}
