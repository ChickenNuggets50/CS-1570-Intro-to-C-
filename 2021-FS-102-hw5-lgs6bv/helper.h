// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/17/2021>
// File: helper.h
// Purpose: Gather input from a file and output it to a file.
#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <fstream>

using namespace std;

const int SAMPLE_SIZE = 100;
const int library_security = 1;
const int training_Room_Security = 2;
const int faculty_Lounge_Security = 3;
const int chamber_Security = 4;
const int total_Files = 4;
const int zero = 0;
const int one = 1;
const int two = 2;
const int three = 3;
const int four = 4;
const int max_age_of_student = 30;
const string Library = "Library";
const string Training = "Training";
const string Faculty = "Faculty";
const string Chamber = "Chamber";

const string libraryInputFile = "the_library.log";
const string libraryOutputFile = "the_library_warnings.txt";

const string trainingRoomInputFile = "training_room.log";
const string trainingRoomOutputFile = "training_room_warnings.txt";

const string facultyLoungeInputFile = "faculty_lounge.log";
const string facultyLoungeOutputFile = "faculty_lounge_warnings.txt";

const string chamberInputFile = "the_chamber_of_ekans.log";
const string chamberOutputFile = "the_chamber_of_ekans_warnings.txt";

// Struct Entrant with three strings (fName, lName, occupation) and three ints (age, numberOfCodemon, securityLevel)
struct Entrant
{
  string fName;
  string lName;
  int age;
  string occupation;
  int numberOfCodemon;
  int securityLevel;
};

// Struct Entrant with one string (room) and one ints (violators)
struct Violatiors
{
  string room;
  int violators;
};

// Sets the values from the input file.
// Input file must be open.
// Gathers the input and sets it. Returns nothing.
void processInputFile(ifstream &in, Entrant person[], const int size);

// Get a line for each line in the file.
// Input file must be open.
// Get a line for each line in the file and increases a count. Returns count.
int totalImportantLines(ifstream &in);

// Sorts the array based on codemon.
// N/A
// Sorts the array based on codemon. Returns nothing.
void bubbleSort(Entrant person[], int importantVals);

// Computes the third quartile.
// N/A
// Computes the third quartile. Returns Nothing.
int thirdQuartile(int importantVals);

// Checks entries for violations.
// N/A
// Checks entries for violations and increments the violators in their respective arrays. Returns nothing.
void warnings(ostream & out, Entrant person[], int importantVals, int third_Quartile, int security_Level, Violatiors & violator);

// Overloads the less than operator.
// N/A
// Returns a bool.
bool operator < (Entrant & violator, int & security_Level);

// Outputs the data.
// Output file must be open.
// Outputs the data to a .txt file. Returns out.
ostream& operator <<(ostream & out, Entrant & person);

// Sorts the array based on violators.
// N/A
// Sorts the array based on violatiors using bubble sort. Returns nothing.
void sortViolators(Violatiors violator[]);

// Prints the violators.
// N/A
// Prints the violators. Returns nothing.
void printViolaions(Violatiors violator[]);

#endif