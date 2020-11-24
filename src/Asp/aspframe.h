#ifndef ASPFRAME_H
#define ASPFRAME_H

#include "Asp/aspmessage.h"

namespace Asp {


class AspFrame
{
private:
    QByteArray buffer;

public:
    static const quint16 preAmble;

    static const quint16 preAmblePosition;
    static const quint16 lengthPosition;

    AspFrame();
    AspFrame(AspMessage &msg);

    void AddMessage(AspMessage &msg);


};

}
#endif // ASPFRAME_H
