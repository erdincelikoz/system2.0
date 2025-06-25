//===========================//
// Bushalte.cpp
//===========================//

/**
 * @file Bushalte.cpp
 * @brief Implementatie van Bushalte klasse met Design by Contract.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#include "Bushalte.h"
#include "DesignByContract.h"

string Bushalte::getNaamBaan() const {
    return baanNaam;
}

void Bushalte::setNaamBaan(const string &baan_naam) {
    baanNaam = baan_naam;
}

int Bushalte::getPositie() const {
    return positie;
}

void Bushalte::setPositie(int positie) {
    this->positie = positie;
}

int Bushalte::getWachttijd() const {
    return wachttijd;
}

void Bushalte::setWachttijd(int wachttijd) {
    this->wachttijd = wachttijd;
}

Bushalte::Bushalte(const string &baan_naam, int positie, int wachttijd) {
    setNaamBaan(baan_naam);
    setPositie(positie);
    setWachttijd(wachttijd);
}
bool Bushalte::properlyInit() {
    return _initCheck == this;
}