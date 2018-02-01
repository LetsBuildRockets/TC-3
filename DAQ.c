#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include "dask.h"
#include "conio.h"

#include "TransferFunctions.h"

#define Max_Chan 4
I16 card, err;

void my_handler(int s){
    printf("Caught signal %d\n",s);
    Release_Card( card );
    exit(1);
}

int main( void )
{
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = my_handler;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);


    int i;
    I16 range=AD_U_10_V;
    U16 chan_data[Max_Chan];
    F64 chan_voltage[Max_Chan];

    setbuf( stdout, NULL );
    if ((card=Register_Card(PCI_9113, 0)) <0 ) {
        printf("Register_Card error=%d\n", card);
        exit(1);
    }

    do{
        clrscr();
        printf("*****************************************************************\n" );
        printf("                      PCI9113 AI Polling                         \n");
        printf("*****************************************************************\n\n");
        printf("                                                                 \n\n\n\n");
        for( i=0 ; i<Max_Chan; i++ ){
            if( (err = AI_ReadChannel(card, i, range, &chan_data[i]) ) != NoError )
                printf(" AI_ReadChannel Ch#%d error : error_code: %d \n", i, err );
            AI_VoltScale(card, range, chan_data[i], &chan_voltage[i]);
            chan_data[i] = chan_data[i] & 0x0ff;
        }
        printf("                Ch0        Ch1        Ch2        Ch3\n");
        printf(" input value :  %04x       %04x       %04x       %04x\n", chan_data[0], chan_data[1], chan_data[2], chan_data[3]);
        printf("     voltage :  %.2f      %.2f      %.2f      %.2f\n\n", chan_voltage[0], chan_voltage[1], chan_voltage[2], chan_voltage[3]);
        printf("\n\n\n\n\n                                       press Enter to stop \n");

        usleep( 50000 );
    }while(1);

    return 0;
}
