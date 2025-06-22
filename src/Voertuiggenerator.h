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

/**
 * @brief Klasse voor het genereren van voertuigen op een bepaalde baan met een specifieke frequentie.
 */
class Voertuiggenerator {
private:
    string baanNaam;
    int frequentie;
    string type;

public:
    /**
    * @brief Constructor voor een nieuwe voertuiggenerator.
    * @param baan De naam van de baan waarop voertuigen worden gegenereerd.
    * @param frequentie De frequentie waarmee nieuwe voertuigen worden gegenereerd.
    * @param type Het type van het gegenereerde voertuig
    */
    Voertuiggenerator(const string &baan, int frequentie, const string &type);

    /**
    * @brief Geeft het type voertuig terug dat door deze generator wordt gemaakt.
    * @return Het type voertuig als string.
    */
    string getType() const;

    /**
     * @brief Stelt het type voertuig in dat door deze generator wordt gemaakt.
     * @param type Het nieuwe type voertuig als string.
     */
    void setType(const string &type);

    /**
     * @brief Geeft de naam van de baan terug waarop voertuigen worden gegenereerd.
     * @return De naam van de baan als string.
     */
    string getNaamBaan() const;

    /**
     * @brief Geeft de frequentie terug waarmee voertuigen worden gegenereerd.
     * @return De frequentie als integer.
     */
    int getFrequentie() const;

    /**
     * @brief Stelt de naam van de baan in waarop voertuigen worden gegenereerd.
     * @param nieuwBaan De nieuwe naam van de baan als string.
     */
    void setBaanNaam(string nieuwBaan);

    /**
     * @brief Stelt de frequentie in waarmee voertuigen worden gegenereerd.
     * @param nieuwFrequentie De nieuwe frequentie als int
     */
    void setFrequentie(int nieuwFrequentie);
};

#endif //VOERTUIGGENERATOR_H