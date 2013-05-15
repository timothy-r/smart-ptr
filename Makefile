APP = ptr
OBJS = person.o counter.o main.o
CC = g++

# change to empty to not add debug symbols 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(APP)

main.o: main.cpp person.h counter.h
	$(CC) $(CFLAGS) main.cpp

person.o: person.cpp person.h
	$(CC) $(CFLAGS) person.cpp

counter.o: counter.h counter.cpp
	$(CC) $(CFLAGS) counter.cpp

clean:
	rm -f *.o *.out $(APP)
