// Programmer: <Lincoln Steber>
// Student ID: <LGS6BV>
// Section: <303>
// Date: <11/4/2021>
// File: queue.h
// Purpose: Create different classes to simulate a game
#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>

using namespace std;

const int max_Contestants = 100;

template <class T>
class Queue
{
  public:
    //default constructor
    Queue(){};

    // Adds an object to the back of the queue
    // N/A
    // Adds an object to the back of the queue returns nothing
    void pushBack(const T temp);

    // returns the first object in the queue and pushes forward the rest of the objects
    // N/A
    // returns the first object in the queue  
    T popfront();

    // returns the first object in the queue
    // N/A
    // returns the first object in the queue 
    T peek();


  private:
    int total_contestants;
    T contestantsInQueue[max_Contestants];
};




#endif