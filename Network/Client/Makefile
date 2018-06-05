CC=g++
CFLAGS=-ggdb -Wall -pedantic

FILES=NetworkClient.c test.c

all: NetworkClient

NetworkClient: $(FILES)
	        $(CC) $(CFLAGS) -o NetworkClient $(FILES) 

clean:
	        rm -rf NetworkClient
