/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *ComPort;
    QComboBox *serialPortInfoListBox;
    QLabel *SpeedRate;
    QComboBox *baudRateBox;
    QWidget *Visualize;
    QPushButton *applyButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(425, 388);
        MainWindow->setMaximumSize(QSize(10000000, 10000000));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ComPort = new QLabel(centralwidget);
        ComPort->setObjectName(QStringLiteral("ComPort"));
        ComPort->setGeometry(QRect(10, 290, 61, 16));
        serialPortInfoListBox = new QComboBox(centralwidget);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));
        serialPortInfoListBox->setGeometry(QRect(70, 290, 69, 22));
        SpeedRate = new QLabel(centralwidget);
        SpeedRate->setObjectName(QStringLiteral("SpeedRate"));
        SpeedRate->setGeometry(QRect(150, 290, 71, 21));
        baudRateBox = new QComboBox(centralwidget);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));
        baudRateBox->setGeometry(QRect(220, 290, 69, 22));
        Visualize = new QWidget(centralwidget);
        Visualize->setObjectName(QStringLiteral("Visualize"));
        Visualize->setGeometry(QRect(10, 10, 401, 261));
        applyButton = new QPushButton(centralwidget);
        applyButton->setObjectName(QStringLiteral("applyButton"));
        applyButton->setGeometry(QRect(320, 290, 75, 23));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 425, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        ComPort->setText(QApplication::translate("MainWindow", "COM PORT:", Q_NULLPTR));
        SpeedRate->setText(QApplication::translate("MainWindow", "SPEED RATE:", Q_NULLPTR));
        applyButton->setText(QApplication::translate("MainWindow", "Apply", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
