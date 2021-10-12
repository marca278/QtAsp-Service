#ifndef ASPMESSAGE_H
#define ASPMESSAGE_H

#include <QByteArray>
#include <QMap>
#include <Asp/aspobject.h>

namespace  Asp{

enum class AspMessageType : quint8 {ReadRequest = 1, WriteRequest = 2, AsyncNotify = 3, Stream = 4, ReadAnswer = 5,
                                     WriteOk = 6, AsyncAck = 7, ReadError = 8, WriteError = 9, Unknown=255};


class AspMessage
{
private:
    QByteArray buffer;
    QMap<AspMessageType, QString> typeToStringMap;


public:
    static const quint16 lengthPosition;
    static const quint16 typePosition;
    static const quint16 idPosition;
    static const quint16 sidPosition;
    static const quint16 dataPosition;

    AspMessage();
    AspMessage(AspMessageType type,const AspObject &obj);
    AspMessage(AspMessageType type, quint16 id, quint16 sid, const QByteArray *data = nullptr);
    AspMessage(AspMessageType type, quint16 id, quint16 sid, const QVector<quint8> data = QVector<quint8>());

    quint16 length();
    AspMessageType getMessageType();
    QString getTypeAsString();
    AspObject getAspObject();

    QVector<quint8> toVector();
    const QByteArray &getBuffer() const;

    QString toString();

};
}

#endif // ASPMESSAGE_H
