#include "Voertuiggenerator.h"
#include "DesignByContract.h"

Voertuiggenerator::Voertuiggenerator(const string &baan, int frequentie, const string &type) {
    _initCheck = this;
    setBaanNaam(baan);
    setFrequentie(frequentie);
    setType(type);
    ENSURE(properlyInit(),"constructor must end in properlyInit state");
}

bool Voertuiggenerator::properlyInit() {
    return _initCheck == this;
}

string Voertuiggenerator::getType() const {
    return type;
}

void Voertuiggenerator::setType(const string &type) {
    this->type = type;
}

string Voertuiggenerator::getNaamBaan() const {
    ENSURE(baanNaam != "", "baan name must not be empty");
    return baanNaam;
}

void Voertuiggenerator::setBaanNaam(string nieuwBaan) {
    REQUIRE(nieuwBaan != "", "baan name must not be set to empty");
    baanNaam = nieuwBaan;
}

int Voertuiggenerator::getFrequentie() const {
    ENSURE(frequentie >= 0, "Frequentie must not be less than zero");
    return frequentie;
}

void Voertuiggenerator::setFrequentie(int nieuwFrequentie) {
    REQUIRE(nieuwFrequentie >= 0, "Frequentie must not be set less than zero");
    frequentie = nieuwFrequentie;
}