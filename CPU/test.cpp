#include "CpuOp.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	CpuOp cpuTester;
	cout<< cpuTester.CreateProOverhead() << endl;
    vector<double> procOverhead = cpuTester.procedureOverhead();
	cout<< "loopOverhead:"  << endl;
	for(auto it = procOverhead.begin();it != procOverhead.end();it++){
		cout<< *it << endl;
	}
	
	cout<< "systemCallOverhead:" << cpuTester.systemCallOverhead() << endl;
	return 0;
}
