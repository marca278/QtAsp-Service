#include "aspmessage.h"

namespace Asp {


AspMessage::AspMessage(AspMessageType type, AspObject &obj)
{
    m_vectorStream.clear();
    m_vectorStream.resize(7);

    m_vectorStream[2] = static_cast<uint8_t>(type);

    m_vectorStream.insert(m_vectorStream.begin() + 3, )
};

AspMessage::AspMessage(AspMessageType type, uint16_t id, uint16_t sid, vector<uint8_t> &data) : messageType(type)
{
    aspObject = new AspObject(id, sid, data);
}

uint16_t AspMessage::length()
{
    return m_vectorStream.size();
}

AspMessageType AspMessage::getMessageType()
{

}

vector<uint8_t> AspMessage::messageToVector()
{
    vector<uint8_t> ret;
    uint16_t len = length();

    ret.push_back(len & 0xff); // low byte
    ret.push_back((len & 0xff00) >> 8); // high byte
    ret.push_back(static_cast<uint8_t>(messageType));
    ret.insert(ret.begin(), )
}


}
