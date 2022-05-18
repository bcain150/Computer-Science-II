//Title: Delivery.cpp
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 5/9/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements Delivery class

#include "Delivery.h"

/*constructor
    -creates an new instance of class Delivery
*/
Delivery::Delivery(){}
Delivery::Delivery(string name, int numItem, int rtMinute){
    m_name = name;
    m_numItem = numItem;
    m_rtMinute = rtMinute;
}//end constructor

/*Getter Functions
    -return member varibles
*/
string Delivery::GetName() const{
    return m_name;
}//end GetName
int Delivery::GetNumItem() const{
    return m_numItem;
}//end GetNumItem
int Delivery::GetRTMinute() const{
    return m_rtMinute;
}//end GetRTMinute (travel time)