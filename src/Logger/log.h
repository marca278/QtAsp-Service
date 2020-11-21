#ifndef LOG_H
#define LOG_H

#include <memory>
#include <string>
#include <stdexcept>
#include <iostream>
#include <QString>
#include <QDateTime>


class Log
{
public:
    template<typename ... Args>
    static void Debug(const std::string& format, Args ... args );
    static void Error(const QString &msg)
    {
        QString time = QDateTime::currentDateTime().toString("hh:mm:ss:zzz");
        std::cout <<"[Error] " << time.toStdString() << " " <<msg.toStdString() << std::endl;
    }
    static void Debug(const QString &msg)
    {
        QString time = QDateTime::currentDateTime().toString("hh:mm:ss:zzz");
        std::cout <<"[Debug] " << time.toStdString() << " " << msg.toStdString() << std::endl;
    }

private:
    Log();
};

template<typename ... Args>
void Log::Debug(const std::string &format, Args ... args)
{
    size_t size = snprintf( nullptr, 0, format.c_str(), args ... ) + 1; // Extra space for '\0'
    if( size <= 0 ){ throw std::runtime_error( "Error during formatting." ); }
    std::unique_ptr<char[]> buf( new char[ size ] );
    snprintf( buf.get(), size, format.c_str(), args ... );
    QString time = QDateTime::currentDateTime().toString("hh:mm:ss:zzz");
    std::cout <<"[Debug] " << time.toStdString() << " " << std::string( buf.get(), buf.get() + size - 1 ) <<std::endl; // We don't want the '\0' inside
}

#endif // LOG_H
