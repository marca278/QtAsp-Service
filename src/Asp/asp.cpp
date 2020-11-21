#include <Asp/asp.h>


StreamBuffer &StreamBuffer::operator<<(uint8_t val)
{
    push_back(val);

    return *this;
}

StreamBuffer &StreamBuffer::operator<<(uint16_t val)
{
    push_back(val & 0xff);
    push_back((val & 0xff00) >> 8);

    return *this;
}

StreamBuffer &StreamBuffer::operator<<(uint32_t val)
{
    push_back(val & 0xff);
    push_back((val & 0xff00) >> 8);
    push_back((val & 0xff0000) >> 16);
    push_back((val & 0xff000000) >> 24);

    return *this;
}
