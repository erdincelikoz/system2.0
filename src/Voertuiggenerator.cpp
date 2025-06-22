#include "Voertuiggenerator.h"
#include <string>

using namespace std;

/**
* @brief Constructor voor een nieuwe voertuiggenerator.
* @param baan De naam van de baan waarop voertuigen worden gegenereerd.
* @param frequentie De frequentie waarmee nieuwe voertuigen worden gegenereerd.
* @param type Het type van het gegenereerde voertuig
*/
Voertuiggenerator::Voertuiggenerator(const string &baan, int frequentie, const string &type) {
    setBaanNaam(baan);
    setFrequentie(frequentie);
    setType(type);
}

/**
 * @brief Geeft het type voertuig terug dat door deze generator wordt gemaakt.
 * @return Het type voertuig als string.
 */
string Voertuiggenerator::getType() const {
    return type;
}

/**
 * @brief Stelt het type voertuig in dat door deze generator wordt gemaakt.
 * @param type Het nieuwe type voertuig als string.
 */
void Voertuiggenerator::setType(const string &type) {
    this->type = type;
}

/**
 * @brief Geeft de naam van de baan terug waarop voertuigen worden gegenereerd.
 * @return De naam van de baan als string.
 */
string Voertuiggenerator::getNaamBaan() const {
    return baanNaam;
}

/**
 * @brief Geeft de frequentie terug waarmee voertuigen worden gegenereerd.
 * @return De frequentie als integer.
 */
int Voertuiggenerator::getFrequentie() const {
    return frequentie;
}

/**
 * @brief Stelt de naam van de baan in waarop voertuigen worden gegenereerd.
 * @param nieuwBaan De nieuwe naam van de baan als string.
 */
void Voertuiggenerator::setBaanNaam(string nieuwBaan) {
    baanNaam = nieuwBaan;
}

/**
 * @brief Stelt de frequentie in waarmee voertuigen worden gegenereerd.
 * @param nieuwFrequentie De nieuwe frequentie als int
 */
void Voertuiggenerator::setFrequentie(int nieuwFrequentie) {
    frequentie = nieuwFrequentie;
}
