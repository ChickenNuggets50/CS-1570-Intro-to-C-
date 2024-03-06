// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: skills.h
// Purpose: Create different classes to simulate a game
#ifndef SKILLS_H
#define SKILLS_H

#include <iostream>
#include <string>
using namespace std;

class Contestant;

class Skills
{
  public:
    // Default constructor
    Skills(){};
    // Constructor with a string (name), and an int (damage). Sets all variables when called.
    Skills(const string name, const int damage): m_name(name), m_damage(damage){};
    // gets m_name value
    // N/A
    // returns m_name 
    string get_Skill_Name() const {return m_name;};

    // gets m_damage value
    // N/A
    // returns m_damage 
    int get_damage() const {return m_damage;};

    // Allows the user to search for a skill and if any pokemon has it the function will print the data
    // N/A
    // returns nothing
    friend void skillLookUp(Contestant contestants[]);

  private:
    string m_name;
    int m_damage;
};


#endif