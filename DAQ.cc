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

#include "TransferFunctions.h"
#include "database.h"

#define MAX_CHAN 4
#define DELAY 1L
#define BILLION 1000000000L
I16 card, err;

void my_handler(int s){
  printf("Caught signal %d\nexiting...\n",s);
  Release_Card( card );
  exit(1);
}

static unsigned long long rdtsc(void)
{
  unsigned int low, high;
  asm("cpuid");
  asm volatile("rdtsc" : "=a" (low), "=d" (high));
  return low | ((unsigned long long)high) << 32;
}

int main(void) {
  int testNumber = getTestNumber();
  TransferFunctions func[MAX_CHAN];
  uint64_t diff;
  struct timespec tv1, tv2, deadline;
  struct timespec sampTime[MAX_CHAN];
  uint64_t sensorUpdateThrottleNS[MAX_CHAN];

  deadline.tv_sec = 0;
  deadline.tv_nsec = 10;

  databaseBufferClear();

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

  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);


  double totaltime = 0;
  long int count = 0;
  I16 range=AD_U_10_V;
  U16 chan_data[MAX_CHAN];
  F64 chan_voltage[MAX_CHAN];

  setbuf( stdout, NULL );
  if ((card=Register_Card(PCI_9113, 0)) <0 ) {
    printf("Register_Card error=%d\n", card);
    exit(1);
  }
  struct timespec currentTime;
  while(1) {
    clock_gettime(CLOCK_MONOTONIC, &tv1);
    for(int i=0 ; i<MAX_CHAN; i++ ){
      clock_gettime(CLOCK_MONOTONIC, &currentTime);
      diff = BILLION * (currentTime.tv_sec - sampTime[i].tv_sec) + currentTime.tv_nsec - sampTime[i].tv_nsec;
      if(diff > sensorUpdateThrottleNS[i]) {
        if( (err = AI_ReadChannel(card, i, range, &chan_data[i]) ) != NoError )
        printf(" AI_ReadChannel Ch#%d error : error_code: %d \n", i, err );
        clock_gettime(CLOCK_MONOTONIC, &sampTime[i]);
        AI_VoltScale(card, range, chan_data[i], &chan_voltage[i]);
        bufferSensorData(testNumber,&sampTime[i],i,chan_data[i],func[i].callFunction(chan_voltage[i]));
      } else {

      }
    }

    /*clrscr();
    printf("\n\n\n\n");
    printf("                Ch0        Ch1        Ch2        Ch3        Ch4\n");
    printf(" input value :  %04x       %04x       %04x       %04x       %04x\n", chan_data[0], chan_data[1], chan_data[2], chan_data[3], chan_data[4]);
    printf("     voltage :  %.2f       %.2f       %.2f       %.2f       %.2f\n", chan_voltage[0], chan_voltage[1], chan_voltage[2], chan_voltage[3], chan_voltage[4]);
    printf("     scaledv :  %.2f       %.2f       %.2f       %.2f       %.2f\n\n", func[0].callFunction(chan_voltage[0]), func[1].callFunction(chan_voltage[1]), func[2].callFunction(chan_voltage[2]), func[3].callFunction(chan_voltage[3]), chan_voltage[4]);
    printf("\n\n\n\n\n  press ^C to stop \n");*/

    if(count%10000 == 99) {
      std::thread databaseWriterThread(executeDatabaseWrite);
      databaseWriterThread.detach();
    }

    clock_nanosleep(CLOCK_MONOTONIC, TIMER_ABSTIME, &deadline, NULL);

    clock_gettime(CLOCK_MONOTONIC, &tv2);
    diff = BILLION * (tv2.tv_sec - tv1.tv_sec) + tv2.tv_nsec - tv1.tv_nsec;
    totaltime += diff;
    count++;
    if(count%100000 == 0) {
      printf("cylce time: %10.0f ns\ncount: %ld\n",totaltime/count, count);
    }
  };

  return 0;
}
