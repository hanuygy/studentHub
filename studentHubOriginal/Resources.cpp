#include "Resources.h"
#include <fstream>
#include <iostream>
using namespace std;

void Resources::printMainMenu() 
{
  char userChoice;
  
  cout << "Here you will find the different resources that BMCC has to\n"
       << "offer to students and the information regarding those resources.\n" 
       << "Please select one of the options below:\n\n"
       << "A) Computer labs (free printing available)\n"
       << "B) Tutoring Center\n"
       << "C) Writing Center\n"
       << "D) Scholarships\n"
       << "E) Career Center\n"
       << "F) Counseling Center\n"
       << "G) Food Pantry\n"
       << "H) Early Childhood Center\n"
       << "I) Fitness Center\n"
       << "J) Go back to the main menu\n\n"
       << "Enter an option:\n";

  do
  {
    cin >> userChoice;
    userChoice = toupper(userChoice);
  } while (!mainMenuOption(userChoice));
  
}

bool Resources::mainMenuOption(char userSelection) 
{
  
  char userChoice = toupper(userSelection);
  string filename;

  switch (userChoice) {
    case 'A':
      filename = "textFiles/computerLabFile.txt";
      break;
  
    case 'B':
      filename = "textFiles/tutoringFile.txt";
      break;
  
    case 'C':
      filename = "textFiles/writingFile.txt";
      break;
  
    case 'D':
      filename = "textFiles/scholarshipsFile.txt";
      break;
  
    case 'E':
      filename = "textFiles/careerFile.txt";
      break;

    case 'F':
      filename = "textFiles/counselingFile.txt";
      break;
    
    case 'G':
      filename = "textFiles/foodFile.txt";
      break;

    case 'H':
      filename = "textFiles/daycareFile.txt";
      break;

    case 'I':
      filename = "textFiles/fitnessFile.txt";
      break;

    case 'J':
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

void Resources::printSubMenu() 
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

bool Resources::subMenuOption(char userSelection) 
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

void Resources::fileOutput(string filename) 
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
