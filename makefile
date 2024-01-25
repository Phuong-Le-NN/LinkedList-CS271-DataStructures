all: test

test: test.o 
	g++ -std=c++11 -Wall -g -o test test.o 

test.o: test.cpp set.h set.cpp
	g++ -std=c++11 -c -g -Wall test.cpp
