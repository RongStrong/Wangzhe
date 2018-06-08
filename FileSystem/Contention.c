#include <stdint.h>
#include <iostream>
#include <unistd.h>
#include <cstring>
#include <cstdlib>
#include <malloc.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

uint64_t inline rdtsc1()
{
	uint32_t lo,hi;
	
	__asm__ __volatile__
	(
	 "rdtsc":"=a"(lo),"=d"(hi)
	);
	return ((uint64_t)hi<<32|lo);
}

int main() {
	int numProc = 0;
	cout << "input number of processes: ";
	cin >> numProc;
	for(int i = 0; i < numProc; i++) {
		pid_t pid = fork();
		if(pid == 0) {
			uint64_t begin;
			uint64_t end;
			uint64_t sum = 0;
			stringstream strStream;
			strStream << i;
			string filename = "ContensionTests/file" + strStream.str() + ".txt";
			const size_t BUFF_SIZE = 4096;
			char* buffer = (char*)memalign(BUFF_SIZE, BUFF_SIZE);
			int fd = open(filename.c_str(), O_DIRECT | O_RDWR);
			for (int i = 0; i < 20; ++i)
			{
				begin = rdtsc1();
				pread(fd, buffer, BUFF_SIZE, i * BUFF_SIZE);
				end = rdtsc1();
				sum += end - begin;
			}
			close(fd);
			double mean = (double) sum / 20;
			cout << "Reading " << filename << ", mean cycles per block: " << mean << endl;
			return EXIT_SUCCESS;
		}
	}
	return EXIT_SUCCESS;
}
