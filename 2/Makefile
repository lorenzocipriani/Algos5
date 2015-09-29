CC=gcc
CFLAGS=-Wall -std=c11
LIBS=-lm
LIBS2=-lgmp

all: clean gausswalk gausswalk_gmp

gausswalk:
	$(CC) $(CFLAGS) $(LIBS) 2.c -o $@

gausswalk_gmp:
	$(CC) $(CFLAGS) $(LIBS2) 2_gmp.c -o $@

.PHONY: clean

clean:
	rm -f *.o gausswalk gausswalk_gmp
