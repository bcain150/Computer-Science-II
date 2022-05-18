/********************************************
** File:    proj1.cpp
** Project: CMSC 202 Project 1, Spring 2017
** Author:  Brendan Cain
** Date:    02-15-17
** Section: 16 (lecture) 18 (discussion)
** E-mail:  bcain1@umbc.edu
**
** This file is the main driver for a manhunt
** simulation. (Project number 1)
**********************************************/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAP_SIZE = 10;//side length of the square map (2D array)
const int NUM_COORDS = 4;//length of the array storing the coordinates of the players I & T

//INDEXES OF COORDINATES FOR INVESTIGATOR AND TARGET
const int IX = 0;
const int IY = 1;
const int TX = 2;
const int TY = 3;

//***NOTE: arrays are never returned because they are pointers
void fillMap(char fMap[][MAP_SIZE]);
int validMenu(int min, int max);
void loadMap(char lMap[][MAP_SIZE], int lCoords[]);
void inputFile(int iCoords[]);
void inputCoords(int inCoords[]);
void printMap(char pMap[][MAP_SIZE]);
void game(char gMap[][MAP_SIZE], int gCoords[]);
void hint(int hCoords[]);


int main(){
	//creates the size of the map and initializes the 2D array.
	char map[MAP_SIZE][MAP_SIZE];
	//creates an array to store coordinates
	int coords[NUM_COORDS];
	fillMap(map); //fills array with underscores

	//Welcomes User
	cout << "Welcome to Manhunt!" << endl;
	//Displays Start Menu
	cout << "What would you like to do?" << endl;
	cout << "1. Load a simulation from file" << endl;
	cout << "2. Start a new simulation" << endl;
	cout << "3. Exit" << endl;

	//validates input
	const int MIN_INT = 1;
	const int MAX_INT = 3;
	int choice = validMenu(MIN_INT, MAX_INT);

	//start menu choice
	switch(choice){
		case 1:
			//inputs coordinate from 
			inputFile(coords);
			loadMap(map, coords);
			game(map, coords);
			break;

		case 2:
			//inputs file manually
			inputCoords(coords);
			loadMap(map, coords);
			game(map, coords);
			break;

		case 3:
			//says goodbye
			cout << "Giving up so soon?" << endl;
			cout << "Good-bye" << endl;
			break;
	}//end switch
	return 0;
}//END main


/*fillMap:
	-takes in a 2D square array and uses the global size constant.
	-completely fills that array with underscores.
	-no return is necessary, arrays are pointers.
*/
void fillMap(char fMap[][MAP_SIZE]){

	for(int y=0; y<MAP_SIZE; y++){
		for(int x=0; x<MAP_SIZE; x++){
			fMap[y][x] = '_';
		}
	}//end fors
}//END fillMap


/*validMenu:
	-validates a menu choice based on the min and max
	constraint values provided
	-repromts user if invalid
	-returns valid choice
*/
int validMenu(int min, int max){
	int num;
	cout << "Enter " << min << " - " << max << ":" << endl;
	cin >> num;
	//repromts user
	while(num < min || num > max){
		cout << "The number you entered is invalid!" << endl;
		cout << "Please reenter " << min << " - " << max << ":" << endl;
		cin >> num;
	}
	return num;
}//END validMenu


/*loadMap:
	-inputs the map and the coordinates for I and T
	-Sets the characters noting the positions of I and T
*/
void loadMap(char lMap[][MAP_SIZE], int lCoords[]){	
	//Marks the starting point of player and computer
	lMap[lCoords[IY]][lCoords[IX]] = 'I'; // Investigator (user)
	lMap[lCoords[TY]][lCoords[TX]] = 'T'; // Target (computer)
}//END loadMap


/*inputFile:
	-takes in the coordinate array
	-prompts user for a file name
	-reads coordinates for I and T from file.
*/
void inputFile(int iCoords[]){
	//prompts user to enter a filename (no more than 9 characters)
	fstream mapStream;
	int const NUM_CHAR = 9;
	char input[NUM_CHAR];
	cout << "What is the name of the file?: " << endl;
	cin >> input;
	//assigns the coordinates to the coordinate array.
	mapStream.open(input);
	mapStream >> iCoords[IX];
	mapStream >> iCoords[IY];
	mapStream >> iCoords[TX];
	mapStream >> iCoords[TY];
	cout << "Map Loaded" << endl;
	mapStream.close();
}


/* inputCoords:
	-takes in the coordinate array and inputs
	the x and y coordinates for I and T manual.
*/
void inputCoords(int inCoords[]){
	//prompts user for each coordinate and validates them.
	//stores in coordinate array
	cout << "What is the X coordinate of the investigator?:" << endl;
	inCoords[IX] = validMenu(0, MAP_SIZE-1);
	cout << "What is the Y coordinate of the investigator?:" << endl;
	inCoords[IY] = validMenu(0, MAP_SIZE-1);
	cout << "What is the X coordinate of the target?:" << endl;
	inCoords[TX] = validMenu(0, MAP_SIZE-1);
	cout << "What is the Y coordinate of the target?:" << endl;
	inCoords[TY] = validMenu(0, MAP_SIZE-1);
}//END inputCoords


/*printMap:
	-takes in the current map and its size and then prints it
*/
void printMap(char pMap[][MAP_SIZE]){
	//the y axis must be printed in reverse because
	//the highest y value should be on top.
	for(int y=MAP_SIZE-1; y>-1; y--){
		for(int x=0; x<MAP_SIZE; x++){
			//prints space as long as it isn't the target space
			if(pMap[y][x] != 'T')
				cout << pMap[y][x] << " ";
			else
				cout << "_ "; //prints an underscore to hide target
		}
		cout << endl;
	}//end fors
}//END printMap


/*game:
	-Displays the main menu and implements the main game loop
	-inputs the map and the I&T coordinates
	-implements movement of the investigator

*/
void game(char gMap[][MAP_SIZE], int gCoords[]){
	int choice;
	const int MIN_INT = 1;
	const int MAX_INT = 6;

	do{
		//prints map and then the menu
		cout << endl;
		printMap(gMap);
		cout << "What would you like to do?" << endl;
		cout << "1. Search North" << endl;
		cout << "2. Search East" << endl;
		cout << "3. Search South" << endl;
		cout << "4. Search West" << endl;
		cout << "5. See Map" << endl;
		cout << "6. Exit" << endl;
		choice = validMenu(MIN_INT, MAX_INT);

		switch(choice){
			case 1://Move NORTH
				//sets the path marker on the map.
				gMap[gCoords[IY]][gCoords[IX]] = '*';
				//checks to see if movement is off the map
				//or if they found the target
				if(gCoords[IY]+1 > MAP_SIZE-1)
					cout << "You can't go that far North!" << endl;
				else if(gMap[gCoords[IY]+1][gCoords[IX]] == 'T'){
					cout << "You found the Target!" << endl;
					choice = MAX_INT;
				}//end else if
				else{
					gCoords[IY]++; //adds to the Y coordinate of investigator
					hint(gCoords);
				}//end if else statements
				gMap[gCoords[IY]][gCoords[IX]] = 'I';
				//sets the I placement on the map
				break;

			case 2://Move EAST
				//sets the path marker on the map.
				gMap[gCoords[IY]][gCoords[IX]] = '*';
				//checks to see if movement is off the map
				//or if they found the target
				if(gCoords[IX]+1 > MAP_SIZE-1)
					cout << "You can't go that far East!" << endl;
				else if(gMap[gCoords[IY]][gCoords[IX]+1] == 'T'){
					cout << "You found the Target!" << endl;
					choice = MAX_INT;
				}//end else if
				else{
					gCoords[IX]++; //adds to the Y coordinate of investigator
					hint(gCoords);
				}//end if else statements
				gMap[gCoords[IY]][gCoords[IX]] = 'I';
				//sets the I placement on the map
				break;

			case 3://Move SOUTH
				//sets the path marker on the map.
				gMap[gCoords[IY]][gCoords[IX]] = '*';
				//checks to see if movement is off the map
				//or if they found the target
				if(gCoords[IY]-1 < 0)
					cout << "You can't go that far South!" << endl;
				else if(gMap[gCoords[IY]-1][gCoords[IX]] == 'T'){
					cout << "You found the Target!" << endl;
					choice = MAX_INT;
				}//end else if
				else{
					gCoords[IY]--; //adds to the Y coordinate of investigator
					hint(gCoords);
				}//end if else statements
				gMap[gCoords[IY]][gCoords[IX]] = 'I';
				//sets the I placement on the map
				break;

			case 4://Move WEST
				//sets the path marker on the map.
				gMap[gCoords[IY]][gCoords[IX]] = '*';
				//checks to see if movement is off the map
				//or if they found the target
				if(gCoords[IX]-1 < 0)
					cout << "You can't go that far West!" << endl;
				else if(gMap[gCoords[IY]][gCoords[IX]-1] == 'T'){
					cout << "You found the Target!" << endl;
					choice = MAX_INT;
				}//end else if
				else{
					gCoords[IX]--; //adds to the Y coordinate of investigator
					hint(gCoords);
				}//end if else statements
				gMap[gCoords[IY]][gCoords[IX]] = 'I';
				//sets the I placement on the map
				break;

			case 5:
				printMap(gMap);
				break;

			case 6:
				cout << "Giving up so soon?" << endl;
				cout << "Good-bye" << endl;
				break;
		}//end switch
	}while(choice != MAX_INT);

}//END game


/*hint:
	-inputs the coords of the investigator & target
	-prints a hint to the investigator on where to search.
*/
void hint(int hCoords[]){
	if(hCoords[IX] < hCoords[TX])
		cout << "Try searching East." << endl;
	else if(hCoords[IX] > hCoords[TX])
		cout << "Try searching West." << endl;
	else if(hCoords[IY] < hCoords[TY])
		cout << "Try searching North." << endl;
	else
		cout << "Try searching South." << endl;
}//END hint
