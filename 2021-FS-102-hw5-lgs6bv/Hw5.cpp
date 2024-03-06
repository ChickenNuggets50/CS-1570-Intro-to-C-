// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <10/17/2021>
// File: Hw5.cpp
// Purpose: Gather input from a file and output it to a file.
#include "helper.h"
#include <iostream>
using namespace std;

Entrant library_entrant[SAMPLE_SIZE];
Entrant training_Entrant[SAMPLE_SIZE];
Entrant faculty_Entrant[SAMPLE_SIZE];
Entrant chamber_Entrant[SAMPLE_SIZE];
Violatiors violator[total_Files];

int main()
{
  int third_Quartile;
  int importantLines;
  violator[zero].room = Library;
  violator[one].room = Training;
  violator[two].room = Faculty;
  violator[three].room = Chamber;
  violator[zero].violators = zero;
  violator[one].violators = zero;
  violator[two].violators = zero;
  violator[three].violators = zero;
  ifstream in;
  ofstream out;
  in.open(libraryInputFile);
  processInputFile(in, library_entrant, SAMPLE_SIZE);
  in.close();
  in.open(libraryInputFile);
  importantLines = totalImportantLines(in);
  in.close();
  bubbleSort(library_entrant, importantLines);
  third_Quartile = thirdQuartile(importantLines);
  out.open(libraryOutputFile);
  warnings(out, library_entrant, importantLines, third_Quartile, library_security, violator[0]);
  out.close();

  in.open(trainingRoomInputFile);
  processInputFile(in, training_Entrant, SAMPLE_SIZE);
  in.close();
  in.open(trainingRoomInputFile);
  importantLines = totalImportantLines(in);
  in.close();
  bubbleSort(training_Entrant, importantLines);
  third_Quartile = thirdQuartile(importantLines);
  out.open(trainingRoomOutputFile);
  warnings(out, training_Entrant, importantLines, third_Quartile, training_Room_Security, violator[1]);
  out.close();

  in.open(facultyLoungeInputFile);
  processInputFile(in, faculty_Entrant, SAMPLE_SIZE);
  in.close();
  in.open(facultyLoungeInputFile);
  importantLines = totalImportantLines(in);
  in.close();
  bubbleSort(faculty_Entrant, importantLines);
  third_Quartile = thirdQuartile(importantLines);
  out.open(facultyLoungeOutputFile);
  warnings(out, faculty_Entrant, importantLines, third_Quartile, faculty_Lounge_Security, violator[2]);
  out.close();

  in.open(chamberInputFile);
  processInputFile(in, chamber_Entrant, SAMPLE_SIZE);
  in.close();
  in.open(chamberInputFile);
  importantLines = totalImportantLines(in);
  in.close();
  bubbleSort(chamber_Entrant, importantLines);
  third_Quartile = thirdQuartile(importantLines);
  out.open(chamberOutputFile);
  warnings(out, chamber_Entrant, importantLines, third_Quartile, chamber_Security, violator[3]);
  out.close();

  sortViolators(violator);
  printViolaions(violator);

  return 0;
}