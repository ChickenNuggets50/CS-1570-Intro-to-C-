// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/16/2021>
// File: helper.cpp
// Purpose: Gather input from the user and determine if there are any potential team picket affiliations.
#include "helper.h"
#include <iostream>
using namespace std;

void printEntrant(Entrant violator)
{
  cout << endl << "Name: " << violator.fName << " " << violator.lName << endl;
  cout << "Age: " << violator.age << endl;
  cout << "Occupation: " << violator.occupation << endl;
  cout << "Number of Codemon: " << violator.numberOfCodemon << endl;
}