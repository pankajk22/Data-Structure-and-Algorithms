all: sample

sample: entry.o main.o
	g++ main.o entry.o  -o sample
	

entry.o: entry.cpp
	g++ -c entry.cpp
	
main.o: main.cpp
	g++ -c main.cpp

clean:
	rm -f *o sample

