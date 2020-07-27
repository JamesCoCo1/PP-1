QT  += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets serialport sql

SOURCES += \
    cloudmonitor.cpp \
    interfacedisplay.cpp \
    main.cpp \
    monitorclient.cpp \
    mytcpclient.cpp \
    qserialrxecg.cpp \
    qserialrxibp2.cpp \
    qserialrxspo2.cpp \
    qserialtxecg.cpp \
    qserialtxibp2.cpp \
    qserialtxspo2.cpp \
    qseriarxibp2.cpp \
    qwidgetdraw.cpp \
    qwidgetdrawfromserial.cpp \
    qwidgetserialrx.cpp \
    qwidgetserialtx.cpp

HEADERS += \
    cloudmonitor.h \
    interfacedisplay.h \
    monitorclient.h \
    mytcpclient.h \
    qserialrxecg.h \
    qserialrxibp2.h \
    qserialrxspo2.h \
    qserialtxecg.h \
    qserialtxibp2.h \
    qserialtxspo2.h \
    qseriarxibp2.h \
    qwidgetdraw.h \
    qwidgetdrawfromserial.h \
    qwidgetserialrx.h \
    qwidgetserialtx.h
