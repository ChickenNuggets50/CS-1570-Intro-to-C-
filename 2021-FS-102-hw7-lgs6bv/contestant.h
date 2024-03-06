// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: contestant.h
// Purpose: Create different classes to simulate a game
#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <iostream>
#include <string>
#include "codemon.h"
#include "item.h"
using namespace std;

const int max_loud = 100;
const int max_Codemon = 10;
const float haildamage = .0625;
const int max_Items = 20;
const int level_Check = 5;
const int max_Contestants = 2;
const int infinateDuration = -1;
const int low = 0;

class Contestant
{
  public:
    // Default constructor with name inputted by user and codemon defaults to 0
    Contestant();
    // Constructor which takes in the parameters of name and num Codemon
    Contestant(const string name, const int num = 0, const int volume = rand() % 100): m_name(name), m_num_Codemon(num), m_volume(volume){};
    // Copy constructor
    Contestant(const Contestant & student);
    // Allows a user to add pokemon to their pocket, add moves to their pokemon, and add items to their bag for the current contestant.
    // N/A
    // returns nothing
    void prepare();
    // Prints the backpack and pocket of the contestant.
    // N/A
    // returns nothing
    void print();

    // overloaded += operator adds a codemon to a contestants pocket 
    // N/A
    // overloaded += operator adds a codemon to a contestants pocket returns nothing
    void operator +=(const Codemon codemon);

    // overloaded + operator adds a codemon to a contestants pocket 
    // N/A
    // overloaded + operator adds a codemon to a contestants pocket returns nothing
    void operator +(const Codemon codemon);

    // overloaded -= operator removes a codemon to a contestants pocket 
    // N/A
    // overloaded -= operator removes a codemon to a contestants pocket returns nothing
    void operator -=(const Codemon codemon);

    // overloaded - operator removes a codemon to a contestants pocket 
    // N/A
    // overloaded - operator removes a codemon to a contestants pocket returns nothing
    void operator -(const Codemon codemon);

    // overloaded += operator adds an item to a contestants backpack 
    // N/A
    // overloaded += operator adds an item to a contestants backpack returns nothing
    void operator +=(const Item item);

    // overloaded + operator adds an item to a contestants backpack 
    // N/A
    // overloaded + operator adds an item to a contestants backpack returns nothing
    void operator +(const Item item);

    // overloaded -= operator removes an item from a contestants backpack 
    // N/A
    // overloaded -= operator removes an item from a contestants backpack returns nothing
    void operator -=(const Item item);

    // overloaded - operator removes an item from a contestants backpack 
    // N/A
    // overloaded - operator removes an item from a contestants backpack returns nothing
    void operator -(const Item item);

    // overloaded () heals all codemon in a contestants pocket if the perameter = "heal"
    // N/A
    // overloaded () heals all codemon in a contestants pocket if the perameter = "heal"
    void operator ()(const string str);

    // gets m_name value
    // N/A
    // returns m_name 
    string get_Name() const {return m_name;};
    
    // sets m_randomskillIndex value
    // N/A
    // returns nothing
    void setrandomskillIndex();

    // sets m_index_Of_First_NonComatosed value
    // N/A
    // returns nothing
    void setFirstNonComatose();

    // battles two codemon
    // N/A
    // returns nothing
    void battle(Contestant& attacker, Contestant& defender, const int attackindex, const int defendindex);

    // puts two contestants against eachother and battles them with their codemon
    // N/A
    // returns the winner 
    Contestant operator *(Contestant & cont2);

    // Allows the user to search for a skill and if any pokemon has it the function will print the data
    // N/A
    // returns nothing
    friend void skillLookUp(Contestant contestants[]);

  private:
    string m_name;
    int m_num_Codemon;
    int m_num_Items;
    int m_volume;
    int m_index_Of_First_NonComatosed;
    int m_randomskillIndex;
    int m_knockedout = 0;
    Codemon m_Codemon[max_Codemon];
    Item m_backpack[max_Items];
    // adds a codemon object to the contestants pocket array
    // N/A
    // returns nothing
    void update_Pocket(const Codemon codemon, int & index);
    // adds an item object to the contestants backpack array
    // N/A
    // returns nothing
    void update_Backpack(const Item item, int & index);
};


#endif