#include "Simulatie.h"
#include "LoggerOutput.h"
#include "XmlParser.h"

int main() {
    LoggerOutput::initialize("traffic_simulation.log");
    runSimulation();
    LoggerOutput::cleanup();
    return 0;
}
