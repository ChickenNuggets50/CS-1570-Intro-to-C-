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