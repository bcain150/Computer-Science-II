//Title: Flower.h
//Author: Jeremy Dixon and Felipe Bastos
//Date: 4/13/2017 test
//Description: Describes the child class Flower (parent Plant.h)

#ifndef FLOWER_H
#define FLOWER_H
#include "Plant.h"

class Flower: public Plant {
public:
  //Title: Flower
  //Pre: None
  //Post: Default constructor
  Flower();

  //Title: Plant(int, string)
  //Pre: None
  //Post: Constructor with custom petals and color
  Flower(int numPetals, string color);

  //Title: die
  //Pre: Flower
  //Post: Sets isAlive to false and numPetals to 0
  virtual void die();

  //Title: virtual tick
  //Pre: Flower
  //Post: A month passes is the flower's life
  virtual void tick();
  
  //Title: operator<< (Overloaded << operator)
  //Pre: Flower
  //Post: Inserts the stream information about the flower
  virtual ostream& operator<<(ostream&);
  
 protected:
  int m_numPetals;
  string m_color;
  bool m_isFlowering;
};

#endif 
