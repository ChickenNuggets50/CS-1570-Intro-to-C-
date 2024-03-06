// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: codemon.h
// Purpose: Create different classes to simulate a game
#ifndef CODEMON_H
#define CODEMON_H

#include <iostream>
#include <string>
#include "skills.h"
using namespace std;

const int max_Skills = 6;
const int increaseLevel = 5;

class Contestant;

class Codemon
{
  public:
    // Default constructor
    Codemon(){};
    // Constructor with strings name and type. Also contains ints level and hp. Sets all variables when called.
    Codemon(const string name, const string type, const int level, const int hp): m_name(name), m_type(type), m_level(level), m_health_Points(hp){};
    // gets m_name value
    // N/A
    // returns m_name
    string getName() const {return m_name;};
    // adds a skill object to the skills matrix for that codemon
    // N/A
    // returns nothing
    void add_Skill(const Skills skill, const int index);
    // gets m_total_Skills value
    // N/A
    // returns m_total_Skills
    int get_Total_Skills() const {return m_total_Skills;};
    // sets m_total_Skills value
    // N/A
    // returns nothing
    void set_Total_Skills(const int skills);
    // Allows the user to search for a skill and if any pokemon has it the function will print the data
    // N/A
    // returns nothing
    friend void skillLookUp(Contestant contestants[]);

  private:
    string m_name;
    string m_type;
    int m_level;
    int m_health_Points;
    int m_total_Skills;
    Skills m_skills_Mat[max_Skills];
    // adds 5 to the codemons level
    // N/A
    // returns nothing
    void evolve();
};


#endif