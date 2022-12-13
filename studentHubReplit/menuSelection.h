#ifndef MENUSELECTION_H
#define MENUSELECTION_H
#include <iostream>
using namespace std;

class menuSelection
{
  public:
    virtual void printMainMenu() = 0;
    virtual bool mainMenuOption(char userSelection) = 0;
    virtual void printSubMenu() = 0;
    virtual bool subMenuOption(char userSelection) = 0;
    virtual void fileOutput(string filename) = 0;
};

#endif
