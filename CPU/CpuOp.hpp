#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

using namespace std;

static int fd[2];

class CpuOp {

public:
	double readOverhead();
    double loopOverhead();
	vector<double> procedureOverhead();
	double systemCallOverhead();
	double ConWitchProOverhead();
	double ConWitchThrOverhead();
	double CreateThrOverhead();
	double CreateProOverhead();
	
};

