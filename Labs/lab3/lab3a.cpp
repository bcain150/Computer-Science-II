//Brendan Cain
//lab 3
//2/23/17

#include <iostream>
#include <string>
using namespace std;

void quaff(int &p);

int main(){
	int hp = 10;
	string ans;
	string quaffed = "quaff potion";
	cout << "You have " << hp << " hit points." << endl;
	cout << "What would you like to do?: " << endl;
	getline(cin, ans);
	if(quaffed.compare(ans) == 0){
		cout << "You have quaffed the potion!" << endl;
		quaff(hp);
	}
	cout << "You have " << hp << " hit points." << endl;
}

void quaff(int &p){
	p += 2;
}