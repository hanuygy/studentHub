#include "resources.h"
#include "ui_resources.h"
#include <iostream>
#include <QString>
#include <QFile>
#include <QLabel>
#include <QTextStream>
using namespace std;

Resources::Resources(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Resources)
{
    ui->setupUi(this);
    ui->computerLabsButton->setStyleSheet("background-color: #FEEEF5");
    ui->tutoringCenterButton->setStyleSheet("background-color: #E9E5F3");
    ui->writingCenterButton->setStyleSheet("background-color: #E0EDF4");
    ui->scholarshipsButton->setStyleSheet("background-color: #F3F3F3");
    ui->careerCenterButton->setStyleSheet("background-color: #FBFBEF");
    ui->counselingCenterButton->setStyleSheet("background-color: #ECE1DB");
    ui->foodPantryButton->setStyleSheet("background-color: #E3F2F7");
    ui->daycareButton->setStyleSheet("background-color: #DEE8E7");
    ui->fitnessCenterButton->setStyleSheet("background-color: #DAD4D4");
    ui->backButton->setStyleSheet("background-color: #C0C0C0");
}

Resources::~Resources()
{
    delete ui;
}

void Resources::printMenu()
{
    const QString mainMenu = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/resourcesMenu.txt";

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

void Resources::fileOutput(const QString& fileName) //pass the filename and the label
{
    myFile = new class fileOutput(this);
    myFile->show();
    myFile->editText(fileName);
}

void Resources::on_computerLabsButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/computerLabFileFile.txt";
    fileOutput(fileName);
}


void Resources::on_tutoringCenterButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/tutoringCenterFile.txt";
    fileOutput(fileName);
}


void Resources::on_writingCenterButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/writingCenterFile.txt";
    fileOutput(fileName);
}


void Resources::on_scholarshipsButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/scholarshipsFile.txt";
    fileOutput(fileName);
}


void Resources::on_careerCenterButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/careerCenterFile.txt";
    fileOutput(fileName);
}


void Resources::on_counselingCenterButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/counselingCenterFile.txt";
    fileOutput(fileName);
}


void Resources::on_foodPantryButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/foodPantryFile.txt";
    fileOutput(fileName);
}


void Resources::on_daycareButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/daycareFile.txt";
    fileOutput(fileName);
}


void Resources::on_fitnessCenterButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/fitnessCenterFile.txt";
    fileOutput(fileName);
}


void Resources::on_backButton_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

