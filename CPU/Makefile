CC=g++
CFLAGS=-ggdb -std=c++11 -Wall -pedantic

H_FILES=CpuOp.hpp
FILES=CpuOp.cpp test.cpp

all: CpuOp

CpuOp: $(FILES) $(H_FILES)
	$(CC) $(CFLAGS) -o CpuOp $(FILES)

clean:
	rm -rf CpuOp
