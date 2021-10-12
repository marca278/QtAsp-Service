#include "aspmessage.h"
#include "Asp/aspHelper.h"
#include <QTextStream>
#include <QDebug>

namespace Asp {

const quint16 AspMessage::lengthPosition = 0;
const quint16 AspMessage::typePosition = 2;
const quint16 AspMessage::idPosition = 3;
const quint16 AspMessage::sidPosition = 5;
const quint16 AspMessage::dataPosition = 7;

AspMessage::AspMessage()
{
    typeToStringMap[AspMessageType::ReadRequest] = "Read Request";
    typeToStringMap[AspMessageType::ReadAnswer] = "Read Answer";
    typeToStringMap[AspMessageType::ReadError] = "Read Error";
    typeToStringMap[AspMessageType::WriteRequest] = "Write Request";
    typeToStringMap[AspMessageType::WriteOk] = "Write Ok";
    typeToStringMap[AspMessageType::WriteError] = "Write Error";
    typeToStringMap[AspMessageType::Stream] = "Stream";
    typeToStringMap[AspMessageType::AsyncNotify] = "Async Notify";
    typeToStringMap[AspMessageType::AsyncAck] = "Async Ack";
    typeToStringMap[AspMessageType::Unknown] = "Unknown";
}

AspMessage::AspMessage(AspMessageType type, const AspObject &obj) : AspMessage()
{
    quint16 len = 3 + obj.getLength();
    buffer.resize(len);
    insert(buffer, len, 0);
    insert(buffer, static_cast<quint8>(type), 2);

    for(const auto &i : obj.getBuffer())
    {
       buffer.append(static_cast<char>(i));
    }
};

AspMessage::AspMessage(AspMessageType type, quint16 id, quint16 sid, const QByteArray *data) : AspMessage()
{

    quint16 len = 3 + 2 + 2;
    if(data != nullptr)
        len += data->length();

    buffer.resize(len);
    insert(buffer, len, lengthPosition);
    insert(buffer, static_cast<quint8>(type), typePosition);
    insert(buffer, id, idPosition);
    insert(buffer, sid, sidPosition);

    if (data != nullptr)
        buffer.append(*data);

}

AspMessage::AspMessage(AspMessageType type, quint16 id, quint16 sid, const QVector<quint8> data)
{

    quint16 len = 3 + 2 + 2;
    len += data.length();

    insert(buffer, len, lengthPosition);
    insert(buffer, static_cast<quint8>(type), typePosition);
    insert(buffer, id, idPosition);
    insert(buffer, sid, sidPosition);

    if (data.length() != 0)
    {
        for (const auto &i : data)
            buffer.append(i);
    }
}

quint16 AspMessage::length()
{
    return buffer.length();
}

AspMessageType AspMessage::getMessageType()
{
    return static_cast<AspMessageType>(static_cast<quint8>(buffer[2]));
}

QString AspMessage::getTypeAsString()
{
    return typeToStringMap[getMessageType()];
}

QVector<quint8> AspMessage::toVector()
{
    QVector<quint8>ret;

    for (const auto &i : buffer)
    {
        ret.append(i);
    }
    return ret;
}

const QByteArray &AspMessage::getBuffer() const
{
    return buffer;
}

QString AspMessage::toString()
{
    QString string;
    QTextStream stream(&string);

    stream << "Type: " << getTypeAsString() << " " << getAspObject().toString();

    return string;
}

AspObject AspMessage::getAspObject()
{
    AspObject obj(buffer.mid(idPosition, length() - 3));
    return obj;
}

}
