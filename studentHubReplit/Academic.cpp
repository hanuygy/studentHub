#include "Academic.h"
#include <fstream>
#include <iostream>
using namespace std;

void Academic::printMainMenu() 
{
  char userChoice;
  
  cout << "\nHere you will find several options regarding your academics\n"
       << "here at BMCC. Please select one of the options below:\n\n"
       << "A) Show me the majors BMCC has to offer\n"
       << "B) Where do I go for advisement?\n"
       << "C) How do I apply for an ePermit?\n"
       << "D) Search for classes using GlobalSearch\n"
       << "E) Show me the Articulation Agreements\n"
       << "F) Go back to the main menu\n\n"
       << "Enter an option:\n";

  do
  {
    cin >> userChoice;
    userChoice = toupper(userChoice);
  } while (!mainMenuOption(userChoice));
  
}

bool Academic::mainMenuOption(char userSelection) 
{
  
  char userChoice = toupper(userSelection);
  string filename;

  switch (userChoice) {
    case 'A':
      filename = "textFiles/majorsFile.txt";
      break;

    case 'B':
      filename = "textFiles/advisementFile.txt";
      break;

    case 'C':
      filename = "textFiles/ePermitFile.txt";
      break;

    case 'D':
      filename = "textFiles/globalSearchFile.txt";
      break;

    case 'E':
      filename = "textFiles/articulationFile.txt";
      break;

    case 'F':
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

void Academic::printSubMenu() 
{
  char userChoice;
  
  cout << "Enter A to go back to main menu, or B to see the Academics menu\n"
          "again:\n";

  do
  {
    cin >> userChoice;
    userChoice = toupper(userChoice);
  } while (!subMenuOption(userChoice));
}

bool Academic::subMenuOption(char userSelection) 
{
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

void Academic::fileOutput(string filename) 
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
    throw "The file you are trying to open does not exist.";
  }
  
}
