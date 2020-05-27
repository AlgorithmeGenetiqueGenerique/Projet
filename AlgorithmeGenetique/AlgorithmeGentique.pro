#-------------------------------------------------
#
# Project created by QtCreator 2020-05-01T12:18:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AlgorithmeGenetic
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11
SOURCES += \
    OP/claviervertuel.cpp \
    OP/notepad.cpp \
        main.cpp \
        OP/mainwindow.cpp \
    OP/modelisationprblm.cpp \
    OP/gene.cpp \
    OP/individu.cpp \
    OP/button.cpp \
    OP/EntreesSorties.cpp \
    OP/evaluation.cpp \
    OP/operationsgenetiques.cpp \
    OP/mythread.cpp \
    Queen/BoxEchiquier.cpp \
    Queen/bouton.cpp \
    Queen/Echiquier.cpp \
    Queen/InterfaceQueen.cpp \
    Queen/Piece.cpp \
    Queen/ProblemeDesHuitDames.cpp \
    mainwindow1.cpp \
    Interface.cpp\
    VoyageurDeCommerce/edge.cpp \
    VoyageurDeCommerce/graphwidget.cpp \
    VoyageurDeCommerce/node.cpp \
    VoyageurDeCommerce/interfaceVoyageur.cpp
    

HEADERS += \
    OP/claviervertuel.h \
        OP/mainwindow.h \
    OP/modelisationprblm.h \
    OP/gene.h \
    OP/individu.h \
    OP/button.h \
    OP/EntreesSorties.h \
    OP/evaluation.h \
    OP/notepad.h \
    OP/operationsgenetiques.h \
    OP/mythread.h \
    Queen/BoxEchiquier.h \
    Queen/bouton.h \
    Queen/Echiquier.h \
    Queen/InterfaceQueen.h \
    Queen/Piece.h \
    Queen/ProblemeDesHuitDames.h \
    Interface.h \
    mainwindow1.h \
    VoyageurDeCommerce/edge.h \
    VoyageurDeCommerce/graphwidget.h \
    VoyageurDeCommerce/node.h \
    VoyageurDeCommerce/interfaceVoyageur.h

FORMS += \
    OP/modelisationprblm.ui \
    OP/notepad.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

STATECHARTS +=

RESOURCES += \
    Queen/Ressource1.qrc \
    OP/Ressources.qrc \
    resource.qrc
RC_FILE = myapp.rc
