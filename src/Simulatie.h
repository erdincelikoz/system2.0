#ifndef SIMULATIE_H
#define SIMULATIE_H
#include "XmlParser.h"
#include <iostream>
#include "VoertuigRijden.h"
#include "Verkeerslicht.h"

class Simulatie {
    const double simulatietijd = 0.0167;

};
void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd);
void defineKleur(vector<Verkeerslicht>& verkeerslichten);
void runSimulation();


#endif //SIMULATIE_H
