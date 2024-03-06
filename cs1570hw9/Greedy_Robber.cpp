// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Greedy_Robber.cpp
// Purpose: Create the class functions for the Greedy Robber class.

#include "Greedy_Robber.h"

Greedy_Robber::~Greedy_Robber()

noexcept {delete [] bag;}

void Greedy_Robber::move(City &input_city)
{
  bool isJewel = false;
  bool allChecked = false; // set false
  bool northwest = false;
  bool north = false;
  bool northeast = false;
  bool west = false;
  bool east = false;
  bool southwest = false;
  bool south = false;
  bool southeast = false;
  

  do
  {
    int dir = rand() % DIRECTION_MAX;
    switch (dir)
    {
      case NW:
        northwest = true;
        for(int i = 0; i <= rob_row && i <= rob_col; i++)
        {
          if (input_city.getCityLetter(rob_row - i, rob_col - i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col--;
            rob_row--;
          } 
        }
        break;
      case N:
        north = true;
        for (int startRow = rob_row; startRow >= 0; startRow--)
        {
          if (input_city.getCityLetter(startRow, rob_col) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_row--;
          }
        }
        break;
      case NE:
        northeast = true;
        for(int i = 0; i <= rob_row && i <= NUM_CITY_COL - rob_col; i++)
        {
          if (input_city.getCityLetter(rob_row - i, rob_col + i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col++;
            rob_row--;
          } 
        }
        break;
      case W:
        west = true;
        for (int i = 0; i <= rob_col ; i++)
        {
          if (input_city.getCityLetter(rob_row, rob_col - i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col--;
          }
        }
        break;
      case E: 
        east = true;
        for (int i = 0; i <= NUM_CITY_COL - rob_col ; i++)
        {
          if (input_city.getCityLetter(rob_row, rob_col + i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col++;
          }
        }
        break;
      case SW:
        southwest = true;
        for(int i = 0; i <= NUM_CITY_ROW - rob_row && i <= rob_col; i++)
        {
          if (input_city.getCityLetter(rob_row + i, rob_col - i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col--;
            rob_row++;
          } 
        }
        break;


      case S:
        south = true;
        for (int i = 0; i < NUM_CITY_ROW - rob_row; i++)
        {
          if (input_city.getCityLetter(rob_row - i, rob_col) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_row++;
          }
        }
        break;
      
      case SE:
        southeast = true;
        for(int i = rob_row; i <= NUM_CITY_ROW - rob_row && i <= NUM_CITY_COL - rob_col; i++)
        {
          if (input_city.getCityLetter(rob_col + i, rob_row + i) == JEWEL_LETTER && isJewel != true)
          {
            isJewel = true;
            rob_col++;
            rob_row++;
          }
        }
        break;

    }
    if(northwest == true && north == true && northeast == true && west == true && east == true && southwest == true && south == true && southeast == true)
    {
      allChecked = true;
    }
  }
  while(isJewel == false && allChecked == false);



  if(allChecked == true)
  {
    bool move = false;
    do {
      int dir = rand() % DIRECTION_MAX;
      move = robMove(dir);
    } while (move == false);
  }
}



void Greedy_Robber::dropHalf()
{
  int half = num_jewels / 2;
  for (int i = num_jewels; i >= half; i--)
  {
    count = count - bag[i].getValue();
    tot_count = tot_count - bag[i].getValue();
  }
  num_jewels = num_jewels / 2;
  Jewel *temp;
  temp = new Jewel[bag_size];
  for (int i = 0; i < num_jewels; ++i)
    temp[i] = bag[i];
  delete[] bag;
  bag = temp;
  return;
}