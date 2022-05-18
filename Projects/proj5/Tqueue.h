#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>

using namespace std;

template <class T, int N>
class Tqueue {
public:
  //Name: Tqueue - Default Constructor
  //Precondition: None (Must be templated)
  //Postcondition: Creates a queue using dynamic array
  Tqueue(); //Default Constructor
  //Name: Copy Constructor - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Copies an existing Tqueue
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  //Name: Destructor
  //Precondition: Existing Tqueue
  //Postcondition: Destructs existing Tqueue
  ~Tqueue(); //Destructor
  //Name: enqueue
  //Precondition: Existing Tqueue
  //Postcondition: Adds item to back of queue
  void enqueue(T data); //Adds item to queue (to back)
  //Name: dequeue
  //Precondition: Existing Tqueue
  //Postcondition: Removes item from front of queue
  void dequeue(T &); //Removes item from queue (from front)
  //Name: queueFront
  //Precondition: Existing Tqueue
  //Postcondition: Retrieve front (does not remove it)
  void queueFront(T &);    // Retrieve front (does not remove it)
  //Name: isEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int isEmpty(); //Returns 1 if queue is empty else 0
  //Name: isFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int isFull(); //Returns 1 if queue is full else 0
  //Name: Overloaded assignment operator - Not used but required for project 5
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue
  int m_back; //Back of the queue
};

//**** Add class definition below ****

//Title: Tqueue.h definition
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 5/9/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements Tqueue class

/*Constructor
    - creates array of type T
    - with max size of N
*/
template <class T, int N>
Tqueue<T,N>::Tqueue(){
    m_data = new T[N];
    m_front = 0;
    m_back = 1;
}//end Tqueue

/*Copy Constructor
    - copies member variables
    - puts them in newly constructed instance
*/
template <class T, int N>
Tqueue<T,N>::Tqueue( const Tqueue<T,N>& x ){
    //copies member variables.
    m_data = new T[N];
    //m_back's and m_front's are not the same 
    //but the functionality is still there
    m_back = x.m_back - x.m_front;
    m_front = 0;
    for(int i=0; i<m_back; i++){
      m_data[i] = x.m_data[x.m_front+i];
    }
}//end Tqueue

/*Destructor
    -deletes the dynamic array
*/
template <class T, int N>
Tqueue<T,N>::~Tqueue(){
    delete []m_data;
    m_data = NULL;
}//end ~Tqueue

/*enqueue
    - updates m_back
    - adds to the end of queue
*/
template <class T, int N>
void Tqueue<T,N>::enqueue(T data){
    m_data[m_back] = data;
    m_back++;
}//enqueue

/*dequeue
    - saves data from the front of the queue
    - updates m_front
*/
template <class T, int N>
void Tqueue<T,N>::dequeue(T& data){
    data = m_data[m_front];
    m_front ++;
}//end dequeue

/*queueFront
*/
template <class T, int N>
void Tqueue<T,N>::queueFront(T& data){
    data = m_data[m_front];
}//end queueFront

/*isEmpty
    -resets m_back and m_front
    -returns 1 if empty 0 if not
*/
template <class T, int N>
int Tqueue<T,N>::isEmpty(){
    if(m_front+1 == m_back){
        m_front = 0;
        m_back = 1;
        return 1;
    }
    return 0;
}//end isEmpty

/*isFull
    -returns 1 if full
    -0 if not
*/
template <class T, int N>
int Tqueue<T,N>::isFull(){
    if(m_back == N)
        return 1;
    return 0;
}//end isFull

/*overloaded = operator
    - makes a copy of thing on right
    - sets it to thing on left
*/
template <class T, int N>
Tqueue<T,N>& Tqueue<T,N>::operator=( Tqueue<T,N> y){
    Tqueue<T,N> x(y);
    return x;
}//end overloaded = operator

#endif
