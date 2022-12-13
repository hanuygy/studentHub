#include "fileoutput.h"
#include "ui_fileoutput.h"
#include <QFile>
#include <QString>
using namespace std;

fileOutput::fileOutput(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::fileOutput)
{
    ui->setupUi(this);
}

fileOutput::~fileOutput()
{
    delete ui;
}


void fileOutput::editText(const QString& fileName)
{
    QFile file(fileName);
    QTextBrowser wordBlocks;
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
        ui->textBrowser->setText(line);

    }
    file.close();
}
