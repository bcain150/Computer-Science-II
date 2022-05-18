// File: monster.h
//
// Modified class definition from Lab 4.
// Added #ifndef ...  macros, default constructor, 
// GetName accessor.

#ifndef MONSTER_H
#define MONSTER_H

#include <string>

using namespace std;

class Monster {
 public:
  // Default constructor--used to initialize all new Monsters.
  // we'll learn about these later!
  Monster();

  // Returns the type of monster
  string GetType();

  // Sets the type of monster
  void SetType(const string &type);

  // Returns the name of the monster
  string GetName();

  // Gives the monster a new name
  void SetName(const string &name);

  // Returns the number of heroes defeated
  int GetHeroesDefeated();

  // Gives the hero a new birth year
  void SetHeroesDefeated(int heroesDefeated);

  // Summon the monster
  void SummonMonster();

  // Reward the monster
  void RewardMonster();

  // See how strong the monster is
  string GetStrength();

  // Prompt the monster to growl at you
  void MonsterGrowl();

 private:
  string m_name;// Name of monster
  int m_heroesDefeated;// Number of heroes the monster has defeated
  string m_type;// Type of monster
  int m_strength;// Strength of monster

};

#endif 
