APP = ptr
OBJS = person.o counter.o main.o
OOBJS = objs/person.o objs/counter.o objs/main.o
CC = g++

# change to empty to not add debug symbols 
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
IFLAGS = -I include/

all: $(OBJS) init
	@$(CC) $(LFLAGS) -Lobjs $(OOBJS) -o $(APP)

main.o: main.cpp include/person.h include/counter.h init
	@$(CC) $(CFLAGS) $(IFLAGS) main.cpp -o objs/main.o

person.o: src/person.cpp include/person.h init
	@$(CC) $(CFLAGS) $(IFLAGS) src/person.cpp -o objs/person.o

counter.o: include/counter.h src/counter.cpp init
	@$(CC) $(CFLAGS) $(IFLAGS) src/counter.cpp -o objs/counter.o

init:
	#@mkdir objs/

clean:
	@rm -f objs/*.o *.out $(APP)
