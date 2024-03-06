// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/2/2021>
// File: Game.h
// Purpose: Create a love game
#ifndef GAME_H
#define GAME_H

#include<cmath>
#include <iostream>
using namespace std;

const int MAX_TURNS = 5;
const int MAX_POINTS = 2;
const int ZERO_INDEX = 0;
const int INDEX_ONE = 1;
const string RIVAL = "Rival";
const string LOVE = "Love";
const string PLAYER = "Player";


class Game
{
  public:
    // Default constructor
    Game();
    // Constructor with one int size
    Game(const int size);
    // Deconstructor
    ~Game();
    // Copy Constructor
    Game(const Game & prevGame);
    // calculates the distance between the two points
    // N/A
    // returns the distance
    double getDistance(const int arr[], const int loveArr[]);
    // Places the people in the array
    // N/A
    // Returns Nothing
    void insertPeople(const int rivalCoordinate[], const int playerCoordinate[], const int loveCoordinate[]);
    // Resets the matrix to contain empty strings
    // N/A
    // returns Nothing
    void emptyMat();
    // Populates the Love and Rival arrays with random nums
    // N/A
    // returns nothing
    void randomPopulate();
    // Resets the scores for both players and sets win back to false
    // N/A
    // Returns Nothing
    void reset();
    // prints the results of the game
    // N/A
    // returns nothing
    void results();
    // gets m_win value
    // N/A
    // returns m_win
    bool getwin()const{return m_win;};
    // gets the first val in the coordinate
    // N/A
    // returns the first val as an int
    int getCoordinate1(const int turn, const string person);
    // gets the second val in the coordinate
    // N/A
    // returns the second val as an int
    int getCoordinate2(const int turn, const string person);
    // adds the score of that turn to the total score for that person
    // N/A
    // returns nothing
    void addScore(const double score, const string person);
    //overloads the = operator for games objects
    // N/A
    // returns nothing
    void operator = (Game & GameRHS);
    // prints out the object
    // N/A
    // Returns output 
    friend ostream &operator <<(ostream &output, const Game &game);

  private:
    int m_size;
    string ** m_matrix;
    int m_rivalArr[MAX_TURNS][MAX_POINTS];
    int m_loveArr[MAX_TURNS][MAX_POINTS];
    int m_playerArr[MAX_TURNS][MAX_POINTS];
    double m_playerScore; 
    double m_rivalScore;
    bool m_win = false;
};

#endif