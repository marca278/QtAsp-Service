#include <iostream>
#include <QByteArray>
#include <QDataStream>
#include <QIODevice>

void test_datastream(void)
{
    QByteArray ar;

    ar.append(23);
    ar.append(0xaa);
    ar.append(0xff);
    ar.append(0x10);

    QDataStream rd(&ar, QIODevice::ReadOnly);
    QDataStream wr(&ar, QIODevice::WriteOnly);

    unsigned char a = 0;
    rd >> a;
    std::cout << (int)a << std::endl;
    rd >> a;
    std::cout << (int)a << std::endl;
    rd >> a;
    std::cout << (int)a << " " << rd.atEnd() << std::endl;
    rd >> a;
    std::cout << (int)a << rd.atEnd() << std::endl;
    rd >> a;
    std::cout << (int)a << rd.device()->size() << std::endl;

    char data[] = {static_cast<char>(0xb0), static_cast<char>(0xb1), static_cast<char>(0xb2), static_cast<char>(0xb3)};
    wr.writeRawData(data, 4);
    std::cout <<rd.device()->size() << std::endl;

}
