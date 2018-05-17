#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "rdtsc.h"
#include <string.h>

int main(int argc, char* argv[]) {

	    for(int sizeIndex = 10; sizeIndex < 29; sizeIndex++){
		            for(int strideSize = 6; strideSize < 7; strideSize ++){

				                int stride = 1 << strideSize;
						            int ** array = malloc(1 << sizeIndex);

							                int i; 
									            int num = (1 << sizeIndex) / (stride * sizeof(*array));
										                for (i = 0; i < num-1; i++)
													                array[i * stride] = (int*)(array + ((i + 1) * stride));
												            array[i * stride] = (int*)array;

													                void **p = (void **)array;

															            float start;
																               float end;																		            float sum=0;

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
