#include "Asp/aspobject.h"
#include <iostream>
#include <QTextStream>

using namespace std;

template<>
void Asp2<int>::print(void)
{
    std::cout << "It's an int id: " << m_id << std::endl;
}

namespace Asp {

AspObject::AspObject()
{
    buffer.resize(4);
    setId(0);
    setSid(0);
}

AspObject::AspObject(const quint16 id, const quint16 sid)
{
    buffer.resize(4);
    setId(id);
    setSid(sid);
}

AspObject::AspObject(const quint16 id,const quint16 sid,const QVector<quint8> &data) : AspObject(id, sid)
{
    for(const auto &i : data)
    {
        buffer.append(static_cast<char>(i));
    }
}

AspObject::AspObject(const QVector<quint8> &data)
{
    for(const auto &i : data)
    {
        buffer.append(static_cast<char>(i));
    }
}

AspObject::AspObject(const QByteArray &data)
{
    buffer = QByteArray(data);
}

quint16 AspObject::getId() const
{
    return static_cast<quint16>((buffer[1] << 8) | buffer[0]);
}

void AspObject::setId(quint16 id)
{
    buffer[0] = static_cast<char>(id & 0xff);
    buffer[1] = static_cast<char>((id & 0xff00) >> 8);
}

quint16 AspObject::getSid() const
{
    return static_cast<quint16>((buffer[3] << 8) | buffer[2]);
}

void AspObject::setSid(quint16 sid)
{
    buffer[2] = static_cast<char>(sid & 0xff);
    buffer[3] = static_cast<char>((sid & 0xff00) >> 8);
}

quint16 AspObject::getLength() const
{
    return static_cast<quint16>(buffer.length());
}

const QByteArray &AspObject::getBuffer() const
{
    return buffer;
}

QByteArray AspObject::getPayload() const
{
    return buffer.mid(4);
}

QString AspObject::toString()
{
    QString string;
    QTextStream stream(&string);

    stream << "Id: " << getId() << "; Sid: " << getSid() << " Data: ";
    for (const auto &i: getPayload())
    {
        stream << static_cast<quint8>(i) <<", ";
    }

    return string;
}

}
