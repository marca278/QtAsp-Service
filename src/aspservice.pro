QT -= gui
QT += serialport

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        Asp/asp.cpp \
        Asp/aspcoder.cpp \
        Asp/aspconnection.cpp \
        Asp/aspframe.cpp \
        Asp/aspmessage.cpp \
        Asp/aspobject.cpp \
        Asp/interface.cpp \
        Logger/log.cpp \
        main.cpp \
        test.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    Asp/asp.h \
    Asp/aspHelper.h \
    Asp/aspcoder.h \
    Asp/aspconnection.h \
    Asp/aspframe.h \
    Asp/aspmessage.h \
    Asp/aspobject.h \
    Asp/interface.h \
    Logger/log.h \
    test.h
