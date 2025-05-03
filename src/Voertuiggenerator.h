/**
* @file Voertuiggenerator.h
 * @brief Simpele klasse die verantwoordelijk is voor het aanmaken van voertuigen met een bepaalde frequentie op een baan.
 * @author Erdin Celikoz & Raj Shah
 * @date 2 mei 2025
 * @version 1.0
 */
#ifndef VOERTUIGGENERATOR_H
#define VOERTUIGGENERATOR_H

#include <string>
using namespace std;

class Voertuiggenerator {
private:
    string baanNaam;
    int frequentie;
    string type;

public:
    Voertuiggenerator(const string &baan, int frequentie, const string &type);

    string getType() const;

    void setType(const string &type);

    string getNaamBaan() const;
    int getFrequentie() const;

    void setBaanNaam(string nieuwBaan);
    void setFrequentie(int nieuwFrequentie);
};

#endif //VOERTUIGGENERATOR_H