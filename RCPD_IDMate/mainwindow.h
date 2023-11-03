#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "my_ini.h"
#include <serialport.h>
#include <QMainWindow>
#include <QTimer>
#include <QDateTime>
#include <QFile>
#include <QDebug>
#include <QKeyEvent>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>


typedef struct my_data
{
    QString ID = "ID";
    QString IDmcu = "";
    QByteArray receive;
    int address;
    int command;
    int len;
    int id1;
    int id2;
    int year;
    int mouth;
    int day;
    int number;


}my_data;

Q_DECLARE_METATYPE(my_data)

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    int powerOnTime = 5000;
    int timerCount = 0;


    void init();

    void addLog(QString str);

    void clearShow();

    void updataShow(bool b);

    bool openSerial1();


    void ACWResData(QByteArray data);

    void strageFile();

    void sleepMsec(int msec);

    void testTimerhund();

    void SP2MateID();

    void receiveHandle();

private slots:
    void on_openButton_clicked();

    void on_idShowEdit_textChanged(const QString &arg1);

    void on_testStopButton_clicked();

private:
    Ui::MainWindow *ui;

    SerialPort *serial1;
    QTimer *testTimer;
    QTimer *receTimer;
    my_data *mydata;
};
#endif // MAINWINDOW_H
