//Title: Tree.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 4/26/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: Implements the Tree class

#include "Tree.h"
/*Tree()
    -constructor
    -does nothing but call plant 
*/
Tree::Tree():Plant(){}//end constructor

/*~Tree()
    -Destructor
    -Destroys every dynamically allocated Fruit in m_fruit
*/
Tree::~Tree(){
    int l = m_fruit.size();
    //goese through vector and deletes all dynamically allocated Fruit
    for(int i=0; i<l; i++){
        delete m_fruit.at(i);
        m_fruit.at(i) = NULL;
    }//end for
}//end ~Plant()

/*die()
    -if tree is greater than 120 size
*/
void Tree::die(){
    SetIsAlive(false);
    cout << "The tree has died."<< endl;
}//end die

/*ClearFruit()
    -empties fruit from vector
    -no more fruit in tree.
*/
void Tree::ClearFruit(){
    m_fruit.clear();
}//end ClearFruit

/*tick()
    -adds fruit
    -calls die
    -changes size
    -20% chance of Diseased
*/
void Tree::tick(){
    //resets m_isDiseased
    SetIsDiseased(false);
	//picks a number between 0 and 4 (20% chance);
	int randNum;
	randNum = (rand() % 5);
    //if 0 is picked the tree gets diseased otherwise it grows
	if(randNum==0)
		SetIsDiseased(true);
	else
		SetSize(GetSize()+1);
    //if its not diseased and greater than size 36 then add Fruit
    if(GetSize()>36 && !GetIsDiseased()){
        Fruit *fr = new Fruit();
        m_fruit.push_back(fr);
    }
    //calls die after its size 120
    if(GetSize()>120 && GetIsAlive())
        die();
}//end tick

/* Overloaded << operator
    -outputs what happens each month
*/
ostream& Tree::operator<<(ostream& os){
    string maturity;
    string isFruiting;
    string isDiseased;
    string isAlive;
    //diseased
    if(GetIsDiseased())
        isDiseased = " Diseased)";
    else
        isDiseased = " Not Diseased)";
    //fruiting
    if(!GetIsDiseased() && GetSize()>36)
        isFruiting = " Fruiting :";
    else
        isFruiting = " Not Fruiting :";
    //tree alive?
    if(GetIsAlive())
        isAlive = " Alive :";
    else{
        isAlive = " Dead :";
        isFruiting = " Fruiting :";
        isDiseased = " Not Diseased)";
    }//end else
    
    //Set tree maturity
    if(GetSize() <= 12)
        maturity = "(Seedling:";
    else if(GetSize() <= 24)
        maturity = "(Sapling:";
    else if(GetSize() <= 36)
        maturity = "(Pole:";
    else
        maturity = "(Mature:";

    //puts together the output and returns
    os << "Tree " << maturity << isAlive << isFruiting << isDiseased << endl;
    return os;
}// end overloaded operator