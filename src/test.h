#ifndef TEST_H
#define TEST_H
#include <Asp/asp.h>
#include <Logger/log.h>
#include <Asp/interface.h>
#include <QDataStream>
#include <QByteArray>
#include <QString>
using namespace Asp;

class Test
{
public:
    static void TestQDataStream(void)
    {
        QByteArray array;
        QDataStream rd(&array, QIODevice::ReadOnly);
        QDataStream wr(&array, QIODevice::WriteOnly);

        for (int i=0; i< 10; i++)
        {
            wr << (uint8_t)0xaa;
        }

        Log::Debug(QString("size %1").arg(array.length()));
        Log::Debug(QString("size2 %1").arg(rd.device()->bytesAvailable()));
        Log::Debug(QString("size3 %1").arg(array.capacity()));

        for (int i=0; i< 5; i++)
        {
            uint8_t data;
            rd >> data;
        }
        Log::Debug(QString("size %1").arg(array.length()));
        Log::Debug(QString("size2 %1").arg(rd.device()->bytesAvailable()));
        Log::Debug(QString("size3 %1").arg(array.capacity()));

        wr.device()->reset();
        for (int i=0; i< 2; i++)
        {
            wr << (uint8_t)0xbb;
        }
        Log::Debug(QString("size %1").arg(array.length()));
        Log::Debug(QString("size2 %1").arg(rd.device()->bytesAvailable()));
        Log::Debug(QString("size3 %1").arg(array.capacity()));

        for (int i=0; i< 2; i++)
        {
            uint8_t data;
            rd >> data;
            Log::Debug(QString("%1").arg(data, 0, 16));
        }

    }
};


class Test_Serial : public QObject
{
    Q_OBJECT
private:
    SerialCommunication *ser;

public:
    Test_Serial();
    ~Test_Serial();

private slots:
    void handle_data_Ready(void);

};

#endif // TEST_H
