#include "interface.h"
#include <iostream>
#include <QCoreApplication>
#include <Logger/log.h>

namespace Asp {




SerialCommunication::SerialCommunication(QString portName, int baudRate, QObject *parent) : ICommunication(parent),
    m_portName(portName),
    m_baudRate(baudRate)
{
    m_port = new QSerialPort();
    m_port->setPortName(portName);
    m_port->setBaudRate(baudRate);

    connect(m_port, &QSerialPort::readyRead, this, &SerialCommunication::handleReadyRead);
    connect(m_port, &QSerialPort::errorOccurred, this, &SerialCommunication::handleError);

    if (!m_port->open(QIODevice::ReadWrite)) {
        Log::Error(QString("Failed to open port %1, error: %2")
                          .arg(m_portName)
                          .arg(m_port->errorString()));
    }
    else
    {
        Log::Debug("serial port opened \n");
        QByteArray data = m_port->readAll();
        for (const auto& value : data)
        {
            std::cout << (int)value <<" ";
        }
    }
}

SerialCommunication::~SerialCommunication()
{
    if(m_port->isOpen())
    {
        m_port->close();
    }

}

void SerialCommunication::handleReadyRead()
{
    m_readBuffer.append(m_port->readAll());

    emit readyRead();
}

void SerialCommunication::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_port->portName())
                            .arg(m_port->errorString())
                         << "\n";
        QCoreApplication::exit(1);
    }
}

qint64 SerialCommunication::write(const uint8_t *data, size_t size)
{
    return m_port->write((char *)data, size);
}

qint64 SerialCommunication::write(const QByteArray &data)
{
    return m_port->write(data);
}

size_t SerialCommunication::bytesAvailable()
{
    return m_port->size();
}

void SerialCommunication::open()
{
    if (!m_port->isOpen())
    {
        m_port->open(QIODevice::ReadWrite);
    }
}

void SerialCommunication::close()
{
    if (m_port->isOpen())
    {
        m_port->close();
    }
}


}
