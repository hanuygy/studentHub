#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QString>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QPixmap>
using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white");
    ui->academicButton->setStyleSheet("background-color: #FEEEF5");
    ui->activitiesButton->setStyleSheet("background-color: #E9E5F3");
    ui->resourcesButton->setStyleSheet("background-color: #E0EDF4");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printMenu()
{
    const QString mainMenu = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/mainMenu.txt";

    QFile file(mainMenu);
    QLabel label;
    QString line;

    file.open(QIODevice::ReadOnly | QIODevice::Text);

    if (!file.isOpen())
    {
        throw string ("Error: text file does not exist.");
    }
    else
    {
        QTextStream stream(&file);
        while (!stream.atEnd())
        {
            line.append(stream.readLine()+"\n");
        }
        ui->label->setText(line);

    }
    file.close();

}

void MainWindow::fileOutput(const QString& fileName){}


void MainWindow::on_academicButton_clicked()
{
    myAcademic = new Academic(this);
    close();
    myAcademic->show();
    try
    {
        myAcademic->printMenu();
    }
    catch(string& msg)
    {
        cout << msg << endl;
    }
}


void MainWindow::on_activitiesButton_clicked()
{
    myActivities = new Activities(this);
    close();
    myActivities->show();
    try
    {
        myActivities->printMenu();
    }
    catch(string& msg)
    {
        cout << msg << endl;
    }
}


void MainWindow::on_resourcesButton_clicked()
{
    myResources = new Resources(this);
    close();
    myResources->show();
    try
    {
        myResources->printMenu();
    }
    catch(string& msg)
    {
        cout << msg << endl;
    }
}

