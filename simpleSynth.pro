######################################################################
# Automatically generated by qmake (2.01a) Sat Dec 19 11:49:03 2009
######################################################################

TEMPLATE = app
TARGET = 
DEPENDPATH += .
INCLUDEPATH += .

# Input
HEADERS += gui.hpp jack.hpp synth.hpp adsr.hpp envelope.hpp note.hpp qknob.hpp
SOURCES += gui.cpp jack.cpp synth.cpp main.cpp envelope.cpp

CONFIG += link_pkgconfig
PKGCONFIG += jack
