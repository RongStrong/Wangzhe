CC=g++
CFLAGS=-ggdb -Wall -pedantic

FILES=NetworkServer.c HandleTCPClient.c

all: NetworkServer

NetworkServer: $(FILES)
	        $(CC) $(CFLAGS) -o NetworkServer $(FILES) 

clean:
	        rm -rf NetworkServer
