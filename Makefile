DAQ: DAQ.c TransferFunctions.cc TransferFunctions.h
	g++ DAQ.c -o DAQ -lpci_dask
clean:
	rm DAQ
