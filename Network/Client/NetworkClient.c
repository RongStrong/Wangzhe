#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), bind(), and connect() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_ntoa() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

using namespace std;
#define BUFSIZE 2048
#define MSGLEN 1024

uint64_t inline rdtsc1()
{
	uint32_t lo,hi;

       	__asm__ __volatile__
	(
	 "rdtsc":"=a"(lo),"=d"(hi)
	);
	return ((uint64_t)hi<<32|lo);
}


void startupClient(int op, int echoServPort, char *servIP)
{
    int clntSock;                    /* Socket descriptor for client */
    struct sockaddr_in echoClntAddr; /* Client address */
    char buffer[BUFSIZE];
    
    if ((clntSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        printf("socket() failed");
        
    /* Construct local address structure */
    memset(&echoClntAddr, 0, sizeof(echoClntAddr));   /* Zero out structure */
    echoClntAddr.sin_family = AF_INET;                /* Internet address family */
    echoClntAddr.sin_port = htons(echoServPort);      /* Local port */
    
    int rtnVal = inet_pton(AF_INET, servIP, &echoClntAddr.sin_addr.s_addr);
	if (rtnVal == 0)
		printf("inet_pton() failed", "invalid address string");
	else if (rtnVal < 0)
		printf("inet_pton() failed");
	
	if (connect(clntSock, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr)) < 0)
		printf("connect() failed");
	
	//Round trip time
	if(op==0){
		uint64_t start;
		uint64_t end;
		uint64_t sum;
		int times = 10000;
		memset(buffer, 97, MSGLEN);
		start = rdtsc1();
		for(int i=0;i<times;i++){
			//start = rdtsc1();
			if(send(clntSock,buffer,MSGLEN,0)!=MSGLEN){
				printf("client send error");
			}
			if(recv(clntSock,buffer,BUFSIZE-1,0)!=MSGLEN){
				printf("client receive error");
			}
		}
		end = rdtsc1();
		sum = end-start;
		double avg = sum*0.45/(times*1000000);
		printf("Round trip time: %f ms\n",avg);
	}
	//Bandwidth
	else if(op==1){
		uint64_t start;
		uint64_t end;
		int times = 1 << 20;
		memset(buffer, 97, MSGLEN);
		start = rdtsc1();
		for(int i=0;i<times;i++){
			if(send(clntSock,buffer,MSGLEN,0)!=MSGLEN){
				printf("client send error");
			}
		}
		end = rdtsc1();
		double sum = (end-start)*0.45/1000;
		double avg = 1.0*MSGLEN*times/sum;
		printf("NetworkBandwidth: %f mb/s\n",avg);
	}
	//Connection overhead
	else if(op==2){
		uint64_t start;
		uint64_t end;
		uint64_t teardown;
		uint64_t setup;
		int times = 1000;
		for(int i=0;i<times;i++){
			start = rdtsc1();
			close(clntSock);
			end = rdtsc1();
			teardown += end-start;
			if ((clntSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        		printf("socket() failed");
        	start = rdtsc1();
        	if (connect(clntSock, (struct sockaddr *) &echoClntAddr, sizeof(echoClntAddr)) < 0)
				printf("connect() failed");
			end = rdtsc1();
			setup += end-start;
		}
 		double avg_s = setup*0.45/(times*1000000);
 		double avg_t = teardown*0.45/(times*1000000);
 		printf("Setup time: %f ms\n",avg_s);
 		printf("Tear down time: %f ms\n",avg_t);
	}
	
	close(clntSock);
}
