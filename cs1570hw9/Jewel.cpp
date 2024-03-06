// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Jewel.cpp
// Purpose: Create the class functions for the Jewel class.

#include "Jewel.h"
#include "City.h"


void Jewel::randCords()
{
    jewel_row = rand()% NUM_CITY_ROW;
    jewel_col = rand()%NUM_CITY_COL;
    return;
}

void Jewel::setValue()
{
    value = jewel_row + jewel_col;
    return;
}

void Jewel::setJewel()
{
    randCords();
    setValue();
    return;
}