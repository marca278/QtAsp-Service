#include "aspframe.h"

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

}

