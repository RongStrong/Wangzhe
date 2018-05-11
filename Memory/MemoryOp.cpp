#include "MemoryOp.hpp"
#include <stdint.h>

uint64_t inline rdtsc1()
{
	uint32_t lo,hi;

       	__asm__ __volatile__
	(
	 "rdtsc":"=a"(lo),"=d"(hi)
	);
	return ((uint64_t)hi<<32|lo);
}



double MemoryOp::pageFaultTime() {
	uint64_t start;
	uint64_t end;
	uint64_t sum;
	int fd = open("TheBlueDanube.mp3", O_RDWR);
	unsigned int page_size = 4096;
	unsigned int file_size = 20971520;
	char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char tmp;
	start = rdtsc1();
	for(int i = 0; i < 1000; i++) {
		int offset = ((i + 1) * page_size) % file_size;
		start = rdtsc1();
		tmp = map[offset];
		end = rdtsc1();
		sum += end - start;
	}

	munmap(map, file_size);
	close(fd);
	double res = sum * 1.0 / 1000;
	return res;
}
