/*
 *Title: Exploding Kittens Card Game
 *Date: 2/22/2017
 *Author: Nick Lawrence and Jeremy Dixon
 *Description: This is the game class for the exploding kittens game
*/

#ifndef GAME_H
#define GAME_H

#include "Player.h"
#include <string>
#include <sstream>
#include <fstream>
#include <cstdlib>

// Game Constants

// Number of cards a See into the Future card can show
const unsigned int PEEK_NUM = 3;
// The number of intial cards
const int INIT_CARDS = 4;
// Name of the main deck file
const string DECK_NAME = "deck.txt";
// Name of the main bomb deck file
const string BOMB_NAME = "bomb.txt";
// Seed for the pseudo random number generator
const int RAND_SEED = 10;


class Game {
public:
	// Name - Constructor
	// Desc - Runs the game
	// Preconditions - a valid constant that holds the name of the deck file and bomb file
	// Postconditions - Runs the game
	Game();

	//Name - SetNumPlayers
	//Desc - Sets the number of players that are playing the game
	//Preconditions - a valid game has been constructed
	//Postconditions - the number of players has been set.
	void SetNumPlayers();
private:
	// Name - Shuffle()
	// Desc - Shuffles the cards that are currently in the deck
	// Preconditions - A deck with at least 1 card
	// Postconditions - A deck with the elements shuffled in a different order
	void Shuffle();

	// Name - Peek()
	// Desc - The Action for the See into the future card
	// Preconditions - A deck with at least 1 card
	// Postconditions - Will print the next [insert const num] card(s) in the deck
	void Peek();

	// Name - DrawCard()
	// Desc - Get the card on the top of the deck and give it to a player
	// Preconditions - At least 1 card in the deck
	// Postconditions - Returns and deletes the top card on the deck
	Card DrawCard();

	// Name - HandleCard()
	// Desc - Handles the last card placed by the currentPlayer
	// Preconditions - An integer number representing the currentPlayer,
	//                 a card placed on the discard pile
	// Postconditions - Handles the card according to their descriptions
	int HandleCard(int);

	// Name - PlayGame()
	// Desc - Runs the game
	// Preconditions - A loaded deck, all players having cards
	// Postconditions - Determine winner and print to console
	void PlayGame();

	// Name - LoadDeck()
	// Desc - Loads the cards in from a text file
	// Preconditions - A valid filepath
	// Postcondition - m_deck contains cards
	int LoadDeck(string);

	// Name - AddBombCards()
	// Desc - Loads the bomb cards in from a text file,
	//        this must be separate due to the nature of the game
	// Preconditions - A valid filepath, the file must contain 1 less bomb
	//                 than the number of players
	// Postconditions - Adds the bomb cards to m_deck
	int AddBombCards(string);

	int m_numPlayers;
	Player m_players[4];
	vector<Card> m_deck; //Vector holding available cards
	vector<Card> m_discard; //Vector holding cards already used
};

#endif /* GAME_H */
