#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "menu.h"
#include "academic.h"
#include "activities.h"
#include "resources.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow, public menu
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual void printMenu() override;
    ~MainWindow();

private slots:
    void on_academicButton_clicked();

    void on_activitiesButton_clicked();

    void on_resourcesButton_clicked();

private:
    Ui::MainWindow *ui;
    Academic *myAcademic;
    Activities *myActivities;
    Resources *myResources;
    virtual void fileOutput(const QString& fileName) override;
};
#endif // MAINWINDOW_H
