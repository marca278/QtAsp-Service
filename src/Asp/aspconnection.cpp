#include "aspconnection.h"
#include <QDebug>
#include <iostream>
#include <QCoreApplication>
#include <cstdint>

namespace Asp {

Connection::Connection(ICommunication *comInterface, QObject *parent) : QObject(parent), m_interface(comInterface)
{

}

Status Connection::read(uint16_t id, uint16_t sid) const
{

}




}
