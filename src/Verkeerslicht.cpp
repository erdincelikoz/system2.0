#include "Verkeerslicht.h"
#include <string>
#include <iostream>
using namespace std;

string Verkeerslicht::getNaamBaan() {
    return baan;
}

void Verkeerslicht::setNaamBaan(string nieuw) {
    baan = nieuw;
}

double Verkeerslicht::getPositie() {
    return positie;
}


void Verkeerslicht::setPositie(double nieuw) {
        positie = nieuw;
}

/**
 * @brief Zet de cyclusduur van het verkeerslicht
 * @param nieuw De nieuwe cyclusduur in seconden
 * @precondition nieuw >= 0
 */
void Verkeerslicht::setCyclus(int nieuw) {
    cyclus = nieuw;
}