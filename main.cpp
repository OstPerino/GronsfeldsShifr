#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyleSheet("* {font-family: century gothic; font-size: 20px}"
                    "QMainWindow {background-color: #222831}"
                    "QLabel {color: #ffd369}"
                    "QLineEdit {background-color: #393e46; color: #ffd369;}"
                    "QPushButton {background-color: #393e46; color: #ffd369}");
    MainWindow w;
    w.show();
    return a.exec();
}
