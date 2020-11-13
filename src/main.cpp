#include <QCoreApplication>
#include <QTextStream>
#include "aspconnection.h"
#include <QDebug>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    const int argumentCount = QCoreApplication::arguments().size();
    const QStringList argumentList = QCoreApplication::arguments();

    QTextStream standardOutput(stdout);

    qDebug() << "start application \n";
    if (argumentCount == 1) {
        standardOutput << QObject::tr("Usage: %1 <serialportname> [baudrate]")
                          .arg(argumentList.first())
                       << "\n";
        return 1;
    }
    int baudrate = (argumentCount > 2) ? argumentList.at(2).toInt() : 115200;

    AspConnection aspCon(argumentList.at(1), baudrate);


    return a.exec();
}