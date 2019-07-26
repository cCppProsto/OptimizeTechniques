TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

QMAKE_CXXFLAGS += -std=c++11
#QMAKE_CXXFLAGS += -std=c++14
#QMAKE_CXXFLAGS += -std=c++17

#QMAKE_CXXFLAGS += -O0
#QMAKE_CXXFLAGS += -O1
#QMAKE_CXXFLAGS += -O2
QMAKE_CXXFLAGS += -O3
#QMAKE_CXXFLAGS += -Os
#QMAKE_CXXFLAGS += -Og
#QMAKE_CXXFLAGS += -Ofast

# https://github.com/google/benchmark
LIBS += -lbenchmark

LIBS += -lpthread -ldl

DISTFILES += \
  different_compilers/bin_clang/CMakeLists.txt \
  different_compilers/bin_gcc/CMakeLists.txt \
  different_compilers/bin_icc/CMakeLists.txt
