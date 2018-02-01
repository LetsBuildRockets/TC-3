class TransferFucntion: public FunctionParser
   {
    public:
       TransferFucntion()
       {
           AddConstant("pi", 3.14159265358979323846);
           AddConstant("e", 2.71828182845904523536);
       }
   };
