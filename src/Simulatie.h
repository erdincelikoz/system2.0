/**
* @file Simulatie.h
 * @brief Bevat declaraties voor de hoofdverkeerssimulatie en ondersteunende functies voor verkeerslichtenbeheer.
 * @author Raj Shah and Erdin Celikoz
 * @date 23 juni 2025
 * @version 1.0
 */

#ifndef SIMULATIE_H
#define SIMULATIE_H

#include "XmlParser.h"
#include <iostream>
#include "Voertuig.h"
#include "Verkeerslicht.h"

/**
 * @brief Klasse die de simulatie van verkeer representeert.
 */
class Simulatie {
private:
    const double simulatietijd = 0.0167;
};

/**
 * REQUIRE(tijd >= 0, "time must not be negative")
 * ENSURE(verkeerslicht.getKleur() != temp.getKleur(), "verkeerslicht color change failed")
 */
void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd);

/**
 * ENSURE(verkeerslicht.getKleur()== true, "verkeerslicht color undefined")
 */
void defineKleur(vector<Verkeerslicht>& verkeerslichten);

/**
 * @brief Voert de verkeerssimulatie uit.
 */
void runSimulation();

#endif //SIMULATIE_H