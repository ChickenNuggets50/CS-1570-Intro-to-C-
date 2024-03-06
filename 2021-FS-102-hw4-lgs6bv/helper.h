// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/16/2021>
// File: helper.h
// Purpose: Gather input from the user and determine if there are any potential team picket affiliations.
#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <fstream>

using namespace std;
const int SAMPLE_SIZE = 5;
const int max_Age_Student = 30;
const int max_Codemon = 6;
const char capY = 'Y';
const char lowy = 'y';
const char capN = 'N';
const char lown = 'n';
const string stud = "Student";
const string fac = "Faculty";
const string staff = "Staff";
const int one_hundred = 100;
const int zero = 0;
const int min_Age = 5;
const int index0 = 0;
const int index1 = 1;
const int index2 = 2;
const int index3 = 3;
const int index4 = 4;

// Struct Entrant with three strings (fName, lName, occupation) and two ints (age, numberOfCodemon)
struct Entrant
{
  string fName;
  string lName;
  int age;
  string occupation;
  int numberOfCodemon;
};

// Prints out the violator.
// N/A
// Prints out the violator and their info. Returns nothing.
void printEntrant(Entrant violator);



#endif