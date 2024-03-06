// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/16/2021>
// File: Match.cpp
// Purpose: Create a love game
#include "Match.h"
#include <iostream>
using namespace std;

void Match::play()
{
  char playAgain;
  char newCity;
  m_gamesPlayed = 0;
  do
  { 
    Game temp(m_citySize);
    game[m_gamesPlayed] = temp;
    game[m_gamesPlayed].emptyMat();
    game[m_gamesPlayed].randomPopulate();
    cout << game[m_gamesPlayed];
    do
    {
      do
      {
        cout << "Turn " << m_turn + 1 << endl << "___________" << endl << "Choose a coordinate:" << endl;
        cin >> playerCoord[ZERO_INDEX] >> playerCoord[INDEX_ONE];
      } while (playerCoord[ZERO_INDEX] < 0 || playerCoord[ZERO_INDEX] >= m_citySize || playerCoord[INDEX_ONE] < 0 || playerCoord[INDEX_ONE] >= m_citySize);
      
      rivalCoord[ZERO_INDEX] = game[m_gamesPlayed].getCoordinate1(m_turn, RIVAL);
      rivalCoord[INDEX_ONE] = game[m_gamesPlayed].getCoordinate2(m_turn, RIVAL);
      loveCoord[ZERO_INDEX] = game[m_gamesPlayed].getCoordinate1(m_turn, LOVE);
      loveCoord[INDEX_ONE] = game[m_gamesPlayed].getCoordinate2(m_turn, LOVE);

      game[m_gamesPlayed].insertPeople(rivalCoord, playerCoord, loveCoord);
      cout << game[m_gamesPlayed];
      cout << "Player Distance to Love Interest: " << game[m_gamesPlayed].getDistance(playerCoord, loveCoord) << endl;
      cout << "Rival Distance to Love Interest: " << game[m_gamesPlayed].getDistance(rivalCoord, loveCoord) << endl; ////////
      game[m_gamesPlayed].addScore(game[m_gamesPlayed].getDistance(playerCoord, loveCoord), PLAYER);
      game[m_gamesPlayed].addScore(game[m_gamesPlayed].getDistance(rivalCoord, loveCoord), RIVAL);
      game[m_gamesPlayed].emptyMat();
      m_turn ++;
    } while (m_turn < MAX_TURNS);
    game[m_gamesPlayed].results();
    m_gamesPlayed++;
    m_turn = 0;
    do
    {
      cout << "Do you want to play again (y/n)? ";
      cin >> playAgain;
    } while (playAgain != 'y' && playAgain != 'n');
    if(playAgain == 'y')
    {
      do
      {
        cout << "Do you want to start in a new city (y/n)? ";
        cin >> newCity;
      } while (newCity != 'y' && newCity != 'n');
      if(newCity == 'y')
      {
        cout << "Please provide the size of the new city: ";
        cin >> m_citySize;
      }
      else
      {
        if(m_gamesPlayed < MAX_GAMES)
        {
          game[m_gamesPlayed] = game[m_gamesPlayed - 1];
          game[m_gamesPlayed].reset();
        }
      }
    }
  } while (m_gamesPlayed < MAX_GAMES && playAgain == 'y');
}

void Match::final_results()
{
  double wins = 0;
  for(int i = 0; i < m_gamesPlayed; i ++)
  {
    if(game[i].getwin() == true)
    {
      wins++;
    }
  }
  cout << "Player Win Rate: " << wins/static_cast<double>(m_gamesPlayed) << endl;
}