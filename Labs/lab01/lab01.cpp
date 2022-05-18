#include <iostream>
#include <string>
using namespace std;

int main(){
	string bottle;
	int num;

	cout << "What number would you like to start with?:" << endl;
	cin >> num;
	cout << "What type of bottle would you like?:" << endl;
	cin >> bottle;

	for(int i=num; i>0; i--){
		cout << i << " bottles of " << bottle << " on the wall." << endl;
		cout << i << " bottles of " << bottle << "." << endl;
		cout << "Take one down, pass it around." << endl;
		cout << i-1 << " bottles of " << bottle << " on the wall." << endl;
	}
	return 0;
}
