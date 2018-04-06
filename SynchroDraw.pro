QT -= gui
QT += widgets network

CONFIG += c++11 console
CONFIG -= app_bundle

DEFINES += QT_DEPRECATED_WARNINGS

SOURCES += main.cpp \
    MouseHandler.cpp \
    Server.cpp \
    KeyboardHandler.cpp \
    ScreenViewer.cpp

HEADERS += \
    MouseHandler.h \
    Server.h \
    KeyboardHandler.h \
    ScreenViewer.h
