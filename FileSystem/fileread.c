#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>


#define BUFFERSIZE 1024

static inline uint64_t  rdtsc(void) __attribute__((always_inline));

static inline uint64_t  rdtsc(void)
{
  uint32_t      hi, lo;

  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( lo | ((uint64_t)hi << 32));
}


int main() {

    char buffer[BUFFERSIZE];
    int64_t current_size = 0;
    int numbytes = 0;

    int64_t size_ini = (int64_t)(1)<<20;
    int64_t size_des = (int64_t)(1)<<27;

    memset(buffer, '0', BUFFERSIZE);

    for(int64_t size = size_ini; size < size_des; size = size*2){

     ////////////////////////////////////////////////
     //    Generate certain MB files      
     //    char filename[] = "fileCacheTest.XXXXXX";
     //    int fd = 0;

     //    if((fd = mkstemp(filename)) == -1){
     //        printf("Fails to creating file");
     //    } 

     //    int64_t writeBytes = 0;
    	// while(writeBytes < size){
    	// 	numbytes = write(fd, buffer, BUFFERSIZE);
    	// 	writeBytes = writeBytes+numbytes;
    	// }

     //    double sizeMB = size*1.0/1024/1024;
     //    printf("Size is %f MB\n", sizeMB);
    /////////////////////////////////////////////////
    	//sequential access test
        int fd = open("/Users/ebowei/Desktop/Zhiyuan/2044_001.pdf", O_SYNC);

        if(fcntl(fd, F_NOCACHE, 1) == -1) {
           printf("Failed to disable cache.\n");
        }

        //sequential access time
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
        
        double sizeMB = readed*1.0/1024/1024; 
        double average = (sum*1.0);
        average =average*0.45*0.001*0.001*0.001;
        printf("%f", average);
        double MB = sizeMB/average;

        printf("Size: %f MB, Speed: %f MB/s \n", sizeMB, MB);
    ///////////////////////////////////////////////////

        //random access file
        // int fd = open("fileCacheTest.zFYKwJ", O_SYNC);

        // if(fcntl(fd, F_NOCACHE, 1) == -1) {
        //    printf("Failed to disable cache.\n");
        // }
        // unsigned long sum = 0;
        // for(int i=1; i<=1024; i++){
          
        //     int random_num = random() % i;
        //     if(lseek(fd, random_num * 1024, SEEK_SET) == -1){
        //         printf("Error!");
        //     }
        //     unsigned long start = rdtsc();
        //     if((numbytes = read(fd, buffer, BUFFERSIZE))== -1){
        //         printf("Error!");
        //     }
        //     unsigned long end = rdtsc();
        //     sum+=(end-start);
        // }
        
        // double sizeMB = 1024*1.0*1024/1024/1024; 
        // double average = (sum*1.0);
        // average =average*0.45*0.01*0.001*0.001;

        // double MB = sizeMB/average;
        
        // printf("Size: %f MB, Speed: %f MB/s \n", sizeMB, MB);
        // printf("\n");

    }

}