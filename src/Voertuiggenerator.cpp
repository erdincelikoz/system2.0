

#include "Voertuiggenerator.h"
#include <string>

using namespace std;

Voertuiggenerator::Voertuiggenerator(string newBaan, int newFrequentie) {
    setBaan(newBaan);
    setFrequentie(newFrequentie);
}

string Voertuiggenerator::getBaan() const {
    return baan;
}

int Voertuiggenerator::getFrequentie() const {
    return frequentie;
}

void Voertuiggenerator::setBaan(string nieuwBaan) {
    baan = nieuwBaan;
}

void Voertuiggenerator::setFrequentie(int nieuwFrequentie) {
    frequentie = nieuwFrequentie;
}
