// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: queue.hpp
// Purpose: Create different classes to simulate a game

#include "queue.h"
#include <iostream>
using namespace std;

template <class T>
void Queue<T>::pushBack(const T temp)
{
  if(total_contestants < max_Contestants)
  {
    contestantsInQueue[total_contestants] = temp;
    total_contestants++;
  }
}

template <class T>
T Queue<T>::popfront() 
{
  T temp = contestantsInQueue[0];
  if(total_contestants > 0)
  {
    for(int i = 0; i < total_contestants; i++)
    {
      contestantsInQueue[i] = contestantsInQueue[i + 1];
    }
  }
  return temp;
}

template <class T>
T Queue<T>::peek()
{
  return contestantsInQueue[0];
}