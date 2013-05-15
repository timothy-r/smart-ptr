APP = ptr
OBJS = person.o counter.o main.o
CC = g++

# change to empty to not add debug symbols 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(APP)

main.o: main.cpp include/person.h include/counter.h
	$(CC) $(CFLAGS) main.cpp

person.o: src/person.cpp include/person.h
	$(CC) $(CFLAGS) src/person.cpp

counter.o: include/counter.h src/counter.cpp
	$(CC) $(CFLAGS) src/counter.cpp

clean:
	rm -f *.o *.out $(APP)
