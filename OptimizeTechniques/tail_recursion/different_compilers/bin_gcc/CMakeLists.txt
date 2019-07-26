cmake_minimum_required(VERSION 3.5)

project (gcc_test)

SET (CMAKE_CXX_FLAGS "-pipe -std=c++11 -O2 -g -std=gnu++11 -Wall -W -fPIC")

set(CMAKE_BUILD_TYPE Debug)
#set(CMAKE_BUILD_TYPE Release)

file(GLOB CPP_SOURCES "../../*.cpp")

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_executable(${PROJECT_NAME} ${CPP_SOURCES})


target_link_libraries( ${PROJECT_NAME}
                       benchmark_gcc
                       pthread 
                       dl
)












