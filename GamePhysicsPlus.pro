QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    andardungeon.cpp \
    arma.cpp \
    bfs.cpp \
    disparo.cpp \
    ground.cpp \
    iinterfacejogo.cpp \
    jogador.cpp \
    list.cpp \
    livingelement.cpp \
    main.cpp \
    mainwindow.cpp \
    monstro.cpp \
    nodelist.cpp \
    nodestack.cpp \
    nodetree.cpp \
    stack.cpp \
    stone.cpp \
    thing.cpp \
    treeavl.cpp

HEADERS += \
    andardungeon.h \
    arma.h \
    bfs.h \
    disparo.h \
    ground.h \
    iinterfacejogo.h \
    jogador.h \
    list.h \
    livingelement.h \
    mainwindow.h \
    monstro.h \
    nodelist.h \
    nodestack.h \
    nodetree.h \
    stack.h \
    stone.h \
    thing.h \
    treeavl.h

FORMS += \
    iinterfacejogo.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
