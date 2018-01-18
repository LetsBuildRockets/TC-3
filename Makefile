DAQ: DAQ.cpp DAQ.h
	g++ DAQ.cpp -o DAQ -std=c++11 -lpci_dask

flags:
	g++ -g -dM -E - < /dev/null

clean:
	rm asdf