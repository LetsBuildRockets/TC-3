#include "fparser4.5.2/fparser.hh"
#include <string>

class TransferFunctions {
public:
  void setFunction(std::string);
  double callFunction(double);
private:
  FunctionParser fp;
};
