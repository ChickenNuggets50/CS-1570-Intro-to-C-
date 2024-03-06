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
#include <cstdlib>
using namespace std;

Contestant::Contestant()
{
  cout << "What's your name, contestant?" << endl;
  getline(cin, m_name);
  m_num_Codemon = low;
  m_volume = rand() % max_loud;
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
  
  if(update == 'y' && m_num_Codemon == max_Codemon)
  {
    cout << "Your pocket is full " << m_name << "!" << endl;
  }

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
    if(update == 'y' && m_num_Codemon == max_Codemon)
      {
        cout << "Your pocket is full " << m_name << "!" << endl;
      }
  }

  do
  {
    cout << "Do you want to add a new item? (y/n)" << endl;
    cin >> update;
  } while(update != 'y' && update != 'n');
  
  if(update == 'y' && m_num_Items == max_Items)
  {
    cout << "Your backpack is full " << m_name << "!" << endl;
  }
  
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
    if(update == 'y' && m_num_Items == max_Items)
    {
      cout << "Your backpack is full " << m_name << "!" << endl;
    }
  }  
  
}

void Contestant::print()
{
  cout << "Contestant Name: " << m_name << endl;
  cout << "Number of Codemons owned: " << m_num_Codemon << endl;
  cout << "Volume: " << m_volume << endl;
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

void Contestant::operator +=(const Codemon codemon)
{
  int temp = 10000;
  int indexoflowestCodemon;
  if(m_num_Codemon < max_Codemon){
    update_Pocket(codemon, m_num_Codemon);
    cout << codemon.getName() << " was added to " << m_name << "'s pocket!" << endl;
  }
  else
  {
    for(int i = 0; i < max_Codemon; i++)
    {
      if(m_Codemon[i].get_Level() < temp)
      {
        temp = m_Codemon[i].get_Level();
        indexoflowestCodemon = i;
      }
    }
    m_Codemon[indexoflowestCodemon] = codemon;
    cout << codemon.getName() << " was added to " << m_name << "'s pocket!" << endl;
  }
}

void Contestant::operator +(const Codemon codemon)
{
  int temp = 10000;
  int indexoflowestCodemon;
  if(m_num_Codemon < max_Codemon){
    update_Pocket(codemon, m_num_Codemon);
    cout << codemon.getName() << " was added to " << m_name << "'s pocket!" << endl;
  }
  else
  {
    for(int i = 0; i < max_Codemon; i++)
    {
      if(m_Codemon[i].get_Level() < temp)
      {
        temp = m_Codemon[i].get_Level();
        indexoflowestCodemon = i;
      }
    }
    m_Codemon[indexoflowestCodemon] = codemon;
    cout << codemon.getName() << " was added to " << m_name << "'s pocket!" << endl;
  }
}

void Contestant::operator -(const Codemon codemon)
{
  bool codemonExists = false;
  int indexToRemove = 0;

  for(int i = 0; i < m_num_Codemon; i++)
  {
    if(m_Codemon[i].getName() == codemon.getName())
    {
      codemonExists = true;
      indexToRemove = i;
      i = m_num_Codemon;
    }
  }

  if(codemonExists == true)
  {
    for(int i = indexToRemove; i < m_num_Codemon - 1; i++)
    {
      m_Codemon[i] = m_Codemon[i + 1];
    }
    m_num_Codemon--;
    cout << codemon.getName() << " was removed from " << m_name << "'s pocket!" << endl;
  }
  else
  {
    cout << codemon.getName() << " does not exist in " << m_name << "'s pocket so it could not be removed." << endl;
  }
}

void Contestant::operator -=(const Codemon codemon)
{
  bool codemonExists = false;
  int indexToRemove = 0;

  for(int i = 0; i < m_num_Codemon; i++)
  {
    if(m_Codemon[i].getName() == codemon.getName())
    {
      codemonExists = true;
      indexToRemove = i;
      i = m_num_Codemon;
    }
  }

  if(codemonExists == true)
  {
    for(int i = indexToRemove; i < m_num_Codemon - 1; i++)
    {
      m_Codemon[i] = m_Codemon[i + 1];
    }
    m_num_Codemon--;
    cout << codemon.getName() << " was removed from " << m_name << "'s pocket!" << endl;
  }
  else
  {
    cout << codemon.getName() << " does not exist in " << m_name << "'s pocket so it could not be removed." << endl;
  }
}

void Contestant::operator +=(const Item item)
{
  if(m_num_Items < max_Items){
    update_Backpack(item, m_num_Items);
    cout << item.getName() << " was added to " << m_name << "'s backpack!" << endl;
  }
  else
  {
    cout << m_name << "'s backpack was full so " << item.getName() << " could not be added." << endl;
  }
}

void Contestant::operator +(const Item item)
{
  if(m_num_Items < max_Items){
    update_Backpack(item, m_num_Items);
    cout << item.getName() << " was added to " << m_name << "'s backpack!" << endl;
  }
  else
  {
    cout << m_name << "'s backpack was full so " << item.getName() << " could not be added." << endl;
  }
}

void Contestant::operator -(const Item item)
{
  bool itemExists = false;
  int indexToRemove = 0;

  for(int i = 0; i < m_num_Items; i++)
  {
    if(m_backpack[i].getName() == item.getName())
    {
      itemExists = true;
      indexToRemove = i;
      i = m_num_Items;
    }
  }

  if(itemExists == true)
  {
    for(int i = indexToRemove; i < m_num_Items - 1; i++)
    {
      m_backpack[i] = m_backpack[i + 1];
    }
    m_num_Items--;
    cout << item.getName() << " was removed from " << m_name << "'s backpack!" << endl;
  }
  else
  {
    cout << item.getName() << " does not exist in " << m_name << "'s backpack so it could not be removed." << endl;
  }
}

void Contestant::operator -=(const Item item)
{
  bool itemExists = false;
  int indexToRemove = 0;

  for(int i = 0; i < m_num_Items; i++)
  {
    if(m_backpack[i].getName() == item.getName())
    {
      itemExists = true;
      indexToRemove = i;
      i = m_num_Items;
    }
  }

  if(itemExists == true)
  {
    for(int i = indexToRemove; i < m_num_Items - 1; i++)
    {
      m_backpack[i] = m_backpack[i + 1];
    }
    m_num_Items--;
    cout << item.getName() << " was removed from " << m_name << "'s backpack!" << endl;
  }
  else
  {
    cout << item.getName() << " does not exist in " << m_name << "'s backpack so it could not be removed." << endl;
  }
}

void Contestant::operator ()(const string str)
{
  if(str == heal)
  {
    for (int i = 0; i < m_num_Codemon; i++)
    {
      m_Codemon[i](str);
    }
  }
}

void Contestant::setFirstNonComatose()
{
  for(int i = 0; i < m_num_Codemon; i++)
  {
    if(m_Codemon[i].get_Current_Health() > 0)
    {
      m_index_Of_First_NonComatosed = i;
      i = m_num_Codemon;
    }
  }
}

void Contestant::battle(Contestant& attacker, Contestant& defender, const int attackindex, const int defendindex)
{
  bool successfulattack = true;
  int oneTwo;

  if(attacker.m_Codemon[attackindex].get_weather() == rain)
  {
    oneTwo = rand() % 2;
    if(oneTwo)
    {
      successfulattack = false;
    }
    
  }
  attacker.setrandomskillIndex();
  cout << attacker.m_Codemon[attackindex].getName() << " used " << attacker.m_Codemon[attackindex].getSkillsArray(attacker.m_randomskillIndex).get_Skill_Name() << endl;
  if(successfulattack)
  {
    defender.m_Codemon[defendindex].set_Current_Health(m_Codemon[defendindex].get_Current_Health() - (attacker.m_Codemon[attackindex].getSkillsArray(attacker.m_randomskillIndex).get_damage()
    * attacker.m_Codemon[attackindex].get_damage_Multiplier())); 
    if (attacker.m_Codemon[attackindex].get_weather() == hail)
    {
      defender.m_Codemon[defendindex].set_Current_Health(defender.m_Codemon[defendindex].get_Current_Health() - (defender.m_Codemon[defendindex].get_Current_Health() * (haildamage)));
      attacker.m_Codemon[attackindex].set_Current_Health(attacker.m_Codemon[attackindex].get_Current_Health() - (attacker.m_Codemon[attackindex].get_Current_Health() * (haildamage)));
      if (defender.m_knockedout <= defender.m_num_Codemon - 1)
      {
        defender.m_Codemon[defendindex + 1].set_Current_Health(defender.m_Codemon[defendindex + 1].get_Current_Health() - (defender.m_Codemon[defendindex + 1].get_Current_Health() * (haildamage)));
      }
      if (attacker.m_knockedout <= attacker.m_num_Codemon - 1)
      {
        attacker.m_Codemon[attackindex + 1].set_Current_Health(attacker.m_Codemon[attackindex + 1].get_Current_Health() - (attacker.m_Codemon[attackindex + 1].get_Current_Health() * (haildamage)));
      }
    }
    

    if(defender.m_Codemon[defendindex].get_Current_Health() <= 0)
    {
      defender.m_Codemon[defendindex].set_Current_Health(0);
      defender.m_knockedout++;
    }

    cout << defender.m_Codemon[defendindex].getName() << " took " << attacker.m_Codemon[attackindex].getSkillsArray(attacker.m_randomskillIndex).get_damage() * attacker.m_Codemon[attackindex].get_damage_Multiplier() << " damage!" << endl;
    if (defender.m_Codemon[defendindex].get_Current_Health() <= 0)
    {
      cout << defender.m_Codemon[defendindex].getName() << " was comatosed" << endl;
    }
     
  }
  else
  {
    cout << "The rain caused the attack to miss!" << endl;
  }

}

void Contestant::setrandomskillIndex()
{
  m_randomskillIndex = rand() % m_Codemon[m_index_Of_First_NonComatosed].get_Total_Skills();
}

Contestant Contestant::operator *(Contestant & cont2)
{
  Codemon temp;
  Contestant winner;
  
  m_Codemon[0].randomize_Weather();
  
  for (int i = m_num_Codemon - 1; i > 0; i--)
  {
    int j = rand() % (i + 1);
    temp = m_Codemon[i];
    m_Codemon[i] = m_Codemon[j];
    m_Codemon[j] = temp;
  }
  for (int i = cont2.m_num_Codemon - 1; i > 0; i--)
  {
    int j = rand() % (i + 1); 
    temp = cont2.m_Codemon[i];
    cont2.m_Codemon[i] = cont2.m_Codemon[j];
    cont2.m_Codemon[j] = temp;
  }
  if(cont2.m_volume >= m_volume)
  {
    while (m_knockedout < m_num_Codemon && cont2.m_knockedout < cont2.m_num_Codemon)
    {
      cont2.setFirstNonComatose();
      setFirstNonComatose();
      cout << cont2.m_name << " sends out " << cont2.m_Codemon[cont2.m_index_Of_First_NonComatosed].getName() << endl;
      cout << m_name << " sends out " << m_Codemon[m_index_Of_First_NonComatosed].getName() << endl;
      while(m_Codemon[m_index_Of_First_NonComatosed].get_Current_Health() > 0 && cont2.m_Codemon[cont2.m_index_Of_First_NonComatosed].get_Current_Health() > 0)
      {
        battle(cont2, *this, cont2.m_index_Of_First_NonComatosed, m_index_Of_First_NonComatosed);
        if(m_Codemon[m_index_Of_First_NonComatosed].get_Current_Health() > 0)
        {
          cont2.battle(*this, cont2, m_index_Of_First_NonComatosed, cont2.m_index_Of_First_NonComatosed);
        }
      }
    }

  }
  else
  {
    while (m_knockedout < m_num_Codemon && cont2.m_knockedout < cont2.m_num_Codemon)
    {
      cont2.setFirstNonComatose();
      setFirstNonComatose();
      cout << m_name << " sends out " << m_Codemon[m_index_Of_First_NonComatosed].getName() << endl;
      cout << cont2.m_name << " sends out " << cont2.m_Codemon[cont2.m_index_Of_First_NonComatosed].getName() << endl;
      
      while(m_Codemon[m_index_Of_First_NonComatosed].get_Current_Health() > 0 && cont2.m_Codemon[cont2.m_index_Of_First_NonComatosed].get_Current_Health() > 0)
      {
        cont2.battle(*this, cont2, m_index_Of_First_NonComatosed, cont2.m_index_Of_First_NonComatosed);
        if(m_Codemon[m_index_Of_First_NonComatosed].get_Current_Health() > 0)
        {
          battle(cont2, *this, cont2.m_index_Of_First_NonComatosed, m_index_Of_First_NonComatosed);
        }
      }
    }
  }

  if(m_num_Codemon == m_knockedout)
  {
    winner = cont2;
  }
  else if(cont2.m_num_Codemon == cont2.m_knockedout)
  {
    winner = *this;
  }    
  return winner;
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

