// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Police.h
// Purpose: Create the class header for the Police class.


#ifndef POLICE_H
#define POLICE_H

#include "Jewel.h"
#include "Robber.h"



class Police
{
  private:
    int id;
    int pol_row;
    int pol_col;
    int count;
    int num_Robbers_Caught;

  public:
    //Des: Default constructor that sets cords.
    Police():count(0), num_Robbers_Caught(0){randCords();}
    //Des: Sets the cords of the Police to a random amount.
    //Pre: Class Police must exist.
    //Post: returns nothing but changes pol_row and pol_col.
    void randCords();
    //Des: Picks up jewel and adds it's value to the count.
    //Pre: Class Police and Jewel must exist and in_jewel must be of object Jewel.
    //Post: returns nothing but adds jewel amount to the count.
    void pickUpJewel(const Jewel in_jewel);
    //Des: getter function to get the Police row.
    //Pre: Class Police must exist.
    //Post: returns pol_row.
    int getRow()const{return pol_row;}
    //Des: getter function to get the Police's col.
    //Pre: Class Police must exist.
    //Post: returns pol_col.
    int getCol()const{return pol_col;}
    //Des: Arrests the robber and takes their jewels
    //Pre: class Robber and class Police must exist.
    //Post: returns nothing but changes the count and num_Robbers_Caught.
    void arrest(const Robber in_robber);
    //Des: Moves the police
    //Pre: class Police must exist.
    //Post: returns nothing but changes the cords.
    void move();
    //Des: sets the id of police
    //Pre: in_id must be an int and class Police must exist
    //Post: returns nothing but sets id
    void setId(const int in_id);
    //Des: getter function for id
    //Pre: class Police must exist.
    //Post: returns id.
    int getId()const{return id;}
    //Des: getter function for the count variable.
    //Pre: Class Police must exist
    //Post: returns count.
    int getCount()const{return count;}
    //Des: getter function for the number of robbers caught.
    //Pre: Class police must exist.
    //Post: returns num_Robbers_Caught.
    int getNumRobCaught()const {return num_Robbers_Caught;}
    //Des: Setter function for count variable.
    //Pre: in_count must be an int and class Police must exist.
    //Post: returns nothing but sets count to in_count.
    void setCount(const int in_count);
};


#endif
