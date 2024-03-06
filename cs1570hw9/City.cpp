// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: City.cpp
// Purpose: Create the class functions for the City class.

#include "City.h"

City::City()
{
  num_jewel = NUM_JEW;
  for (int i = 0; i < NUM_CITY_ROW; ++i)
  {
    for (int j = 0; j < NUM_CITY_COL; ++j)
    {
      city_board[i][j] = ' ';
    }
  }
}

void City::collectJewel()
{
  num_jewel = num_jewel - 1;
  return;
}

void City::replaceJewel()
{
  num_jewel = num_jewel + 1;
  return;
}

void City::setLetterBoard(const int in_row, const int in_col, const char type)
{
  city_board[in_row][in_col] = type;
  return;
}

void City::print()
{
  for (int i = 0; i < NUM_CITY_ROW; ++i)
  {
    if(i < 10)
      cout<<" "<< i <<" |" ;
    else
      cout<<i<<" |";
    for (int j = 0; j < NUM_CITY_COL; ++j)
    {
      if(j + 1 == NUM_CITY_COL)
        cout<<" "<<city_board[i][j]<<" |";
      else
        cout<<" "<<city_board[i][j]<<" ,";
    }
    cout<<endl;
  }
  cout<<"    ";
  for (int i = 0; i < NUM_CITY_ROW; ++i)
  {
    if(i < 10)
      cout<<" "<< i <<"  " ;
    else
      cout<<i<<"  ";
  }
  cout<<endl;
  return;
}