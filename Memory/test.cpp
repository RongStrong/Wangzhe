#include "MemoryOp.hpp"
#include <iostream>

using namespace std;

int main() {
	MemoryOp memoryTester;
	cout << "page fault service time: " << memoryTester.pageFaultTime() << endl;
	return 0;
}
