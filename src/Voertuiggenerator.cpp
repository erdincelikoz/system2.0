

#include "Voertuiggenerator.h"
#include <string>

using namespace std;

Voertuiggenerator::Voertuiggenerator(const string &baan, int frequentie, const string &type) {
    setBaanNaam(baan);
    setFrequentie(frequentie);
    setType(type);
}

string Voertuiggenerator::getType() const {
    return type;
}

void Voertuiggenerator::setType(const string &type) {
    this->type = type;
}

string Voertuiggenerator::getNaamBaan() const {
    return baanNaam;
}

int Voertuiggenerator::getFrequentie() const {
    return frequentie;
}

void Voertuiggenerator::setBaanNaam(string nieuwBaan) {
    baanNaam = nieuwBaan;
}

void Voertuiggenerator::setFrequentie(int nieuwFrequentie) {
    frequentie = nieuwFrequentie;
}
