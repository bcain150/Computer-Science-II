/********************************************
** File:    Game.cpp
** Project: CMSC 202 Project 2, Spring 2017
** Author:  Brendan Cain
** Date:    03-06-17
** Section: 16 (lecture) 18 (discussion)
** E-mail:  bcain1@umbc.edu
**
** This file defines the class Game
**********************************************/

#include "Game.h"
#include "Player.h"

/*Constructor:
	-runs game
*/
Game::Game(){
	//Welcomes User
	string meow = "MEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOWMEOW";
	cout << meow << endl;
	cout << "Welcome to Exploding Kittens" << endl;
	cout << "A Game By Elan Lee, Shane Small, and Mathew Inman" << endl;
	cout << meow << endl;
	cout << endl;

	//initializes possible players 
	m_players[0] = Player("Player 1");
	m_players[1] = Player("Player 2");
	m_players[2] = Player("Player 3");
	m_players[3] = Player("Player 4");

	SetNumPlayers();
	LoadDeck(DECK_NAME);
	cout << "Shuffling the cards" << endl;
	Shuffle();
	cout << "Dealing" << endl;
	//deals four cards to each player
	for(int i=0; i<INIT_CARDS; i++){
		for(int j=0; j<m_numPlayers; j++){
			m_players[j].AddToHand(DrawCard());
		}
	}//end fors
	//Loads the deck, shuffles, and deals to players
	
	
	//adds bomb cards, prints the number of cards left to user, 
	//and reshuffles.
	AddBombCards(BOMB_NAME);
	cout << "Number of cards remaining: " << m_deck.size() << endl;
	//Starts game
	PlayGame();
}//end Game

/*SetNumPlayers:
	-validates user input of the number of players
	-sets it to m_numPlayers
*/
void Game::SetNumPlayers(){
	//validates number of players entry and sets it to member variable
	cout << "How many players would you like?" << endl;
	int num;
	do{
		cout << "Choose 2 - 4 players: " << endl;
		cin >> num;
	}while(num < 2 || num > 4);
	m_numPlayers = num;
}//end SetNumPlayers

/*Shuffle:
	-uses a random number generator to shuffle the current deck
	-shuffles 8 times for every time called.
*/
void Game::Shuffle(){
	const int NUM = 8;
	//Number of times shuffled^
	//initalizes tempIndex, and a random num generator.
	srand(RAND_SEED);
	int tempIndex;
	int size = m_deck.size();
	//shuffles deck NUM amount of times.
	for(int i=0; i<NUM; i++){
		//goes through the deck and switches random cards
		for(int j=0; j<size; j++){
			tempIndex = rand() % size;
			Card temp = m_deck.at(i);
			m_deck.at(i) = m_deck.at(tempIndex);
			m_deck.at(tempIndex) = temp;

		}// this ends the for loop for one shuffle
	}//end shuffle NUM more times.
}//end shuffle

/*Peek:
	-action for see into the future card
	-prints the first three cards in the deck to the user.
*/
void Game::Peek(){
	//initializes a "peeker player" to utilize DisplayHand
	cout << "Here are the top 3 cards: " << endl;
	for(int i=0; i<PEEK_NUM; i++){
		cout << i+1 << ". "; //numbering
		//prints type of card as a string
		switch(m_deck.at(i).GetType()){
			case 0:
				cout << "Exploding Kitten: ";
				break;
			case 1:
				cout << "Defuse: ";
				break;
			case 2:
				cout << "Attack: ";
				break;
			case 3:
				cout << "Skip: ";
				break;
			case 4:
				cout << "See into the Future: ";
				break;
			case 5:
				cout << "Shuffle: ";
				break;
			default:
				break;
		}//end switch
		//print the name of the card.
		cout << m_deck.at(i).ToString() << endl;
	}//end for
}//end Peek

/*DrawCard()
	-gets a card from the top of the deck
	-gives it to player throught the return statement
	-deletes that card from the deck through moving everything up
	one and then resizing the vector
*/
Card Game::DrawCard(){
	//saves the card at the top of the deck as the card drawn
	Card cardDrawn = m_deck.at(0);
	m_deck.erase(m_deck.begin());
	return cardDrawn;
}//end DrawCard

/*HandleCard:
	-uses the type of card placed by the current player to determine
	what actions to take.
	-takes in the current players number.
	-returns an int??
*/
int Game::HandleCard(int player){
	//gets the card played from the discard pile and its type
	Card played = m_discard.at(m_discard.size()-1);
	int type = played.GetType();
	//decides what card to handle
	switch(type){
		case 1: //Defuse
			if(m_players[player].HasLost()){
				//adds the bomb back to the deck and resets lost var.
				m_deck.push_back(m_players[player].ReturnBomb());
				m_players[player].SetLost(false);
			}//end if
			else{//gives the player back their defuse card
				cout << "There is no kitten to defuse!" << endl;
				m_players[player].AddToHand(played);
				m_discard.resize(m_discard.size()-1);
			}//end else
			break;
		case 2: //Attack
			//counteracts if they had to take an extra turn.
			m_players[player].SetExtraTurn(false);
			//sets the next player's extra turn to true.
			if(player==m_numPlayers-1)
				m_players[0].SetExtraTurn(true); //aka the first player
			else
				m_players[player+1].SetExtraTurn(true);
			//end if else
			break;
		case 3: //Skip
			m_players[player].SetExtraTurn(false);
			break;
		case 4: //Peek
			Peek();
			break;
		case 5: //Shuffle
			Shuffle();
			break;
		default: //Normal Pairs
			//checks too see if the player played a correct pair
			// if the last card played is the same type as 2nd to last card that was played
			if(m_discard.size()>1 && type == m_discard.at(m_discard.size()-2).GetType()){
				cout << "You played a pair! You can now steal a card from another player!" << endl;
				cout << "Select a Player" << endl;

				//prints out the list of players available
				for(int i=0; i<m_numPlayers; i++){
					//print as long as the player isnt the one who played and the players being printed have cards and haved lost yet.
					if(i!=player && !(m_players[i].HasLost()) && m_players[i].HasCards() )
						cout << i << ". " << m_players[i].GetName() << endl;
				}//end for
				//validates pick
				int pick;
				cin >> pick;
				while(pick<0 || pick>m_numPlayers-1 || pick==player || m_players[pick].HasLost() || !(m_players[pick].HasCards()) ){
					cout << "That choice was invalid. Choose from the list above." << endl;
					cin >> pick;
				}//end while;
				//displays the number of cards in the players hand.
				int numCards = m_players[pick].GetNumberOfCards();
				for(int i=0; i<numCards; i++){
					cout << "Card " << i << endl;
				}//end for
				//inputs the players card to steal and validates it
				int cardNum;
				cout << "Select a card: " << endl;
				cin >> cardNum;
				while(cardNum<0 || cardNum>numCards-1){
					cout << "That card is unavailable. Pick again: " << endl;
					cin >> cardNum;
				}
				//Now that both the player and the card have been validated, the card can be stolen.
				m_players[player].AddToHand(m_players[pick].LoseCard(cardNum));
			}//end if
			//if the normal Card Played isnt a pair... nothing happens.
			break;
	}//end swtich
	return type;
}//end HandleCard

/*PlayGame:
	-Runs the game and the turn taking.
	-prints out the winner
*/
void Game::PlayGame(){
	//variable that controls whether someone has won or not
	bool turn_end;//knows when a players turn is over
	int c;
	int play;
	int win_count; //makes sure there is only 1 winner
	int winner; // the winning player's index
	do{
		//for loop controls turns
		for(int x=0; x<m_numPlayers; x++){
			//as long as the player has not lost
			turn_end = false;
			while(!m_players[x].HasLost() && !turn_end){
				//print menu
				cout << endl;
				cout << "It is " << m_players[x].GetName() << "'s turn." << endl;
				cout << "What would you like to do: " << endl;
				cout << "1. View Cards\n2. Play A Card\n3. Draw A Card" << endl;
				//validates that the choice is between 1-3 inclusive.
				cin >> c;
				while(c<1 || c>3){
					cout << "That was not a choice. Enter 1-3:" << endl;
					cin >> c;
				}//end while
				switch(c){
					case 1:// view cards
						m_players[x].DisplayHand();
						break;
					case 2://play a card
						m_discard.push_back(m_players[x].PlayCard());
						play = HandleCard(x); //type of the card just played
						//if an attack or a skip is played then the turn ends
						if(play==2 || play==3)
							turn_end = true;
						break;
					case 3://draw a card
						// if the card is 0 or -1 there is a bomb drawn
						play = m_players[x].AddToHand(DrawCard());
						if(play == -1){
							m_discard.push_back(m_players[x].PlayCard());
							HandleCard(x);
							if(m_players[x].HasLost()){
								cout << "Sorry! You're out of the game!" << endl;
								m_players[x].SetExtraTurn(false);
							}//end if
						}//end if
						turn_end = true;
						cout << "Number of Cards Remaining: " << m_deck.size();
						break;
					default:
						break;
				}//end switch
			}// end turn taker while
			//if the player was attacked and has an extra turn then...
			if(m_players[x].HasExtraTurn()){
				//repeat the last foor loop
				x--;
				m_players[x].SetExtraTurn(false);
			}//end if
		}//end for loop for turns
		win_count = 0;
		for(int z=0; z<m_numPlayers; z++){
			if(!m_players[z].HasLost()){
				win_count++;
				winner = z;//sets the winner.
				//should only be set one time if there is a winner.
			}
		}//end for
	}while(win_count>1);
	cout << "The winner is " << m_players[winner].GetName() << endl;
}//end PlayGame

/*LoadDeck:
	-adds the normal cards to the deck from file
*/
int Game::LoadDeck(string file_name){
	fstream inStream;
	inStream.open(file_name.c_str());

	string type;
	string name;
	const int length = 27; //number of cards in the deck file
	for(int i=0; i<length; i++){
		//input cards from 
		getline(inStream, type);
		getline(inStream, name);
		Card temp = Card(atoi(type.c_str()), name);
		//add to deck
		m_deck.push_back(temp);
	}
	inStream.close();
}

/*AddBombCards:
	-adds the bomb cards to the deck after the players have been dealt their cards.
*/
int Game::AddBombCards(string file_name){
	fstream inStream;
	inStream.open(file_name.c_str());
	//add as many bombs as there are number of players -1
	string type;
	string name;
	for(int i=0; i<m_numPlayers-1; i++){
		//input cards from 
		getline(inStream, type);
		getline(inStream, name);
		Card temp = Card(atoi(type.c_str()), name);
		//add to deck
		m_deck.push_back(temp);
	}
	Shuffle();
	cout << "Shuffling in the exploding kittens!" << endl;
	inStream.close();
}