#ifndef ASP_H
#define ASP_H
#include <Asp/aspobject.h>
#include <Asp/aspmessage.h>
#include <Asp/interface.h>
#include <Asp/aspframe.h>

#include <vector>
#include <QDataStream>

using namespace std;

static inline std::vector<uint8_t> Serialize(uint16_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0x00ff));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00) >> 8));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(uint32_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0x000000ff));
    retVal.push_back(static_cast<uint8_t>((val & 0x0000ff00) >> 8));
    retVal.push_back(static_cast<uint8_t>((val & 0x00ff0000) >> 16));
    retVal.push_back(static_cast<uint8_t>((val & 0xff000000) >> 24));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(uint64_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0xff));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00) >> 8));
    retVal.push_back(static_cast<uint8_t>((val & 0xff0000) >> 16));
    retVal.push_back(static_cast<uint8_t>((val & 0xff000000) >> 24));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00000000) >> 32));
    retVal.push_back(static_cast<uint8_t>((val & 0xff0000000000) >> 40));
    retVal.push_back(static_cast<uint8_t>((val & 0xff000000000000) >> 48));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00000000000000) >> 56));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(int16_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0x00ff));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00) >> 8));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(int32_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0x000000ff));
    retVal.push_back(static_cast<uint8_t>((val & 0x0000ff00) >> 8));
    retVal.push_back(static_cast<uint8_t>((val & 0x00ff0000) >> 16));
    retVal.push_back(static_cast<uint8_t>((val & 0xff000000) >> 24));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(int64_t val)
{
    vector<uint8_t> retVal;

    retVal.push_back(static_cast<uint8_t>(val & 0xff));
    retVal.push_back(retVal[1] = static_cast<uint8_t>((val & 0xff00) >> 8));
    retVal.push_back(retVal[2] = static_cast<uint8_t>((val & 0xff0000) >> 16));
    retVal.push_back(retVal[3] = static_cast<uint8_t>((val & 0xff000000) >> 24));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00000000) >> 32));
    retVal.push_back(static_cast<uint8_t>((val & 0xff0000000000) >> 40));
    retVal.push_back(static_cast<uint8_t>((val & 0xff000000000000) >> 48));
    retVal.push_back(static_cast<uint8_t>((val & 0xff00000000000000) >> 56));

    return retVal;
}
static inline std::vector<uint8_t> Serialize(float val)
{
    vector<uint8_t> retVal;

    uint32_t *intVal = reinterpret_cast<uint32_t *>(&val);

    retVal.push_back(static_cast<uint8_t>(*intVal & 0x000000ff));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0x0000ff00) >> 8));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0x00ff0000) >> 16));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff000000) >> 24));

    return retVal;
}

static inline std::vector<uint8_t> Serialize(double val)
{
    vector<uint8_t> retVal;

    uint64_t *intVal = reinterpret_cast<uint64_t *>(&val);

    retVal.push_back(static_cast<uint8_t>(*intVal & 0xff));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff00) >> 8));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff0000) >> 16));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff000000) >> 24));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff00000000) >> 32));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff0000000000) >> 40));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff000000000000) >> 48));
    retVal.push_back(static_cast<uint8_t>((*intVal & 0xff00000000000000) >> 56));


    return retVal;
}

static inline void ConcateVectors(vector<uint8_t> &dest,const vector<uint8_t> &src)
{
    dest.insert(dest.end(), src.begin(), src.end());
}

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

//static inline void insert(QByteArray& ba, quint16 val, quint32 pos)
//{
//    ba[pos] = static_cast<char>(val & 0xff);
//    ba[++pos] = static_cast<char>((val & 0xff00)>>8);
//}

//static inline void insert(QByteArray& ba, quint32 val, quint32 pos)
//{
//    ba[pos] = static_cast<char>(val & 0xff);
//    ba[++pos] = static_cast<char>((val & 0xff00)>>8);
//    ba[++pos] = static_cast<char>((val & 0xff0000)>>16);
//    ba[++pos] = static_cast<char>((val & 0xff000000)>>24);
//}

//static inline void insert(QByteArray& ba, qint8 val, quint32 pos)
//{
//    ba[pos] = static_cast<char>(val);
//}

//static inline void insert(QByteArray& ba, qint16 val, quint32 pos)
//{
//    ba[pos] = static_cast<char>(val & 0xff);
//    ba[++pos] = static_cast<char>((val & 0xff00)>>8);
//}

//static inline void insert(QByteArray& ba, qint32 val, quint32 pos)
//{
//    ba[pos] = static_cast<char>(val & 0xff);
//    ba[++pos] = static_cast<char>((val & 0xff00)>>8);
//    ba[++pos] = static_cast<char>((val & 0xff0000)>>16);
//    ba[++pos] = static_cast<char>((val & 0xff000000)>>24);
//}

#endif // ASP_H
