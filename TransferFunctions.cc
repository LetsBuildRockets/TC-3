#include  "TransferFunctions.h"

TransferFunctions::addFunction(std::string funcText) {
      fp.Parse("x+1", "x");
}

TransferFunctions::callFunction(double data) {
  double variables[1] = { data };
  return fp.Eval(variables);
}
