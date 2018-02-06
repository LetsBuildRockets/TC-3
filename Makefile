ALL: DAQ PSQL
DAQ: DAQ.c TransferFunctions.cc TransferFunctions.h database.cpp database.h
	g++ -std=c++0x DAQ.c TransferFunctions.cc database.cpp fparser4.5.2/fparser.cc -o DAQ -lpci_dask -lpq -I/usr/include/postgresql -g
PSQL: psql.c
	g++ -std=c++0x  psql.c -o PSQL -lpq -I/usr/include/postgresql
clean:
	rm DAQ
