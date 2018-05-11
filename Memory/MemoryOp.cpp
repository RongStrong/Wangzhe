#include "MemoryOp.hpp"
#include <stdint.h>
#include <iostream>

double MemoryReadBD(int *array, int len, int numloop);
double MemoryWriteBD(int *array, int len, int numloop);

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
	uint64_t sum = 0;
	int fd = open("../../CloudAtlas.mp4", O_RDWR);
	unsigned int page_size = 4096;
	unsigned int file_size = 3435973836;
	char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char tmp;
	start = rdtsc1();
	for(int i = 0; i < 100000; i++) {
		int offset = (i + 1) * 5 * page_size % file_size;
		//tmp = map[offset];
		start = rdtsc1();
		tmp = map[offset];
		//tmp = map[(i + 1) * 5 * page_size % file_size];
		end = rdtsc1();
		sum += end - start;
	}

	munmap(map, file_size);
	close(fd);
	double res = sum * 1.0 / 100000;
	return res;
}

void MemoryOp::MemoryBindWidth(int rounds){
	int exp = 22;
	int len = 1 << exp;
	int size = len*sizeof(int);
	int *in;
	//cout<<"before malloc"<<endl;
	if (!(in = (int *)malloc(size)))
	{
		cout << "Malloc failure" << endl;
		exit(1);
	}
	//cout<<"after malloc"<<endl;
	double write_bd;
	double read_bd;
	for(int i=0;i<rounds;i++){
		//cout<< "loop " << i << endl;
		write_bd = MemoryWriteBD(in, len, 100);
		read_bd = MemoryReadBD(in, len, 100);
		cout << "MemoryWriteBD: " << write_bd << "byte/cycle" << endl;
		cout << "MemoryReadBD: " << read_bd << "byte/cycle" << endl;
	}
	free(in);
	return;	
}

double MemoryWriteBD(int *array, int len, int numloop){
	uint64_t start;
	uint64_t end;
	uint64_t sum;
	for(int i=0;i<numloop;i++){
		for(int j=0;j<len;j++){
			//cout<<"writing"<<endl;
			start = rdtsc1();
			array[j] = 1;
			end = rdtsc1();
			sum += end-start;
		}
	}
	uint64_t volumn = 4*len*numloop;
	return double(volumn)/sum;
}


double MemoryReadBD(int *array, int len, int numloop){
	uint64_t start;
	uint64_t end;
	uint64_t sum;
	int tmp;
	int stride = 1 << 16;
	for(int i=0;i<numloop;i++){
		for(int j=0;j<len;j++){
			start = rdtsc1();
			tmp = array[j];
			end = rdtsc1();
			sum += end-start;
		}
	}
	uint64_t volumn = 4*len*numloop;
	return double(volumn)/sum;
}
