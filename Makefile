CC = gcc

all: main

main: functions.o
    $(CC)  -o main main.c functions.o

functions.o: functions.c header.h
    $(CC)  -c functions.c

clean:
    rm -f *.o main

.PHONY: all clean
