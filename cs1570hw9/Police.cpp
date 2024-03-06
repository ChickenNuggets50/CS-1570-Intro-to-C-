// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Police.cpp
// Purpose: Create the class functions for the Police class.

#include "Police.h"
#include "header.h"


void Police::randCords()
{
    pol_row = rand()% NUM_CITY_ROW;
    pol_col = rand()% NUM_CITY_COL;
    return;
}


void Police::pickUpJewel(const Jewel in_jewel)
{
    count += in_jewel.getValue();
    return;
}


void Police::move()
{
  bool validMove = false;
  do
  {
    int dir = rand()% DIRECTION_MAX;
    switch (dir)
    {
    case NW:
      if(pol_col - 1 >= 0 && pol_row - 1 >= 0)
      {
        cout << "NW" << endl;
        pol_col --;
        pol_row --;
        validMove = true;
      }
      break;
    
    case N:
      if (pol_row - 1 >= 0)
      {
        cout << "N" << endl;
        pol_row --;
        validMove = true;
      }
      break;

    case NE:
      if (pol_row - 1 >= 0 && pol_col + 1 < 10)
      {
        cout << "NE" << endl;
        pol_row --;
        pol_col ++;
        validMove = true;
      }
      break;

    case W:
      if(pol_col - 1 >= 0)
      {
        cout << "W" << endl;
        pol_col --;
        validMove = true;
      }
      break;

    case E:
      if(pol_col + 1 < 10)
      {
        cout << "E" << endl;
        pol_col ++;
        validMove = true;
      }
      break;

    case SW:
      if(pol_row + 1 < 10 && pol_col - 1 >= 0)
      {
        cout << "SW" << endl;
        pol_col --;
        pol_row ++;
        validMove = true;
      }
      break;

    case S:
      if(pol_row + 1 < 10)
      {
        cout << "S" << endl;
        pol_row ++;
        validMove = true;
      }
      break;

    case SE:
      if(pol_row + 1 < 10 && pol_col + 1 < 10)
        {
          cout << "SE" << endl;
          pol_row ++;
          pol_col ++;
          validMove = true;
        }
      break;

    default:
      cout << "Out of bounds " << dir << endl;
      break;
    }
  } while (validMove == false);
  return;
}

void Police::setId(const int in_id)
{
  id = in_id;
  return;
}


void Police::arrest(const Robber in_robber)
{
  count += in_robber.getCount();
  num_Robbers_Caught++;
  return;
}

void Police::setCount(const int in_count)
{
  count = in_count;
  return;
}