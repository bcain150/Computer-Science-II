//Title: Fruit.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 4/26/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the Fruit class

#include "Fruit.h"

/*Fruit()
    -constructor
    -sets color
*/
Fruit::Fruit(){
    m_color = "Red";
}//end Fruit

/*GetColor()
    -getter for m_color
*/
string Fruit::GetColor(){
    return m_color;
}//end GetColor