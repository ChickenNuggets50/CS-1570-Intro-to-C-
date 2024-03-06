// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: codemon.cpp
// Purpose: Create different classes to simulate a game
#include "codemon.h"
#include <iostream>
using namespace std;

void Codemon::add_Skill(const Skills skill, const int index)
{
  m_skills_Mat[index] = skill;
  m_total_Skills++;
}

void Codemon::evolve()
{
  m_level += increaseLevel;
}

void Codemon::set_Total_Skills(const int skills)
{
  m_total_Skills = skills;
}

void Codemon::set_Current_Health(const int health)
{
  m_current_Health = health;
}

string Codemon::m_weather = " ";
float Codemon::m_damage_multiplier = 1;

void Codemon::randomize_Weather()
{
  int rndNum = rand() % max_weather;
  switch(rndNum)
  {
    case case_None:
      cout << "The weather is clear" << endl;
      m_damage_multiplier = base_damage;
      m_weather = none;
      break;
    case case_Sunny:
      cout << "The sun is shinning" << endl;
      m_damage_multiplier = sunny_damage;
      m_weather = sunny;
      break;
    case case_Hail:
      cout << "It started to hail" << endl;
      m_damage_multiplier = base_damage;
      m_weather = hail;
      break;
    case case_Snow:
      cout << "It started to snow" << endl;
      m_damage_multiplier = snow_damage;
      m_weather = snow;
      break;
    case case_Rain:
      cout << "It started to rain" << endl;
      m_damage_multiplier = base_damage;
      m_weather = rain;
      break; 
  }
}

void Codemon::operator ()(const string str)
{
  if(str == heal)
  {
    m_current_Health = m_health_Points;
  }
}