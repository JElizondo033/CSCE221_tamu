# makefile

all: PQList PQHeap Main

PQHeap: PQHeap.h BinaryHeap.h PQHeap.cpp
	g++ -std=c++11 -o PQHeap PQHeap.cpp

PQList: PQList.h PQList.cpp 
	g++ -std=c++11 -o PQList PQList.cpp

Main: main.cpp
	g++ -o Main main.cpp

clean:
	rm -rf PQHeap PQList Main 
