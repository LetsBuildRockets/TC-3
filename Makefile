DAQ: DAQ.c TransferFunctions.cc TransferFunctions.h
	g++ DAQ.c TransferFunctions.cc -o DAQ -lpci_dask
clean:
	rm DAQ
