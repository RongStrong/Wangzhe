#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

static inline uint64_t  rdtsc(void) __attribute__((always_inline));

static inline uint64_t  rdtsc(void)
{
  uint32_t      hi, lo;

  __asm__ __volatile__ ("rdtsc" : "=a"(lo), "=d"(hi));
  return ( lo | ((uint64_t)hi << 32));
}

int main(int argc, char* argv[]) {

    for(int sizeIndex = 10; sizeIndex < 29; sizeIndex++){
        for(int strideSize = 5; strideSize < 6; strideSize ++){

            int stride = 1 << strideSize;
            int ** array = malloc(1 << sizeIndex);

            int i; 
            int num = (1 << sizeIndex) / (stride * sizeof(*array));
            for (i = 0; i < num-1; i++)
                array[i * stride] = (int*)(array + ((i + 1) * stride));
            array[i * stride] = (int*)array;

            void **p = (void **)array;

            uint64_t start;
            uint64_t end;
            uint64_t sum=0;

            start = rdtsc();
            for(int i=0; i<100000; i++){
                p = *p;
            }
            end = rdtsc();

            double latency = (1.0*(end-start))/100000;

            printf("SizeIndex is %d, stride is %d, latency is %f\n", sizeIndex, stride, latency-6);

        }
    }
}


    
    
    
