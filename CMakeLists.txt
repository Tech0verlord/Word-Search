cmake_minimum_required(VERSION 3.3)
project(Program_2__Word_Search_)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror -Wno-unused-variable")

set(SOURCE_FILES
    wordsearch.c)

add_executable(wordsearch ${SOURCE_FILES})