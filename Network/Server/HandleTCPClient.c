#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for recv() and send() */
#include <unistd.h>     /* for close() */
#include <iostream>
#include <assert.h>


using namespace std;
#define BUFSIZE 2048

void HandleTCPClient(int clntSocket, int type)
{
	
    char buffer[BUFSIZE];
    unsigned numBytesSent;
    unsigned numBytesRcvd;
    
    if(!type){
    	//send back to client
		while((numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0)) > 0){
			numBytesSent = send(clntSocket, buffer, numBytesRcvd, 0);
			if(numBytesSent != numBytesRcvd){
				printf("Error when server send!");
			}
		}
	}
	else{
		//do nothing
		while((numBytesRcvd = recv(clntSocket, buffer, BUFSIZE, 0)) > 0){
		}
	}
	   
    close(clntSocket);    /* Close client socket */
}


