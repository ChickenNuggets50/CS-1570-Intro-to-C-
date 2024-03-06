// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <9/8/2021>
// File: hw1.cpp
// Purpose: Calculate the cost to heal the Codemon.
#include <iostream>
  using namespace std;
  int main(){
  int region = 9;  //Declaration of every variable that is used in the code
  char insurance;
  float insuranceRate = 101;
  int numCodeballs = 7;
  int ballType = 0;
  int codeBall = 0;
  int goodBall = 0;
  int extremeBall = 0;
  int budgetBall = 0;
  int boujeeBall = 0;
  const float konta = 1.00;
  const float jahta = 0.80;
  const float hainn = 0.95;
  const float sennah = 1.15;
  const float ynavo = 1.50;
  const float kolas = 1.12;
  const float olalo = 0.75;
  const float golor = 2.50;
  float price = 0;
  float priceWithTax = 0;
  float priceWithInsurrance = 0;
  float finalPrice = 0;
  char coachesLeft = 'y';
  cout << endl << "Welcome to the Faboulous Codecenter Price Gourger Calculater" << endl;
  while (region < 1 || region > 8) {
    cout << endl << "What region are you using this program from?" << endl; //prints out all of the regions so the user can easily pick one
    cout << "1. Konta" << endl;
    cout << "2. Jahta" << endl;
    cout << "3. Hainn" << endl;
    cout << "4. Sennah" << endl;
    cout << "5. Ynavo" << endl;
    cout << "6. Kolas" << endl;
    cout << "7. Olalo" << endl;
    cout << "8. Golor" << endl;
    cout << "Region: ";
    cin >> region; //collects the users input for the region
  }
  while (coachesLeft == 'y') { //loops until the users says there are no more coaches left
    insurance = 'k'; //resets all of the variables for when the loop wraps around 
    insuranceRate = 101;
    numCodeballs = 7;
    ballType = 0;
    codeBall = 0;
    goodBall = 0;
    extremeBall = 0;
    budgetBall = 0;
    boujeeBall = 0;
    price = 0;
    priceWithTax = 0;
    priceWithInsurrance = 0;
    finalPrice = 0;
    while(insurance != 'y' && insurance != 'n' ) { //ensures the user can only input y or n and will ask the user again if wrong input is given
      cout << endl << "Does the coach have insurance (y/n)? ";
      cin >> insurance;
    }
    if (insurance == 'y') { // if the coach has insurance then it will ask the user for a number between 1 and 100 and will ask until the input is given
      while (insuranceRate < 1 || insuranceRate > 100) { 
        cout << endl << "What is this coach's insurance rate (1-100)? ";
        cin >> insuranceRate; 
      }
    } else { //if the coach does not have insurance the rate will automatically be one
      insuranceRate = 1;
    }
    while (numCodeballs < 1 || numCodeballs > 6) { //requires the user to input number of codeballs and must be 1 to 6
      cout << endl << "How many codeballs does this coach need healed (1-6)? ";
      cin >> numCodeballs;
    }
    for (int i = 1; i <= numCodeballs; i++) { //loops through the number of codeballs
      ballType = 0; //resets ball type 
      while (ballType < 1 || ballType > 5) { //requires the user to enter a ball type 1 to 5 else it will prompt the user for a valid ball type
        cout << endl << "Which ball?" << endl;
        cout << "1. Code Ball" << endl;
        cout << "2. Good Ball" << endl;
        cout << "3. Extreme Ball" << endl;
        cout << "4. Budget Ball" << endl;
        cout << "5. Boujee Ball" << endl;
        cout << "Ball Type: ";
        cin >> ballType;
        if (ballType < 1 || ballType > 5) {
          cout << endl << "Please enter a valid ball type" << endl;
        }
      }
      if (ballType == 1) { //adds 1 to whichever ball the user entered
        codeBall += 1;
      } else if (ballType == 2) {
          goodBall += 1;
      } else if (ballType == 3) {
          extremeBall += 1;
      } else if (ballType == 4) {
          budgetBall += 1;
      } else if (ballType == 5) {
          boujeeBall += 1;
      }
      if ((region == 1 || region == 2 || region == 5 || region == 7) && (budgetBall > 0 && boujeeBall > 0)) { //if the coach has a boujee and budget ball and is in a region that starts with o or a it ends here
        cout << endl << "Authorities have been notified and the client will be arrested shortly" << endl; // and the cost is never calculated it just states that the client will be arrested
        i = numCodeballs + 1;
      }
    }
    if ((region != 1 && region != 2 && region != 5 && region != 7) || (budgetBall == 0 || boujeeBall == 0)) { //if the coach is not breaking the law it will calculate their cost
//    cout << endl << "CodeBalls: " << codeBall << endl; // test cases to ensure the program was functioning correctly
//    cout << "GoodBalls: " << goodBall << endl;
//    cout << "ExtremeBalls: " << extremeBall << endl;
//    cout << "BudgetBalls: " << budgetBall << endl;
//    cout << "BoujeeBalls: " << boujeeBall << endl;  
      price = codeBall * 90 + goodBall * 115 + extremeBall * 130 + budgetBall * 50 + boujeeBall * 350; //calculates the price of all the balls the coach is healing
//    cout << endl << "Price: " << price << endl;
      if (region == 1) { //multiplies the cost of the balls times the regions tax to get the price with tax
        priceWithTax = price * konta;
      } else if (region == 2) {
          priceWithTax = price * jahta;
      } else if (region == 3) {
          priceWithTax = price * hainn;
      } else if (region == 4) {
          priceWithTax = price * sennah;
      } else if (region == 5) {
          priceWithTax = price * ynavo;
      } else if (region == 6) {
          priceWithTax = price * kolas;
      } else if (region == 7) {
          priceWithTax = price * olalo;
      } else if (region == 8) {
          priceWithTax = price * golor;
      }
//    cout << endl << "Price with Tax: " << priceWithTax << endl; // test case to ensure the price with tax was correct
      if (insurance == 'y') { //if the coach has insurance it will divide the price with tax by the coaches insurance rate
        priceWithInsurrance = priceWithTax / insuranceRate; 
//      cout << endl << "Price With Insurance: " << priceWithInsurrance << endl;
      }
      finalPrice = priceWithInsurrance * 11 / 17 + 3.62; //converts the dollar value to the ampersand value
      cout.setf(ios::fixed); //formats output to have two decimal places
      cout.setf(ios::showpoint);
      cout.precision(2);
      cout << endl << "Total Cost: &" << finalPrice << endl; //prints the total cost
    }
    cout << endl << "Are there any coaches left (y/n)? "; //gets input from the user if there are any more coaches
    cin >> coachesLeft;
      while (coachesLeft != 'y' && coachesLeft != 'n') { //ensures the user inputs y or n else it asks until they give a y or n
        cout << endl << "Are there any coaches left (y/n)? ";
        cin >> coachesLeft;
      }
  }
  cout << endl << "Good Bye!" << endl; //says good bye and the program ends
 return 0;
}
