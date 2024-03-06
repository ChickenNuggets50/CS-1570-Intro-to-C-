// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <9/27/2021>
// File: hw3.cpp
// Purpose: Calculate the cost to heal the Codemon.
#include "hw3.h"
#include <iostream>
#include <cstdlib>
using namespace std;

char explore(int & total_Time, int & time_To_Encounter){
  char rand_Letter;
  time_To_Encounter = 0;
  do
  {
    rand_Letter = (rand() % (Z_Ascii - A_Ascii_plus_one)) + A_Ascii;
    // cout << rand_Letter << endl;
    time_To_Encounter += 1;
  } while (rand_Letter != 'B' && rand_Letter != 'F' && rand_Letter != 'R' && rand_Letter != 'P' && rand_Letter != 'W');
  total_Time += time_To_Encounter;
  return rand_Letter;
}

bool is_Triangular_Num(int num){
  int sum = 0;
  bool t_or_f = false;
  for (int i = 1; sum <= num; i++)
  {
    sum = sum + i;
    if (sum == num)
      t_or_f = true;
  }
  return t_or_f;
}

int triangular_Num(int min, int max){
  int min_Minus_One = min - one;
  int rand_Num;
  do
  {
    rand_Num = (rand() % (max - min_Minus_One)) + min;
  } while (is_Triangular_Num(rand_Num) == false);
  // cout << "Random Trangular Number is: " << rand_Num << endl;
  return rand_Num;
}

bool capture(int left_Arm, int right_Arm){ //Flying
  bool t_or_f = false;
  int total_Arm_Length = left_Arm + right_Arm;
  if(is_Triangular_Num(total_Arm_Length) == true){
    t_or_f = true;
  }
  return t_or_f;
} 

bool capture(){ //Poison
  bool t_or_f = false;
  int rand_Trangular_Num = triangular_Num(poison_Min, poison_Max);
  if(rand_Trangular_Num < poison_Magic_Num){
    t_or_f = true;
  }
  return t_or_f;
} 

bool capture(int & time_To_Encounter){ //Rock
  bool t_or_f = false;
  int rock_Codemon_Num = triangular_Num(rock_Min, rock_Max);
  int student_Num = triangular_Num(rock_Min, rock_Max) * time_To_Encounter;
  // cout << "Rock: " << rock_Codemon_Num << " Student: " << student_Num << endl;
  if (student_Num > rock_Codemon_Num)
  {
    t_or_f = true;
  }
  return t_or_f;
} 

bool capture(bool poison, bool water){ //Bug
  bool t_or_f = false;
  if((poison == true) & (water == true))
  {
    t_or_f = true;
  }
  return t_or_f;
} 

bool capture(int year, int month, int day){ //Water
  bool t_or_f = false;
  int student_Num = (((year * one_hundred) + month) * one_hundred) + day;
  int water_Num = triangular_Num(water_Min, water_Max);
  // cout << student_Num << endl;
  if(student_Num < water_Num)
  {
    t_or_f = true;
  }
  return t_or_f;
} 
