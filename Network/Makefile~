CC=g++
CFLAGS=-ggdb -std=c++11 -Wall -pedantic

H_FILES=NetworkOp.h
FILES=NetworkOp.c

all: NetworkOp

MemoryOp: $(FILES) $(H_FILES)
	        $(CC) $(CFLAGS) -o NetworkOp $(FILES) -lpthread

clean:
	        rm -rf NetworkOp
