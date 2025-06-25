//===========================//
// LoggerOutput.cpp
//===========================//

/**
 * @file LoggerOutput.cpp
 * @brief Initialisatie van statisch bestand voor loggen.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#include "LoggerOutput.h"

ofstream LoggerOutput::logFile;

void LoggerOutput::initialize(const string& filename ) {
    REQUIRE(filename != "", "log file name must not be empty");
    logFile.open(filename, ios::out | ios::trunc);
    ENSURE(logFile.is_open(), "Could not open log file");
}
void LoggerOutput::cleanup() {
    REQUIRE(logFile.is_open(), "Log file already cleaned");
    if (logFile.is_open()) {
        logFile.close();
    }
    ENSURE(!logFile.is_open(), "Could not close log file");
}

void LoggerOutput::log(const string& message, Level level) {
    REQUIRE(logFile.is_open(), "Could not open log file");
    string prefix;
    switch (level) {
        case INFO: prefix = "[INFO] "; break;
        case DEBUG: prefix = "[DEBUG] "; break;
        case ERROR: prefix = "[ERROR] "; break;
    }

    string fullMessage = prefix + message;
    ENSURE(!fullMessage.empty(), "Log message must not be empty");
    cout << fullMessage << endl; //output naar console

    logFile << fullMessage << endl;
    logFile.flush();

    logFile.seekp(0, ios::end);
    ENSURE(logFile.tellp() > 0, "Log file is still empty after writing");
}
