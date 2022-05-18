#include <iostream>
using namespace std;

void fillArray(int ar, int size);
void printArray(int arr, int dim);

int main(){

	const sizeOfArray = 5;
	int array[sizeOfArray];

	cout << "Array Before: " << endl;
	printArray(array, sizeOfArray);
	fillArray(array, sizeOfArray);
	cout << "Array After: " << endl;
	printArray(array, sizeOfArray);
	return 0;
}

void fillArray(int ar, int size){

	for(int i=0; i<size; i++){
		ar[i] = i;
	}
}

void printArray(int arr, int dim){

	for(int i=0; i<dim; i++){
		cout << arr[i] << ", ";
	}
	cout << endl;
}