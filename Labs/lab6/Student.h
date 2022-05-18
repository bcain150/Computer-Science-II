#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

class Student
{
 public:
  Student();
  ~Student();
  void Display();
 private:
  int m_num;
  float *m_ptr;
};

#endif
