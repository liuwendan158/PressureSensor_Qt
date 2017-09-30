#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>
#include <QIntValidator>
#include <QLineEdit>
#include <QDebug>
#include <QtGlobal>

QT_USE_NAMESPACE

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    intValidator = new QIntValidator(0, 4000000, this);

    ui->baudRateBox->setInsertPolicy(QComboBox::NoInsert);

    connect(ui->applyButton, &QPushButton::clicked,
            this, &MainWindow::apply);
    connect(ui->serialPortInfoListBox,  static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::checkCustomDevicePathPolicy);
    connect(ui->baudRateBox,  static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::checkCustomBaudRatePolicy);
    connect(ui->serialPortInfoListBox, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &MainWindow::showPortInfo);

    serial = new QSerialPort(this);
    readTimer = new QTimer(this);
    readTimer->start(100);
    connect(readTimer, &QTimer::timeout, this, &MainWindow::ShowData);
    fillPortsParameters();
    fillPortsInfo();
    updateSettings();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::apply()
{
    updateSettings();
}

void MainWindow::checkCustomBaudRatePolicy(int idx)
{
    bool isCustomBaudRate = !ui->baudRateBox->itemData(idx).isValid();
    ui->baudRateBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        ui->baudRateBox->clearEditText();
        QLineEdit *edit = ui->baudRateBox->lineEdit();
        edit->setValidator(intValidator);
    }
}

void MainWindow::checkCustomDevicePathPolicy(int idx)
{
    bool isCustomPath = !ui->serialPortInfoListBox->itemData(idx).isValid();
    ui->serialPortInfoListBox->setEditable(isCustomPath);
    if (isCustomPath)
        ui->serialPortInfoListBox->clearEditText();
}

void MainWindow::fillPortsParameters()
{
    ui->baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    ui->baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    ui->baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    ui->baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    ui->baudRateBox->addItem(tr("Custom"));
}

void MainWindow::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    QStringList list = ui->serialPortInfoListBox->itemData(idx).toStringList();
}

void MainWindow::fillPortsInfo()
{
    ui->serialPortInfoListBox->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        list << info.portName();

        ui->serialPortInfoListBox->addItem(list.first(), list);
    }

    ui->serialPortInfoListBox->addItem(tr("Custom"));
}

void MainWindow::updateSettings()
{
    currentSettings.name = ui->serialPortInfoListBox->currentText();

    if (ui->baudRateBox->currentIndex() == 4) {
        currentSettings.baudRate = ui->baudRateBox->currentText().toInt();
    } else {
        currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    ui->baudRateBox->itemData(ui->baudRateBox->currentIndex()).toInt());
    }
    currentSettings.stringBaudRate = QString::number(currentSettings.baudRate);
    serial->close();
    openserialport();
}

void MainWindow::openserialport()
{
    serial->setPortName(currentSettings.name);
    serial->setBaudRate(currentSettings.baudRate);
    serial->setDataBits(QSerialPort::Data8);
    serial->setParity(QSerialPort::NoParity);
    serial->setStopBits(QSerialPort::OneStop);
    serial->setFlowControl(QSerialPort::NoFlowControl);
    qDebug()<<currentSettings.name<<currentSettings.baudRate;

    if(serial->open(QIODevice::ReadWrite))
    {
        qDebug()<<"Successful";
    }
    else{
        serial->close();
        qDebug()<<serial->errorString();
    }
}

void MainWindow::ShowData()
{
    QByteArray temp=serial->readAll();
    int len=temp.size();
    int data[len];
    int display[900];
    int p=0;
    int i=0;
    int j=0;


    for(i =0; i<len;i++)
    {
        data[i]=int(temp[i]);
    }

    for (i=0;i<len;i++){
        if(data[i]==255&&data[i+1]==255)
        {
            p=i+2;
            qDebug()<<"Data";
            for(j=0;j<900;j++)
            {
                display[j]=data[p+2*j]+data[p+2*j+1]*256;
                qDebug()<<display[j];
            }
            p=i+1802;//1802 len+1
            for(i=0;i<len-p;i++)
            {
                data[i]=data[p+1];
                p=p+1;
            }
            p=display[0]+12;
        }
    }

}



