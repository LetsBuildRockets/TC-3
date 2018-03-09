
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
#define MILLION 1000000L
#define SEQUENCE_START_TIME -20 // in seconds

int testNumber;
long long sampleCount = 0;
int loopCount = 0;


enum Throttle { THROTTLE_NONE, THROTTLE_1_US, THROTTLE_10_US, THROTTLE_100_US, THROTTLE_1_MS, THROTTLE_10_MS, THROTTLE_100_MS, THROTTLE_1_S };
enum State { prerun, run, aborttest };

State state = prerun;
Throttle throttle = THROTTLE_100_MS;

struct timespec startTime, abortTime;
long long T, A; // time in microseconds

std::mutex stateMutex;
std::queue<std::string> commandBuffer;


void my_handler(int s){
  printf("Caught signal %d\nexiting...\n",s);
  releaseAI();
  releaseDO();
  exit(1);
}

int cToI(char c) {
  return c - 48;
}

void runSequence() {
  double Tdouble = T/((double) MILLION);
  printf("running! T%f\n", Tdouble);
  if(Tdouble < -11) {

  } else if (Tdouble < -10) {
    setOutput(0, 1);
  } else if (Tdouble < -9) {
    setOutput(1, 1);
  } else if (Tdouble < -8) {
    setOutput(2, 1);
  } else if (Tdouble < -7) {
    setOutput(3, 1);
  } else if (Tdouble < -6) {
    setOutput(0, 0);
  } else if (Tdouble < -5) {
    setOutput(1, 0);
  } else if (Tdouble < -4) {
    setOutput(2, 0);
  } else if (Tdouble < -3) {
    setOutput(3, 0);
  } else if (Tdouble < -2) {
    setOutput(0, 1);
    setOutput(1, 1);
    setOutput(2, 1);
    setOutput(3, 1);
  } else if (Tdouble < 0) {

  } else {
    clock_gettime(CLOCK_MONOTONIC, &abortTime);
    state = aborttest;
  }
}

void abortSequcence() {
  double Adouble = A/((double) MILLION);
  printf("ABORTING! A%f\n", Adouble);
  if(Adouble < 1) {
    turnOffAllOutputs();
  } else if (Adouble < 2) {

  } else if (Adouble < 3) {

  } else  {
    state = prerun;
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
  initDO();
  initAI();

  // reserve memory for buffer to get ready for sampling
  databaseBufferClear();

  printf("setup done\n");
  struct timespec tv1, tv2;

  while(1) {
    //printf("tick%d\n", loopCount);
    if(sampleCount == 0) {
      clock_gettime(CLOCK_MONOTONIC, &tv1);
    }

    // Program runs too fast, lets slow it down a little.
    bool checkStatesNow;
    switch(throttle) {
      case THROTTLE_NONE:
      checkStatesNow = (loopCount % 10000 == 0);
      break;
      case THROTTLE_1_US:
      usleep(1);
      checkStatesNow = (loopCount % 1000 == 0);
      break;
      case THROTTLE_10_US:
      usleep(10);
      checkStatesNow = (loopCount % 100 == 0);
      break;
      case THROTTLE_100_US:
      usleep(100);
      checkStatesNow = (loopCount % 10 == 0);
      break;
      case THROTTLE_1_MS:
      usleep(1000);
      checkStatesNow =  true;
      break;
      case THROTTLE_10_MS:
      usleep(10000);
      checkStatesNow =  true;
      break;
      case THROTTLE_100_MS:
      usleep(100000);
      checkStatesNow =  true;
      break;
      // THROTTLE_1_S is for testing only!
      case THROTTLE_1_S:
      usleep(MILLION);
      checkStatesNow = (loopCount % 5 == 0);
      break;
      default:
      printf("INVALID THROTTLE SELECTION");
      exit(1);
    }

    // Check the commands from the TCP socket buffer
    if(checkStatesNow) {
      //printf("checkStatesNow\n");
      while(!commandBuffer.empty()) {
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
            clock_gettime(CLOCK_MONOTONIC, &startTime);
          } else if(cToI(s[1]) == 0) {
            printf("end\n");
            state = aborttest;
            clock_gettime(CLOCK_MONOTONIC, &abortTime);
          }
          break;
          INVALID:
          default:
          printf("Command not recognized!\n");
        }

        commandBuffer.pop();
      }
    }

    // Check time and update countdown
    struct timespec currentTime;
    clock_gettime(CLOCK_MONOTONIC, &currentTime);
    switch (state) {
      case run:
      T = SEQUENCE_START_TIME * MILLION + ((currentTime.tv_nsec - startTime.tv_nsec) / 1000 + MILLION * (currentTime.tv_sec - startTime.tv_sec));
      runSequence();
      break;

      case aborttest:
      A = (currentTime.tv_nsec - abortTime.tv_nsec) / 1000 + MILLION * (currentTime.tv_sec - abortTime.tv_sec);
      abortSequcence();
      break;

      case prerun:
      break;
    }

    // Sample sensors
    tickAI();

    // Get average sample rate
    if(sampleCount >= 1000000) {
      clock_gettime(CLOCK_MONOTONIC, &tv2);
      double diff = tv2.tv_sec - tv1.tv_sec;
      diff *= 1000 * 1000;
      diff += (tv2.tv_nsec - tv1.tv_nsec) / 1000;
      printf("total time: %10.3f us \ncylce time: %10.3f us average \nsampleCount: %lld\n", diff, diff/(double)sampleCount, sampleCount);
      sampleCount = 0;
    }

    loopCount++;
    if(loopCount > 10000) loopCount = 0;
  }

  // dont forget to let the TCP socket die...
  serviceWorker.detach();
  return 0;
}
