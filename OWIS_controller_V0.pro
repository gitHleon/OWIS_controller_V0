#-------------------------------------------------
#
# Project created by QtCreator 2019-06-06T15:15:53
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OWIS_controller_V0
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
CONFIG += static

include(QJoysticks-master\QJoysticks.pri)

SOURCES += \
        initialization.cpp \
        main.cpp \
        master_stages.cpp \
        movement_stages.cpp \
        owis_controller.cpp \
        update_stages.cpp
#        QJoysticks-master\src\Qjoysticks.cpp
#        QJoysticks-master\src\Qjoysticks\SDL_Joysticks.cpp \
#        QJoysticks-master\src\Qjoysticks\VirtualJoysticks.cpp \
#        QJoysticks-master\src\Qjoysticks\Android_Joystick.cpp
HEADERS += \
        owis_controller.h \
        x86\ps90.h
#        QJoysticks-master\src\Qjoysticks.h
#        QJoysticks-master\src\Qjoysticks\SDL_Joysticks.h \
#        QJoysticks-master\src\Qjoysticks\VirtualJoystics.h \
#        QJoysticks-master\src\Qjoysticks\Android_Joystick.h \
#        QJoysticks-master\src\Qjoysticks\JoysticksCommon.h


FORMS += \
        owis_controller.ui

#LIBS += F:\Users\leon\Documents\ATLAS\ENSAMBLAJE_MODULOS\setup_metrologia_OWIS\OWIS_stages\programming\Pablo\OWIS_controller_V0\ps90.dll
#LIBS += F:\Users\leon\Documents\ATLAS\ENSAMBLAJE_MODULOS\setup_metrologia_OWIS\OWIS_stages\programming\Pablo\OWIS_controller_V0\x86\ps90.lib

LIBS += C:\OWIS\OWIS_controller_V0\ps90.dll
LIBS += C:\OWIS\OWIS_controller_V0\x86\ps90.lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


