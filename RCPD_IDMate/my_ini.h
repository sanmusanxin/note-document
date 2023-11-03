#ifndef MY_INI_H
#define MY_INI_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSettings>
#include <QtCore/QtCore>
#include <QFile>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>


struct myTestData{
    QList<float> testList;
    QList<float> measVoutlist;
    float Vref = 0.0;
    float fullRange = 40;
    float voutGain = 0;
    float voutOffset = 0;
    float voutLinearity = 0;
    float BasicErr =0 ;
    QList<float> zero;
    QList<QString> judge;
    QString ID = "23999999999";

    float VerfRange = 0.01;
    float unlineRang = 0.0001;
    float GainTRange = 0.0005;
    float offsetRang = 0.01;//23-03-21
    float BasicErrRang = 0.005;
    float timeout = 1100;

};
Q_DECLARE_METATYPE(myTestData)

class my_ini
{
public:
    my_ini(QString qstrfilename = "");
    virtual ~my_ini(void);

    ///创建ini文件
    void CreateFile( QString qstrFileName,QString qstrFilePath = QCoreApplication::applicationDirPath());

    ///ini文件模型
    void Set(QString,QString,QVariant);
    QVariant Get(QString,QString);

public slots:
    ///最小二乘法拟合
    QList<float> LineFitLeastSquares(QList<float> data_x, QList<float> data_y, int data_n);

private:
    QString m_qstrFileName;
    QSettings *m_psetting;



};

#endif // MY_INI_H
