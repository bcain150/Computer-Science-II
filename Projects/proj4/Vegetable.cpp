//Title: Vegetable.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 4/20/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the plant class

#include "Vegetable.h"

/*Vegetable():
	-default Constructor
	-calls plant constructor
*/
Vegetable::Vegetable():Plant(){}//end Vegetable

/*Vegetable():
	-custom Constructor
	-calls plant constructor
	-sets vegetable color
*/
Vegetable::Vegetable(string color):Plant(){
	m_color = color;
}//end Vegetable

/*die()
	-m_isAlive = false
	-calls plant setter
*/
void Vegetable::die(){
	SetIsAlive(false);
}//end die

/*die()
	-vegetable is harvested only if its ready
	-harvested only if it isnt already dead
	-calls die()
*/
void Vegetable::harvest(){
	//Only harvests the vegetable if its ready and isn't already dead.
	if(GetSize() >= 5 && GetIsAlive()){
		cout << "The vegetable has been harvested." << endl;
		die();
	}
}//end harvest

/*tick()
	-controls the tick for vegetable(one month)
	-decides what happens during a single month
	-20% chance the vegatble is diseased.
*/
void Vegetable::tick(){
	//vegetable gets reset
	SetIsDiseased(false);
	harvest();
	//picks a number between 0 and 4 (20% chance);
	int randNum;
	randNum = (rand() % 5);
	//if 0 is picked the vegetable gets diseased otherwise it grows
	if(randNum==0)
		SetIsDiseased(true);
	else
		SetSize(GetSize()+1);	
}//end tick()

/*<< operator overloading
	- sets strings depending on whether the vegetable is diseased or not.
	- alive
	- and harvestable
	- shows how the operator should output.
*/
ostream& Vegetable::operator<<(ostream& os){
	string isDiseased;
	string isHarvestable;
	//sets strings for output
	if(GetIsDiseased())
		isDiseased = "Diseased";
	else
		isDiseased = "Not Diseased";
	if(GetSize() < 5)
		isHarvestable = "Not Harvestable";
	else
		isHarvestable = "Harvestable";
	//different formats depending on whether it is alive or not.
	if(GetIsAlive())
		os << "Vegetable (Alive : " << isHarvestable << " : " << isDiseased << ")"  << endl;
	else
		os << "Vegetable: Harvested" << endl;
	return os;
}// end operator << overload