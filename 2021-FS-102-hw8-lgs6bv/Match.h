// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/2/2021>
// File: Match.h
// Purpose: Create a love game
#ifndef MATCH_H
#define MATCH_H

#include "Game.h"
#include <iostream>
using namespace std;

const int MAX_GAMES = 20;
const int COORD_SIZE = 2;



class Match
{
  public:
    // constructor with one int(size)
    Match(const int size): m_citySize(size){} 
    // calculates and prints the win rate
    // N/A
    // Returns nothing
    void final_results();
    // plays the game
    // N/A
    // returns nothing
    void play();

  private:
    int m_citySize;
    int m_turn = 0;
    Game game[MAX_GAMES];
    int m_gamesPlayed;
    int rivalCoord[COORD_SIZE];
    int playerCoord[COORD_SIZE];
    int loveCoord[COORD_SIZE];
};

#endif