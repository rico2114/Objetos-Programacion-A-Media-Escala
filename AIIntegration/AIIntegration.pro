#-------------------------------------------------
#
# Project created by QtCreator 2016-11-10T00:41:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AIIntegration
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CorpusLoader.cpp \
    Edge.cpp \
    EigenVectorCalculator.cpp \
    Image.cpp \
    ImageManager.cpp \
    NeuralNetwork.cpp \
    Vertex.cpp \

HEADERS  += mainwindow.h \
    CorpusLoader.h \
    Edge.h \
    EigenVectorCalculator.h \
    Image.h \
    ImageManager.h \
    NeuralNetwork.h \
    Vertex.h \

FORMS    += mainwindow.ui
