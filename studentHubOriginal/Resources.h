#ifndef RESOURCES_H
#define RESOURCES_H
#include "menuSelection.h"

class Resources: public menuSelection
{
  private:
    virtual void printSubMenu() override;
    virtual bool subMenuOption(char userSelection) override;
    virtual void fileOutput(string filename) override;

  public:
    virtual void printMainMenu() override;
    virtual bool mainMenuOption(char userSelection) override;
};

#endif