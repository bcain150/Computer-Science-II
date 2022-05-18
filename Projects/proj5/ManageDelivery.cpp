//Title: ManageDelivery.cpp
//Project: The Grocer (proj5) CMSC 202 Spring 2017
//Author: Brendan Cain
//Date: 5/11/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: implements ManageDelivery Class

#include "ManageDelivery.h"

/*Constructor
*/
ManageDelivery::ManageDelivery(vector< Truck <Item, MAX_CAPACITY> > truck, vector< Delivery > delivery, vector< Item > item){
    m_truck = truck;
    m_delivery = delivery;
    m_item = item;
    StartDelivery();
}//end constructor

/*StartDelivery
    -loads trucks with deliveries and items
    -calls 
*/
void ManageDelivery::StartDelivery(){
    //displays the current loaded file.
    cout << "Trucks Loaded: " << m_truck.size() << endl;
    cout << "Deliveries Loaded: " << m_delivery.size() << endl;
    cout << "Items Loaded: " << m_item.size() << endl;
    cout << "Start Time: 0\n" << endl;
    
    int numDelivery;//keeps track of number of deliveries in the truck.
    //loops through every truck
    for(int i=0; i<m_truck.size(); i++){
        numDelivery = 0;//number of deliveries in a truck
        //sets name capacity and prints that its loading
        string name = m_truck.at(i).GetName();
        int truckCap = m_truck.at(i).GetCapacity();
        string loading = "\n*****Loading Truck (" + name + ")*****";
        cout << loading << endl;

        //while the next delivery can still fit in the truck
        //and there is still a next delivery
        while(numDelivery < m_delivery.size() && truckCap-m_delivery.at(numDelivery).GetNumItem() > 0){
            int numItems = m_delivery.at(numDelivery).GetNumItem();//numItems in this delivery
            //adds the delivery to the truck and updates the truckCap
            m_truck.at(i).AddDelivery(m_delivery.at(numDelivery));
            truckCap -= numItems;
            //adds items to the truck and updates m_item
            for(int j=0; j<numItems; j++){
                m_truck.at(i).AddItem(m_item.at(j));
                cout << m_item.at(j).GetName() << " loaded into " << name << endl;
            }//end for
            //updates Delivery index
            //deletes m_items that were just Loaded
            //if statement is neccessary so that an index that is out of bounds is not called

            if(m_item.size() == numItems){
                m_item.clear();
            }
            else{
                m_item.erase(m_item.begin(), m_item.begin()+numItems);
            }
            numDelivery++;
        }//end while

        //updates the delivery vector
        if(m_delivery.size() == numDelivery){
            m_delivery.clear();
        }
        else{
            m_delivery.erase(m_delivery.begin(), m_delivery.begin()+numDelivery);
        }
        //delivers item
        DeliverItem(i);

        //if there are deliveries left, reset the truck index.
        if(m_delivery.size() > 0 && i == m_truck.size()-1)
            i=-1;
        //if there are no       
        else if(m_delivery.size() == 0 && i != m_truck.size()-1)
            i = m_truck.size()-1;
    }//end for
    DisplayItemLeft();
}//end StartDelivery

/*DeliverItem
    -prints out the delivery status
    -updates the time
    -delivers item (dequeues)
*/
void ManageDelivery::DeliverItem(int j){
    //change time to 10 because it takes 10 mins to load trucks
    vector<Delivery> curDelivery = m_truck.at(j).GetDelivery();
    int curTime = 10;
    m_truck.at(j).SetTime(curTime);
    string name = m_truck.at(j).GetName();
    //for loop to loop through items
    cout << "\n**Truck Name: " << name << "**" << endl;
    for(int k=0; k<curDelivery.size(); k++){
        //prints out delivery
        cout << "***********Delivery " << k+1 << "*************" << endl;
        //updates time for truck
        int min = curDelivery.at(k).GetRTMinute();
        curTime += min;
        m_truck.at(j).SetTime(curTime);
        //outputs time, name and number of items.
        cout << "Delivery Time: " << m_truck.at(j).GetTime() << endl;
        cout << "Delivery for: " << curDelivery.at(k).GetName() << endl;
        int numItemsInTruck = curDelivery.at(k).GetNumItem();
        cout << "Delivered: " << numItemsInTruck << endl;
        for(int i=0; i<numItemsInTruck; i++)
            m_truck.at(j).DeliverItemFromTruck();
    }//end for
    m_truck.at(j).CompleteDelivery();
}//end DeliveryItem

/*DisplayItemLeft
    -displays the rest of the items in the m_item vector
*/
void ManageDelivery::DisplayItemLeft(){
    cout << "\n*****Items Left After Deliveries*****" << endl;
    //iterates through a for loop to display items in m_item vector
    for(int i=0; i<m_item.size(); i++){
        string it = m_item.at(i).GetName();
        float w = m_item.at(i).GetWeight();
        cout << "Item " << i+1 << " - Name: " << it << " - Weight: " << w << endl;
    }//endl;
}//end DisplayItemLeft