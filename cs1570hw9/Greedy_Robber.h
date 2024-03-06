// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Greedy_Robber.h
// Purpose: Create the class header for the Greedy Robber class.
#include "Robber.h"
#include "City.h"

#ifndef GREEDY_ROBBER_H
#define GREEDY_ROBBER_H


class Greedy_Robber: public Robber
{
  public:
    //Des: default de-constructor for greedy robber that deletes the bag pointer array.
    ~Greedy_Robber();
    //Des: Move function that moves the greedy robber in a way random direction but makes sure they stay on the array. (No bonus)
    //Pre: Class Greed_Robber must be a child of the existing class Robber.
    //Post: Returns nothing but changes the cords for the robber
    void move(City &input_city);
    //Des: Function that drops half the jewels that they own if they run into another robber.
    //Pre: Class Greed_Robber must be a child of the existing class Robber.
    //Post: returns nothing but changes the number of jewels owned and the robber's count
    void dropHalf();
};


#endif