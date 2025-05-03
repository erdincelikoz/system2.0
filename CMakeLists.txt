cmake_minimum_required(VERSION 3.30)
project(system2_0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_STANDARD 20)
enable_testing()

# reference: https://google.github.io/googletest/quickstart-cmake.html

find_package(GTest REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/src ${GTEST_INCLUDE_DIRS})

# Set Library dir
link_directories(${CMAKE_SOURCE_DIR}/gtest/lib)

add_executable(system2_0 main.cpp
        src/Baan.cpp
        src/Baan.h
        src/XmlParser.cpp
        src/XmlParser.h
        src/Voertuig.cpp
        src/Voertuig.h
        src/Verkeerslicht.cpp
        src/Verkeerslicht.h
        src/Voertuiggenerator.cpp
        src/Voertuiggenerator.h)
# src files for release
#///
# src files for debug
#///
target_link_libraries(target_link_libraries(verkeers_tests gtest))