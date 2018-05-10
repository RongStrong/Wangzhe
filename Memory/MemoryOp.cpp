#include "MemoryOp.hpp"

uint64_t inline rdtsc1()
{
	uint32_t lo,hi;

       	__asm__ __volatile__
	(
	 "rdtsc":"=a"(lo),"=d"(hi)
	);
	return ((uint64_t)hi<<32|lo);
}

