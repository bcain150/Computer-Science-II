#ifndef FRUIT_H
#define FRUIT_H
#include <string>
using namespace std;

class Fruit {
public:
    
    // Fruit()
    // pre:  -
    // post: fruit object with random color
    Fruit();
    
   //  getColor()
    // pre:  -
    // post: returns own color
    string GetColor();

private:
    string m_color;
};

#endif
