// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/16/2021>
// File: Game.cpp
// Purpose: Create a love game
#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(): m_size(5)
{
  m_matrix = new string * [m_size];
  // for ( int i = 0; i < m_size; i++)
  // {
  //   m_matrix[i] = new string [m_size];
  // }
}

Game::Game(const int size): m_size(size)
    {
      m_matrix = new string * [m_size];
      for ( int i = 0; i < m_size; i++)
      {
        m_matrix[i] = new string [m_size];
      }
    }

  Game::Game(const Game & prevGame)
  {
    m_size = prevGame.m_size;
    m_matrix = prevGame.m_matrix;
    m_playerScore = prevGame.m_playerScore;
    m_rivalScore = prevGame.m_rivalScore;
    m_win = prevGame.m_win;
  }

  void Game:: operator = (Game & GameRHS)
  {
    m_size = GameRHS.m_size;
    m_matrix = GameRHS.m_matrix;
    
  }

Game::~Game()
{
  for (int i = 0; i < m_size; i++)
  {
    delete[]m_matrix[i];
  }
  delete[]m_matrix;
  m_matrix = nullptr;
}

void Game::emptyMat()
{
  for (int i = 0; i < m_size; i++)
  {
    for (int j = 0; j < m_size; j++)
    {
      m_matrix[i][j] = " ";
    }
  }
}

double Game::getDistance(const int arr[], const int loveArr[])
{
  double dist;
  dist = sqrt(pow((arr[ZERO_INDEX] - loveArr[ZERO_INDEX]), 2) + pow((arr[INDEX_ONE] - loveArr[INDEX_ONE]), 2));
  return dist;
}

void Game::randomPopulate()
{
  for(int i = 0; i < MAX_TURNS; i++)
  {
    for(int j = 0; j < MAX_POINTS; j++)
    {
      m_rivalArr[i][j] = rand() % m_size;
      m_loveArr[i][j] = rand() % m_size;
    }
  }
}

int Game::getCoordinate1(const int turn, const string person)
{
  int num;
  if(person == "Rival")
  {
    num = m_rivalArr[turn][ZERO_INDEX];
  }
  else
  {
    num = m_loveArr[turn][ZERO_INDEX];
  }
  return num;
}

int Game::getCoordinate2(const int turn, const string person)
{
  int num;
  if(person == RIVAL)
  {
    num = m_rivalArr[turn][INDEX_ONE];
  }
  else
  {
    num = m_loveArr[turn][INDEX_ONE];
  }
  return num;
}

void Game::insertPeople(const int rivalCoordinate[], const int playerCoordinate[], const int loveCoordinate[])
{
  m_matrix[rivalCoordinate[ZERO_INDEX]][rivalCoordinate[INDEX_ONE]] = "R";
  m_matrix[playerCoordinate[ZERO_INDEX]][playerCoordinate[INDEX_ONE]] = "P";
  m_matrix[loveCoordinate[ZERO_INDEX]][loveCoordinate[INDEX_ONE]] = "L";
}

void Game::addScore(const double score, const string person)
{
  if(person == RIVAL)
  {
    m_rivalScore += score;

  }
  else
  {
    m_playerScore += score;
    
  }
}


ostream &operator <<(ostream &output, const Game &game)
{
  cout << endl;
  for (int i = 0; i < game.m_size; i++) 
  {
    cout << i << " | ";
    for (int j = 0; j < game.m_size; j++)
    {
      if(j < game.m_size - 1)
      {
        cout << game.m_matrix[i][j] << " , ";
      }
      else
      {
        cout << game.m_matrix[i][j] << " |" << endl;
      }
    }
  }
  cout << "    ";
  for (int i = 0; i < game.m_size; i++)
  {
    cout << i << "   ";
  }
  cout << endl << endl;
  return output;
}

void Game::results()
{
  cout << "Player Total Score: " << m_playerScore << endl;
  cout << "Rival Total Score: " << m_rivalScore << endl;
  if(m_playerScore < m_rivalScore)
  {
    cout << "Player Wins!" << endl;
    m_win = true;
  }
  else if (m_rivalScore < m_playerScore)
  {
    cout << "Rival Wins!" << endl;
  }
  else
  {
    cout << "Tie!" << endl;
  }
}

void Game::reset()
{
    m_playerScore = 0;
    m_rivalScore = 0;
    m_win = false;
}