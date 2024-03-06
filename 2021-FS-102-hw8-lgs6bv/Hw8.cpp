// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/16/2021>
// File: Hw8.cpp
// Purpose: Create a love game
#include "Match.h"
#include <iostream>
using namespace std;

int main()
{
  srand(8);
  int arrsize;
  cout << "Welcome to the Love Triangle Game! Ready for some heartbreak?" << endl << endl;
  cout << "How big is your city?" << endl;
  cin >> arrsize;
  Match match(arrsize);
  match.play();
  match.final_results();
  return 0;
}