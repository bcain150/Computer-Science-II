//Title: Item.cpp
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 5/4/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements item class

#include "Item.h"
/*Constuctor
    -sets member varibles
*/
Item::Item(){}
Item::Item(string iName, float iWeight){
    m_name = iName;
    m_weight = iWeight;
}//end item

/*GetName
    -returns m_name of item
*/
string Item::GetName() const{
    return m_name;
}//end GetName

/*GetWeight
    -returns items weight
*/
float Item::GetWeight() const{
    return m_weight;
}//end GetWeight