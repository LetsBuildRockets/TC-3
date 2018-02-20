
#include <sys/time.h>
#include <iostream>
#include <boost/asio.hpp>
#include <mutex>
#include <thread>
#include <queue>

#include "server.hpp"

#define SEQUENCE_START_TIME -30

enum State { prerun, run, aborttest };
State state = prerun;

struct timeval startTime, abortTime;
double T, A;

std::mutex stateMutex;
std::queue<std::string> commandBuffer;


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
  std::thread serviceWorker(runAsyncServer);
  while(1) {
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
    if(state == run) {
      T = SEQUENCE_START_TIME + ((double) (currentTime.tv_usec - startTime.tv_usec) / 1000000 +(double) (currentTime.tv_sec - startTime.tv_sec));
      runSequence();
    } else if (state == aborttest) {
      A = (double) (currentTime.tv_usec - abortTime.tv_usec) / 1000000 +(double) (currentTime.tv_sec - abortTime.tv_sec);
      abortSequcence();
    }

    usleep(1*1000*1000);
  }
  return 0;
}
