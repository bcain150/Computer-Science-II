// File: lab4.cpp
	//
	// Demonstrates use of the Monster class.
	// Compile together with Monster.cpp
	//

#include <iostream>
#include "Monster.h"

using namespace std;

int main() {
  // Instantiate "Monster" class twice
  // Create "monster1" object and "monster2" object
  Monster monster1;
  Monster monster2;

  //Part 1: Using getters to access private data members for monster1
  cout << "Monster1's original data:\n";
  cout << "\tName is: " << monster1.GetName() << endl;
  cout << "\tType is: " << monster1.GetType() << endl;
  cout << "\tStrength is: " << monster1.GetStrength() << endl;

  // MODIFY monster1 AND monster2, BY USING THE Monster CLASS METHODS,
  // TO SET THE "type" FIELD TO SOMETHING NEW, GET THE FIELDS
  // BACK OUT AND PRINT

  //Part 2: Using settings to update private data members for monster1 and monster2
  cout << "Your monster1 has earned a super ability." << endl;
  monster1.SetType("Super"); // set new type for monster1 to Super.
  cout << "Monster1's new type is: " << monster1.GetType() << endl;
  cout << "Your monster2 has earned an evil ability." << endl;
  monster2.SetType("Evil"); // Set new type for monster2 to Evil.
  cout << "Monster2's new type is: " << monster2.GetType() << endl << endl;

  // INTERACT WITH YOUR MONSTER TO AFFECT STRENGTH RATING
  // BY USING THE SummonMonster() AND RewardMonster() METHODS

  //Part 3: Calling methods on a specific object that modify data members
  cout << "Call and reward your monster several times:" << endl;

  // Fetch current Strength value and display it
  cout << "Monster1 starts out " << monster1.GetStrength() << endl;

  // Now, summon your monster1 once, then reward monster1 twice.
  // Printing out the strength level after each change:

  monster1.SummonMonster();  // Summon the monster - Reduces monster strength
  cout << "You summoned the monster. Monster1's strength is now " 
       << monster1.GetStrength() << endl;
  monster1.RewardMonster();  // Reward the monster - Increases monster strength
  cout << "You rewarded the monster. Monster1's strength is now " 
       << monster1.GetStrength() << endl;
  monster1.RewardMonster();  // Reward the monster - Increases monster strength
  cout << "You rewarded the monster. Monster1's strength is now " 
       << monster1.GetStrength() << endl << endl;


  //Part 4: Calling a specific method of an object
  cout << "The monster growls!" << endl;
  monster1.MonsterGrowl();
 
  return 0;

}
