QT  += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport sql

HEADERS += \
    mytcpclient.h \
    mytcpserver.h \
    mytcpsocket.h

SOURCES += \
    main.cpp \
    mytcpclient.cpp \
    mytcpserver.cpp \
    mytcpsocket.cpp
