CC = gcc
CFLAGS = -Wall
DEP = src/main.c src/io.c src/operations.c

all:TRIANGLE

TRIANGLE: 
	$(CC) -c src/main.c -o obj/main.o
	$(CC) -c src/io.c -o obj/io.o -lm
	$(CC) -c src/t_calc.c -o obj/t_calc.o -lm
	$(CC) obj/* -o triangle -lm

clean:
	rm -f triangle
	rm -rf obj/*
	rm -rf *.o