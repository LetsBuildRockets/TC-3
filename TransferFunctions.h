<<<<<<< HEAD
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
=======
#include "fparser4.5.2/fparser.hh"
class TransferFucntion: public FunctionParser
   {
    public:
       TransferFucntion()
       {
           AddConstant("pi", 3.14159265358979323846);
           AddConstant("e", 2.71828182845904523536);
       }
   };
>>>>>>> 520c9f818184251ed2f00bab1a6076c07012e043
