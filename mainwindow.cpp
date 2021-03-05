#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>
#include <iostream>

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
    //! Making key and userInput from ui form
    QString key = ui->keyEdit->text();
    QString userInput = ui->stringEdit->text();
    QString result = "";

    //! Count for making key
    int count = 0;

    //! Making new key to know what needs to code other symbols
    while (key.length() < userInput.length())
    {
        key.append(key[count]);
        count++;
        if (count == key.length())
            count = 0;
    }

    //! Main loop for coding
    for (int i = 0; i < userInput.length(); ++i)
    {
        //! Find out an index of current element in alphabet
        int index = contain(userInput[i], lowerCase, upperCase);
        //! Find out a new index for next element
        int newKey = key[i].digitValue();

        if (userInput[i] == " " || userInput[i].isLower())
            result.append(lowerCase[newKey + index]);
        else
            result.append(upperCase[newKey + index]);
    }

    ui->resutlEdit->setText(result);
    //! s: my fat dog k: 143 - interesting example
    //! i am nikita - 121
    //! dog like jump - 13
    //! symbols are here - 9
    //! the end - 9
}

int MainWindow::contain(QChar charTmp, const QString upperCase, const QString lowerCase)
{
    for (int i = 0; i < lowerCase.length(); ++i)
        if (lowerCase[i] == charTmp || upperCase[i] == charTmp)
            return i;
    return -1;
}
