#ifndef ASPOBJECT_H
#define ASPOBJECT_H


#include<QVector>
#include <iostream>
#include <QByteArray>

template <class T>
class Asp2
{
protected:
    quint16 m_id;
    quint16 m_sid;
    T *data;

public:
    Asp2()
    {
        m_id = 0;
        m_sid = 0;
    };
    Asp2(quint16 id, quint16 sid);

    quint16 id() const;
    void setId(const quint16 &id);
    quint16 sid() const;
    void setSid(const quint16 &sid);
    void print(void);

};


template<class T>
void Asp2<T>::print(void)
{
    std::cout << "It's the template id: " << m_id << std::endl;
}

template<class T>
Asp2<T>::Asp2(quint16 id, quint16 sid) : m_id(id), m_sid(sid){}

template<class T>
quint16 Asp2<T>::id() const
{
    return m_id;
}

template<class T>
void Asp2<T>::setId(const quint16 &id)
{
    m_id = id;
}

template<class T>
quint16 Asp2<T>::sid() const
{
    return m_sid;
}

template<class T>
void Asp2<T>::setSid(const quint16 &sid)
{
    m_sid = sid;
}

namespace Asp {

class AspObject;


class AspObject
{

protected:

    QByteArray buffer;

public:

    typedef  QVector<quint8>& (*SerialiazeFunction) ();
    AspObject();
    AspObject(const quint16 id,const quint16 sid);
    AspObject(const quint16 id,const  quint16 sid,const QVector<quint8> &data);
    AspObject(const QVector<quint8> &data);
    AspObject(const QByteArray& data);

    template <typename T>
    AspObject(const quint16 id,const quint16 sid,const T& data);
    template <typename T>
    AspObject(const quint16 id, const quint16 sid,const T& data, SerialiazeFunction ptr);

    quint16 getId() const;
    void setId(quint16 id);
    quint16 getSid() const;
    void setSid(quint16 sid);

    quint16 getLength() const;

    QByteArray& getBuffer();
    const QByteArray& getBuffer() const;

public:

    QString formatString;
};

template<typename T>
AspObject::AspObject(const quint16 id, const quint16 sid, const T &data, AspObject::SerialiazeFunction ptr): AspObject(id, sid, data.ptr()){}

template<typename T>
AspObject::AspObject(const quint16 id, const quint16 sid,const T &data) : AspObject(id, sid, data.toVector()){}

}

#endif // ASPOBJECT_H
