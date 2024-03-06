// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <9/27/2021>
// File: hw3.h
// Purpose: Calculate the cost to heal the Codemon.

#ifndef HW3_H
#define HW3_H

#include <iostream> 
#include <cstdlib>
#include <string>
using namespace std;

const int A_Ascii = 65;
const int Z_Ascii = 90;
const int A_Ascii_plus_one = 66;
const int poison_Magic_Num = 43;
const int poison_Min = 1;
const int poison_Max = 100;
const int rock_Min = 56;
const int rock_Max = 4586;
const int water_Min = 10000000;
const int water_Max = 20219999;
const int one = 1;
const int max_Captures = 20; 
const int one_hundred = 100;
const int two_hundred = 200;
const int fifty = 50;
const char letter_F = 'F';
const char letter_P = 'P';
const char letter_R = 'R';
const char letter_B = 'B';
const char letter_W = 'W';
const char letter_D = 'D';
const string the_word_Super = "Super";
const string the_word_Acceptable = "Acceptable";
const string the_word_Diminishing = "Diminishing";

// Increments time and gets a random letter
// N/A
//Increases time. Returns the Random letter
char explore(int & time, int & time_To_Encounter);

// Creates a random num and calls is_Triangular_Num
// N/A
//Returns a random triangular num
int triangular_Num(int min, int max);

// Gets a random Num and decides if it is triangula
// N/A
//Returns if the num is true or false
bool is_Triangular_Num(int num);

// Adds the arms lengths together then calls is_Triangular_Num
// N/A
//Returns true if the arm length is a triangular num and false if not
bool capture(int left_Arm, int right_Arm); //Flying

// Calls rand_Triangular_Num and checks if that num is less than 43
// N/A
//Returns true if the random num is less than 43 and false if not
bool capture(); //Poison

// Calls rand_Triangular_Num twice and multiplies students num * the time it took to encounter
// N/A
//Returns true if students num * the time it took to encounter is larger and false if not
bool capture(int & time_To_Encounter); //Rock

// Checks if a water and poison codemon have been caught yet
// N/A
//Returns true if they have both been caught and false if not
bool capture(bool poison, bool water); //Bug

// Sets student num to birth year followed by birth month followed by birthday then calls rand_Triangular_Num to set the water codemons num
// N/A
//Returns true if the random num is less than the water codemons and false if not
bool capture(int year, int month, int day); //Water

// Prints the info
// The type to fill the template parameter must have the insertion operator defined for it.
//Returns nothing. Prints the messages of how the student did.
template <typename T>
void testSummary(string first_Name, string last_Name, string student_ranking, T ranking_Based_Info, int number_Of_Dragons_Rewarded = 0){
  if(student_ranking == the_word_Super){
    number_Of_Dragons_Rewarded += one;
    cout << first_Name << " " << last_Name << "'s Test Ranking: " << student_ranking << endl;
    cout << first_Name << "'s Emotional Message: " << ranking_Based_Info << endl;
    cout << first_Name << " will be rewarded with " << number_Of_Dragons_Rewarded << " Dragon Codemons!" << endl;
  }
  else if (student_ranking == the_word_Acceptable)
  {
    cout << first_Name << " " << last_Name << "'s Test Ranking: " << student_ranking << endl;
    cout << first_Name << "'s Favorite Letter: " << ranking_Based_Info << endl;
    cout << first_Name << " will be rewarded with " << number_Of_Dragons_Rewarded << " Dragon Codemons!" << endl;
  }
  else
  {
    cout << first_Name << " " << last_Name << "'s Test Ranking: " << student_ranking << endl;
    cout << first_Name << "'s Total Exploration Time: " << ranking_Based_Info << endl;
    cout << first_Name << " will be rewarded with " << number_Of_Dragons_Rewarded << " Dragon Codemons!" << endl;
  }
  
}


#endif