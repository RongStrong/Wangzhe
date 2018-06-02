CC=g++
CFLAGS=-ggdb -std=c++11 -Wall -pedantic

H_FILES=MemoryOp.hpp
FILES=MemoryOp.cpp test.cpp

all: MemoryOp

MemoryOp: $(FILES) $(H_FILES)
	        $(CC) $(CFLAGS) -o MemoryOp $(FILES) -lpthread

clean:
	        rm -rf MemoryOp
