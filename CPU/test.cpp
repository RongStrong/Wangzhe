#include "CpuOp.hpp"
#include <iostream>
#include <vector>
using namespace std;

int main(){
	CpuOp cpuTester;
	cout<< "readOverhead:" << cpuTester.readOverhead() << endl;
	cout<< "loopOverhead:" << cpuTester.loopOverhead() << endl;
//	cout<< cpuTester.CreateProOverhead() << endl;
    vector<double> procOverhead = cpuTester.procedureOverhead();
	cout<< "procedureOverhead:"  << endl;
	for(auto it = procOverhead.begin();it != procOverhead.end();it++){
		cout<< *it << endl;
	}
	double ConWitchProOverhead = cpuTester.ConWitchProOverhead();
	double ConWitchThrOverhead = cpuTester.ConWitchThrOverhead();
	double CreateProOverhead = cpuTester.CreateProOverhead();
	double CreateThrOverhead = cpuTester.CreateThrOverhead();
	double systemCallOverhead = cpuTester.systemCallOverhead();

    cout<< "systemCallOverhead:" << systemCallOverhead << endl;
	cout<< "ConWitchProOverhead:" << ConWitchProOverhead << endl;
    cout<< "ConWitchThrOverhead:" << ConWitchThrOverhead << endl;
    cout<< "CreateProOverhead:" << CreateProOverhead << endl;
    cout<< "CreateThrOverhead:" << CreateThrOverhead << endl;
	return 0;




}
