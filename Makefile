all: vector

vector: IntVector.o main.o 
	gcc -o vector IntVector.o main.o 
	
IntVector.o: ./src/IntVector.c
	gcc -Wall -c ./src/IntVector.c

main.o: ./src/main.c 
	gcc -Wall -c ./src/main.c