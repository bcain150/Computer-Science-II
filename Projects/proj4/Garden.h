#ifndef GARDEN_H
#define GARDEN_H
#include "Plant.h"
#include "Vegetable.h"
#include "Tree.h"
#include "Flower.h"

class Garden {
public:
  //Title: Garden() Constructor
  //Pre: Garden
  //Post: Garden object with no plants
  Garden();
  //Title: Garden() Destructor
  //Pre: Garden
  //Post: Garden object (and plants) are destroyed
  ~Garden();

  //Title: addPlant(int, int)
  //Pre: Requires type of plant (1 = Flower, 2 = Vegetable, 3 = Tree) and the quantity of that type
  //Post: Plant added to the garden vector  
  void addPlant(int type, int quantity);

  //Title: tick(int) 
  //Pre: Garden One tick = One month
  //Post: Calls tick for each item in the garden for the duration passed to it
  void tick(int);

  //Title: tick(1)
  //Pre: Garden
  //Post: Calls tick for each item in the garden for exactly one month
  void tick();
    
  //Title: getSize
  //Pre: Garden
  //Post: returns how many items are in the garden
  int getSize();
  
  //Title: getMonths
  //Pre: Garden
  //Post: returns how many months have passed since start of simulation
  //    (i.e., how many ticks)
  int getMonths();
        
private:
    vector <Plant*> m_garden;
    int m_gardenSize;
    int m_month;
};

#endif
