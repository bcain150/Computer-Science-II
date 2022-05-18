 //Title: Flower.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 4/24/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the plant class

#include "Flower.h"

/*Flower()
	-constructor
	-has a default value for petals
	-and color
*/
Flower::Flower():Plant(){
	m_numPetals = 6;
	m_isFlowering = false;
	m_color = "White";
}//end Flower

/*Flower()
	-constructor
	-sets num petals and color
*/
Flower::Flower(int numPetals, string color):Plant(){
	m_numPetals = numPetals;
	m_isFlowering = false;
	m_color = color;
}//end Flower

/*
	-sets isAlive to false
	-deletes petals
*/
void Flower::die(){
	cout << "The flower dies." << endl;
	SetIsAlive(false);
	m_numPetals = 0;
}//end die

/*tick()
	-one month passes
	-the flower may become diseased.
	-controls life of flower.
*/
void Flower::tick(){
	SetIsDiseased(false);
	//picks a number between 0 and 4 (20% chance);
	int randNum;
	randNum = (rand() % 5);
	//drops petals if it hasn't already and it is flowering
	if(m_isFlowering && m_numPetals > 0){	
		m_numPetals = 0;
		cout << "The flower drops its petals." << endl;
	}//call die if the petals already fell
	else if(m_isFlowering && m_numPetals==0 && GetIsAlive())
		die();
	//if the flower was already fully grown coming into the month then it begins flowering.
	if(GetSize() >= 3)
		m_isFlowering = true;
	//if 0 is picked the flower gets diseased otherwise it grows
	if(randNum==0)
		SetIsDiseased(true);
	else
		SetSize(GetSize()+1);
}
/*<< operator overloading
	- sets on how the 
	- shows how the operator should output.
*/
ostream& Flower::operator<<(ostream& os){
	string isDiseased;
	string isFlowering;
	string isAlive;

	//sets string for diseased or not
	if(GetIsDiseased())
		isDiseased = "Diseased";
	else
		isDiseased = "Not Diseased";
	//sets string for flowering
	if(m_isFlowering)
		isFlowering = "Flowering";
	else
		isFlowering = "Not Flowering";
	//sets where the flower is at in its life
	if(GetSize() <= 1)
		isAlive = "Seedling: Alive";
	else if(GetSize() == 2)
		isAlive = "Medium-sized: Alive";
	else if(GetSize() >= 3)
		isAlive = "Fully Mature: Alive";
	//sets output
	if(GetIsAlive())
		os << "Flower (" << isAlive << " : " << isFlowering << " : " << isDiseased << ")" << endl;
	else
		os << "Flower(dead)" << endl;
	return os;
}