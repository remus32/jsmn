cmake_minimum_required(VERSION 3.5)
project(Jsmn)

#set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES native.c jsmn.c)
add_library(jsmn SHARED ${SOURCE_FILES})
