#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

static int fd[2];

class CpuOp {

public:
	double readOverhead();
	double ConWitchProOverhead();
	double ConWitchThrOverhead();
	double CreateThrOverhead();
	double CreateProOverhead();
	
};

