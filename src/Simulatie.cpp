/**
 * @file Simulatie.cpp
 * @brief Uitvoeren van de verkeerssimulatie en verkeerslichtlogica.
 * @author Raj Shah en Erdin Celikoz
 * @date 23 juni 2025
 * @version 1.0
 */

#include "Simulatie.h"
#include "LoggerOutput.h"
#include <chrono>
#include <thread>
#include <cmath>
using namespace std::this_thread;
using namespace std::chrono;

/**
 * @brief Schakelt verkeerslichten van kleur op basis van hun cyclustijd.
 * @param verkeerslichten Vector met verkeerslichten die mogelijk van kleur moeten veranderen.
 * @param tijd De huidige simulatietijd.
 */
void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd) {
    REQUIRE(tijd >= 0, "time must not be negative");
    for (Verkeerslicht& verkeerslicht : verkeerslichten) {
        Verkeerslicht temp = verkeerslicht;
        if (tijd % verkeerslicht.getCyclus() == 0) {
            verkeerslicht.setKleur(verkeerslicht.getKleur() ? false : true);
            LoggerOutput::log("Verkeerslicht met cyclus " + to_string(verkeerslicht.getCyclus()) + " verandert naar "
                              + (verkeerslicht.getKleur() ? "groen" : "rood"), LoggerOutput::DEBUG);
            ENSURE(verkeerslicht.getKleur() != temp.getKleur(), "verkeerslicht color change failed");
        }
    }
}

/**
 * @brief Initialiseert alle verkeerslichten met de groene kleur.
 * @param verkeerslichten Vector met verkeerslichten die geïnitialiseerd moeten worden.
 */
void defineKleur(vector<Verkeerslicht>& verkeerslichten) {
    for (Verkeerslicht& verkeerslicht : verkeerslichten) {
        verkeerslicht.setKleur(true);
    }
}

/**
 * @brief Voert de verkeerssimulatie uit.
 * @details Leest invoerdata via XmlParser, initialiseert instellingen en voert de simulatie in tijdstappen uit.
 */
void runSimulation() {
    XmlParser parser("src/input.xml");
    parser.parse();
    int tijd = 0;
    while (true) {
        if (tijd == 0) {
            Voertuig::defineGewensteMaxSnelheid(parser.getParsedVoertuigen());
            Voertuig::defineStopped(parser.getParsedVoertuigen());
            defineKleur(parser.getParsedVerkeerslichten());
        }

        LoggerOutput::log("Tijd: " + to_string(tijd));
        switchKleur(parser.getParsedVerkeerslichten(), tijd);
        Voertuig::updateVoertuigen(parser.getParsedVoertuigen(), parser.getParsedVerkeerslichten(), tijd);

        for (unsigned int i = 0; i < parser.getParsedVoertuigen().size(); i++) {
            LoggerOutput::log("Voertuig " + to_string(i + 1));
            LoggerOutput::log("-> baan: " + parser.getParsedVoertuigen()[i].getNaamBaan());
            LoggerOutput::log("-> positie: " + to_string(int(round(parser.getParsedVoertuigen()[i].getPositie()))));
            LoggerOutput::log("-> snelheid: " + to_string(parser.getParsedVoertuigen()[i].getSnelheid()));
        }
        sleep_for(microseconds(16600));
        tijd++;
    }
}
