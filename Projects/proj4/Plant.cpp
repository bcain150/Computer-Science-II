//Title: Plant.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 4/20/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the plant class

#include "Plant.h"

/*Plant():
	-Constructor
	-sets up a plant object
*/
Plant::Plant(){
	m_isAlive = true;
	m_isDiseased = false;
	m_size = 0;
}//end Plant

/*~Plant():
	-Destructor
	-Destroys a plant object
*/
Plant::~Plant(){
	m_isAlive = NULL;
	m_isDiseased = NULL;
	m_size = NULL;
}//end ~Plant

//HELPER METHODS: Getters & Setters.\\
--------------------------------------

/*GetIsDiseased:
	-getter
	-returns whether the plant is diseased
*/
bool Plant::GetIsDiseased(){
	return m_isDiseased;
}//end GetIsDiseased

/*GetIsAlive:
	-getter
	-returns whether the plant is alive
*/
bool Plant::GetIsAlive(){
	return m_isAlive;
}//end GetIsAlive

/*GetSize:
	-getter
	-returns the plant's size
*/
int Plant::GetSize(){
	return m_size;
}//end GetSize

/*SetSize:
	-setter
	-sets size
*/
void Plant::SetSize(int size){
	m_size = size;
}//end SetSize

/*SetIsAlive:
	-setter
	-sets whether the plant is alive
*/
void Plant::SetIsAlive(bool isAlive){
	m_isAlive = isAlive;
}//end SetIsAlive

/*SetIsDiseased:
	-setter
	-sets whether the plant is diseased
*/
void Plant::SetIsDiseased(bool isDiseased){
	m_isDiseased = isDiseased;
}//end SetIsDiseased