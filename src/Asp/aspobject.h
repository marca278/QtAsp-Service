#ifndef ASPOBJECT_H
#define ASPOBJECT_H

#include<cstdint>
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class Asp2
{
protected:
    uint16_t m_id;
    uint16_t m_sid;
    T *data;

public:
    Asp2()
    {
        m_id = 0;
        m_sid = 0;
    };
    Asp2(uint16_t id, uint16_t sid);

    uint16_t id() const;
    void setId(const uint16_t &id);
    uint16_t sid() const;
    void setSid(const uint16_t &sid);
    void print(void);

};


template<class T>
void Asp2<T>::print(void)
{
    std::cout << "It's the template id: " << m_id << std::endl;
}

template<class T>
Asp2<T>::Asp2(uint16_t id, uint16_t sid) : m_id(id), m_sid(sid){}

template<class T>
uint16_t Asp2<T>::id() const
{
    return m_id;
}

template<class T>
void Asp2<T>::setId(const uint16_t &id)
{
    m_id = id;
}

template<class T>
uint16_t Asp2<T>::sid() const
{
    return m_sid;
}

template<class T>
void Asp2<T>::setSid(const uint16_t &sid)
{
    m_sid = sid;
}

namespace Asp {


class AspObject
{

protected:
    std::vector<uint8_t> m_vectorStream;
    char *formatString;

public:
    uint16_t getId();
    uint16_t setId(uint16_t);
    uint16_t getSid();
    uint16_t setSid(uint16_t);

    AspObject();
    AspObject(uint16_t id, uint16_t sid);
    AspObject(uint16_t id, uint16_t sid, uint8_t *data, size_t dataSize);
    AspObject(uint16_t id, uint16_t sid, vector<uint8_t> &data);
    AspObject(vector<uint8_t> &data);

    void setPayload(const uint8_t *payload, const size_t size);
    void setPayload(const vector<uint8_t> &payload);

    const std::vector<uint8_t>& getPayload() const;
    unsigned getPayloadLength(void) const;

    char *getFormatString() const;
    void setFormatString(const char *value);

    const vector<uint8_t> & toStream(void);


    unsigned length() const;

    std::vector<uint8_t> toVector(void) const;




};

}

#endif // ASPOBJECT_H
