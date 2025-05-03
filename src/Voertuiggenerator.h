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

public:
    /**
     * @brief Constructor voor Voertuiggenerator
     * @param newBaan Naam van de baan waarop voertuigen worden gegenereerd
     * @param newFrequentie Hoe vaak voertuigen gegenereerd worden
     */
    Voertuiggenerator(string newBaan, int newFrequentie);

    string getBaan() const;
    int getFrequentie() const;

    void setBaan(string nieuwBaan);
    void setFrequentie(int nieuwFrequentie);
};

#endif //VOERTUIGGENERATOR_H