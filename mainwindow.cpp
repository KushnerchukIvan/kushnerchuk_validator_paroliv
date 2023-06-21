#include "mainwindow.h"
#include "./ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_returnPressed()
{
    QString str = ui -> lineEdit -> text();
    NewValidator valid("^(?=\\S*\\d)(?=\\S*[a-z])(?=\\S*[A-Z])(?=\\S*[@#\\*\\+])\\S{4,6}$");
    if (valid.isValid(str))
    {
        ui -> label -> setText("Перевірку пройдено");
    }
    else
    {
        ui -> label -> setText("Перевірку не пройдено");
    }
}

