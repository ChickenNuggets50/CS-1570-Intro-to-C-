// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: City.h
// Purpose: Create the class header for the City class.

#ifndef CITY_H
#define CITY_H

#include "header.h"
#include "Jewel.h"

class City
{
  private:
    char city_board[NUM_CITY_ROW][NUM_CITY_COL];
    int num_jewel;
  public:
    //Des: A default constructor that sets the number of jewels in the city to the set number (47 for this).
    City();
    //Des: Gets the number of jewels in the city.
    //Pre: City class must exist.
    //Post: returns num_jewel.
    int getNumJewel()const{return num_jewel;}
    //Des: Subtracts one from the number of jewels because the jewel was collected.
    //Pre: City class must exist.
    //Post: returns nothing but changes num_jewel.
    void collectJewel();
    //Des: Adds one to the number of jewels because the jewel was replaced.
    //Pre: City class must exist.
    //Post: returns nothing but changes num_jewel.
    void replaceJewel();
    //Des: Sets the char in the city_board array to the respective member.
    //Pre: in_row and in_col must be an int and type must be a char.
    //Post: returns nothing but changes letter at given spot.
    void setLetterBoard(const int in_row, const int in_col, const char type);
    //Des: Gets the letter at a spot.
    //Pre: City class must exist and in_row and in_col must exist.
    //Post: returns character at index.
    char getCityLetter(const int in_row, const int in_col)const{return city_board[in_row][in_col];}
    //Des: Prints the city.
    //Pre: Class City must exist.
    //Post: returns nothing but prints out city.
    void print();
};

#endif
