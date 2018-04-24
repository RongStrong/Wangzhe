#include "CpuOp.hpp"
#include <stdint.h>
#include <vector>

#define TIMES 10000

uint64_t inline rdtsc()
{
        uint32_t lo,hi;

        __asm__ __volatile__
        (
         "rdtsc":"=a"(lo),"=d"(hi)
        );
        return ((uint64_t)hi<<32|lo);
}

uint64_t inline rdtsc1(){
	uint32_t lo, hi;
	__asm__ __volatile__("xor %%eax, %%eax;" "cpuid;" "rdtsc;": "=a" (lo), "=d" (hi));
	return ((uint64_t)hi << 32) | lo;
}

double CpuOp::readOverhead(){
	uint64_t sum = 0;
	uint64_t start;
	uint64_t end;
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		end = rdtsc1();
		sum += end - start;
	}
	return double(1.0*sum/TIMES);
}

double CpuOp::loopOverhead(){
	uint64_t start;
	uint64_t end;
	start = rdtsc1();
	for(int i=0;i<TIMES;i++){}
	end = rdtsc1();
	return double(1.0*(end-start)/TIMES);
}

vector<double> CpuOp::procedureOverhead(){
	vector<double> res;
	uint64_t sum = 0;
	uint64_t start;
	uint64_t end;
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee0();
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee1(0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee2(0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee3(0,0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee4(0,0,0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee5(0,0,0,0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee6(0,0,0,0,0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	sum = 0;
	
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		callee7(0,0,0,0,0,0,0);
		end = rdtsc1();
		sum += end-start;
	}
	res.push_back(double(1.0*sum/TIMES));
	
	
	return res;
}

double CpuOp::systemCallOverhead(){
	uint64_t sum = 0;
	uint64_t start;
	uint64_t end;
	for(int i=0;i<TIMES;i++){
		start = rdtsc1();
		getpid();
		end = rdtsc1();
		sum += start-end;
	}
	return double(1.0*sum/TIMES);
}

double CpuOp::ConWitchProOverhead(){
	uint64_t sum = 0;
	uint64_t count = 0;
	// int fd[2];
	pipe(fd);


	for(int i=0;i<TIMES;i++){
		uint64_t start ;
	    uint64_t end ;

		if(fork()!=0){
		   start = rdtsc1();
		   wait(NULL);
		   read(fd[0], (void*)&end, sizeof(uint64_t));
		}
		else{
			end = rdtsc1();
			write(fd[1], (void*)&end, sizeof(uint64_t));
			exit(1);
		}
		if(end>start){
			sum+=end-start;
            count++;
		}
	}

    return double(1.0*sum/count);

}

void *func(void * ) {
    uint64_t end= rdtsc1();
    write(fd[1], (void*)&end, sizeof(uint64_t));
    pthread_exit(NULL);
}

double CpuOp::ConWitchThrOverhead(){
	uint64_t sum = 0;
	pipe(fd);

	for(int i=0;i<TIMES;i++){
		uint64_t start ;
	    uint64_t end ;

		pthread_t thread;
		pthread_create(&thread, NULL, func, NULL);
		start = rdtsc1();
		pthread_join(thread, NULL);

		read(fd[0], (void*)&end, sizeof(uint64_t));
        sum+=end-start;
	}

    return double(1.0*sum/TIMES);

}

double CpuOp::CreateProOverhead(){
	uint64_t sum=0;
    
    for(int i=0;i<TIMES;i++){
		uint64_t start;
	    uint64_t end;

        rdtsc1();
        start = rdtsc1();
		if(fork()!=0){
		   wait(NULL);
		   end = rdtsc1();
		   sum+=end-start;
		}
		else{
			exit(1);
		}
	}

	return double(1.0*sum/TIMES);

}

void *func2(void * ) {
    pthread_exit(NULL);
}

double CpuOp::CreateThrOverhead(){
	uint64_t sum = 0;

	for(int i=0;i<TIMES;i++){
		uint64_t start;
	    uint64_t end;

		pthread_t thread;
		start = rdtsc1();
		pthread_create(&thread, NULL, func2, NULL);
		pthread_join(thread, NULL);
        
        end = rdtsc1();
		sum+=end-start;
	}
    
    return double(1.0*sum/TIMES); 
}







