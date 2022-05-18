//Title: Vegetable.h
//Author: Jeremy Dixon and Felipe Bastos
//Date: 4/11/2017
//Description: Describes the child class Vegetable (Parent Plant.h)

#ifndef VEGETABLE_H
#define VEGETABLE_H
#include "Plant.h"

class Vegetable: public Plant {
public:
  //Title: Vegetable
  //Pre: None
  //Post: Default constructor
  Vegetable();

  //Title: Vegetable(string)
  //Pre: None
  //Post: Constructor looking for vegetable color
  Vegetable(string color);

  //Title: die
  //Pre: None
  //Post: Vegetable isAlive = false
  virtual void die();

  //Title: virtual harvest
  //Pre: None
  //Post: Harvest the vegetables and calls die
  void harvest();

  //Title: virtual tick
  //Pre: None
  //Post: A month passes in the vegetable's life
  //Vegetables are harvested when they have a size of 5
  //Vegetables grow every tick that they aren't diseased
  //Vegetables have a 20% chance of being diseased each month
  //Vegetables are "un" diseased at the beginning of each month
  virtual void tick();

  //Title: operator << (Overloaded << operator)
  //Pre: None
  //Post: Inserts into the stream the vegetable's information
  virtual ostream& operator<<(ostream&);

private:
    string m_color;
};

#endif 
