#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), serial(new QSerialPort(this))
{
    ui->setupUi(this);
    
    // Scan for ports immediately
    on_refreshBtn_clicked();

    // Connect hardware signals
    connect(serial, &QSerialPort::readyRead, this, &MainWindow::readData);
}

MainWindow::~MainWindow() {
    if (serial->isOpen()) serial->close();
    delete ui; // Proper cleanup
}

void MainWindow::on_refreshBtn_clicked() {
    ui->portSelector->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        ui->portSelector->addItem(info.portName());
    }
}

void MainWindow::on_connectBtn_clicked() {
    if (serial->isOpen()) {
        serial->close();
        ui->connectBtn->setText("Connect");
        return;
    }

    QString portName = ui->portSelector->currentText();
    if (portName.isEmpty()) return;

    serial->setPortName(portName);
    serial->setBaudRate(QSerialPort::Baud9600);

    if (serial->open(QIODevice::ReadWrite)) {
        ui->connectBtn->setText("Disconnect");
    } else {
        QMessageBox::critical(this, "Error", "Could not open " + portName);
    }
}

void MainWindow::readData() {
    QByteArray data = serial->readAll();
    // Logic for incoming data goes here
}