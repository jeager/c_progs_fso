CC = gcc
CFLAGS = -Wall

all:SORTING

SORTING: 
	$(CC) -c src/main.c -o obj/main.o
	$(CC) -c src/io.c -o obj/io.o -lm
	$(CC) -c src/sort.c -o obj/sort.o -lm
	$(CC) obj/* -o sorting -lm

clean:
	rm -f sorting
	rm -rf obj/*
	rm -rf *.o