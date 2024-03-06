// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <9/27/2021>
// File: main.cpp
// Purpose: Calculate the cost to heal the Codemon.
#include "hw3.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
  srand(1100);
  char codemon_Type;
  char prev_Codemon_Type = letter_D;
  bool poison_Captured = false;
  bool water_Captured = false;
  int totalTime = 0;
  int student_Left_Arm;
  int student_Right_Arm;
  int time_To_Encounter;
  int birth_Year;
  int birth_Month;
  int birth_Day;
  int total_Arm_Length;
  int captured_Codemon = 0;
  int flying_Captures = 0;
  int poison_Captures = 0;
  int rock_Captures = 0;
  int bug_Captures = 0;
  int water_Captures = 0;
  int dragon_Captures = 0;
  int highest_capture = 0;
  char highest_capture_letter;
  // int rand_Triangular_Num;
  string student_First_Name;
  string student_Last_Name;
  string student_Rank;
  string emotionalMsg;
  bool cap = false;
  

  cout << "Welcome Challenger!" << endl;
  cout << "Lets gather some info from you before you start." << endl;
  cout << "What is your first name? ";
  cin >> student_First_Name;
  cout << "Last Name? ";
  cin >> student_Last_Name;
  cout << "How long is your left arm (in inches, >0 and <= 1000): ";
  cin >> student_Left_Arm;
  cout << "How long is your right arm (in inches, >0 and <= 1000): ";
  cin >> student_Right_Arm;
  cout << "What is your birth year? ";
  cin >> birth_Year;
  cout << "What is your birth month? (1-12) ";
  cin >> birth_Month;
  cout << "What is your birth day? (1-31) ";
  cin >> birth_Day;

  do
  {
    codemon_Type = explore(totalTime, time_To_Encounter);
    if(codemon_Type == prev_Codemon_Type)
    {
      codemon_Type = letter_D;
      prev_Codemon_Type = letter_D;
    }
    else
    {
      prev_Codemon_Type = codemon_Type;
    }
    // cout << "Total Time: " << totalTime << endl << "Codemon Type: " << codemon_Type << endl;
  
    switch (codemon_Type)
    {
      case letter_F:
        total_Arm_Length = student_Left_Arm + student_Right_Arm;
        cap = capture(student_Left_Arm, student_Right_Arm);
        cout << student_First_Name << " Encountered a Flying Codemon in " << time_To_Encounter << " time units." << endl;
        if(cap == true){
          cout << "Your total arm lengths (" << total_Arm_Length << ") is a triangular number!" << endl;
          cout << "The capture was successful!" << endl << endl;
          captured_Codemon += one;
          flying_Captures += one;
          // cout << "Captured Codemon " << captured_Codemon << endl;
        } 
        else{
          cout << "Your total arm lengths (" << total_Arm_Length << ") is not a triangular number." << endl ;
          cout << "The capture was unsuccessful!" << endl;
          cout << "Captured Codemon " << captured_Codemon << endl << endl;
        }
        break;
      case letter_P:
        cap = capture();
        cout << student_First_Name << " Encountered a Poison Codemon in " << time_To_Encounter << " time units." << endl;
        if (cap == true)
        {
          cout << "The random Trangular number is less than the magic number (43)!" << endl;
          cout << "The capture was successful!" << endl << endl;
          captured_Codemon += one;
          poison_Captured = true;
          poison_Captures += one;
        }
        else
        {
          cout << "The random Trangular number is not less than the magic number (43)!" << endl;
          cout << "The capture was unsuccessful!" << endl << endl;
        }
        break;
      case letter_R:
        cap = capture(time_To_Encounter);
        cout << student_First_Name << " Encountered a Rock Codemon in " << time_To_Encounter << " time units." << endl;
        if(cap == true)
        {
          cout << "Your number beat Rocky's triangular number!" << endl;
          cout << "The capture was successful!" << endl << endl;
          captured_Codemon += one;
          rock_Captures += one;
        }
        else
        {
          cout << "Your number did not beat Rocky's triangular number!" << endl;
          cout << "The capture was unsuccessful!" << endl << endl;
        }
        break;
      case letter_B:
        cap = capture(poison_Captured, water_Captured);
        cout << student_First_Name << " Encountered a Bug Codemon in " << time_To_Encounter << " time units." << endl;
        if(cap == true)
        {
          cout << "You had the pesticide!" << endl;
          cout << "The capture was successful!" << endl << endl;
          captured_Codemon += one;
          bug_Captures += one;
        }
        else
        {
          cout << "You did not have the pesticide!" << endl;
          cout << "The capture was unsuccessful!" << endl << endl;
        }
        
        break;
      case letter_W:
        cap = capture(birth_Year, birth_Month, birth_Day);
        cout << student_First_Name << " Encountered a Water Codemon in " << time_To_Encounter << " time units." << endl;
        if(cap == true)
        {
          cout << "Your number was less than H2O's Number!" << endl;
          cout << "The capture was successful!" << endl << endl;
          captured_Codemon += one;
          water_Captured = true;
          water_Captures += one;
        }
        else
        {
          cout << "Your number was not less than H2O's Number!" << endl;
          cout << "The capture was unsuccessful!" << endl << endl;
        }
        break;

      case letter_D:
        cout << student_First_Name << " Encountered a Dragon Codemon in " << time_To_Encounter << " time units." << endl;
        cout << "The capture was successful!" << endl << endl;
        captured_Codemon += one;
        dragon_Captures += one;
        break;

    }
  } while (captured_Codemon != max_Captures);
  
  cout << endl << "You passed the test!" << endl;
  if (totalTime <= fifty)
  {
    student_Rank = "Super";
    cout << "What's on your mind right now?" << endl;
    cin.ignore(); 
    getline(cin, emotionalMsg); 
    testSummary(student_First_Name, student_Last_Name, student_Rank, emotionalMsg, dragon_Captures);
  }
  else if(totalTime <= two_hundred) 
  {
    student_Rank = "Acceptable";
    if(flying_Captures > highest_capture)
    {
      highest_capture = flying_Captures;
      highest_capture_letter = letter_F;
    }
    if(poison_Captures > highest_capture)
    {
      highest_capture = poison_Captures;
      highest_capture_letter = letter_P;
    }
    if(rock_Captures > highest_capture)
    {
      highest_capture = rock_Captures;
      highest_capture_letter = letter_R;
    }
    if(bug_Captures > highest_capture)
    {
      highest_capture = bug_Captures;
      highest_capture_letter = letter_B;
    }
    if(water_Captures > highest_capture)
    {
      highest_capture = water_Captures;
      highest_capture_letter = letter_W;
    }
    if(dragon_Captures > highest_capture)
    {
      highest_capture = dragon_Captures;
      highest_capture_letter = letter_D;
    }
    testSummary(student_First_Name, student_Last_Name, student_Rank, highest_capture_letter);
  }
  else
  {
    student_Rank = "Diminishing";
    testSummary(student_First_Name, student_Last_Name, student_Rank, totalTime);
  }
  return 0;
}
