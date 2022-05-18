//Title: Plant.h
//Author: Jeremy Dixon and Felipe Bastos
//Date: 4/11/2017
//Description: Describes the parent class Plant

#ifndef PLANT_H
#define PLANT_H
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Plant {
public:
  //Title: Plant
  //Pre: None
  //Post: Abstract class (cannot be called)
  Plant();
  
  // virtual ~Plant()
  // pre:  -
  // post: destroys plant object
  virtual ~Plant();
  
  //Accessors
  
  //Title: GetIsDiseased
  //Pre: None
  //Post: returns m_isDiseased
  bool GetIsDiseased();
  
  //Title: GetIsAlive
  //Pre: None
  //Post: returns m_isAlive
  bool GetIsAlive();
  
  //Title: GetSize
  //Pre: None
  //Post: returns m_size
  int GetSize();
  
  //Title: SetSize(int)
  //Pre: None
  //Post: m_size is set
  void SetSize(int size);
  
//Title: SetIsAlive(bool)
  //Pre: None
  //Post: m_isAlive is set
  void SetIsAlive(bool isAlive);

  //Title: SetIsDiseased(bool)
  //Pre: None
  //Post: m_isDiseased is set
  void SetIsDiseased(bool isDiseased);
  
  //Title: die
  //Pre: Virtual
  //Post: Virtual
  virtual void die() = 0;
  
  //Title: tick
  //Pre: Virtual
  //Post: Virtual
  virtual void tick() = 0;
  
  // virtual std::ostream &operator>>(std::ostream&)
  // pre:  Virtual
  // post: Virtual
  virtual ostream& operator<<(ostream& os) = 0;
  
 private:
  int m_size; //Current size
  bool m_isDiseased; //Can die
  bool m_isAlive; //Current status
};


#endif
