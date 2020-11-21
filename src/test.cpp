#include <test.h>
#include <Asp/asp.h>
#include <Logger/log.h>
#include <Asp/interface.h>
#include <QTextStream>
#include <QString>

using namespace Asp;
void test2(void)
{
    Asp2<double> a;
    a.print();
    a.setId(23);
    a.print();

    Asp2<int> b;
    b.print();
    b.setId(56);
    b.print();

    Asp2<float> c(24, 45);
    c.print();
}

void test_logger(void)
{
    Log::Debug("Simple text");
    Log::Debug("Simple dez %d", 123);
    Log::Debug("Simple hex %x", 123);
}

void test_asp(void)
{
    uint8_t data[] = {1,2,3,4,5};
    AspObject obj(12, 34, data, sizeof(data));

    AspMessage m(AspMessageType::WriteRequest, &obj);

    Log::Debug("id: %d  sid: %d", m.Id(), m.Sid());


}



Test_Serial::Test_Serial()
{

    Log::Debug("Port eingeben: \n");
    char portname[128];
    std::cin.getline(portname, 128);


    ser = new SerialCommunication(portname, 115200);

    connect(ser, &SerialCommunication::readyRead, this, &Test_Serial::handle_data_Ready);
}

Test_Serial::~Test_Serial()
{

}

void Test_Serial::handle_data_Ready()
{
    Log::Debug("Handle ready read");
}
