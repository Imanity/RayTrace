#-------------------------------------------------
#
# Project created by QtCreator 2017-11-18T15:40:32
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RayTrace
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    vec3.cpp \
    ray.cpp \
    perspectivecamera.cpp \
    plane.cpp \
    scene.cpp \
    geometry.cpp \
    raytracer.cpp \
    sphere.cpp \
    orthogonalcamera.cpp \
    utility.cpp \
    pointlight.cpp \
    chesstexture.cpp \
    objloader.cpp \
    aabb.cpp

HEADERS += \
        mainwindow.h \
    vec3.h \
    ray.h \
    perspectivecamera.h \
    plane.h \
    utility.h \
    scene.h \
    geometry.h \
    raytracer.h \
    sphere.h \
    orthogonalcamera.h \
    pointlight.h \
    chesstexture.h \
    objloader.h \
    aabb.h

FORMS += \
        mainwindow.ui
