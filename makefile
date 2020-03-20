CC = gcc

all: main.o pnoise.o
	$(CC) -o main main.o pnoise.o -lm

main.o: main.c pnoise.h
	$(CC) -c main.c

pnoise.o: pnoise.c pnoise.h
	$(CC) -c pnoise.c

run:
	./main