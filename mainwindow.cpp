#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QString>
#include <QIcon>
#include <iostream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Gronsfeld Shifr");
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
        int newIndex = userInput[i].unicode();
        int newKey = key[i].digitValue();

        int resultIndex = newIndex + newKey;

        if (userInput[i] == " ")
            resultIndex = 97 + newKey;
        else if (resultIndex > 65 && resultIndex < 90)
            resultIndex -= 26;
        else if (resultIndex > 122)
            resultIndex -= 26;

        result.append(QChar(resultIndex));
        // A - 65, Z - 90
        // a - 97, z - 122
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
