// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: Hw6.cpp
// Purpose: Create different classes to simulate a game
#include "contestant.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  srand(11);
  Contestant contestants[max_Contestants];

  for(int i = 0; i < max_Contestants; i++)
  {
    contestants[i].prepare();
  }
  cout << endl << endl << "Contestant Summary: " << endl;
  for(int i = 0; i < max_Contestants; i++)
  {
    contestants[i].print();
  }
  skillLookUp(contestants);
  cout << endl << "Good bye, the combat shall begin soon!" << endl;
  return 0;
}