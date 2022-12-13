#include "Academic.h"
#include "Activities.h"
#include "Resources.h"
#include <iostream>
using namespace std;

int main() 
{
  char userChoice;
  Academic myAcademic;
  Activities myActivities;
  Resources myResources;

  cout << "Welcome to the StudentHub!\n\n" 
       << "Are you here looking for ways to get academic help? Looking\n"
       << "for activties to participate in? Or resources that are\n"
       << "available to you as a BMCC student? The StudentHub is here\n" 
       << "to help you with all of those!\n";
  
  do
  { 
    cout << "\nPlease select one of the following options:\n"
         << "A) Information on majors, looking up classes, advisement, and\n"
         << "   the articulation agreements BMCC has with other colleges.\n"
         << "B) Clubs and Success Programs\n"
         << "C) Student resources\n"
         << "D) Quit the program\n\n"
         << "Enter an option:\n";

    cin >> userChoice;
    userChoice = toupper(userChoice);

    switch (userChoice)
    {
      case 'A':
        myAcademic.printMainMenu();
        break;
      case 'B':
        myActivities.printMainMenu();
        break;
      case 'C':
        myResources.printMainMenu();
        break;
      case 'D':
        break;
      default:  
        cout << "\nThe option you have entered is not valid.\n\n";
    }
      
  } while (userChoice != 'D');

  return 0;
}
