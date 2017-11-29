SRC=src/
INC=include/
OBJ=obj/

all: main

main: main.o MyAlgorithm.o Problem.o SetUpParams.o Solution.o
	g++ -o main $(OBJ)main.o $(OBJ)MyAlgorithm.o $(OBJ)Problem.o $(OBJ)SetUpParams.o $(OBJ)Solution.o

main.o: $(SRC)main.cpp
	g++ -o $(OBJ)main.o -c $(SRC)main.cpp

MyAlgorithm.o: $(SRC)MyAlgorithm.cpp $(INC)MyAlgorithm.h
	g++ -o $(OBJ)MyAlgorithm.o -c $(SRC)MyAlgorithm.cpp

Problem.o: $(SRC)Problem.cpp $(INC)Problem.h
	g++ -o $(OBJ)Problem.o -c $(SRC)Problem.cpp

SetUpParams.o: $(SRC)SetUpParams.cpp $(INC)SetUpParams.h
	g++ -o $(OBJ)SetUpParams.o -c $(SRC)SetUpParams.cpp

Solution.o: $(SRC)Solution.cpp $(INC)Solution.h
	g++ -o $(OBJ)Solution.o -c $(SRC)Solution.cpp
