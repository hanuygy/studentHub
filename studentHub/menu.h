#ifndef MENU_H
#define MENU_H
#include <QString>

class menu
{
    public:
        virtual void printMenu() = 0;
        virtual void fileOutput(const QString& fileName) = 0;
};

#endif // MENU_H
