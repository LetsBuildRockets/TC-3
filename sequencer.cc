
#include <sys/time.h>
#include <iostream>
#include <boost/asio.hpp>
#include <mutex>
#include <thread>
#include "server.hpp"

enum  State { prerun, run, aborttest };
State state = prerun;
double startTime = -1;
double T, A;

std::mutex stateMutex;
std::string commandBuffer = "";

int main(void) {
std::thread serviceWorker(runAsyncServer);
  while(1) {
    printf("%s\n",commandBuffer.c_str());
    usleep(500*1000);
  }
  return 0;
}


void runSequence() {
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

  }
}

void abortSequcence() {
  if(A < 1) {

  } else if (A < 2) {

  } else if (A < 3) {

  }
}
