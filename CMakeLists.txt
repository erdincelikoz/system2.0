cmake_minimum_required(VERSION 3.30)
project(system2_0)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -Werror -O2")
set(CMAKE_EXE_LINKER_FLAGS -pthread)
enable_testing()

# Inclusie van je eigen source directory
include_directories(${PROJECT_SOURCE_DIR}/src)

# Inclusie van GTest headers (die je lokaal hebt)
include_directories(${CMAKE_SOURCE_DIR}/gtest/include)

# ---------- Executable: productiesysteem ----------
add_executable(system2_0
        main.cpp
        src/Baan.cpp src/Baan.h
        src/XmlParser.cpp src/XmlParser.h
        src/Voertuig.cpp src/Voertuig.h
        src/Verkeerslicht.cpp src/Verkeerslicht.h
        src/Voertuiggenerator.cpp src/Voertuiggenerator.h
        src/tinyxml.cpp src/tinystr.cpp
        src/tinyxmlparser.cpp src/tinyxmlerror.cpp
        src/Bushalte.cpp
        src/Bushalte.h
        src/Kruispunt.cpp
        src/Kruispunt.h
        src/Simulatie.cpp
        src/Simulatie.h
        src/LoggerOutput.cpp
        src/LoggerOutput.h
        src/Bus.cpp
        src/Bus.h
        src/Auto.cpp
        src/Auto.h
        src/Brandweerwagen.cpp
        src/Brandweerwagen.h
        src/Ziekenwagen.cpp
        src/Ziekenwagen.h
        src/Politiecombi.cpp
        src/Politiecombi.h
        src/DesignByContract.h

)

# ---------- Executable: testprogramma ----------
add_executable(verkeers_tests
        tests/VoertuigTests.cpp
        tests/XmlParserTests.cpp
        src/Baan.cpp
        src/XmlParser.cpp
        src/Voertuig.cpp
        src/Verkeerslicht.cpp
        src/Voertuiggenerator.cpp
        src/tinyxml.cpp
        src/tinystr.cpp
        src/tinyxmlparser.cpp
        src/tinyxmlerror.cpp
        src/Bushalte.cpp
        src/Bushalte.h
        src/Kruispunt.cpp
        src/Kruispunt.h
        src/Simulatie.cpp
        src/Simulatie.h
        src/LoggerOutput.cpp
        src/LoggerOutput.h
        src/Bus.cpp
        src/Bus.h
        src/Auto.cpp
        src/Auto.h
        src/Brandweerwagen.cpp
        src/Brandweerwagen.h
        src/Ziekenwagen.cpp
        src/Ziekenwagen.h
        src/Politiecombi.cpp
        src/Politiecombi.h
)

# ---------- Link testprogramma met GTest ----------
target_link_libraries(verkeers_tests
        ${CMAKE_SOURCE_DIR}/gtest/lib/libgtest.a
        ${CMAKE_SOURCE_DIR}/gtest/lib/libgtest_main.a
        pthread
)

# Voeg test toe aan CTest systeem (optioneel)
add_test(NAME VerkeersTests COMMAND verkeers_tests)
