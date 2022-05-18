#ifndef TREE_H
#define TREE_H
#include "Plant.h"
#include "Fruit.h"
#include <vector>

class Tree: public Plant {
public:
  //Title: Tree () Constructor
  //Pre: Garden
  //Post: Tree object
  Tree();

  //Title: ~Tree
  //Pre: Garden
  //Post: Destroys tree (and fruit?)  
  ~Tree();

  //Title: die
  //Pre: Garden
  //Post: A tree can die after 120 months
  virtual void die();

  //Title: ClearFruit
  //Pre: Garden and Tree with fruit
  //Post: Clears all fruit from the tree  
  void ClearFruit();

  //Title: virtual void tick(Plant::EVENT)
  //Pre: Garden
  //Post: A month passes in the tree's life
  virtual void tick();
  
  //Title: virtual std::ostream &operator>>(std::ostream&)
  //Pre:  -
  //Post: Inserts into the ostream& the tree's information
  virtual ostream& operator<<(ostream&);

private:
    vector <Fruit*> m_fruit;
};

#endif 
