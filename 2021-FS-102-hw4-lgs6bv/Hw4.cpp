// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/16/2021>
// File: Hw4.cpp
// Purpose: Gather input from the user and determine if there are any potential team picket affiliations.
#include "helper.h"
#include <iostream>
using namespace std;
Entrant e0, e1, e2, e3, e4;
Entrant Entrant_Array[SAMPLE_SIZE];

int main()
{
  char more_entrants;
  bool spycraft;
  Entrant_Array[index0] = e0;
  Entrant_Array[index1] = e1;
  Entrant_Array[index2] = e2;
  Entrant_Array[index3] = e3;
  Entrant_Array[index4] = e4;
  cout << "---Now booting up Codémon Academy security system---" << endl;
  do
  {
    spycraft = false;
    for(int i = 0; i < SAMPLE_SIZE; i++)
    {
      do
      {
        cout << endl << "Please input name, age, occupation, and the number of Codémon for entrant " << i + 1 << ":" << endl;
        cin >> Entrant_Array[i].fName >> Entrant_Array[i].lName >> Entrant_Array[i].age >> Entrant_Array[i].occupation >> Entrant_Array[i].numberOfCodemon;
      } while ((Entrant_Array[i].age < min_Age || Entrant_Array[i].age > one_hundred) || (Entrant_Array[i].occupation != stud && Entrant_Array[i].occupation != fac &&
       Entrant_Array[i].occupation != staff) || (Entrant_Array[i].numberOfCodemon < zero || Entrant_Array[i].numberOfCodemon > one_hundred));
      
      
    }

    for(int i = 0; i < SAMPLE_SIZE; i++)
    {
      if((Entrant_Array[i].age >= max_Age_Student && Entrant_Array[i].occupation == stud) || Entrant_Array[i].numberOfCodemon > max_Codemon)
      {
        cout << endl << "The following entrants have been denied entry due to suspicions of Team Picket affiliations:" << endl;
        i = SAMPLE_SIZE;
        spycraft = true;

      }
    }

    if(spycraft == false)
    {
      cout << endl << "None of the entrants were suspected of spycraft, all were allowed to enter" << endl;
    }

    for(int i = 0; i < SAMPLE_SIZE; i++)
    {
      if(Entrant_Array[i].age >= max_Age_Student && Entrant_Array[i].occupation == stud)
      {
        printEntrant(Entrant_Array[i]);
      }
      else if(Entrant_Array[i].numberOfCodemon > max_Codemon)
      {
        printEntrant(Entrant_Array[i]);
      }
    }
    do
    {
      cout << endl << "Are there more people waiting to enter the academy?" << endl;
      cin >> more_entrants;
    } while (more_entrants != capY && more_entrants != lowy && more_entrants != capN && more_entrants != lown);
    
  } while(more_entrants == capY || more_entrants == lowy);

  cout << endl << "Goodbye" << endl;
  return 0;
}