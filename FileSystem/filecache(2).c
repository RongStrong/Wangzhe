#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFERSIZE 1024

static inline uint64_t  rdtsc(void) __attribute__((always_inline));

static inline uint64_t  rdtsc(void)
{
  uint32_t      hi, lo;

  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( lo | ((uint64_t)hi << 32));
}


int main() {

    char filename[] = "fileCacheTest.XXXXXX";
    char buffer[BUFFERSIZE];
    int fd = 0;
    int64_t current_size = 0;
    int numbytes = 0;

    int64_t size_ini = (int64_t)(1)<<30;
    int64_t size_des = (int64_t)(1)<<34;
    int pace = 1 << 30;
    
    memset(buffer, '0', BUFFERSIZE);
    if((fd = mkstemp(filename)) == -1){
    	printf("Fails to creating file");
    } 

    for(int64_t size = size_ini, i = 1; i < 16; size = size+pace, i++){
        
    	while(current_size < size){
    		numbytes = write(fd, buffer, BUFFERSIZE);
    		current_size = current_size+numbytes;
    	}

        double sizeGB = 0;

        //reading file into main memory
        if(lseek(fd, 0, SEEK_SET) == -1){
                printf("Error!");
        }

        while((numbytes = read(fd, buffer, BUFFERSIZE))!= 0){

        }
        
        //estimate cache size
        unsigned long sum = 0;
        if(lseek(fd, 0, SEEK_SET) == -1){
                printf("Error!");
        }

        int64_t readed = 0;
        while(1){
            unsigned long start = rdtsc();
            numbytes = read(fd, buffer, BUFFERSIZE);
            unsigned long end = rdtsc();
            sum+=(end-start);
            if(numbytes == 0) break; 
            readed += numbytes;
        }
        
        sizeGB = readed*1.0/1024/1024/1024; 
        double average = (sum*1.0);
        average =average*0.45*0.001*0.001*0.001;

        double GB = sizeGB/average;

        printf("Size: %f GB, Speed: %f GB/s \n", sizeGB, GB);

    }

}


