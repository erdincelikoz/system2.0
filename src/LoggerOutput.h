//===========================//
// LoggerOutput.h
//===========================//

/**
 * @file LoggerOutput.h
 * @brief Logging klasse voor simulatie.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#ifndef LOGGEROUTPUT_H
#define LOGGEROUTPUT_H

#include <fstream>
#include <iostream>
#include <string>
#include "DesignByContract.h"
using namespace std;

class LoggerOutput {
public:
    enum Level { INFO, DEBUG, ERROR };

    /**
     * REQUIRE(filename != "", "log file name must not be empty")
     * ENSURE(logFile.is_open(), "Could not open log file")
     */
    static void initialize(const string& filename= "simulation.log");

    /**
 * REQUIRE(logFile.is_open(), "Log file already cleaned");
 * ENSURE(!logFile.is_open(), "Could not close log file")
 */
    static void cleanup();

    /**
     *REQUIRE(logFile.is_open(), "Could not open log file")
     *ENSURE(!fullMessage.empty(), "Log message must not be empty")
     *ENSURE(logFile.tellp() > 0, "Log file is still empty after writing")
     */
    static void log(const string& message, Level level = INFO);

private:
    static ofstream logFile;
};
#endif //LOGGLOGGEROUTPUT_H