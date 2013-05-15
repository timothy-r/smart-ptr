CC = g++

all: person.o counter.o main.o
	$(CC) -Wall main.o person.o counter.o -o ptr

main.o: main.cpp person.h counter.h
	$(CC) -Wall -c main.cpp

person.o: person.cpp person.h
	$(CC) -Wall -c person.cpp

counter.o: counter.h counter.cpp
	$(CC) -Wall -c counter.cpp

clean:
	rm -f *.o *.out
