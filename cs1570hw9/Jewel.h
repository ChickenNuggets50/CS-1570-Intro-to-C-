// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: Jewel.h
// Purpose: Create the class header for the Jewel class.

#ifndef JEWEL_H
#define JEWEL_H


class Jewel
{
    private:
        int value;
        int jewel_row;
        int jewel_col;
    public:
        //Des: Default constructor that does nothing.
        Jewel(){}
        //Des: Sets the cords of the jewels to a random amount.
        //Pre: Class Jewel must exist.
        //Post: returns nothing but changes jewel_row and jewel_col.
        void randCords();
        //Des: Sets the value of Value by adding the cords together.
        //Pre: Class Jewel must exist and jewel_row and jewel_col must be ints.
        //Post: returns nothing but changes the value of Value.
        void setValue();
        //Des: Sets the jewels value and cords.
        //Pre: Class Jewel must exist and jewel_row and jewel_col must be ints.
        //Post: returns nothing but changes value, jewel_row and jewel_col.
        void setJewel();
        //Des: getter function to get the value of the jewel.
        //Pre: Class Jewel must exist.
        //Post: returns value.
        int getValue()const{return value;}
        //Des: getter function to get the jewel row.
        //Pre: Class Jewel must exist.
        //Post: returns jewel_row.
        int getRow()const{return jewel_row;}
        //Des: getter function to get the jewel col.
        //Pre: Class Jewel must exist.
        //Post: returns jewel_col.
        int getCol()const{return jewel_col;}
};


#endif
