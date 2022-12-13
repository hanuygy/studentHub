#include "Activities.h"
#include <fstream>
#include <iostream>
using namespace std;

void Activities::printMainMenu() 
{
  char userChoice;
  
  cout << "Here you will find several options regarding BMCC's activties\n"
       << "and directory. Please select one of the options below:\n\n"
       << "A) Show me the clubs at BMCC\n"
       << "B) Show me the success programs BMCC has to offer\n"
       << "C) Directory\n"
       << "D) Go back to the main menu\n\n"
       << "Enter an option:\n";

  do
  {
    cin >> userChoice;
    userChoice = toupper(userChoice);
  } while (!mainMenuOption(userChoice));
  
}

bool Activities::mainMenuOption(char userSelection) 
{
  
  char userChoice = toupper(userSelection);
  string filename;

  switch (userChoice) {
    case 'A':
      filename = "textFiles/clubsFile.txt";
      break;
  
    case 'B':
      filename = "textFiles/successFile.txt";
      break;
  
    case 'C':
      filename = "textFiles/directoryFile.txt";
      break;
  
    case 'D':
      return true;
  
    default:
      cout << "\nThe option you have entered is not valid, please enter\n"
           << "a valid option:\n";
      return false;
  }

  try
  {
    fileOutput(filename);
  }
  catch (string &msg)
  {
    cout << msg << endl;
  }
  
  printSubMenu();
  return true;
  
}

void Activities::printSubMenu() 
{
  char userChoice;
  
  cout << "\nEnter A to go back to main menu, or B to see the Academics menu "
          "again:\n";

  do
  {
    cin >> userChoice;
    userChoice = toupper(userChoice);
  } while (!subMenuOption(userChoice));
}

bool Activities::subMenuOption(char userSelection) 
{
  cout << endl;
  char userChoice = toupper(userSelection);

  switch (userSelection) 
  {
    case 'A':
      break;
  
    case 'B':
      printMainMenu();
      break;
      
    default:
      cout << "\nThe option you have entered is not valid, please\n"
           << "enter a valid option:\n";
      return false;
  }

  return true;
  
}

void Activities::fileOutput(string filename) 
{
  
  string line;
  ifstream inFile;
  inFile.open(filename);

  if (inFile) 
  {
    while (!inFile.eof()) 
    {
      getline(inFile, line);
      cout << line << endl;
    }

    inFile.close();
  } 
  else 
  {
    throw string ("The file you are trying to open does not exist.");
  }
  
}
