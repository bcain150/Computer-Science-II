/*There are a number of optional functions in Truck.h. 
This is because you may want to implement the management of the trucks in a variety of ways. 
Trucks are kind of complex so it is up to you as to how you want to implement them. 
If you don't use a function, just stub it out and include a quick comment.
 */

#ifndef TRUCK_H
#define TRUCK_H

#include "Item.h"
#include "Tqueue.h"
#include "Delivery.h"

#include <vector>
using namespace std;

template <class T, int N>
class Truck {
 public:
  //Name: Truck(string, int) Overloaded constructor.
  //Precondition: Requires truck file has been loaded
  //Postcondition: Builds a new templated truck
  Truck(string inName, int capacity);

  //Name: Destructor
  //Precondition: Requires truck file has been loaded
  //Postcondition: Destroys everything in truck
  ~Truck();

  //Name: GetItem (optional)
  //Precondition: Requires that the truck's item queue has been populated
  //Postcondition: Templated accessor for this truck's cargo
  //Tqueue<T,N> GetItem() const;

  //Name: GetItemAt (optional)
  //Precondition: Requires that the truck's item queue has been populated
  //Postcondition: Templated accessor for this truck's cargo at a specific location
  //const T& GetItemAt(int index) const;

  //Name: AddItem (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Adds item into this truck
  void AddItem(T& inputObject);

  //Name: DeliverItemFromTruck (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Delivers item from this truck to customer
  void DeliverItemFromTruck();

  //Name: AddDelivery (optional)
  //Precondition: Requires that all deliveries have been input and trucks
  //Postcondition: Used to add deliveries for specific trucks
  void AddDelivery(Delivery&);

  //Name: CompleteDelivery (optional)
  //Precondition: Requires that deliveries have been assigned to this truck
  //Postcondition: Removes current deliveries from this truck
  void CompleteDelivery();

  //Name: GetDeliveryAt (optional)
  //Precondition: Requires that this truck has at least 1 delivery assigned to it
  //Postcondition: Used to return a specific delivery
  Delivery& GetDeliveryAt(int index);

  //Name: GetDelivery (optional)
  //Precondition: Requires deliveries have been asssigned to this truck
  //Postcondition: Used to return the entire vector of deliveries
  vector<Delivery> GetDelivery() const;
 
  //Name: GetTime (optional)
  //Precondition: None
  //Postcondition: Used to return current time for a specific truck
  int GetTime(); 

  //Name: SetTime (optional)
  //Precondition: None
  //Postcondition: Used to set time for a specific truck
  void SetTime(int time);

  //Name: GetCapacity (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Used to access the capacity of a truck
  int GetCapacity() const;

  //Name: GetName (optional)
  //Precondition: Requires that the trucks have been loaded
  //Postcondition: Used to access the name of a truck
  string GetName() const;

private:
  string m_name;
  int m_capacity;
  int m_time;
  vector<Delivery> m_curDelivery;
  Tqueue<T,N> m_item;
};
//Implement the class definition below

//Title: Truck.h definition
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 5/10/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements Truck class

/*Constructor
*/
template <class T, int N>
Truck<T,N>::Truck(string inName, int capacity){
  m_name = inName;
  m_capacity = capacity;
}//end constructor

/*Destructor
*/
template <class T, int N>
Truck<T,N>::~Truck(){}

/*AddItem
  -adds Item to Tqueue in truck
*/
template <class T, int N>
void Truck<T,N>::AddItem(T& inputObject){
  m_item.enqueue(inputObject);
}//end AddItem

/*DeliverItemFromTruck
  -removes item from m_item Tqueue
*/
template <class T, int N>
void Truck<T,N>::DeliverItemFromTruck(){
  T data;
  m_item.dequeue(data);
}//end DeliverItemFromTruck

/*AddDelivery
  -adds a delivery to the delivery vector
*/
template <class T, int N>
void Truck<T,N>::AddDelivery(Delivery& del){
  m_curDelivery.push_back(del);
}//end AddDelivery

/*CompleteDelivery
  -adds a delivery to the delivery vector
*/
template <class T, int N>
void Truck<T,N>::CompleteDelivery(){
  m_curDelivery.clear();
}//end CompleteDelivery

/*GetDeliveryAt
  -returns Delivery at index
*/
template <class T, int N>
Delivery& Truck<T,N>::GetDeliveryAt(int index){
  return m_curDelivery.at(index);
}//end GetDeliveryAt

/*GetDelivery
  -returns delivery vector;
*/
template <class T, int N>
vector<Delivery> Truck<T,N>::GetDelivery() const{
  return m_curDelivery;
}//end GetDelivery

/*GetTime
  -returns m_time
*/
template <class T, int N>
int Truck<T,N>::GetTime(){
  return m_time;
}//end GetTime

/*SetTime
  -sets m_time
*/
template <class T, int N>
void Truck<T,N>::SetTime(int time){
  m_time = time;
}//end SetTime

/*GetCapactiy
  -returns size of truck vector
*/
template <class T, int N>
int Truck<T,N>::GetCapacity() const{
  return m_capacity;
}//end GetCapacity

/*GetName
  -returns m_name;
*/
template <class T, int N>
string Truck<T,N>::GetName() const{
  return m_name;
}//end GetName


#endif