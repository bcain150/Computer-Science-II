/*
 *Title: Exploding Kittens Card Game
 *Date: 2/22/2017
 *Author: Nick Lawrence and Jeremy Dixon
 *Description: This is the player class for the exploding kittens game
*/

#ifndef PLAYER_H //Include guard to protect against multiple declarations
#define PLAYER_H //Include guard

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Card.h"

class Player {
public:
  // Name - Default Constructor
  // Unused
  Player();
  
  // Name - Constructor (Overloaded)
  // Preconditions: A valid input string for the name
  // Postcondition: A player with a name, an empty hand, and m_lost set to false
  Player(string);
  
  // Name - PlayCard()
  // Desc - Function for moving a card from a player's hand to the discard pile
  // Preconditions - A hand with at least 1 card, a valid index
  // Postconditions - Returns a card from the hand and deletes it from the array
  Card PlayCard();
  
  // Name - LoseCard() 
  // Desc - Function where a player steals card from another player
  // Preconditions - A hand with at least 1 card, a valid index
  // Postconditions - Returns and deletes the card at index i
  Card LoseCard(int);
  
  // Name - HasCards() 
  // Desc - Function to check if the player has cards
  // Preconditions - None
  // Postconditions - True if the player has cards, false otherwise
  bool HasCards();
  
  // Name - HasLost()
  // Desc - Function checks to see if player already lost.
  //        If already lost, skips turn.
  // Preconditions - None
  // Postconditions - The state of m_lost
  bool HasLost();

  // Name - HasExtraTurn()
  // Desc - Function checks to see if player has extra turn.
  //        If already lost, skips turn.
  // Preconditions - None
  // Postconditions - The state of m_extraTurn
  bool HasExtraTurn();
  
  // Name - AddToHand()
  // Desc - Function to add a card to the players hand.
  //        This also detects if the player has drawn a bomb
  // Preconditions - A valid Card input
  // Postconditions - A integer status about the player in regards to the card
  //                  that was just added to his hand (see .cpp for more info)
  int AddToHand(Card);
  
  // Name - GetName()
  // Desc - Function to get the name of the player
  // Preconditions - None
  // Postconditions - Returns the name of the player
  string GetName();
  
  // Name - DisplayHand()
  // Desc - Function to print out the cards in the hand
  // Preconditions - None
  // Postconditions - Uses cout to print the player's hand
  void DisplayHand();
  
  // Name - GetNumberOfCards()
  // Desc - Returns the number of cards in the player's hand
  // Preconditions - None
  // Postconditions - Returns an integer number for the number of cards
  //                  in the player's hand
  int GetNumberOfCards();
  
  // Name - ReturnBomb()
  // Desc - Returns the bomb card the player drew in the event of a defusal
  // Preconditions - A bomb in the player's hand
  // Postconditions - A card object that is the bomb the player drew
  Card ReturnBomb();
  
  // Name - SetLost() 
  // Desc - Sets if the player lost or not
  // Preconditions - a bool
  // Postconditions - m_lost is set to the input
  void SetLost(bool);
  
  // Name - SetExtraTurn()
  // Desc - Sets if the player was attacked or not
  // Preconditions - a bool
  // Postconditions - m_extraTurn is toggled
  void SetExtraTurn(bool);
  
private:
  vector<Card> m_hand;
  string m_name;
  bool m_lost;
  bool m_extraTurn;
};

#endif // PLAYER_H
