#include  "fparser4.5.2/TransferFunctions.h"
TransferFunctions::TransferFunctions() {
  fp.AddConstant("pi", 3.14159265358979323846);
  fp.ddConstant("e", 2.71828182845904523536);
}

TransferFunctions::addFunction(std::String funcText) {
      fp.Parse("x+1", "x");
}

TransferFunctions::callFunction(double data) {
  double variables[1] = { data };
  return fp.Eval(variables);
}
