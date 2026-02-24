#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSerialPortInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) 
{
    ui->setupUi(this);
    serial = new QSerialPort(this);

    // Initial scan
    refreshPorts();

    // Connect the Refresh button
    connect(ui->refreshBtn, &QPushButton::clicked, this, &MainWindow::refreshPorts);
}

MainWindow::~MainWindow() {
    if (serial->isOpen()) {
        serial->close();
    }
    delete ui;
}

void MainWindow::handleSend() {
    

void MainWindow::readSerial() {
    
}

void MainWindow::refreshPorts() {
    ui->portSelector->clear();
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QString label = info.portName() + " (" + info.description() + ")";
        ui->portSelector->addItem(label, info.portName()); 
    }
}