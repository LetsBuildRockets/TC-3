ALL: TC3
TC3: sequencer.cc server.cc DAQ.cc DAQ.h DO.cc DO.h TransferFunctions.cc TransferFunctions.h database.cc database.h
	g++ -std=c++0x -Wall -g DAQ.cc DO.cc TransferFunctions.cc database.cc fparser4.5.2/fparser.cc sequencer.cc server.cc -o TC3 -lboost_system -lrt -lpci_dask -lpq -I/usr/include/postgresql
clean:
	rm TC3
