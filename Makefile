DAQ: DAQ.c TransferFunctions.cc TransferFunctions.h
	g++ DAQ.c TransferFunctions.cc fparser4.5.2/fparser.cc -o DAQ -lpci_dask
clean:
	rm DAQ
