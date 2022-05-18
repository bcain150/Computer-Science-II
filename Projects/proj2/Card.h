/*
 *Title: Exploding Kittens Card Game
 *Date: 2/22/2017
 *Author: Nick Lawrence and Jeremy Dixon
 *Description: This is the card class for the exploding kittens game
*/

#ifndef CARD_H //Include guard to protect against double declarations
#define CARD_H //Includ guard

#include <string>

using namespace std;

class Card {
public:
	// Default Constructor
        // Unused
	Card();

	// Name - Constructor
	// Preconditions - valid int type for type of card, string name
	// Postcontions - A card object with the given input values
	Card(int, string);

	// Name -  GetType() - Returns the type of card
	// Preconditions - an initialized card
	// Postconditions - integer representing the type of card
	// (see reference chart below)
	int GetType();

	// Name - ToString() - Returns a string representation of the card
	// Preconditions - An intitalized card
	// Postcontitions - Returns a string containing the representation of the card
	string ToString();

private:
	// 0 Bomb
	// 1 Defuse
	// 2 Attack
	// 3 Skip
	// 4 Peek
	// 5 Shuffle
	// 6,7,8,9 Normal Cards
	int m_type; //Defined by the types of cards above
	string m_desc; //Description comes from deck.txt file or bomb.txt file
};

#endif // CARD_H
