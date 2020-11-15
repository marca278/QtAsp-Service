#ifndef ASPOBJECT_H
#define ASPOBJECT_H

#include<cstdint>
#include <vector>
#include <iostream>

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

#endif // ASPOBJECT_H
