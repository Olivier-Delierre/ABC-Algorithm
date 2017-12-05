CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

SRC=src/
INC=include/

all: main

main: main.o MyAlgorithm.o Problem.o SetUpParams.o Solution.o
	$(CXX) $(CXXFLAGS) -o main main.o MyAlgorithm.o Problem.o SetUpParams.o Solution.o

main.o: $(SRC)main.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c $(SRC)main.cpp

MyAlgorithm.o: $(SRC)MyAlgorithm.cpp $(INC)MyAlgorithm.h
	$(CXX) $(CXXFLAGS) -o MyAlgorithm.o -c $(SRC)MyAlgorithm.cpp

Problem.o: $(SRC)Problem.cpp $(INC)Problem.h
	$(CXX) $(CXXFLAGS) -o Problem.o -c $(SRC)Problem.cpp

SetUpParams.o: $(SRC)SetUpParams.cpp $(INC)SetUpParams.h
	$(CXX) $(CXXFLAGS) -o SetUpParams.o -c $(SRC)SetUpParams.cpp

Solution.o: $(SRC)Solution.cpp $(INC)Solution.h
	$(CXX) $(CXXFLAGS) -o Solution.o -c $(SRC)Solution.cpp
