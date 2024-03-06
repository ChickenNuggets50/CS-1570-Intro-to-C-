// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/17/2021>
// File: helper.cpp
// Purpose: Gather input from a file and output it to a file.
#include "helper.h"
#include <iostream>
#include <string>
using namespace std;

void processInputFile(ifstream &in, Entrant person[], const int size){
  for(int i = 0; i < size; i++){
    in >> person[i].fName >> person[i].lName >> person[i].age >> person[i].occupation >> person[i].numberOfCodemon >> person[i].securityLevel;
  }
}

int totalImportantLines(ifstream &in){
  string line;
  int count = 0;
  while(getline(in, line))
  {
    count += one;
  }
  return count;
}

void bubbleSort(Entrant person[], int importantVals)
{
  Entrant temp;
  string temp_First;
  string temp_Last;
  int temp_Age;
  string temp_occupation;
  int temp_Codemon;
  int temp_Security;

  for(int i = 0; i < importantVals; i++) {
    for(int j = i + one; j < importantVals; j++)
    {
      if(person[j].numberOfCodemon < person[i].numberOfCodemon) 
      {
        temp_First = person[i].fName;
        temp_Last = person[i].lName;
        temp_Age = person[i].age;
        temp_occupation = person[i].occupation;
        temp_Codemon = person[i].numberOfCodemon;
        temp_Security = person[i].securityLevel;

        person[i].fName = person[j].fName;
        person[i].lName = person[j].lName;
        person[i].age = person[j].age;
        person[i].occupation = person[j].occupation;
        person[i].numberOfCodemon = person[j].numberOfCodemon;
        person[i].securityLevel = person[j].securityLevel;

        person[j].fName = temp_First;
        person[j].lName = temp_Last;
        person[j].age = temp_Age;
        person[j].occupation = temp_occupation;
        person[j].numberOfCodemon = temp_Codemon;
        person[j].securityLevel = temp_Security;
      }
    }
  }
}

int thirdQuartile(int importantVals){
  int third_Quartile;
  third_Quartile = ((importantVals + one) * three ) / four;
  return third_Quartile;
}

void warnings(ostream & out, Entrant person[], int importantVals, int third_Quartile, int security_Level, Violatiors & violator)
{
  for (int i = 0; i < importantVals; i++)
  {
    if(person[i].age > max_age_of_student && person[i].occupation == "Student"){
      out << person[i];
      out << "WARNING: Classified as Student at age " << person[i].age << endl << endl;
      violator.violators += one;
    }
  }

  for (int i = 0; i < importantVals; i++)
  {
    if(person[i] < security_Level){
      out << person[i];
      out << "WARNING: Entrant with level of " << person[i].securityLevel << " entered a zone of level " << security_Level << endl << endl;
      violator.violators += one;
    }
  }

  for (int i = 0; i < importantVals; i++)
  {
    if(person[i].numberOfCodemon > person[third_Quartile - one].numberOfCodemon){
      out << person[i];
      out << "WARNING: Entrant has too many codemon, entrant has " << person[i].numberOfCodemon << " codemon, the third quartile is " 
      << person[third_Quartile - one].numberOfCodemon << endl << endl;
      violator.violators += one;
    }
  }
  
}

bool operator < (Entrant & violator, int & security_Level){
  bool lessThanSecurityLevel = false;
  if(violator.securityLevel < security_Level){
    lessThanSecurityLevel = true;
  }
  return lessThanSecurityLevel;
}


ostream& operator <<(ostream & out, Entrant & person)
{
  out << "Name: " << person.fName << " " << person.lName << endl;
  out << "Age: " << person.age << endl;
  out << "Occupation: " << person.occupation << endl;
  out << "Number of Codemon Owned: " << person.numberOfCodemon << endl;
  out << "Security: " << person.securityLevel << endl;
  return out;
}

void sortViolators(Violatiors violator[]){
  string temp_Room;
  int temp_violator;
  for(int i = 0; i < total_Files; i++) {
    for(int j = i + one; j < total_Files; j++)
    {
      if(violator[j].violators > violator[i].violators) 
      {
        temp_Room = violator[i].room;
        temp_violator = violator[i].violators;

        violator[i].room = violator[j].room;
        violator[i].violators = violator[j].violators;

        violator[j].room = temp_Room;
        violator[j].violators = temp_violator;
      }
    }
  }

}

void printViolaions(Violatiors violator[]){
  cout << endl << "Summary" << endl << endl;
  for(int i = 0; i < total_Files; i++) 
  {
    if(violator[i].room == Library)
    {
      cout << "The Library: " << violator[i].violators << " potential violators" << endl;
    }
    else if(violator[i].room == Training)
    {
      cout << "Training Room: " << violator[i].violators << " potential violators" << endl;
    }
    else if(violator[i].room == Faculty)
    {
      cout << "Faculty Lounge: " << violator[i].violators << " potential violators" << endl;
    }
    else if(violator[i].room == Chamber)
    {
      cout << "The Chamber of Ekans: " << violator[i].violators << " potential violators" << endl;
    }
  }
}