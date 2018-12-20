TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++17

SOURCES += main.cpp \
           udemyBuild/Facets.cpp \
           udemyBuild/Person.cpp \
           udemyBuild/PersonBuilder.cpp \
    builderexercise.cpp


HEADERS += \
    simplebuilder.h \
    groovystylebuilder.h \
    udemyBuild/Facets.h \
    udemyBuild/Person.h \
    udemyBuild/PersonBuilder.h \
    classtypebuilder.h \
    builderexercise.h
