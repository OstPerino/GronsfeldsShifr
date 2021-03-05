#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>

const QString upperCase = " ABCDEGHIJKLMNOPQRSTUVWXYZ";
const QString lowerCase = " abcdegfijklmnopqrstuwxyz";


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


void MainWindow::on_pushButton_clicked()
{
    QString key = ui->keyEdit->text();
    QString userInput = ui->stringEdit->text();

    int count = 0;

    while (key.length() < userInput.length())
    {
        key.append(key[count]);
        count++;
        if (count == key.length())
            count = 0;
    }


}
