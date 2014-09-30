TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++1y

SOURCES += main.cpp \
    ciphertext.cpp \
    algorithm.cpp \
    hash.cpp \
    sha512.cpp \
    cryptutils.cpp \
    md5.cpp

HEADERS += \
    ciphertext.h \
    algorithm.h \
    hash.h \
    sha512.h \
    cryptutils.hpp \
    md5.hpp



LIBS += -lcrypto
