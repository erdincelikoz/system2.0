#include "Verkeerslicht.h"
#include <algorithm>
#include "DesignByContract.h"

Verkeerslicht::Verkeerslicht(string baan, double positie, int cyclus) {
    _initCheck = this;
    setNaamBaan(baan);
    setPositie(positie);
    setCyclus(cyclus);
    ENSURE(properlyInit(),"constructor must end in properlyInit state");
}

bool Verkeerslicht::properlyInit() {
    return _initCheck == this;
}

bool Verkeerslicht::getKleur() {
    return kleur;
}

void Verkeerslicht::setKleur(bool kleur) {
    this->kleur = kleur;
}

string Verkeerslicht::getNaamBaan() {
    ENSURE(baan != "", "baan name must not be empty");
    return baan;
}

void Verkeerslicht::setNaamBaan(string nieuw) {
    REQUIRE(nieuw != "", "baan name must not be set to empty");
    baan = nieuw;
}

double Verkeerslicht::getPositie() {
    ENSURE(positie >= 0, "Positie must not be less than zero");
    return positie;
}

void Verkeerslicht::setPositie(double nieuw) {
    REQUIRE(nieuw >= 0, "Positie must not be set to less than zero");
    positie = nieuw;
}

int Verkeerslicht::getCyclus() {
    ENSURE(cyclus >= 0, "Cyclus must not be less than zero");
    return cyclus;
}

void Verkeerslicht::setCyclus(int nieuw) {
    REQUIRE(nieuw >= 0, "Cyclus must not be set to less than zero");
    cyclus = nieuw;
}

vector<Verkeerslicht> Verkeerslicht::sortVerkeerslichten(vector<Verkeerslicht> verkeerslichten) {
    sort(verkeerslichten.begin(), verkeerslichten.end(), [](Verkeerslicht a, Verkeerslicht b) {
        return a.getPositie() < b.getPositie();
    });
    return verkeerslichten;
}