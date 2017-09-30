#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QtGlobal>
#include <QMainWindow>
#include <QDialog>
#include <QtSerialPort/QSerialPort>
#include <QIntValidator>
#include <QTimer>

QT_USE_NAMESPACE

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}

class QInvalidator;
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
    struct Settings {
        QString name;
        qint32 baudRate;
        QString stringBaudRate;
    };

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    Settings settings() const;

private slots:
    void showPortInfo(int idx);
    void apply();
    void checkCustomBaudRatePolicy(int idx);
    void checkCustomDevicePathPolicy(int idx);
    void ShowData();
    void openserialport();

private:
    void fillPortsParameters();
    void fillPortsInfo();
    void updateSettings();

private:
    Ui::MainWindow *ui;
    Settings currentSettings;
    QIntValidator *intValidator;
    QSerialPort *serial;
    QTimer *readTimer;
};

#endif // MAINWINDOW_H
