#ifndef INTERFACE_H
#define INTERFACE_H

#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>
#include <vector>
#include <QQueue>

namespace  Asp{

class ICommunication : public QObject
{
    Q_OBJECT


public:
    ICommunication(QObject *parent) : QObject(parent) {};
    virtual qint64 write(const uint8_t *data, size_t size) = 0;
    virtual qint64 write(const QByteArray &data) = 0;

    virtual size_t bytesAvailable() = 0;
    virtual void open() =0;
    virtual void close() = 0;

    virtual ~ICommunication() {};

signals:
    void readyRead();

};

class SerialCommunication : public ICommunication
{
    Q_OBJECT

public:
    explicit SerialCommunication(QString portName, int baudRate, QObject *parent = nullptr);
    ~SerialCommunication();

private slots:
    void handleReadyRead();
    // void handleTimeout();
    void handleError(QSerialPort::SerialPortError error);

private:
    QString m_portName;
    int m_baudRate;
    QSerialPort *m_port;
    QByteArray m_readData;
    QTextStream m_standardOutput;
    QByteArray m_readBuffer;



    // ICommunication interface
public:
    qint64 write(const uint8_t *data, size_t size) override;
    qint64 write(const QByteArray &data) override;


    // ICommunication interface
public:
    size_t bytesAvailable() override;

    // ICommunication interface
public:
    void open() override;
    void close() override;
};

}
#endif // INTERFACE_H
