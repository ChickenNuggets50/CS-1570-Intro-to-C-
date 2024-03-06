// Programmer: Justin Burski and Lincoln Steber
// Student ID: Burski (jdbrnt) Steber(lgs6bv)
// Date: 11/29/2021
// File: main.h
// Purpose: Create a program that tracks the robbers and police as they chase each other around the city, fighting over the jewels.

#include "City.h"
#include "Jewel.h"
#include "Robber.h"
#include "Police.h"
#include "Ordinary_Robber.h"
#include "Greedy_Robber.h"


int main()
{
  srand(SEED);
  int turns =  0, num_robbers = NUM_ROBBERS;
  City main_city;
  Jewel main_jewels[NUM_JEW];
  for (int i = 0; i < NUM_JEW; ++i)
  {
    bool proceed = false;
    do
    {
      main_jewels[i].setJewel();
      if(main_city.getCityLetter(main_jewels[i].getRow(), main_jewels[i].getCol())  == JEWEL_LETTER)
          proceed = false;
      else
      {
          main_city.setLetterBoard(main_jewels[i].getRow(), main_jewels[i].getCol(), JEWEL_LETTER);
          proceed = true;
      }
    } while (proceed == false);
  }
  Police PaulBlart;
  Ordinary_Robber ordinary[NUM_ROB];
  Greedy_Robber greedy[NUM_ROB];
  main_city.setLetterBoard(PaulBlart.getRow(), PaulBlart.getCol(), POLICE_LETTER);
  PaulBlart.setId(1);

  for(int i = 0; i < NUM_ROB; i++)
  { 
    main_city.setLetterBoard(ordinary[i].getRow(), ordinary[i].getCol(), ROBBER_LETTER);
    cout<<"Row: "<<ordinary[i].getRow()<<"  Col: "<<ordinary[i].getCol()<<endl;
    ordinary[i].setId(i);
  }

  for(int i = 0; i < NUM_ROB; i++)
  { 
    main_city.setLetterBoard(greedy[i].getRow(), greedy[i].getCol(), ROBBER_LETTER);
    cout<<" Greedy Row: "<<greedy[i].getRow()<<"  Col: "<<greedy[i].getCol()<<endl;
    greedy[i].setId(i + NUM_ROB);
  }
  cout<<"\t Starting City"<<endl;
  main_city.print();
  cout<<endl<<endl<<endl;

  do
  {
    cout<< endl << endl << "\t Round Summary"<<endl;
    cout<<"Turn "<<turns + 1<<endl<<endl;
    int jewel_value = 0;
    for(int i = 0; i < NUM_ROB; i++)
    {
      if(greedy[i].getActive())
      {
        bool again = false;
        int again_count = 0;
        int half = greedy[i].getNumJewels() / 2;
        do
        {
          again = false;
          main_city.setLetterBoard(greedy[i].getRow(), greedy[i].getCol(), BLANK);
          cout<<"Greedy Robber "<<greedy[i].getId()<<" moved ";
          greedy[i].move(main_city);
          cout<<"Their New Position: ("<<greedy[i].getRow()<<", "<<greedy[i].getCol()<<")"<<endl;

          if(main_city.getCityLetter(greedy[i].getRow(), greedy[i].getCol())  == JEWEL_LETTER) {
            for (int j = 0; j < NUM_JEW; ++j) {
              if (main_jewels[j].getRow() == greedy[i].getRow() && main_jewels[j].getCol() == greedy[i].getCol()) {
                jewel_value = main_jewels[j].getValue();
                greedy[i].pickUpJewel(main_jewels[j]);
                cout << "Greedy Robber " << greedy[i].getId() << " found a jewel of value " << jewel_value << "."
                     << endl;
                if (jewel_value % 2 == 0) {
                  cout << "Because the value was even, they get to move again" << endl;
                  again = true;
                  again_count++;
                } else {
                  again = false;
                }
              }
//              else
//                again = false;
            }
            cout << "Greedy Robber " << greedy[i].getId() << "'s current count is " << greedy[i].getCount() << "."
                 << endl << endl;
          }
          if(main_city.getCityLetter(greedy[i].getRow(), greedy[i].getCol())  == ROBBER_LETTER)
          {
            for (int j = 0; j < half; ++j)
            {
              Jewel temp_jewel = greedy[i].getJewel(j);
              bool proceed = false;
              do
              {
                if(main_city.getCityLetter(temp_jewel.getRow(), temp_jewel.getCol())  == BLANK)
                {
                  main_city.setLetterBoard(temp_jewel.getRow(), temp_jewel.getCol(), JEWEL_LETTER);
                  proceed = true;
                }
                else
                {
                  temp_jewel.randCords();
                  proceed = false;
                }
              } while (proceed == false);
              greedy[i].dropHalf();
            }
            cout<<"OUCH!! Greedy Robber "<<greedy[i].getId()<<" ran into another robber, causing them to drop half of their Jewels"<<endl;
            cout<<"Greedy Robber "<<greedy[i].getId()<<"s count after drop is "<<greedy[i].getCount()<<"."<<endl<<endl;
          }
        } while (again == true && again_count < MAX_AGAIN);
        cout<<endl;
      }
    }

    for(int i = 0; i < NUM_ROB; i++)
    {
      if(ordinary[i].getActive())
      {
        main_city.setLetterBoard(ordinary[i].getRow(), ordinary[i].getCol(), BLANK);
        cout<<"Ordinary Robber "<<ordinary[i].getId()<<" moved ";
        ordinary[i].move();
        cout<<"Their New Position: ("<<ordinary[i].getRow()<<", "<<ordinary[i].getCol()<<")"<<endl;
        if(main_city.getCityLetter(ordinary[i].getRow(), ordinary[i].getCol())  == JEWEL_LETTER)
        {
          for (int j = 0; j < NUM_JEW; ++j)
          {
            if(main_jewels[j].getRow() == ordinary[i].getRow() && main_jewels[j].getCol() == ordinary[i].getCol())
            {
              jewel_value = main_jewels[j].getValue();
              ordinary[i].pickUpJewel(main_jewels[j]);
              cout<<"Ordinary Robber "<<ordinary[i].getId()<<" found a jewel of value "<<jewel_value<<"."<<endl;
            }
          }
          cout<<"Ordinary Robber "<<ordinary[i].getId()<<"'s current count is "<<ordinary[i].getCount()<<"."<<endl<<endl;
        }
        cout<<endl;
      }
    }
    for (int i = 0; i < NUM_ROB; ++i)
    {
      if(ordinary[i].getActive())
        main_city.setLetterBoard(ordinary[i].getRow(), ordinary[i].getCol(), ROBBER_LETTER);
    }
    for (int i = 0; i < NUM_ROB; ++i)
    {
      if(greedy[i].getActive())
        main_city.setLetterBoard(greedy[i].getRow(), greedy[i].getCol(), ROBBER_LETTER);
    }
    main_city.setLetterBoard(PaulBlart.getRow(), PaulBlart.getCol(), BLANK);
    cout<<"Police Officer "<<PaulBlart.getId()<<" moved ";
    PaulBlart.move();
    cout<<"Their New Position: ("<<PaulBlart.getRow()<<", "<<PaulBlart.getCol()<<")"<<endl;
    if(main_city.getCityLetter(PaulBlart.getRow(), PaulBlart.getCol())  == JEWEL_LETTER)
    {
      for (int j = 0; j < NUM_JEW; ++j)
      {
        if(main_jewels[j].getRow() == PaulBlart.getRow() && main_jewels[j].getCol() == PaulBlart.getCol())
        {
          jewel_value = main_jewels[j].getValue();
          PaulBlart.pickUpJewel(main_jewels[j]);
          cout<<"Police Officer "<<PaulBlart.getId()<<" found a jewel of value "<<jewel_value<<"."<<endl;
        }
      }
    }
    if(main_city.getCityLetter(PaulBlart.getRow(), PaulBlart.getCol())  == ROBBER_LETTER)
    {
      for(int i = 0; i < NUM_ROB; i++)
      {
        if(ordinary[i].getRow() == PaulBlart.getRow() && ordinary[i].getCol() == PaulBlart.getCol())
        {
          cout<<"ARRESTED!! Police Officer "<<PaulBlart.getId()<<" arrested Ordinary Robber "<<ordinary[i].getId()<<" and confiscated "<<ordinary[i].getCount()<<" dollars worth of Jewels"<<endl<<endl;
          PaulBlart.arrest(ordinary[i]);
          ordinary[i].arrest();
          num_robbers--;
        }
        if(greedy[i].getRow() == PaulBlart.getRow() && greedy[i].getCol() == PaulBlart.getCol())
        {
          cout<<"ARRESTED!! Police Officer "<<PaulBlart.getId()<<" arrested Greedy Robber "<<greedy[i].getId()<<" and confiscated "<<greedy[i].getCount()<<" dollars worth of Jewels"<<endl<<endl;
          PaulBlart.arrest(greedy[i]);
          greedy[i].arrest();
          num_robbers--;
        }
      }
      cout<<endl;
    }
    cout<<"Total amount collected by the robbers: "<<ordinary[1].getTotValue()<<endl;
    cout<<"Total amount confiscated by the police: "<<PaulBlart.getCount()<<endl<<endl;
    cout<<"Current city layout below"<<endl;
    main_city.setLetterBoard(PaulBlart.getRow(), PaulBlart.getCol(), POLICE_LETTER);
    main_city.print();
    turns++;
  } while(turns < MAX_TURN && num_robbers > 0 && ordinary[1].getTotValue() < ROB_WIN);


  cout << endl << endl << "Summary of the chase:" << endl;
  if(turns == MAX_TURN)
  {
    cout << "\t The robbers win the chase because maximum turns (" << MAX_TURN << ") have been reached" << endl<<endl;
  }
  else if(ordinary[0].getTotValue() == ROB_WIN)
  {
    cout << "\t The robbers win the chase because they have picked up $2022 worth of jewels" << endl<<endl;
  }
  else if(num_robbers <= 0)
  {
    if(ordinary[1].getTotValue() > 0)
    {
      PaulBlart.setCount(PaulBlart.getCount() + ordinary[1].getTotValue());
      ordinary[1].setTotValue(0);
    }
    cout<<"\t The police win because they captured all of the robbers"<<endl<<endl;
  }
  cout<<"Police id: "<<PaulBlart.getId()<<endl;
  cout<<"\t Confiscated jewels amount: $"<<PaulBlart.getCount()<<endl;
  cout<<"\t Final number of robbers caught: "<<PaulBlart.getNumRobCaught()<<endl;
  for(int i = 0; i < NUM_ROB; i++)
  {
    cout<<"Ordinary Robber id: "<<ordinary[i].getId()<<endl;
    if (ordinary[i].getActive())
    {
      cout << "\t Final number of jewels picked up: " << ordinary[i].getNumJewels() << endl;
      cout << "\t Total jewel worth: $" << ordinary[i].getCount() << endl;
    }
    else
    {
      cout<<"\t Suspect was arrested"<<endl;
    }
  }
  for(int i = 0; i < NUM_ROB; i++)
  {
    cout<<"Greedy Robber id: "<<greedy[i].getId()<<endl;
    if (greedy[i].getActive())
    {
      cout << "\t Final number of jewels picked up: " << greedy[i].getNumJewels() << endl;
      cout << "\t Total jewel worth: $" << greedy[i].getCount() << endl;
    }
    else
    {
      cout<<"\t Suspect was arrested"<<endl;
    }
  }
  cout<<endl<<"Total Robber Value: $"<<greedy[1].getTotValue()<<endl;
  return 0;
}