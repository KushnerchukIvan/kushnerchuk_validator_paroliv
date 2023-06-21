#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QRegularExpressionValidator>
#include <QRegularExpressionMatch>

class Validator
{
public:
    Validator(){};
    virtual ~Validator(){};
    virtual bool isValid(QString somestring);
};

class SomeValidator
{
    virtual bool isValid(QString somestring)
    {
        return true;
    }
};

class NewValidator
{
    QRegularExpression reg;
public:
    NewValidator (QString str)
    {
        reg = QRegularExpression (str);
        // QValidator *validator(reg, this);
    }
    virtual bool isValid(QString somestring)
    {
        QRegularExpressionMatch regmatch = reg.match(somestring);
        bool ismatch = regmatch.hasMatch();
        if (ismatch)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_lineEdit_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
