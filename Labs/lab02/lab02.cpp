//Brendan Cain
//2-16-17

#include <iostream>
using namespace std;

const int NUM_SCORES = 3;

//calculates average
double calcAvg(double scores[]);
void printGrade(double a);

int main(){
	
	double scores[3];

	for(int i=0; i<NUM_SCORES; i++){
		cout << "Enter your score: " << endl;
		cin >> scores[i];
	}
	double avg = calcAvg(scores);
	printGrade(avg);
}//end main

double calcAvg(double scores[]){
	double total = 0;
	double avg;
	for(int i=0; i<NUM_SCORES; i++){
		total += scores[i];
	}

	avg = total/NUM_SCORES;

	return avg;
}//end calculate average

void printGrade(double a){

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Your average is: " << a << endl;
	int c = static_cast<int>(a)/10;

	switch(c){
		case 10:
		case 9:
			cout << "You earned an A." << endl;
			break;

		case 8:
			cout << "You earned a B." << endl;
			break;

		case 7:
			cout << "You earned a C." << endl;
			break;

		case 6:
			cout << "You earned a D." << endl;
			break;

		default:
			cout << "You earned an F." << endl;
			break;
	}//end switch case
}//end Print Grade