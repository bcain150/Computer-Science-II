//Title: driver.cpp
//Project: The Garden (proj4) CMSC 202 Spring 2017
//Author: Brendan Cain test
//Date: 4/26/17
//Email: bcain1@umbc.edu
//Discussion: 16 (lecture) 18 (discussion)
//Description: the driver file for proj4

#include "driver.h"

/*menu
    -displays first menu
*/
void menu(){
    //print out main menu
    cout << "Welcome to the Garden" << endl;
    cout << "1. Plant Single Item\n2. Plant Many of the Same Item\n3. Plant A Full Garden\n4. Exit" << endl;
}//end menu

/*mangaeGarden()
    -calls proper function for menu choice
*/
void manageGarden(Garden& garden){
    //validates choice
    int choice;
    cout << "Enter 1-4:" << endl;
    cin >> choice;
    while(choice<1 || choice>4){
        cout << "That was not a choice please enter 1-4: " << endl;
        cin >> choice;
    }
    //switch statement handles what to do
    switch(choice){
        case 1://Plant single
        case 2: //plant many of same
            singleGarden(garden, choice);
            break;
        case 3:
            manyGarden(garden);
            break;
        default:
            break;  
    }//end swtich
}//end manageGarden()

/*singleGarden
    -plants a garden of only one plant.
    -may plant one or many
*/
void singleGarden(Garden& garden, int quantity){
    //outputs plant menu and validates choice
    cout << "What would you like to plant?" << endl;
    plantMenu();
    int plant;
    cout << "Enter 1-3:" << endl;
    cin >> plant;
    //validate
    while(plant<1 or plant>3){
        cout << "That was not a choice please enter 1-3: " << endl;
        cin >> plant;
    }//end while

    //gets how many the user would like to plant.
    if(quantity != 1){
        cout << "How many would you like to plant?" << endl;
        cin >> quantity;
    }
    //adds to garden and simulates time
    garden.addPlant(plant, quantity);
    simulateTime(garden);
}//end singleGarden

/*manyGarden
    -plants a full garden
    -asks the user how much of each plant
*/
void manyGarden(Garden& garden){
    //while loops validate.
    int q;
    //adds flowers
    cout << "How many Flowers would you like to plant?" << endl;
    cin >> q;
    while(q<1){
        cout << "Please enter a number greater than 0: " << endl;
        cin >> q;
    }//end while
    garden.addPlant(1, q);

    //adds vegetables
    cout << "How many Vegetables would you like to plant?" << endl;
    cin >> q;
    while(q<1){
        cout << "Please enter a number greater than 0: " << endl;
        cin >> q;
    }//end while
    garden.addPlant(2, q);

    //adds trees
    cout << "How many Trees would you like to plant?" << endl;
    cin >> q;
    while(q<1){
        cout << "Please enter a number greater than 0: " << endl;
        cin >> q;
    }//end while
    garden.addPlant(3, q);

    //simulates time
    simulateTime(garden);
}//end manyGarden

/*plantMenu()
    -displays plants;
*/
void plantMenu(){
    cout << "1. Flower\n2. Vegetable\n3. Tree" << endl;
}//end plantMenu

/*simulateTime()
    -takes in how many months
    -calls tick
*/
void simulateTime(Garden& garden){
    //gets month amount
    int months;
    cout << "How many months would you like to simulate?:" << endl;
    cin >> months;
    //validate
    while(months<1){
        cout << "Please enter a number greater than 0: " << endl;
        cin >> months;
    }//end while
    garden.tick(months);
}//end simulateTime()

//////////////////////MAIN///////////////////////////

int main(){
    //calls main menu and creates new garden
    srand(time(NULL));
    Garden g = Garden();
    menu();
    manageGarden(g);

    return 0;
}//end main