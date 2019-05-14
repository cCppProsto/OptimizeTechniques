TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

#QMAKE_CXXFLAGS += -O0
#QMAKE_CXXFLAGS += -O1
#QMAKE_CXXFLAGS += -O2
QMAKE_CXXFLAGS += -O3
#QMAKE_CXXFLAGS += -Os
#QMAKE_CXXFLAGS += -Ofast

# https://github.com/google/benchmark
LIBS += -lbenchmark

LIBS += -lpthread -ldl
