#include "activities.h"
#include "ui_activities.h"
#include <iostream>
#include <QString>
#include <QFile>
#include <QLabel>
#include <QTextStream>
using namespace std;

Activities::Activities(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Activities)
{
    ui->setupUi(this);
    ui->clubsButton->setStyleSheet("background-color: #FEEEF5");
    ui->successButton->setStyleSheet("background-color: #E9E5F3");
    ui->directoryButton->setStyleSheet("background-color: #E0EDF4");
    ui->backButton->setStyleSheet("background-color: #C0C0C0");
}

Activities::~Activities()
{
    delete ui;
}

void Activities::printMenu()
{
    const QString mainMenu = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/activitiesMenu.txt";

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

void Activities::fileOutput(const QString& fileName) //pass the filename and the label
{
    myFile = new class fileOutput(this);
    myFile->show();
    myFile->editText(fileName);
}

void Activities::on_clubsButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/clubsFile.txt";
    fileOutput(fileName);
}


void Activities::on_successButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/successProgramFile.txt";
    fileOutput(fileName);
}


void Activities::on_directoryButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/directoryFile.txt";
    fileOutput(fileName);
}


void Activities::on_backButton_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

