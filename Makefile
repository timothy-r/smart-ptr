APP = ptr
OBJS = person.o counter.o main.o
CC = g++

# change to empty to not add debug symbols 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
IFLAGS = -I include/

all: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(APP)

main.o: main.cpp include/person.h include/counter.h
	$(CC) $(CFLAGS) $(IFLAGS) main.cpp

person.o: src/person.cpp include/person.h
	$(CC) $(CFLAGS) $(IFLAGS) src/person.cpp

counter.o: include/counter.h src/counter.cpp
	$(CC) $(CFLAGS) $(IFLAGS) src/counter.cpp

clean:
	rm -f *.o *.out $(APP)
