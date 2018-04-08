CC=g++
CFLAGS=-std=c++11 -g -Wall -c 

all: main

main: main.o lib.o
	$(CC) main.o lib.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS)  -c main.cpp 

lib.o: lib.cpp
	$(CC) $(CFLAGS)  -c lib.cpp  -std=c++11 -g -Wall


clean:
	-@rm -rf *.o main >/dev/null 2>/dev/null

#commend add 
