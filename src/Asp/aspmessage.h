#ifndef ASPMESSAGE_H
#define ASPMESSAGE_H

#include <cstdint>
#include <vector>
#include <Asp/asp.h>

namespace  Asp{


using namespace std;
enum class AspMessageType : uint8_t {ReadRequest = 1, WriteRequest = 2, AsyncNotify = 3, Stream = 4, ReadAnswer = 5,
                                     WriteOk = 6, AsyncAck = 7, ReadError = 8, WriteError = 9, Unknown=255};


class AspMessage
{
private:
    vector<uint8_t> m_vectorStream;

public:
    AspMessage(AspMessageType type, AspObject &obj);
    AspMessage(AspMessageType, uint16_t id, uint16_t sid, uint8_t *data = nullptr);
    AspMessage(AspMessageType, uint16_t id, uint16_t sid, vector<uint8_t> &data);

    uint16_t length();
    AspMessageType getMessageType();
    AspObject getAspObject();

    vector<uint8_t> messageToVector();

};
}

#endif // ASPMESSAGE_H
