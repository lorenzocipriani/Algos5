CC=g++
CFLAGS=-Wall -std=c++11 -Wno-sign-compare
binary=bitmaze

all: clean $(binary)

$(binary):
	$(CC) $(CFLAGS) *.cc -o $(binary)

.PHONY: clean

clean:
	rm -f *.o $(binary)
