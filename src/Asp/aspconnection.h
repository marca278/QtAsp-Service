#ifndef ASPCONNECTION_H
#define ASPCONNECTION_H

#include <QObject>
#include <QByteArray>
#include <QSerialPort>
#include <QTextStream>

#include <Asp/asp.h>

using namespace std;

namespace Asp {


enum class Status {Ok, Error, Timeout};

class Connection : public QObject
{
    Q_OBJECT

private:
    ICommunication *m_interface;

public:
    Connection(ICommunication *comInterface, QObject *parent = nullptr);
    Status read(uint16_t id, uint16_t sid) const;
    Status read(AspObject &obj) const;
    Status write(uint16_t id, uint16_t sid,uint8_t *data) const;
    Status write(uint16_t id, uint16_t sid,vector<uint8_t> &data) const;
    Status write(const AspObject &obj) const;
};

}

#endif // ASPCONNECTION_H
