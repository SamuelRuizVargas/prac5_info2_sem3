QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bomber.cpp \
    destructibles.cpp \
    main.cpp \
    interfaz.cpp \
    solidos.cpp

HEADERS += \
    bomber.h \
    destructibles.h \
    interfaz.h \
    solidos.h

FORMS += \
    interfaz.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    imagenes/bloque.png \
    imagenes/icono.ico \
    imagenes/icono.png
