#ifndef ASPHELPER_H
#define ASPHELPER_H

#include <QDataStream>



namespace Asp {

template <typename T>
static inline void insert(QByteArray& ba, T val, quint32 pos)
{
    if((ba.length() + 1) < static_cast<qint32>(pos))
    {
        ba.resize(pos);
    }
    QDataStream st{&ba, QIODevice::WriteOnly};
    st.setByteOrder(QDataStream::LittleEndian);
    st.device()->seek(pos);
    st << val;
}

}

#endif // ASPHELPER_H
