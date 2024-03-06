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

const int base_damage = 1;
const int sunny_damage = 2;
const float snow_damage = .5;
const int max_weather = 4;
const int max_Skills = 6;
const int increaseLevel = 5;
const int case_None = 0;
const int case_Sunny = 1;
const int case_Hail = 2;
const int case_Snow = 3;
const int case_Rain = 4;
const string none = "None";
const string sunny = "Sunny";
const string hail = "Hail";
const string snow = "Snow";
const string rain = "Rain";
const string heal = "heal";

class Contestant;

class Codemon
{
  public:
    // Default constructor
    Codemon(){};
    // Constructor with strings name and type. Also contains ints level and hp. Sets all variables when called.
    Codemon(const string name, const string type, const int level, const int hp): m_name(name), m_type(type), m_level(level), m_health_Points(hp), m_current_Health(hp){};
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
    // gets m_level value
    // N/A
    // returns m_level
    int get_Level() const {return m_level;};

    // gets m_current_Health value
    // N/A
    // returns m_current_Health
    int get_Current_Health() const {return m_current_Health;};
    
    // sets m_current_Health value
    // N/A
    // returns nothing
    void set_Current_Health(const int health);

    // gets m_weather value
    // N/A
    // returns m_weather
    string get_weather() const {return m_weather;};

    // gets m_damage_multiplier value
    // N/A
    // returns m_damage_multiplier
    int get_damage_Multiplier() const {return m_damage_multiplier;};

    // gets m_skills_Mat[index] value
    // N/A
    // returns m_skills_Mat[index]
    Skills getSkillsArray(const int index) const {return m_skills_Mat[index];};

    // sets m_weather value and m_damage_multiplier value
    // N/A
    // returns nothing
    void randomize_Weather();

    // overloaded () heals all codemon in a contestants pocket if the perameter = "heal"
    // N/A
    // overloaded () heals all codemon in a contestants pocket if the perameter = "heal"
    void operator ()(const string str);

  private:
    
    string m_name;
    string m_type;
    int m_level;
    int m_health_Points;
    int m_total_Skills = 0;
    int m_current_Health;
    static float m_damage_multiplier;
    static string m_weather;
    Skills m_skills_Mat[max_Skills];
    // adds 5 to the codemons level
    // N/A
    // returns nothing
    void evolve();
};


#endif