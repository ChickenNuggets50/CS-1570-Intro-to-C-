// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: item.h
// Purpose: Create different classes to simulate a game
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
using namespace std;

class Item
{
  public:
  // Default constructor
    Item(){};
    // Constructor with two strings (name and descrpition) and one int (duration) Sets all variables when called.
    Item(const string name, const string description, const int duration): m_name(name), m_description(description), m_duration(duration){};
    // gets m_name value
    // N/A
    // returns m_name
    string getName() const {return m_name;};

  private:
    string m_name;
    string m_description;
    int m_duration;
    int m_num_Items;
};



#endif