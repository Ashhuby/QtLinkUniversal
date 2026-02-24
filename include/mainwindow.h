#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT // This must stay in the header file

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_refreshBtn_clicked();
    void on_connectBtn_clicked();
    void readData();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
};

#endif