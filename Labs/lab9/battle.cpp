#include <iostream>
#include <string>
using namespace std;

class Creature{
public:
  void Attack(Creature * target)
  {
    target->m_hp -= m_attack;
    DerivedAttack();
    if (target->IsDead()){
      cout << target->m_name << " has perished." << endl;
    }
  }
  
  bool IsDead(){
    if(m_hp > 0){
      return false;
    }
    return true;
  }

  virtual void DerivedAttack() {
    cout << "Parent class derived attack firing" << endl;
  //  virtual void DerivedAttack() = 0;
  }

  void SetValues(string newName, int hp, int att)
  {
    m_name = newName;
    m_attack = att;
    m_hp = hp;
  }

  void Display(Creature * target){
    cout << target->m_name 
	 << " (hp: " << target->m_hp
	 << " att: " << target->m_attack << ")" << endl;
  }

protected:
  string m_name;
  int m_attack;
  int m_hp;
};

class Dragon : public Creature{
public:
  void DerivedAttack()
  {
    cout << "The dragon does " << m_attack << " points of damage to the hero!" << endl;
  }
};

class Hero : public Creature{
public:
  void DerivedAttack()
  {
    cout << "The hero does " << m_attack << " points of damage to the dragon!" << endl;
  }
};

int main() {
  Dragon dragon;
  Hero hero;
  Creature * dragon1 = &dragon;
  Creature * hero1 = &hero;
  dragon1->SetValues("SlashyClaw", 75, 25);
  hero1->SetValues("Sir CuttySword", 100, 25);

  cout << "The battle begins!" << endl;
  while(! dragon1->IsDead() and ! hero1->IsDead())
    {
      dragon1->Attack(hero1);
      dragon1->Display(hero1);
      hero1->Attack(dragon1);
      hero1->Display(dragon1);
    }
  return 0;
}
