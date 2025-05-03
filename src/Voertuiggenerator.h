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
    string baan;
    int frequentie;
    string type;

public:
    string type1() const;

    void set_type(const string &type);

    string getBaan() const;
    int getFrequentie() const;

    void setBaan(string nieuwBaan);
    void setFrequentie(int nieuwFrequentie);
};

#endif //VOERTUIGGENERATOR_H