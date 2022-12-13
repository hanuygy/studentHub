#ifndef FILEOUTPUT_H
#define FILEOUTPUT_H

#include <QMainWindow>

namespace Ui {
class fileOutput;
}

class fileOutput : public QMainWindow
{
    Q_OBJECT

public:
    explicit fileOutput(QWidget *parent = nullptr);
    void editText(const QString& fileName);
    ~fileOutput();

private:
    Ui::fileOutput *ui;
};

#endif // FILEOUTPUT_H
