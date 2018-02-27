
#include <sys/time.h>
#include <iostream>
#include <boost/asio.hpp>
#include <mutex>
#include <thread>
#include <queue>

#include "server.h"
#include "DO.h"
#include "DAQ.h"
#include "database.h"


#define BILLION 1000000000L
#define SEQUENCE_START_TIME -30

int testNumber;
long long sampleCount = 0;
long long realSampleCount = 0;


enum State { prerun, run, aborttest };
State state = prerun;

struct timeval startTime, abortTime;
double T, A;

std::mutex stateMutex;
std::queue<std::string> commandBuffer;


void my_handler(int s){
  printf("Caught signal %d\nexiting...\n",s);
  releaseAI();
  exit(1);
}

int cToI(char c) {
  return c - 48;
}

void runSequence() {
  printf("running! T%f\n", T);
  if(T < -30) {

  } else if (T < -10) {

  } else if (T < -5) {

  } else if (T < -1) {

  } else if (T < -.5) {

  } else if (T < 0) {

  } else if (T < .1) {

  } else if (T < 5) {

  } else if (T < 6) {

  } else if (T < 60) {

  } else {
    state = aborttest;
  }
}

void abortSequcence() {
  if(A < 1) {

  } else if (A < 2) {

  } else if (A < 3) {

  }
}

int main(void) {

  // catch ^C
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = my_handler;
  sigemptyset(&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction(SIGINT, &sigIntHandler, NULL);

  // set global testNumber
  testNumber = getTestNumber();


  // start tcp socket server
  std::thread serviceWorker(runAsyncServer);

  // init both cards and associated variables
  //initDO();
  initAI();

  // reserve memory for buffer to get ready for sampling
  databaseBufferClear();

  printf("setup done\n");
  struct timespec tv1, tv2;
  while(1) {

    /*while(!commandBuffer.empty()) {
      bool valve[100];
      char *s = (char *)commandBuffer.front().c_str();
      int length = strchr(s, '\n') - s  - 1;
      switch (s[0]) {
        case 's':
        if(length != 4) goto INVALID;
        valve[cToI(s[1])*10 + cToI(s[2])] = cToI(s[3]);
        break;
        case 'q':
        if(length != 2) goto INVALID;
        if(cToI(s[1]) == 1) {
          printf("start\n");
          state = run;
          gettimeofday(&startTime, NULL);
        } else if(cToI(s[1]) == 0) {
          printf("end\n");
          state = aborttest;
          gettimeofday(&abortTime, NULL);
        }
        break;
        INVALID:
        default:
        printf("nope!\n");
      }

      commandBuffer.pop();
    }

    struct timeval currentTime;
    gettimeofday(&currentTime, NULL);
    switch (state) {
      case run:
      T = SEQUENCE_START_TIME + ((double) (currentTime.tv_usec - startTime.tv_usec) / 1000000 +(double) (currentTime.tv_sec - startTime.tv_sec));
      runSequence();
      break;

      case aborttest:
      A = (double) (currentTime.tv_usec - abortTime.tv_usec) / 1000000 +(double) (currentTime.tv_sec - abortTime.tv_sec);
      abortSequcence();
      break;
    }*/

    //usleep(1);
    if(sampleCount == 0) {
      clock_gettime(CLOCK_MONOTONIC, &tv1);
    }
    tickAI();
    if(sampleCount >= 1000000) {
      clock_gettime(CLOCK_MONOTONIC, &tv2);
      double diff = tv2.tv_sec - tv1.tv_sec;
      diff *= 1000 * 1000;
      diff += (tv2.tv_nsec - tv1.tv_nsec) / 1000;
      printf("total time: %10.3f us \ncylce time: %10.3f us average \nsampleCount: %lld\n", diff, diff/(double)sampleCount, sampleCount);
      sampleCount = 0;
    }
  }
  serviceWorker.detach();
  return 0;
}
