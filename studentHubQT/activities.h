#ifndef ACTIVITIES_H
#define ACTIVITIES_H
#include "menu.h"
#include "fileoutput.h"

#include <QMainWindow>

namespace Ui {
class Activities;
}

class Activities : public QMainWindow, public menu
{
    Q_OBJECT

public:
    explicit Activities(QWidget *parent = nullptr);
    ~Activities();
    virtual void printMenu() override;
    virtual void fileOutput(const QString& fileName) override;

private slots:


    void on_clubsButton_clicked();

    void on_successButton_clicked();

    void on_directoryButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Activities *ui;
    class fileOutput *myFile;
};

#endif // ACTIVITIES_H
