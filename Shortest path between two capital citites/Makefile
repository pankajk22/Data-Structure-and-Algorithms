all: sample cleanz

sample: main.o vertex.o edge.o
	g++ main.o vertex.o edge.o -o sample
	
main.o: main.cpp
	g++ -c main.cpp
	
vertex.o:vertex.cpp	
	g++ -c vertex.cpp

edge.o:edge.cpp
	g++ -c edge.cpp
	

	
	
cleanz:
	rm *o
	
clean:
	rm *o
