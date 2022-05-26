CC = gcc
CFLAGS = -Wall -pedantic -g -O3


all: forkit

forkit: forkit.o
	$(CC) $(CFLAGS) -o forkit forkit.c

forkit.o: forkit.c
	$(CC) $(CFLAGS) -o forkit.o forkit.c


clean:
	rm -f *.o

server:
	ssh acheun29@unix1.csc.calpoly.edu

upload:
	scp -r ../csc357-lab07 acheun29@unix1.csc.calpoly.edu:csc357

download:
	scp -r acheun29@unix1.csc.calpoly.edu:csc357/csc357-lab07 /Users/andrewcheung/Documents/Cal\ Poly\ Stuff/csc357

