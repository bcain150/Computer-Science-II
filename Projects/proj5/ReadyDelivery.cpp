//Title: ReadyDelivery.cpp
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 5/11/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements ReadyDelivery Class

#include "ReadyDelivery.h"

/*Constructor
    -sets the member variable strings
    -calls load functions
*/
ReadyDelivery::ReadyDelivery(){}
ReadyDelivery::ReadyDelivery(string truckFile, string deliveryFile, string itemFile){
    m_truckFile = truckFile;
    m_deliveryFile = deliveryFile;
    m_itemFile = itemFile;
    LoadItem();
    LoadDelivery();
    LoadTruck();
}//end constructor

/*LoadTruck
    -reads in the truck file
    -loads to the truck vector.
*/
void ReadyDelivery::LoadTruck(){
    //initialize variables
    fstream readTruck;
    int truckSize;
    string truckName;
    readTruck.open(m_truckFile.c_str());
    //while stuff can still be read in...
    //read in truck info and put it into an object then push it into vector
    while(readTruck >> truckName >> truckSize){
        Truck<Item, MAX_CAPACITY> t1(truckName, truckSize);
        m_truck.push_back(t1);
    }//end while
    readTruck.close();
}//end LoadTruck

/*LoadDelivery
    -reads in the delivery file
    -loads to the delivery vector.
*/
void ReadyDelivery::LoadDelivery(){
    //initialize variables
    fstream readDeliver;
    int numItems;
    int time;
    string deliveryName;
    readDeliver.open(m_deliveryFile.c_str());
    //while there is still something to read in...
    //read in info and push it into the vector
    while(readDeliver >> deliveryName >> numItems >> time){
        Delivery d1(deliveryName, numItems, time);
        m_delivery.push_back(d1);
    }//end while
    readDeliver.close();
}//end LoadDelivery

/*LoadItem
    -reads in the Item file
    -loads to the Item vector.
*/
void ReadyDelivery::LoadItem(){
    fstream readItem;
    float weight;
    string name;
    readItem.open(m_itemFile.c_str());
    //while the file can continue to read in...
    //push an item back in the m_item vector
    while(readItem >> name >> weight){
        Item i1(name, weight);
        m_item.push_back(i1);
    }//end while
    readItem.close();
}//end LoadDelivery

/*GetTruck
    -returns Truck Vector
*/
 vector< Truck<Item, MAX_CAPACITY> >& ReadyDelivery::GetTruck(){
     return m_truck;
 }//end GetTruck

 /*GetDelivery
    -returns Delivery Vector
 */
 vector<Delivery> ReadyDelivery::GetDelivery(){
     return m_delivery;
 }//end GetDelivery

  /*GetItem
    -returns Item Vector
 */
 vector<Item> ReadyDelivery::GetItem(){
     return m_item;
 }//end GetItem