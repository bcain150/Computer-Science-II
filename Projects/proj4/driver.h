#ifndef DRIVER_H
#define DRIVER_H
#include "Garden.h"

//Title: menu
//Pre: None
//Post: Displays the first menu (1. Plant Single Item to 4. Exit)
void menu();

//Title: manageMenu(Garden)
//Pre: Garden
//Post: Manages user input and calls corresponding function
void manageMenu(Garden& garden);

//Title: singleGarden(Garden)
//Pre: Garden - 1 for single plant, >1 for multiple plants
//Asks user what type of plant and quantity of plants
//Post: Calls addPlant and then simulateTime
void singleGarden(Garden& garden, int quantity = 1);

//Title: manyGarden(Garden)
//Pre: Garden
//Asks user how many of each plant to plant (Flower, Vegetable, Tree)
//Post: Calls addPlant and then simulateTime
void manyGarden(Garden& garden);

//Title: plantMenu
//Pre: None
//Post: Displays the menu of different types of plants (Flower, Vegetable, Tree)
void plantMenu();

//Title: simulateTime(Garden)
//Pre: Garden with plants and asks user how many months to simulate
//Post: Calls the garden.tick and passes it the number of months
void simulateTime(Garden& garden);

#endif
