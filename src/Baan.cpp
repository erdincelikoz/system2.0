/**
* @file Baan.cpp
 * @brief Implementatie van de Baan klasse.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#include "Baan.h"
#include <string>

bool Baan::properlyInit() {
    return _initCheck == this;
}
Baan::Baan(string naam, double lengte) {
    _initCheck = this;
    setNaamBaan(naam);
    setLengteBaan(lengte);
    ENSURE(properlyInit(),"constructor must end in properlyInit state");
}

double Baan::getLengteBaan() {
    return lengte;
}

void Baan::setLengteBaan(double nieuw) {
    lengte = nieuw;
}

string Baan::getNaamBaan() {
    return naam;
}

void Baan::setNaamBaan(string nieuw) {
    naam = nieuw;
}
