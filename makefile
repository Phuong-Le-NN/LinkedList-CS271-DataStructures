all: main

main: main.o 
	g++ -std=c++11 -Wall -g -o main main.o 

main.o: test.cpp set.h set.cpp
	g++ -std=c++11 -c -g -Wall test.cpp



