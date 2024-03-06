// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: Hw6.cpp
// Purpose: Create different classes to simulate a game
#include "contestant.h"
#include "codemon.h"
#include "item.h"
#include "skills.h"
#include <iostream>
#include <string>
#include <cstdlib> 
using namespace std;

int main()
{
  srand(11);
  Codemon charizard("Charizard", "Fire", 85, 70);
  Codemon piplup("Piplup", "Water", 50, 80);
  Codemon machamp("Machamp", "Fighting", 70, 90);
  Codemon lugia("Lugia", "Flying", 90, 40);
  Codemon palkia("Palkia", "Flying", 90, 70);
  Codemon magicarp("Magicarp", "Water", 25, 30);
  Codemon lucario("Lucario", "Fighting", 60, 95);
  Item berry("Berry", "Does Nothing", 46);
  Item potion("Potion", "Does Nothing", 35);
  Skills pound("Pound", 40);
  Skills slam("Slam", 80);
  Skills bind("Bind", 20);
  Skills wrap("Wrap", 20);
  Skills bite("Bite", 25);

  Contestant contestants[max_Contestants];

  charizard.add_Skill(pound, 0);
  charizard.add_Skill(slam, 1);
  charizard.add_Skill(wrap, 2);

  piplup.add_Skill(bind, 0);
  piplup.add_Skill(slam, 1);
  piplup.add_Skill(pound, 2);

  machamp.add_Skill(bite, 0);
  machamp.add_Skill(wrap, 1);
  machamp.add_Skill(pound, 2);

  lugia.add_Skill(bite, 0);
  lugia.add_Skill(wrap, 1);
  lugia.add_Skill(pound, 2);

  palkia.add_Skill(pound, 0);
  palkia.add_Skill(slam, 1);
  palkia.add_Skill(wrap, 2);

  magicarp.add_Skill(bind, 0);
  magicarp.add_Skill(slam, 1);
  magicarp.add_Skill(pound, 2);

  lucario.add_Skill(bite, 0);
  lucario.add_Skill(wrap, 1);
  lucario.add_Skill(pound, 2);


  contestants[0] + charizard;
  contestants[0] += piplup;
  contestants[0] + charizard;
  contestants[0] += machamp;
  contestants[0] + lugia;
  contestants[0] += lucario;
  contestants[0] + magicarp;


  contestants[0] += berry;
  contestants[0] + potion;
  contestants[0] += berry;
  contestants[0] + potion;
  contestants[0] += potion;
  contestants[0] + berry;
  contestants[0] += berry;
  contestants[1] += potion;
  contestants[1] + berry;
  
  contestants[0] -= berry;
  contestants[1] - berry;
  contestants[0] - potion;
  contestants[1] -= potion;

  contestants[1] + charizard;
  contestants[1] + piplup;
  contestants[1] += magicarp;
  contestants[1] += machamp;
  contestants[1] += lugia;
  contestants[1] += lucario;
  contestants[1] += lugia;

  contestants[0] -= lugia;
  contestants[0] - lugia;
  contestants[1] -= lugia;


  
  
  // for(int i = 0; i < max_Contestants; i++)
  // {
  //   contestants[i].prepare();
  // }
  cout << endl << endl << "Contestant Summary: " << endl;
  for(int i = 0; i < max_Contestants; i++)
  {
    contestants[i].print();
  }
  skillLookUp(contestants);

  Contestant winner(contestants[0] * contestants[1]);
  cout << endl << "The winner is " << winner.get_Name() << endl;
  

  contestants[0](heal);
  contestants[1](heal);
  return 0;
}