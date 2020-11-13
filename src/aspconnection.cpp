#include "aspconnection.h"
#include <QDebug>
#include <iostream>
#include <QCoreApplication>


AspConnection::AspConnection(QString portName, int baudRate, QObject *parent):
    QObject(parent),
    m_portName(portName),
    m_baudRate(baudRate),
    m_standardOutput(stdout)
{
    m_serialPort = new QSerialPort();
    m_serialPort->setPortName(portName);
    m_serialPort->setBaudRate(baudRate);

    connect(m_serialPort, &QSerialPort::readyRead, this, &AspConnection::handleReadyRead);
    connect(m_serialPort, &QSerialPort::errorOccurred, this, &AspConnection::handleError);

    if (!m_serialPort->open(QIODevice::ReadOnly)) {
        qDebug() << QString("Failed to open port %1, error: %2")
                          .arg(m_portName)
                          .arg(m_serialPort->errorString())
                       << "\n";
    }
    else
    {
        m_standardOutput << "serial port opened \n";
        QByteArray data = m_serialPort->readAll();
        for (const auto& value : data)
        {
            std::cout << value <<";";
        }
        std::cout<<std::endl;
        m_standardOutput << data << '\n';
    }


}

AspConnection::~AspConnection()
{

    std::cout << "closing port" << std::endl;
    if (m_serialPort->isOpen())
    {
        m_serialPort->close();
        delete m_serialPort;
    }
}

void AspConnection::handleReadyRead()
{
    QByteArray data = m_serialPort->readAll();
    for (const auto& value : data)
    {
        std::cout << value <<";";
        if ('q' == value)
        {
            m_serialPort->close();
            QCoreApplication::exit(1);
        }
    }
    std::cout<<std::endl;
    m_standardOutput << data << '\n';
}

void AspConnection::handleError(QSerialPort::SerialPortError serialPortError)
{
    if (serialPortError == QSerialPort::ReadError) {
        m_standardOutput << QObject::tr("An I/O error occurred while reading "
                                        "the data from port %1, error: %2")
                            .arg(m_serialPort->portName())
                            .arg(m_serialPort->errorString())
                         << "\n";
    }
}
