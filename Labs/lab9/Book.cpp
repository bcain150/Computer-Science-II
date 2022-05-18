#include "Book.h"
#include <iostream>
#include <string>
using namespace std;

Book::Book(string name, string author){
  m_name = name;
  m_author = author;
}

Fiction::Fiction(string name, string author)
  : Book(name, author){}

void Fiction::Open(){
  cout << "You open your favorite book, " << m_name << ", which was written by " 
       << m_author << "." << endl;
}
void Fiction::Close(){
  cout << "You tire of reading and you shut " << m_name << "." << endl;
}
void Fiction::Borrow(){
  cout << "The library allows you to check out " << m_name << "." << endl;
}

NonFiction::NonFiction(string name, string author)
  : Book(name, author)
{
}

void NonFiction::Open(){
  cout << "You lift the heavy tome, " << m_name << ", and open it." << endl;
}
void NonFiction::Close(){
  cout << "You finish with the mighty book, " << m_name << " and close it." << endl;
}
void NonFiction::Borrow(){
  cout << "You try to borrow the large book but you are denied." << endl;
}

