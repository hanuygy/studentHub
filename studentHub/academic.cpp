#include "academic.h"
#include "ui_academic.h"
#include <iostream>
#include <QString>
#include <QFile>
#include <QLabel>
#include <QTextStream>
#include <QTextBrowser>
using namespace std;


Academic::Academic(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Academic)
{
    ui->setupUi(this);
    ui->majorsButton->setStyleSheet("background-color: #FEEEF5");
    ui->advisementButton->setStyleSheet("background-color: #E9E5F3");
    ui->ePermitButton->setStyleSheet("background-color: #E0EDF4");
    ui->classesButton->setStyleSheet("background-color: #F3F3F3");
    ui->articulationButton->setStyleSheet("background-color: #FBFBEF");
    ui->backButton->setStyleSheet("background-color: #C0C0C0");
}

Academic::~Academic()
{
    delete ui;
}

void Academic::printMenu()
{
    const QString mainMenu = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/academicMenu.txt";

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

void Academic::fileOutput(const QString& fileName) //pass the filename and the label
{
    myFile = new class fileOutput(this);
    myFile->show();
    myFile->editText(fileName);
}

void Academic::on_majorsButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/majorsFile.txt";
    fileOutput(fileName);
}


void Academic::on_advisementButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/advisementFile.txt";
    fileOutput(fileName);
}


void Academic::on_ePermitButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/ePermitFile.txt";
    fileOutput(fileName);
}


void Academic::on_classesButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/globalSearchtFile.txt";
    fileOutput(fileName);
}


void Academic::on_articulationButton_clicked()
{
    QString fileName = "/Users/jo/Documents/Projects/QT/studentHub/textFiles/articulationFile.txt";
    fileOutput(fileName);
}


void Academic::on_backButton_clicked()
{
    close();
    QWidget *parent = this->parentWidget();
    parent->show();
}

