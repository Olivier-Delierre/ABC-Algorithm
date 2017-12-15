CXX=g++
CXXFLAGS=-g -std=c++11 -Wall -pedantic

SRC=src/

all: main.out

main.out: main.o MyAlgorithm.o Problem.o SetUpParams.o Solution.o Benchmark.o
	$(CXX) $(CXXFLAGS) -o main.out main.o MyAlgorithm.o Problem.o SetUpParams.o Solution.o Benchmark.o

main.o: $(SRC)main.cpp
	$(CXX) $(CXXFLAGS) -o main.o -c $(SRC)main.cpp

MyAlgorithm.o: $(SRC)MyAlgorithm.cpp $(SRC)MyAlgorithm.h
	$(CXX) $(CXXFLAGS) -o MyAlgorithm.o -c $(SRC)MyAlgorithm.cpp

Problem.o: $(SRC)Problem.cpp $(SRC)Problem.h
	$(CXX) $(CXXFLAGS) -o Problem.o -c $(SRC)Problem.cpp

SetUpParams.o: $(SRC)SetUpParams.cpp $(SRC)SetUpParams.h
	$(CXX) $(CXXFLAGS) -o SetUpParams.o -c $(SRC)SetUpParams.cpp

Solution.o: $(SRC)Solution.cpp $(SRC)Solution.h
	$(CXX) $(CXXFLAGS) -o Solution.o -c $(SRC)Solution.cpp

Benchmark.o: $(SRC)Benchmark.cpp $(SRC)Benchmark.h
	$(CXX) $(CXXFLAGS) -o Benchmark.o -c $(SRC)Benchmark.cpp

clean:
	@rm -f *.o
