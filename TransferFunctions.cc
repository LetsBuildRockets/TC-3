#include  "TransferFunction.h"
TransferFunction::TransferFunction() {
  fp.AddConstant("pi", 3.14159265358979323846);
  fp.ddConstant("e", 2.71828182845904523536);
}

TransferFunction::addFunction(std::String funcText) {
      fp.Parse("x+1", "x");
}

TransferFunction::callFunction(double data) {
  double variables[1] = { data };
  return fp.Eval(variables);
}
