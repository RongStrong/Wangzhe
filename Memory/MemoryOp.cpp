#include "MemoryOp.hpp"
#include <stdint.h>
#include <iostream>

double MemoryReadBD(int *array, uint64_t len, int numloop);
double MemoryWriteBD(int *array, uint64_t len, int numloop);

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
	//int fd = open("TheBlueDanube.mp3", O_RDWR);
	unsigned int page_size = 4096;
	unsigned int file_size = 3435973836;
	//unsigned int file_size = 24517284;
	char* map =(char*) mmap(NULL, file_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	char tmp;
	start = rdtsc1();
	for(int i = 0; i < 100; i++) {
		int offset = (i + 1) * 100 * page_size % file_size;
		//tmp = map[offset];
		start = rdtsc1();
		tmp = map[offset];
		//tmp = map[(i + 1) * 5 * page_size % file_size];
		end = rdtsc1();
		sum += end - start;
	}

	munmap(map, file_size);
	close(fd);
	double res = sum * 1.0 / 100;
	res = res * 0.45 / 1000000;
	return res;
}

void MemoryOp::MemoryBindWidth(int rounds){
	int exp = 26;
	uint64_t len = 1 << exp;
	int size = len*sizeof(int);
	int *in;
	//cout<<"before malloc"<<endl;
	if (!(in = (int *)malloc(size)))
	{
		cout << "Malloc failure" << endl;
		exit(1);
	}
	//cout<<"after malloc"<<endl;
	MemoryWriteBD(in, len, 1);
	
	double write_bd;
	double read_bd;
	for(int i=0;i<rounds;i++){
		//cout<< "loop " << i << endl;
		write_bd = MemoryWriteBD(in, len, 100);
		read_bd = MemoryReadBD(in, len, 100);
		cout << "MemoryWriteBD: " << write_bd << "Mb/s" << endl;
		cout << "MemoryReadBD: " << read_bd << "Mb/s" << endl;
	}
	free(in);
	return;	
}

double MemoryWriteBD(int *array, uint64_t len, int numloop){
	uint64_t start;
	uint64_t end;
	uint64_t sum;
	start = rdtsc1();
	for(int i=0;i<numloop;i++){
		//start = rdtsc1();
		for(int j=0;j<len;j+=8){
			//cout<<"writing"<<endl;
			//start = rdtsc1();
			array[j] = 123;
			array[j+1] = 124;
			array[j+2] = 124;
			array[j+3] = 124;
			array[j+4] = 124;
			array[j+5] = 124;
			array[j+6] = 124;
			array[j+7] = 124;
			//end = rdtsc1();
			//sum += end-start;
		}
		//end = rdtsc1();
		//sum += end-start;
	}
	end = rdtsc1();
	sum = end-start;
	uint64_t volumn = 4*len*numloop;
	return double(volumn)*1024/(sum*0.45);
}


double MemoryReadBD(int *array, uint64_t len, int numloop){
	uint64_t start;
	uint64_t end;
	uint64_t sum;
	uint64_t tmp;
	int stride = 1 << 16;
	start = rdtsc1();
	for(int i=0;i<numloop;i++){
		//start = rdtsc1();
		for(int j=0;j<len;j+=8){
			//start = rdtsc1();
			tmp += array[j]+array[j+1]+array[j+2]+array[j+3]+array[j+4]+array[j+5]+array[j+6]+array[j+7];
			/*tmp += array[j+1];
			tmp += array[j+2];
			tmp += array[j+3];
			tmp += array[j+4];
			tmp += array[j+5];
			tmp += array[j+6];
			tmp += array[j+7];*/
			//end = rdtsc1();
			//sum += end-start;
		}
		//end = rdtsc1();
		//sum += end-start;
	}
	end = rdtsc1();
	sum = end-start;
	uint64_t volumn = 4*len*numloop;
	return double(volumn)*1024/(sum*0.45);
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

