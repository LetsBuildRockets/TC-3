
#include <sys/time.h>
#include <iostream>
#include <boost/asio.hpp>
#include <mutex>
#include <thread>
#include <queue>
#include <string>

#include "server.h"
#include "DO.h"
#include "DAQ.h"
#include "database.h"


#define BILLION 1000000000L
#define MILLION 1000000L
#define SEQUENCE_START_TIME -60 // in seconds

#define TC3_CV_004 0
#define TC3_CV_003 1
#define TC3_CV_005 2
#define TC3_CV_002 3
#define TC3_CV_001 4
#define TC3_CV_006 5
#define TC3_Igniter 6
#define TC3_CV_000 8

int testNumber;
long long sampleCount = 0;
int loopCount = 0;


enum Throttle { THROTTLE_NONE, THROTTLE_1_US, THROTTLE_10_US, THROTTLE_100_US, THROTTLE_1_MS, THROTTLE_10_MS, THROTTLE_100_MS, THROTTLE_1_S };
enum State { prerun, run, aborttest };

State state = prerun;
Throttle throttle = THROTTLE_10_MS;

struct timespec startTime, abortTime;
long long T, A; // time in microseconds
long long lastT = -99999999999999999LL, lastA = -99999999999999999LL;

extern std::mutex stateMutex;
extern std::queue<std::string> commandBuffer;

extern std::mutex tcpSendMutex;
extern std::queue<std::string> tcpSendBuffer;

extern double localSensorVals[MAX_CHAN];


void my_handler(int s){
  printf("Caught signal %d\nexiting...\n",s);
  releaseAI();
  releaseDO();
  exit(1);
}

int cToI(char c) {
  return c - 48;
}

void ABORT() {
  clock_gettime(CLOCK_MONOTONIC, &abortTime);
  state = aborttest;
}

void sendMsg(std::string str) {
  tcpSendMutex.lock();
  tcpSendBuffer.push(str);
  tcpSendMutex.unlock();
}

void runSequence() {
  double Tdouble = T/((double) MILLION);
  if(Tdouble - lastT/((double) MILLION) > .2){
    printf("running! T%f\n", Tdouble);
    char buffer [32];
    if(Tdouble > 0) {
      sprintf(buffer,"TT+%f\r\n", Tdouble);
    } else {
      sprintf(buffer,"TT%f\r\n", Tdouble);
    }
    std::string s(buffer);
    sendMsg(s);
    lastT= T;
  }
  
  if(Tdouble >= 10){
    ABORT();
  } else if(Tdouble >= 5) {
    setOutput(TC3_CV_003, 0);
    setOutput(TC3_CV_004, 0);
  } else if (Tdouble >= 0) {  
    setOutput(TC3_CV_003, 1);
    setOutput(TC3_CV_004, 1);
    setOutput(TC3_CV_005, 0);
    setOutput(TC3_Igniter, 0);
  } else if (Tdouble >= -1) {
    setOutput(TC3_Igniter, 1);
  } else if (Tdouble >= -3) {
    setOutput(TC3_CV_005, 1);
  } else if (Tdouble >= -20) {
    if(localSensorVals[5] < 50) {
      ABORT();
      char buffer[256];
      sprintf(buffer,"MABORTING! LOX Tank pressure is below 50 psi, it is %f\r\n", localSensorVals[5]);
      sendMsg(std::string(buffer));
    }
    if(localSensorVals[6] < 50) {
      ABORT();
      char buffer[256];
      sprintf(buffer,"MABORTING! Fuel Tank Pressure is below 50 psi, it is %f\r\n", localSensorVals[6]);
      sendMsg(std::string(buffer));
    }
  } else if (Tdouble >= -50) {
    setOutput(TC3_CV_000, 1);
  } else if (Tdouble >= -55) {
    if(localSensorVals[14] < 50) {
      ABORT();
      char buffer[256];
      sprintf(buffer,"MABORTING! Helium is below 50 psi, it is %f\r\n", localSensorVals[14]);
      sendMsg(std::string(buffer));  
    }
  } else {
    setOutput(TC3_CV_000, 0);
    setOutput(TC3_CV_001, 0);
    setOutput(TC3_CV_002, 0);
    setOutput(TC3_CV_003, 0);
    setOutput(TC3_CV_004, 0);
    setOutput(TC3_CV_005, 0);
    setOutput(TC3_CV_006, 0);
    setOutput(TC3_Igniter, 0);
  }
}

void abortSequcence() {
  double Adouble = A/((double) MILLION);
  if(Adouble - lastA/((double) MILLION) > .2){
    printf("ABORTING! A%f\n", Adouble);
    char buffer [32];
    sprintf(buffer,"TA+%f\r\n", Adouble);
    std::string s(buffer);
    sendMsg(s);
    lastA=A;
  }
  if(Adouble > 5) {
    state = prerun;
  } else if(Adouble > 1) {
      
  } else {
     turnOffAllOutputs();
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
        char *s = (char *)commandBuffer.front().c_str();
        printf("command: %s\n", s);
        int length = strchr(s, '\n') - s;
        if(length <= 0) goto INVALID;
        switch (s[0]) {
          case 's':
          if(length < 4) goto INVALID;
          setOutput(cToI(s[1])*10 + cToI(s[2]), cToI(s[3]));
          break;
          case 'q':
          printf("command starts with q... l: %d\n",length);
          if(length < 2) goto INVALID;
          if(s[1] == '1') {
            printf("start\n");
            state = run;
            clock_gettime(CLOCK_MONOTONIC, &startTime);
          } else if(s[1] == '0') {
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
