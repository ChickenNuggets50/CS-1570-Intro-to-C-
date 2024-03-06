// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Ordinary_Robber.cpp
// Purpose: Create the class functions for the Ordinary Robber class.

#include "Ordinary_Robber.h"
#include <cstdlib>

Ordinary_Robber::~Ordinary_Robber()

noexcept {delete [] bag;}

void Ordinary_Robber::move() {
  bool move = false;
  do {
    int dir = rand() % DIRECTION_MAX;
    move = robMove(dir);
  } while (move == false);
  return;
}
