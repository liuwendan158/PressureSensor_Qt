#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QApplication>
#include <QtWidgets>

#include <QtSerialPort/QSerialPortInfo>
#include <QIntValidator>
#include <QLineEdit>

QT_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QWidget *widget = new QWidget();
    //widget ->setWindowTitle(QObject::tr("NAMI PressureSensor"));


    MainWindow w;
    w.show();
    //widget->show();

    return a.exec();
}

