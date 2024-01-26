all: test

test: test.o 
	g++ -std=c++11 -Wall -g -o test test.o 

test.o: test_set.cpp set.h set.cpp
	g++ -std=c++11 -c -g -Wall test_set.cpp
