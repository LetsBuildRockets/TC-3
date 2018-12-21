#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>
#include <thread>
#include <time.h>
#include "dask.h"
#include "conio.h"

#include "DAQ.h"
#include "TransferFunctions.h"
#include "database.h"


extern int testNumber;
extern long long sampleCount;
long long realSampleCount = 0;

I16 cardAI;
TransferFunctions func[MAX_CHAN];
struct timespec sampTime[MAX_CHAN], deadline;
uint64_t sensorUpdateThrottleNS[MAX_CHAN];

double localSensorVals[MAX_CHAN] = {0};

void releaseAI() {
  Release_Card(cardAI);
}

void initAI() {
  if ((cardAI = Register_Card(PCI_9113, 0)) < 0) {
    printf("Register_Card error=%d\n", cardAI);
    exit(1);
  }
  for(int i=0; i < MAX_CHAN; i++) {
    std::string transfunc = getSensorTransferFunction(i);
    if(transfunc.compare("")!=0) {
      func[i].setFunction(transfunc);
    } else {
      func[i].setFunction("x");
    }
  }

  for(int i=0; i < MAX_CHAN; i++) {
    sensorUpdateThrottleNS[i] = 1000 * getSensorUpdateThrottle(i);
    clock_gettime(CLOCK_MONOTONIC, &sampTime[i]);
  }

  // set sample tick time
  deadline.tv_sec = 0;
  deadline.tv_nsec = 1;
}


void tickAI() {
  struct timespec currentTime;
  U16 chan_data[MAX_CHAN];
  F64 chan_voltage[MAX_CHAN];

  for(int i = 0 ; i < MAX_CHAN; i++ ) {
    clock_gettime(CLOCK_MONOTONIC, &currentTime);
    uint64_t diff = BILLION * (currentTime.tv_sec - sampTime[i].tv_sec) + currentTime.tv_nsec - sampTime[i].tv_nsec;
    if(diff >= sensorUpdateThrottleNS[i]) {
      I16 err;
      if((err = AI_ReadChannel(cardAI, i, range, &chan_data[i])) == NoError) {
        //printf("sampled %lld\n", realSampleCount);
        realSampleCount++;
        clock_gettime(CLOCK_MONOTONIC, &sampTime[i]);
        AI_VoltScale(cardAI, range, chan_data[i], &chan_voltage[i]);
        localSensorVals[i] = func[i].callFunction(chan_voltage[i]);
        bufferSensorData(testNumber,&sampTime[i],i,chan_data[i],localSensorVals[i]);
      } else {
        printf("AI_ReadChannel Ch#%d error : error_code: %d \n", i, err );
      }
    } else {
      // not time to sample
    }
  }

  if(realSampleCount%4 == 0 && realSampleCount > 0) {
    //printf("writing to database... %lld\n", realSampleCount);
    std::thread databaseWriterThread(executeDatabaseWrite);
    databaseWriterThread.detach();
  }

  sampleCount++;
};
