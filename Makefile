CC=g++
CFLAGS= -Wall -std=c++11 -g

graph: main.o graph.o
	$(CC) $(CFLAGS) -o graph graph.o main.o 

graph.o: graph.cpp graph.h
	$(CC) $(CFLAGS) -c graph.cpp

main.o: main.cpp graph.h
	$(CC) $(CFLAGS) -c main.cpp

clean: 
	rm *.o graph
	clear
