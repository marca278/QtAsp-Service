#include <QCoreApplication>
#include <QTextStream>
#include "Asp/aspconnection.h"
#include <QDebug>
#include <iostream>
#include "Asp/aspobject.h"
#include <QByteArray>
#include "test.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int argumentCount = QCoreApplication::arguments().size();
    const QStringList argumentList = QCoreApplication::arguments();

    QTextStream standardOutput(stdout);

    qInfo() << "Is this working?";
    qDebug() << "start application \n";
//    if (argumentCount == 1) {
//        standardOutput << QObject::tr("Usage: %1 <serialportname> [baudrate]")
//                          .arg(argumentList.first())
//                       << "\n";
//        return 1;
//    }
//    int baudrate = (argumentCount > 2) ? argumentList.at(2).toInt() : 115200;

    //AspConnection aspCon(argumentList.at(1), baudrate);


    AspFrame frame;

    AspMessage msg(AspMessageType::WriteRequest, 8, 3, QVector<quint8>({1,2,3,4,6}));
    qDebug() << msg.toString();
    frame.AddMessage(msg);
    qDebug() << frame.toString();

    //Test::TestQDataStream();

    Test_Serial *test23 = new Test_Serial();

    return a.exec();

}
