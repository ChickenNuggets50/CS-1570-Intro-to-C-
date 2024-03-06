// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Robber.cpp
// Purpose: Create the class functions for the Robber class.


#include "Robber.h"
#include "header.h"


Robber::Robber()
{
  randCords();
  active = true;
  bag_size = START_BAG;
  num_jewels = 0;
  count = 0;
  bag = new Jewel[START_BAG];
}

Robber::~Robber()
{

}

void Robber::randCords()
{
  rob_row = rand()% NUM_CITY_ROW;
  rob_col = rand()%NUM_CITY_COL;
  return;
}

int Robber::tot_count = 0;

void Robber::pickUpJewel(const Jewel in_jewel)
{
  Jewel *temp;
  if(num_jewels >= bag_size)
  {
    bag_size = bag_size * 2;
    temp = new Jewel[bag_size];
    for (int i = 0; i < num_jewels; ++i)
      temp[i] = bag[i];
    delete[] bag;
    bag = temp;
  }
  bag[num_jewels] = in_jewel;
  count += in_jewel.getValue();
  tot_count += in_jewel.getValue();
  num_jewels++;
  return;
}

void Robber::arrest()
{
  active = false;
  count = 0;
  return;
}

void Robber::setId(const int in_id)
{
  id = in_id;
  return;
}

bool Robber::robMove(const int in_dir)
{
  bool validMove = false;
  int dir = in_dir;
  switch (dir)
  {
    case NW:
    if(rob_col - 1 >= 0 && rob_row - 1 >= 0)
    {
      cout << "NW" << endl;
      rob_col --;
      rob_row --;
      validMove = true;
    }
    break;

    case N:
    if (rob_row - 1 >= 0)
    {
      cout << "N" << endl;
      rob_row --;
      validMove = true;
    }
    break;

    case NE:
    if (rob_row - 1 >= 0 && rob_col + 1 < 10)
    {
      cout << "NE" << endl;
      rob_row --;
      rob_col ++;
      validMove = true;
    }
    break;

    case W:
    if(rob_col - 1 >= 0)
    {
      cout << "W" << endl;
      rob_col --;
      validMove = true;
    }
    break;

    case E:
    if(rob_col + 1 < 10)
    {
      cout << "E" << endl;
      rob_col ++;
      validMove = true;
    }
    break;

    case SW:
    if(rob_row + 1 < 10 && rob_col - 1 >= 0)
    {
      cout << "SW" << endl;
      rob_col --;
      rob_row ++;
      validMove = true;
    }
    break;

    case S:
    if(rob_row + 1 < 10)
    {
      cout << "S" << endl;
      rob_row ++;
      validMove = true;
    }
    break;

    case SE:
    if(rob_row + 1 < 10 && rob_col + 1 < 10)
    {
      cout << "SE" << endl;
      rob_row ++;
      rob_col ++;
      validMove = true;
    }
    break;

    default:
    cout << "Out of bounds " << dir << endl;
    break;
  }
  return validMove;
}

void Robber::setCount(const int in_count)
{
  count = in_count;
  return;
}


void Robber::setTotValue(const int in_tot)
{
  tot_count = in_tot;
  return;
}