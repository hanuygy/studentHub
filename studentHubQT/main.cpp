#include "mainwindow.h"
#include <iostream>
#include <QApplication>
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    try
    {
        w.printMenu();
    }
    catch(string& msg)
    {
        cout << msg << endl;
    }

    w.show();
    return a.exec();
}
