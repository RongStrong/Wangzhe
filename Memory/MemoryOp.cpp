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
	//int fd = open("../../CloudAtlas.mp4", O_RDWR);
	int fd = open("TheBlueDanube.mp3", O_RDWR);
	unsigned int page_size = 4096;
	//unsigned int file_size = 3435973836;
	unsigned int file_size = 24517284;
	char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char tmp;
	start = rdtsc1();
	for(int i = 0; i < 1000; i++) {
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
	double res = sum * 1.0 / 1000;
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


double MemoryOp::MemoryLatency(){


	for(int sizeIndex = 10; sizeIndex < 25; sizeIndex++){
		for(int stride = 1; stride < 10; stride ++){

			size_t size = 1 << sizeIndex;
			uint64_t* array = (uint64_t*) malloc(size);
            memset(array, 0, size);
            void ** parray =  (void **) array;

			int num = size/(sizeof(int*));

			for(int i=0; i<num; i++){
				parray[i] = &parray[(i+stride)%num];
			}

			uint64_t* p = array;
                uint64_t start;
	        uint64_t end;
	        uint64_t sum=0;

            for(int i=0; i<1000; i++){
            	start = rdtsc1();
            	p = (uint64_t*) (*p);
            	end = rdtsc1();

                sum+=(end-start);
            }

            float latency = (sum*1.0)/1000;

            printf("SizeIndex is %d, stride is %d, latency is %f\n", sizeIndex, stride, latency);

		}
	}

	return 0.0;

}

