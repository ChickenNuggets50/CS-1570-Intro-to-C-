// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <9/14/2021>
// File: hw2.cpp
// Purpose: Calculate the cost of tuition for accepted students.
#include <iostream>
using namespace std;
int wins;
int codemon;
float income;
char parents;
float donations;
float score;
bool admitted;
float donationProb;
float tuition;
char multipleApplicants;
bool isAdmitted(int wins, int codemon, float donationProb);
bool isAdmitted(int wins, float donationProb);
float calculateDonationProbability(char parents, float income, float donations);
float calculateTuition();
int main()
{
  cout.setf(ios::fixed); //formats output to have two decimal places
  cout.setf(ios::showpoint);
  cout.precision(2);
  cout << "Welcome to the Codemon Academy admission program";
  do
  {
    do
    {
      cout << endl << "How many tournaments has the applicant won? (0-50) "; //ensures the user inputs a number 0 to 50
      cin >> wins;
    } while (wins <= 0 || wins >= 50);
    do
    {
      cout << endl << "How many codemon does the applicant own? (0-30) (Or -1 if the applicant prefers not to say) "; //ensures the user inputs a number -1 to 30
      cin >> codemon;
    } while (codemon <= -1 || codemon >= 30); 
    cout << endl << "What is your household income? ";
    cin >> income;
    if (income >= 30000) //if the user has an income greater than 30000 then they can continue otherwise they are denied immediately
    {
      do
      {
        cout << endl << "Were the applicant's parents in the hit 90's TV Show “Brimful Residence”? (y/n) "; //ensures the user inputs a y or n
        cin >> parents;
      } while (parents != 'y' && parents != 'n');
      do
      {
        cout << endl << "How much money has this applicant paid off to the athletic director? (Must be greater than 99) "; //ensures the user inputs a number greater that 99
        cin >> donations;
      } while (donations < 100);
      donationProb = calculateDonationProbability(parents, income, donations); //sets donationProb equal to the outcome of calculateDonationProbability
      if (codemon > 0) //if the user specified their codemon it calls isAdmitted with three variables then calls calculate tuition if their score is high enough
      {
        admitted = isAdmitted(wins, codemon, donationProb);
        if (admitted == true)
        {
          tuition = calculateTuition();
        }
      }
      else
      {
        admitted = isAdmitted(wins, donationProb); //if the user chose -1 then it will call isAdmitted with only two variables then calls calculate tuition if their score is high enough
        if (admitted == true)
        {
          tuition = calculateTuition();
        }
      }
      cout << endl << "The student will pay: " << tuition << endl;
      
    } else
    {
      cout << endl << "This student will not be admitted." << endl; //student will not be admitted if their income is less than 30000
    }
    do
    {
      cout << endl << "Is there another applicant? (y/n) "; 
      cin >> multipleApplicants;
    } while (multipleApplicants != 'y' && multipleApplicants != 'n'); //loops if the user selects anything other than y or n
  } while (multipleApplicants == 'y'); //loops back to the beginning if there is another user
  return 0;
}

bool isAdmitted(int applicant_wins, int applicant_codemon, float donationProb)
{
  score = 0; //resets score
  score += 10 * applicant_wins; //calculates the score of the applicant
  score += 2 * applicant_codemon;
  score += score * donationProb;
  cout << endl << "The student has been accepted with a score of: " << score; //prints out the score of the inputed applicant
  if (score >= 30){ //if the score is greater than thirty they are admitted and the function returns true else they are not and the function returns false
    return true;
  } 
  return false;
}

bool isAdmitted(int applicant_wins, float donationProb)
{
  score = 0; //resets score
  score += 10 * applicant_wins; //calculates the score of the applicant
  score += score * donationProb;
  cout << "The student has been accepted with a score of: " << score << endl; //prints out the score of the inputed applicant
  if (score >= 30){ //if the score is greater than thirty they are admitted and the function returns true else they are not and the function returns false
    return true;
  } 
  return false;
}

float calculateDonationProbability(char applicants_parents, float applicants_income, float applicants_donations)
{
  float chance = .01; //all applicants start with a .01 chance
  if (applicants_parents == 'y') //if the applicant fits the criteria it increases their chance 
  {
    chance += .10;
  }
  if (applicants_income > 200000)
  {
    chance += .10;
  }
  else if (applicants_income > 500000)
  {
    chance += .20;
  }
  if (applicants_donations >= 10000)
  {
    chance += .05;
  }
  else if (applicants_donations >= 100000)
  {
    chance += .10;
  }
  if (applicants_income < 200000)
  {
    applicants_parents = 'n'; //if the applicants parents are not considered true cast members it resets the variables to n
    parents = 'n';
  }
  return chance; //returns the chance of the user donating
}

float calculateTuition()
{
  srand(8); //set the random seed to 8
  float tuition = (rand()%(1000000-50000+1)) + 50000; //sets the bounds for the random tuition
  cout << endl << "Starting Tuition: " << tuition; 
  float scholarships = 0; //resets the scholarship 
  scholarships += score * 100; //increases the scolarship 
  scholarships += wins * 5000;
  if (parents == 'y') //if the parents were true cast members they get the scholarship
  {
    scholarships += 20000;
  }
  cout << endl << "Scholarships: " << scholarships;
  if (income >= 100000) //if the users income is greater than or equal to 100000 then it divides by 100000 and multiplies by 20000 to increase the tuition
  {
    int tuition_increase = income / 100000;
    cout << endl << "Tuition Incrase: " << tuition_increase * 20000;
    tuition += tuition_increase * 20000;
  }
  tuition -= scholarships; //gets the tuition with scholarships
  if (tuition < 0) //if the applicant has a tuition less than 0 it becomes 3.5
  {
    tuition = 3.50;
  }
  return tuition; //returns tuition
}