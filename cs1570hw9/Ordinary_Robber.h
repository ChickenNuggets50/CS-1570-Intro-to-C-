// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Ordinary_Robber.cpp
// Purpose: Create the class header for the Ordinary Robber class.
#include "Robber.h"
#include "header.h"
#ifndef ORDINARY_ROBBER_H
#define ORDINARY_ROBBER_H

class Ordinary_Robber: public Robber
{
  private:
    

  public:
    //Des: default de-constructor for ordinary robber that deletes the bag pointer array.
    ~Ordinary_Robber();
    //Des: Move function that moves the ordinary robber in a way random direction but makes sure they stay on the array.
    //Pre: Class Ordinary_Robber must be a child of the existing class Robber.
    //Post: Returns nothing but changes the cords for the robber
    void move();
};


#endif
