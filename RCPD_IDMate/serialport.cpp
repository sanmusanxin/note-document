#include "serialport.h"
#include <QEventLoop>
#include <qtimer.h>

SerialPort::SerialPort(QObject *parent)
    : QObject(parent), m_serialPort(new QSerialPort(this))
{
    connect(m_serialPort, &QSerialPort::readyRead, this, &SerialPort::read);

}

SerialPort::~SerialPort()
{
    close();
}

bool SerialPort::open(QString portName, int baudRate, QSerialPort::DataBits dataBits, QSerialPort::StopBits stopBits,
                      QSerialPort::Parity parity, QSerialPort::FlowControl flowControl)
{
    close();

    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate);
    m_serialPort->setDataBits(dataBits);
    m_serialPort->setStopBits(stopBits);
    m_serialPort->setParity(parity);
    m_serialPort->setFlowControl(flowControl);

    bool success = m_serialPort->open(QIODevice::ReadWrite);

    if (!success)
    {
        QString errorMassage = m_serialPort->errorString();
        emit error(errorMassage);
    }

    return success;
}

void SerialPort::close()
{
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
    }
}

bool SerialPort::write(const QByteArray &data)
{
    if (!m_serialPort->isOpen())
    {
        QString errorstr = tr("Serial port is not open.");
        emit error(errorstr);
        return false;
    }

    qint64 bytesWritten = m_serialPort->write(data);

    if (bytesWritten != data.size())
    {
        QString errorMassage = "Error writing data to serial port.";
        emit error(errorMassage);
        return false;
    }

    return true;
}

void SerialPort::read()
{
        if (!m_serialPort->isOpen())
        {
            QString errMassage = "Serial port is not open.";
            emit error(errMassage);
        }

        qint64 dataSize = 0;
        if(m_serialPort->bytesAvailable() > 0)
        {
            dataSize = m_serialPort->bytesAvailable();
             QByteArray data = m_serialPort->read(dataSize);
             emit dataReceived(data);
        }
}

bool SerialPort::clear()
{
    if (!m_serialPort->isOpen())
    {
        QString errorstr = tr("Serial port is not open.");
        emit error(errorstr);
        return false;
    }

    m_serialPort->clear();

    return true;
}

QString SerialPort::errorString()
{
    return m_serialPort->errorString();
}

bool SerialPort::isopen()
{
    return m_serialPort->isOpen();
}

void SerialPort::sleepMsec(int msec)
{
    QEventLoop loop;		//定义一个新的事件循环
    QTimer::singleShot(msec, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();			//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
}
