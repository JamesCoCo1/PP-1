QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets sql

SOURCES += \
    main.cpp \
    mytcpsocket.cpp \
    tcpserver.cpp

HEADERS += \
    mytcpsocket.h \
    tcpserver.h


