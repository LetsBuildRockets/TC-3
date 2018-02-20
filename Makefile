ALL: DAQ SEQ
DAQ: DAQ.cc TransferFunctions.cc TransferFunctions.h database.cc database.h
	g++ -std=c++0x DAQ.cc TransferFunctions.cc database.cc fparser4.5.2/fparser.cc -o DAQ -lpci_dask -lpq -I/usr/include/postgresql -lrt
SEQ: sequencer.cc server.cpp
	g++ -std=c++0x sequencer.cc server.cpp -o TC3 -lboost_system -lrt
clean:
	rm DAQ TC3
