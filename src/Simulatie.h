#ifndef SIMULATIE_H
#define SIMULATIE_H
#include "XmlParser.h"
#include <iostream>
#include "VoertuigRijden.h"
#include "Verkeerslicht.h"

/**
 * @brief Klasse die de simulatie van verkeer representeert.
 */
class Simulatie {
    const double simulatietijd = 0.0167; //ong 60 fps
};

/**
 * @brief Schakelt verkeerslichten van kleur op basis van hun cyclustijd.
 * @param verkeerslichten Vector met verkeerslichten die van kleur moeten veranderen.
 * @param tijd De huidige simulatietijd.
 */
void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd);

/**
 * @brief Initialiseert alle verkeerslichten met de groene kleur
 * @param verkeerslichten Vector met verkeerslichten die geïnitialiseerd moeten worden
 */
void defineKleur(vector<Verkeerslicht>& verkeerslichten);

/**
 * @brief Voert de verkeerssimulatie uit.
 */
void runSimulation();


#endif //SIMULATIE_H
