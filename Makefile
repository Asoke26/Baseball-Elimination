CC = g++ -g -O0 -Wno-deprecated

tag = -i

ifdef linux
	tag = -n
endif

all: main.out

main.out:	fordFulkerson.o flowGraph.o flowEdge.o main.o
	$(CC) -o main.out fordFulkerson.o flowGraph.o flowEdge.o main.o

flowEdge.o: flowEdge.h flowEdge.cpp	
	$(CC) -c flowEdge.cpp


flowGraph.o: flowEdge.h flowGraph.h flowGraph.cpp	
	$(CC) -c flowGraph.cpp
	

fordFulkerson.o: fordFulkerson.h fordFulkerson.cpp flowEdge.h flowGraph.h
	$(CC) -c fordFulkerson.cpp
	
main.o:	main.cpp fordFulkerson.h flowEdge.h flowGraph.h
	$(CC) -c main.cpp
	

	
clean: 
	rm -f *.o
	rm -f *.out
