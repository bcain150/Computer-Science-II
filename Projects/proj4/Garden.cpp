//Title: Garden.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 4/26/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the Garden Class

#include "Garden.h"

/*Garden()
    -constructor
    -initializes month and gardenSize
*/
Garden::Garden(){
    m_month = 0;
    m_gardenSize = 0;
}//end Garden

/*~Garden()
    -destructor
    -handles dynamically allocated plants
*/
Garden::~Garden(){
    //goes through garden vector and deletes each dynamically allocated plant
    for(int i=0; i<m_gardenSize; i++){
        delete m_garden.at(i);
        m_garden.at(i) = NULL;
    }//end for
}//end ~Garden

/*addPlant()
    -dynamically allocates a plant of a specific type
    -1=vegetable, 2=flower, 3=tree
    -quatity can be controlled as well
*/
void Garden::addPlant(int type, int quantity){
    //switch case determines which type to allocate
    //for loops determines how many to make
    //declare plant pointer
    Plant *ptr;
    switch(type){
        case 1: //Flower
            for(int i=0; i<quantity; i++){
                ptr = new Flower();
                m_garden.push_back(ptr);
            }//end for
            break;
        case 2: //Vegetable
            for(int i=0; i<quantity; i++){
                ptr = new Vegetable();
                m_garden.push_back(ptr);
            }//end for
            break;
        case 3: //Tree
            for(int i=0; i<quantity; i++){
                ptr = new Tree();
                m_garden.push_back(ptr);
            }//end for
            break;           
    }//end switch
    //resets the value of m_gardenSize
    m_gardenSize = m_garden.size();
}//end addPlant

/*tick(int)
    -ticks the number of months passed
    -calls tick() that ticks only once
*/
void Garden::tick(int num){
    for(int i=0;i<num;i++)
        tick();
}//end tick(int)

/*tick(1)
    -ticks every plant in the garden one month
*/
void Garden::tick(){
    cout << "MONTH: " << m_month + 1 << endl;
    for(int i=0; i<m_gardenSize; i++){
        m_garden.at(i) -> tick();
        cout << i+1 << ": ";
        *m_garden.at(i) << cout;
    }//end for
    m_month++;
}//end tick(1)

/*getSize()
    -returns how many plants are in the garden
*/
int Garden::getSize(){
    return m_gardenSize;
}//end getSize()

/*getMonths()
    -returns number of months passed.
*/
int Garden::getMonths(){
    return m_month;
}//end getMonths