// File: Monster.cpp
//
// Implementation of Monster class.
//

#include <iostream>
#include "Monster.h"

// ------------- Constructors ----------------------

// Default constructor--used to initialize all new Monsters.
// we'll learn about these later!
//
Monster::Monster() 
{
  cout << "Creating a Monster...\n";
  m_type = "Normal";
  m_name = "Jabberwocky";
  m_heroesDefeated = 16;
  m_strength = 10;  // Start out at 10
}


// ------------- Accessors -------------------------
//
// These do what you think.

string Monster::GetType() {
  return m_type;
}

void Monster::SetType(const string &type) {
  m_type = type;
}

string Monster::GetName() {
  return m_name;
}

void Monster::SetName(const string &name) {
  m_name = name;
}

int Monster::GetHeroesDefeated() {
  return m_heroesDefeated;
}

void Monster::SetHeroesDefeated(int heroesDefeated) {
  m_heroesDefeated = heroesDefeated;
}

void Monster::SummonMonster() {
  m_strength--;
}

void Monster::RewardMonster() {
  m_strength++;
}



// ------ Helper Methods --------------

string Monster::GetStrength() {
  if(m_strength > 10) {
    return "strong!";
  }

  else if(m_strength < 10) {
    return "showing weakness.";
  }
    
  else {
    return "ok.";
  }
}
        
void Monster::MonsterGrowl() {
  cout << "ROAR!!" << endl;
}
