#include "CpuOp.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	CpuOp cpuTester;
    cout<< "readOverhead:" << cpuTester.readOverhead() << endl;
	cout<< "loopOverhead:" << cpuTester.loopOverhead() << endl;
	cout<< cpuTester.CreateProOverhead() << endl;
    vector<double> procOverhead = cpuTester.procedureOverhead();
	cout<< "procedureOverhead:"  << endl;
	for(auto it = procOverhead.begin();it != procOverhead.end();it++){
		cout<< *it << endl;
	}
    cout<< "systemCallOverhead:" << cpuTester.systemCallOverhead() << endl;
	cout<< "ConWitchProOverhead:" << cpuTester.ConWitchProOverhead() << endl;
    cout<< "ConWitchThrOverhead:" << cpuTester.ConWitchThrOverhead() << endl;
    cout<< "CreateProOverhead:" << cpuTester.CreateProOverhead() << endl;
    cout<< "CreateThrOverhead:" << cpuTester.CreateThrOverhead() << endl;
	return 0;
}
