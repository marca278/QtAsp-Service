#include "aspframe.h"
#include "Asp/aspHelper.h"

#include <QTextStream>

namespace Asp {

const quint16 AspFrame::preAmble = 0xDEFA;
const quint16 AspFrame::preAmblePosition = 0;
const quint16 AspFrame::lengthPosition = 2;

AspFrame::AspFrame()
{
    insert(buffer, preAmble, preAmblePosition);
    insert(buffer, static_cast<quint16>(4), 2);
}

AspFrame::AspFrame(AspMessage &msg) : AspFrame()
{
    buffer.append(msg.getBuffer());
}

void AspFrame::AddMessage(AspMessage &msg)
{
    buffer.append(msg.getBuffer());
}

QString AspFrame::toString() const
{
    QString string;

    QTextStream stream(&string);

    for (const auto &i : buffer)
    {
        stream << Qt::showbase << Qt::hex << static_cast<quint8>(i) << ", ";
    }

    return string;
}

}

