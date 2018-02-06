#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <string.h>
#include <thread>
#include "dask.h"
#include "conio.h"

#include "TransferFunctions.h"
#include "database.h"

#define MAX_CHAN 4
#define DELAY 10000L
I16 card, err;

void my_handler(int s){
  printf("Caught signal %d\nexiting...\n",s);
  Release_Card( card );
  exit(1);
}

int main( void ) {
  int testNumber = getTestNumber();
  TransferFunctions func[MAX_CHAN];
  for(int i=0; i < MAX_CHAN; i++) {
    std::string transfunc = getSensorTransferFunction(i);
    if(transfunc.compare("")!=0) {
      func[i].setFunction(transfunc);
    } else {
      func[i].setFunction("x");
    }
  }
  struct timeval tv1, tv2;
  struct timeval sampTime[MAX_CHAN];

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
  DatabaseBuffer databaseBuffer;

  while(1) {
    gettimeofday(&tv1, NULL);
    for(int i=0 ; i<MAX_CHAN; i++ ){
      if( (err = AI_ReadChannel(card, i, range, &chan_data[i]) ) != NoError )
        printf(" AI_ReadChannel Ch#%d error : error_code: %d \n", i, err );
      gettimeofday(&sampTime[i], NULL);
      AI_VoltScale(card, range, chan_data[i], &chan_voltage[i]);
      databaseBuffer.bufferSensorData(testNumber,&sampTime[i],i,chan_data[i],func[i].callFunction(chan_voltage[i]));
      //chan_data[i] = chan_data[i] & 0x0ff;
    }

    clrscr();
    printf("\n\n\n\n");
    printf("                Ch0        Ch1        Ch2        Ch3        Ch4\n");
    printf(" input value :  %04x       %04x       %04x       %04x       %04x\n", chan_data[0], chan_data[1], chan_data[2], chan_data[3], chan_data[4]);
    printf("     voltage :  %.2f       %.2f       %.2f       %.2f       %.2f\n", chan_voltage[0], chan_voltage[1], chan_voltage[2], chan_voltage[3], chan_voltage[4]);
    printf("     scaledv :  %.2f       %.2f       %.2f       %.2f       %.2f\n\n", func[0].callFunction(chan_voltage[0]), func[1].callFunction(chan_voltage[1]), func[2].callFunction(chan_voltage[2]), func[3].callFunction(chan_voltage[3]), chan_voltage[4]);
    printf("\n\n\n\n\n  press ^C to stop \n");

    if(count%100 == 99) {
      std::string trans = databaseBuffer.getTransaction();
      std::thread databaseWriterThread(executeDatabaseWrite, trans);
      databaseWriterThread.detach();
      databaseBuffer.clear();
    }
    gettimeofday(&tv2, NULL);
    totaltime += ((double) (tv2.tv_usec - tv1.tv_usec) / 1000000 +(double) (tv2.tv_sec - tv1.tv_sec))*1000;
    count++;
    //if(count%1000 == 0)
      printf("cylce time: %f ms\ncount: %ld\n",totaltime/count, count);
    usleep(DELAY);
  };

  return 0;
}
