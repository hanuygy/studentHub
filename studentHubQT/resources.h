#ifndef RESOURCES_H
#define RESOURCES_H
#include "menu.h"
#include "fileoutput.h"

#include <QMainWindow>

namespace Ui {
class Resources;
}

class Resources : public QMainWindow, public menu
{
    Q_OBJECT

public:
    explicit Resources(QWidget *parent = nullptr);
    ~Resources();
    virtual void printMenu() override;
    virtual void fileOutput(const QString& fileName) override;

private slots:
    void on_computerLabsButton_clicked();

    void on_tutoringCenterButton_clicked();

    void on_writingCenterButton_clicked();

    void on_scholarshipsButton_clicked();

    void on_careerCenterButton_clicked();

    void on_counselingCenterButton_clicked();

    void on_foodPantryButton_clicked();

    void on_daycareButton_clicked();

    void on_fitnessCenterButton_clicked();

    void on_backButton_clicked();

private:
    Ui::Resources *ui;
    class fileOutput *myFile;
};

#endif // RESOURCES_H
