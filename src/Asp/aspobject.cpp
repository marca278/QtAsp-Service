#include "Asp/aspobject.h"
#include <iostream>
#include <cstring>

using namespace std;

template<>
void Asp2<int>::print(void)
{
    std::cout << "It's an int id: " << m_id << std::endl;
}

namespace Asp {

AspObject::AspObject()
{
    m_vectorStream.clear();
    for(int i = 0; i<4; i++)
        m_vectorStream.push_back(0);
}

AspObject::AspObject(uint16_t id, uint16_t sid) : AspObject()
{
    setId(id);
    setSid(sid);
}

AspObject::AspObject(uint16_t id, uint16_t sid, uint8_t *data, size_t dataSize) : AspObject(id, sid)
{
    this->setPayload(data, dataSize);
}

AspObject::AspObject(uint16_t id, uint16_t sid, vector<uint8_t> &data) : AspObject(id, sid)
{
   setPayload(data);
}

AspObject::AspObject(vector<uint8_t> &data)
{
    m_vectorStream.clear();
    m_vectorStream.insert(m_vectorStream.begin(), data.begin(), data.end());
}

void AspObject::setPayload(const uint8_t *payload, const size_t size)
{
    m_vectorStream.resize(4);

    for(unsigned i=0; i< size; i++)
    {
        m_vectorStream.push_back(payload[i]);
    }

}

void AspObject::setPayload(const vector<uint8_t> &payload)
{
    m_vectorStream.resize(4);

    m_vectorStream.insert(m_vectorStream.begin() + 4, payload.begin(), payload.end());
}

char *AspObject::getFormatString() const
{
    return formatString;
}

void AspObject::setFormatString(const char *value)
{
    size_t len = std::strlen(value);
    if(len < 1000)
    {
        formatString = new char[len];
    }

}

unsigned AspObject::getPayloadLength() const
{
    return this->length() - 4;
}

unsigned AspObject::length() const
{
    return m_vectorStream.size();
}

std::vector<uint8_t> AspObject::toVector() const
{
    vector<uint8_t> v(m_vectorStream);
    return v;
}

}
