CC=gcc
CFLAGS=-Wall -std=c11
LIBS=

all: clean attraction

attraction:
	$(CC) $(CFLAGS) $(LIBS) *.c -o $@


.PHONY: clean

clean:
	rm -f *.o attraction
