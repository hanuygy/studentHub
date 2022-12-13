#ifndef ACADEMIC_H
#define ACADEMIC_H
#include "menu.h"
#include "fileoutput.h"

#include <QMainWindow>

namespace Ui {
class Academic;
}

class Academic : public QMainWindow, public menu
{
    Q_OBJECT

public:
    explicit Academic(QWidget *parent = nullptr);
    ~Academic();
    virtual void printMenu() override;
    virtual void fileOutput(const QString& fileName) override;

private slots:


    void on_majorsButton_clicked();

    void on_advisementButton_clicked();

    void on_ePermitButton_clicked();

    void on_classesButton_clicked();

    void on_articulationButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Academic *ui;
    class fileOutput *myFile;
};

#endif // ACADEMIC_H
