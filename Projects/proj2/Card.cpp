/********************************************
** File:    Card.cpp
** Project: CMSC 202 Project 2, Spring 2017
** Author:  Brendan Cain
** Date:    03-06-17
** Section: 16 (lecture) 18 (discussion)
** E-mail:  bcain1@umbc.edu
**
** This file defines the class Card.
**********************************************/

#include "Card.h"

//Constructor Method for Card
Card::Card(){}

Card::Card(int type, string name){

	m_type = type; 
	m_desc = name;
}//end Card

//GetType():
//returns the card's type.
int Card::GetType(){
	return m_type;
}//end GetType

//ToString():
//returns the card's description
string Card::ToString(){
	return m_desc;
}//end ToString