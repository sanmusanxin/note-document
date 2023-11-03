#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class SerialPort : public QObject
{
    Q_OBJECT
public:
    explicit SerialPort(QObject *parent = nullptr);
    ~SerialPort();

    ///打开串口
    bool open(QString portName, int baudRate, QSerialPort::DataBits dataBits = QSerialPort::Data8,
              QSerialPort::StopBits stopBits = QSerialPort::OneStop, QSerialPort::Parity parity = QSerialPort::NoParity,
              QSerialPort::FlowControl flowControl = QSerialPort::NoFlowControl);

    ///关闭串口
    void close();

    ///串口写
    bool write(const QByteArray &data);

    ///串口读
    void read();

    ///清除串口
    bool clear();

    ///错误信息
    QString errorString();

    ///检查串口是否打开
    bool isopen();

    ///非阻塞延迟函数
    void sleepMsec(int msec);


private:
    QSerialPort *m_serialPort;

signals:
    ///用于错误信息传递的信号
    void error(QString &errMessage);

    ///用于串口读到的数据传递的信号
    void dataReceived(QByteArray &data);
};

#endif // SERIALPORT_H
