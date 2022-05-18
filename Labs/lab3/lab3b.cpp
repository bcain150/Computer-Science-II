#include <iostream>
using namespace std;

int main(){
	int numIcedTea = 10;
	int *pntrIcedTea = &numIcedTea;

	cout << "pntrIcedTea = " << pntrIcedTea << endl;
	cout << "*pntrIcedTea = " << *pntrIcedTea << endl;
	*pntrIcedTea = 20;
	cout << "numIcedTea = " << numIcedTea << endl;
	cout << "*pntrIcedTea =" << *pntrIcedTea << endl;

	return 0;
}