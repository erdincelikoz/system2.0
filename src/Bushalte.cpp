//
// Created by erdin on 5/3/2025.
//

#include "Bushalte.h"

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
