/********************************************
** File:    Player.cpp
** Project: CMSC 202 Project 2, Spring 2017
** Author:  Brendan Cain
** Date:    03-06-17
** Section: 16 (lecture) 18 (discussion)
** E-mail:  bcain1@umbc.edu
**
** This file defines the class Player
**********************************************/

#include "Player.h"

/*Constructor Method:
	-sets the players name and gives them an empty hand.
*/
Player::Player(){}

Player::Player(string name){
	m_name = name;
	m_lost = false;
}//end Player

/*PlayCard:
	-takes in the index of the card the player wishes to play
	-returns the discarded card and deletes it from the deck.
*/
Card Player::PlayCard(){
	int i = 0;
	Card discard;
	//prints hand
	DisplayHand();
	do{// ensures that the card is inbounds and also isnt an exploding kitten
		cout << "Select a card: " << endl;
		cin >> i;
		//with in the number of cards in hand?
		if(i<0 || i>m_hand.size()-1){
			cout << "That option was not on the list. Choose between 0-" << m_hand.size()-1 << ": " << endl;
			cout << "Select a different card: " << endl;
			cin >> i;
		}//checks too see if the user tried to play the bomb they just got.
		else if(m_hand.at(i).GetType()==0){
			cout << "You cannot play an Exploding Kitten! Get rid of it!" << endl;
			cout << "Select a different card: " << endl;
			cin >> i;
		}	
	}while(i<0 || i>m_hand.size()-1 || m_hand.at(i).GetType()==0);
	//saves card to discard. it is now validated
	discard = m_hand.at(i);
	m_hand.erase(m_hand.begin()+i);
	//prints number of cards left and returns the discard.
	cout << "Number of cards remaining: " << GetNumberOfCards() << endl;
	return discard;
}//end PlayCard

/*LoseCard:
	-One Player steals card from another.
	-return card at index and delete it from hand.
*/
Card Player::LoseCard(int i){
	Card stolenCard = m_hand.at(i);
	//saves card
	m_hand.erase(m_hand.begin()+i);
	return stolenCard;
}//end LoseCard

/*HasCards:
	-checks to see if the player has any cards in their hand
*/
bool Player::HasCards(){
	if(m_hand.size()>0)
		return true;
	else
		return false;
}//end HasCards

/*HasLost:
	-retuns m_lost
*/
bool Player::HasLost(){
	return m_lost;
}//end HasLost

/*HasExtraTurn:
	-retuns m_extraTurn
*/
bool Player::HasExtraTurn(){
	return m_extraTurn;
}//end HasExtraTurn

/*AddToHand:
	-adds a card to the players hand
	-detects if there is a bomb drawn
	-returns the card's type and -1 if a bomb can be defused
*/
int Player::AddToHand(Card cardDrawn){
	//adds card to hand and gets its type
	m_hand.push_back(cardDrawn);
	int type = cardDrawn.GetType();
	//checks to see if its a bomb
	if(type==0){
		SetLost(true);
		cout << "Oh No! You drew an Exploding Kitten: ";
		cout << cardDrawn.ToString() << endl;
		//checks if the player has a defuse card
		bool noDefuse = true;
		int c = 0;
		while(noDefuse && c<m_hand.size()){
			if(m_hand.at(c).GetType()==1)
				noDefuse = false;
			c++;
		}//end while
		if(noDefuse){
			cout << "Sorry! You're out of the game!" << endl;
			SetExtraTurn(false);
		}
		else{
			cout << "But you have a defuse card! Play it or lose!" << endl;
			return -1; //returns -1 if they have the ability to defuse the bomb
		}
	}//end if
	return type;
}//end AddToHand

/*GetName:
	-returns the players name
*/
string Player::GetName(){
	return m_name;
}//end GetName

/*DisplayHand:
	-prints out the cards in hand.
*/
void Player::DisplayHand(){
	cout << endl;
	for(int i=0; i<m_hand.size(); i++){
		cout << i << ". "; //numbering
		//prints type of card as a string
		switch(m_hand.at(i).GetType()){
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
		cout << m_hand.at(i).ToString() << endl;
	}//end for
}//end DisplayHand

/*GetNumberOfCards:
	-returns the number of cards in the players hand
*/
int Player::GetNumberOfCards(){
	return m_hand.size();
}//end GetNumberOfCards

/*ReturnBomb:
	-Returns the bomb card the player drew in the event of a diffusal
	-Assumes that the player has a diffuse card
*/
Card Player::ReturnBomb(){
	//the card is known to be in the last index
	//we can use the Lose Card method
	return LoseCard(m_hand.size()-1);
}//end ReturnBomb

/*SetLost:
	-sets if the player lost or not
*/
void Player::SetLost(bool l){
	m_lost = l;
}//end SetLost

/*SetExtraTurn:
	-sets if the player was attacked or not.
*/
void Player::SetExtraTurn(bool e){
	m_extraTurn = e;
}