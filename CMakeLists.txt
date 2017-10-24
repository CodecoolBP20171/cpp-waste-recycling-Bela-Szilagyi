cmake_minimum_required(VERSION 3.8)
project(cpp_waste_recycling)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES main.cpp Garbage.cpp Garbage.h PaperGarbage.cpp PaperGarbage.h PlasticGarbage.cpp PlasticGarbage.h Dustbin.cpp Dustbin.h tests/test.cpp Exceptions.hpp Dustbin9000.h MetalGarbage.h BottleCap.h Dustbin9000.cpp Commands.hpp ConsoleInterface.cpp ConsoleInterface.h)
add_executable(cpp_waste_recycling ${SOURCE_FILES} MetalGarbage.h BottleCap.h Dustbin9000.cpp Commands.hpp ConsoleInterface.cpp ConsoleInterface.h)
target_link_libraries(cpp_waste_recycling gtest gtest_main)