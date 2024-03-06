// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Robber.h
// Purpose: Create the class header for the Robber class.

#ifndef ROBBER_H
#define ROBBER_H

#include "Jewel.h"



class Robber
{
  protected:
    int id;
    int rob_row;
    int rob_col;
    int count;
    bool active;
    int bag_size;
    int num_jewels;
    static int tot_count;
    Jewel *bag;
  public:
    //Des: Default constructor that initializes the member functions
    Robber();
    //Des: Destructor for the Robber class
    virtual ~Robber();
    //Des: Sets the cords of the robber to a random amount.
    //Pre: Class robber must exist.
    //Post: returns nothing but changes rob_row and rob_col.
    void randCords();
    //Des: Adds a jewel to the bag. If the bag is too small, it expands the dynamic array to fit it in.
    //Pre: Class Robber and Jewel must exist and in_jewel must be of object Jewel.
    //Post: returns nothing but appends bag.
    void pickUpJewel(const Jewel in_jewel);
    //Des: Setts the active bool to false, indicating that the robber is no longer in play.
    //Pre: Class Robber must exist.
    //Post: returns nothing but changes active.
    void arrest();
    //Des: getter function to get the Robber row.
    //Pre: Class Robber must exist.
    //Post: returns rob_row.
    int getRow()const{return rob_row;}
    //Des: getter function to get the robber's col.
    //Pre: Class Robber must exist.
    //Post: returns rob_col.
    int getCol()const{return rob_col;}
    //Des: getter function to get the all robber's total value.
    //Pre: Class Robber must exist.
    //Post: returns tot_count.
    int getTotValue()const{return tot_count;}
    //Des: getter function to get the robber's count.
    //Pre: Class Robber must exist.
    //Post: returns count.
    int getCount()const{return count;}
    //Des: getter function to get the robber's active status.
    //Pre: Class Robber must exist.
    //Post: returns active.
    bool getActive()const{return active;}
    //Des: getter function to get the robber's jewel count.
    //Pre: Class Robber must exist.
    //Post: returns num_jewels.
    int getNumJewels()const {return num_jewels;}
    //Des: getter function to get robbers id.
    //Pre: Class Robber must exist.
    //Post: returns id.
    int getId()const{return id;}
    //Des: getter function to get the jewel at a certain index.
    //Pre: Class Robber and Jewel must exist and index must be an int.
    //Post: returns jewel of class Jewel
    Jewel getJewel(const int index)const {return bag[index];}
    //Des: Setter function for setting the count of the robber.
    //Pre: in_count must be an int and class Robber must exist.
    //Post: returns nothing but changes count.
    void setCount(const int in_count);
    //Des: Setter function for setting the id of the robber.
    //Pre: in_id must be an int and class Robber must exist.
    //Post: returns nothing but changes id.
    void setId(const int in_id);
    //Des: Setter function for setting the count for all robbers.
    //Pre: in_tot must be an int and class Robber must exist.
    //Post: returns nothing but changes tot_count.
    void setTotValue(const int in_tot);
    //Des: default function called for moving the robber.
    //Pre: in_dir must be an int and class Robber must exist.
    //Post: returns nothing but moves the robber to a new location
    bool robMove(const int in_dir);

};

#endif