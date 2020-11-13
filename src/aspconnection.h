#ifndef ASPCONNECTION_H
#define ASPCONNECTION_H

#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>

class AspConnection : public QObject
{
    Q_OBJECT
public:
    explicit AspConnection(QString portName, int baudRate, QObject *parent = nullptr);
    ~AspConnection();

private slots:
    void handleReadyRead();
   // void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QString m_portName;
    int m_baudRate;
    QSerialPort *m_serialPort = nullptr;
    QByteArray m_readData;
    QTextStream m_standardOutput;

};

#endif // ASPCONNECTION_H
