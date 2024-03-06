// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: contestant.cpp
// Purpose: Create different classes to simulate a game
#include "contestant.h"
#include "codemon.h"
#include "item.h"
#include "skills.h"
#include <iostream>
#include <string>
using namespace std;

Contestant::Contestant()
{
  cout << "What's your name, contestant?" << endl;
  getline(cin, m_name);
  m_num_Codemon = low;
  m_volume = rand() % 100;
}

Contestant::Contestant(const Contestant & student) 
{
  m_name = student.m_name;
  m_num_Codemon = student.m_num_Codemon;
  m_num_Items = student.m_num_Items;
  m_volume = student.m_volume;
  for(int i = 0; i < max_Codemon; i++){
    m_Codemon[i] = student.m_Codemon[i];
  }
  for(int i = 0; i < max_Items; i++){
    m_backpack[i] = student.m_backpack[i];
  }
}

void Contestant::update_Pocket(const Codemon codemon, int & index)
{
  m_Codemon[index] = codemon;
  index += 1;
}

void Contestant::update_Backpack(const Item item, int & index)
{
  m_backpack[index] = item;
  index += 1;
}

void Contestant::prepare()
{
  char update;
  string codemonName, type, skillName, itemName, itemDescription;
  int level, hp, currentCodemonsTotalSkills, skillDamage, itemDuration;

  cout << endl  << endl << "Let's prepare you for the combat, contestant " << m_name << "!" << endl;
  do
  {
    cout << "Do you want to add a new Codemon? (y/n)" << endl;
    cin >> update;
  } while(update != 'y' && update != 'n');
  

  while (update == 'y' && m_num_Codemon < max_Codemon)
  {
    cout << "Name of the Codemon?" << endl;
    cin.ignore();
    getline(cin, codemonName);

    cout << "What is " << codemonName << "'s type?" << endl;
    cin.ignore();
    getline(cin, type);

    do
    {
      cout << "What is " << codemonName << "'s level?" << endl;
      cin >> level;
    } while (level % level_Check != low);
  
    do
    {
      cout << "What is " << codemonName << "'s HP?" << endl;
      cin >> hp;
    } while (hp <= low);
    
    Codemon temp_Codemon(codemonName, type, level, hp);

    do
    {
      cout << "Do you want to add a new skill for " << codemonName << "? (y/n)" << endl;
      cin >> update;
    } while(update != 'y' && update != 'n');

    if (update == 'y')
    {
      currentCodemonsTotalSkills = low;
      do
      {
        cout << "What is the name of the new skill?" << endl;
        cin.ignore();
        getline(cin, skillName);

        cout << "What is the skill's base damage?" << endl;
        cin >> skillDamage;
        
        Skills temp_Skill(skillName, skillDamage);
        temp_Codemon.add_Skill(temp_Skill, currentCodemonsTotalSkills);
        currentCodemonsTotalSkills ++;

        do
        {
          cout << "Do you want to add a new skill for " << codemonName << "? (y/n)" << endl;
          cin >> update;
        } while(update != 'y' && update != 'n');
      } while (update == 'y' && currentCodemonsTotalSkills < max_Skills);
    }
    
    // temp_Codemon.set_Total_Skills(currentCodemonsTotalSkills);
    cout << "Codemon Total Skills " << temp_Codemon.get_Total_Skills() << endl;  
    update_Pocket(temp_Codemon, m_num_Codemon);

    do
    {
      cout << "Do you want to add a new Codemon? (y/n)" << endl;
      cin >> update;
    } while(update != 'y' && update != 'n');
  }

  do
  {
    cout << "Do you want to add a new item? (y/n)" << endl;
    cin >> update;
  } while(update != 'y' && update != 'n');
  
  while (update == 'y' && m_num_Items < max_Items)
  {
    cout << "Name of the item?" << endl;
    cin.ignore();
    getline(cin, itemName);

    cout << "What is the purpose of " << itemName << "?" << endl;
    cin.ignore();
    getline(cin, itemDescription);

    do
    {
      cout << "What is the durration of the item?" << endl;
      cin >> itemDuration;
    } while (itemDuration < infinateDuration);

    do
    {
      cout << "Do you want to add a new item? (y/n)" << endl;
      cin >> update;
    } while(update != 'y' && update != 'n');

    Item tempItem(itemName, itemDescription, itemDuration);
    update_Backpack(tempItem, m_num_Items);
    // cout << "Num Items" << m_num_Items << endl;
  }  
}

void Contestant::print()
{
  cout << "Contestant Name: " << m_name << endl;
  cout << "Number of Codemons owned: " << m_num_Codemon << endl;
  if(m_num_Codemon > low){
    cout << "Pocket List:" << endl;
    for(int i = 0; i < m_num_Codemon; i++)
    {
      cout << "  " << i + 1 << ") " << m_Codemon[i].getName() << endl;
    }
  }
  
  if(m_num_Items > low){
    cout << "Backpack List:" << endl;
    for(int i = 0; i < m_num_Items; i++)
    {
      cout << "  " << i + 1 << ") " << m_backpack[i].getName() << endl;
    }
  }
  cout << endl;
}

void skillLookUp(Contestant contestants[])
{
  char update;
  string findSkill;
  bool found = false;
  do
  {
    cout << "Would you like to look up a skill? (y/n)" << endl;
    cin >> update;
  } while (update != 'y' && update != 'n');


  while (update == 'y')
  {
    found = false;
    cout << "What skill would you like to look up?" << endl;
    cin.ignore();
    getline(cin, findSkill);
    for(int i = 0; i < max_Contestants; i++)
    {
      for(int j = 0; j < max_Codemon; j++)
      {
        for(int k = 0; k < max_Skills; k++)
        {
          if (findSkill == contestants[i].m_Codemon[j].m_skills_Mat[k].m_name)
          {
            cout << "Skill name: " << findSkill << endl;
            cout << "Base damage: " << contestants[i].m_Codemon[j].m_skills_Mat[k].m_damage << endl;
            cout << "Acquired by: " << contestants[i].m_Codemon[j].m_name << " (" << contestants[i].m_name << ")" << endl;
            found = true;
          }
          
        }
      }
    }
    if(found == false){
      cout << "Skill not found" << endl;
    }
    do
    {
      cout << "Would you like to look up a skill? (y/n)" << endl;
      cin >> update;
    } while (update != 'y' && update != 'n');
  }
}

