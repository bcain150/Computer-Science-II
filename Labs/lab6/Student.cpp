#include "Student.h"

Student::Student(){
	cout << "Enter total number of students: ";
	cin >> m_num;
	cout << endl;
	m_ptr = new float[m_num];
	cout << "Enter GPA of students." << endl;
	float temp = 0;
	for(int i=0; i<m_num; i++){
		cout << "Student" << i+1 << ": ";
		cin >> temp;
		cout << endl;
		m_ptr[i] = temp;
	}//end for
}//end constructor

Student::~Student(){
	delete[] m_ptr;
}//endl;

void Student::Display(){
	cout << "Displaying GPA of students." << endl;
	for(int i=0; i<m_num; i++){
		cout << "Student" << i+1 << ": " << m_ptr[i] << endl;
	}//end for
}//end display