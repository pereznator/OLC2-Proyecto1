QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ast.cpp \
    entorno.cpp \
    expresion.cpp \
    lex.yy.c \
    main.cpp \
    mainwindow.cpp \
    parser.cpp \
    parserctx.cpp \
    sentencia.cpp

HEADERS += \
    ast.h \
    entorno.h \
    expresion.h \
    instruccion.h \
    mainwindow.h \
    parser.hpp \
    parserctx.hpp \
    sentencia.h \
    tipo.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    lexer.l \
    parser.y
