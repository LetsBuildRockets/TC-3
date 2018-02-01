#include "fparser.hh"
#include <String.h>

class TransferFucntion {
  public:
    TransferFucntion();
    addFunction(std::String);
    callFunction(double input);
  private:
    FunctionParser fp;
};
