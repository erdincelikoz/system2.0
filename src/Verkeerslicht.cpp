#include "Verkeerslicht.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Geeft de huidige kleur van het verkeerslicht terug.
 * @return Boolean waarde: true voor groen, false voor rood.
 */
bool Verkeerslicht::getKleur(){
    return kleur;
}

/**
 * @brief Stelt de kleur van het verkeerslicht in.
 * @param kleur Boolean waarde: true voor groen, false voor rood.
 */
void Verkeerslicht::setKleur(bool kleur) {
    this->kleur = kleur;
}

/**
 * @brief Retourneert naam van de baan waarop verkeerslicht is geplaatst.
 * @return Naam van de baan als string.
 */
string Verkeerslicht::getNaamBaan() {
    return baan;
}

/**
 * @brief Setter voor nieuwe naam van de baan.
 * @param nieuw Nieuw baannaam.
 */
void Verkeerslicht::setNaamBaan(string nieuw) {
    baan = nieuw;
}

/**
 * @brief Retourneert positie van verkeerslicht.
 * @return Positie van verkeerslicht.
 */
double Verkeerslicht::getPositie() {
    return positie;
}

/**
 * @brief Setter voor nieuwe positie van verkeerslicht.
 * @param nieuw Nieuwe positie van verkeerslicht.
 */
void Verkeerslicht::setPositie(double nieuw){
    positie = nieuw;
}

/**
 * @brief Retourneert cyclus duur van verkeerslicht.
 * @return Cyclus duur (in seconden).
 */
int Verkeerslicht::getCyclus() {
    return cyclus;
}

/**
 * @brief Setter voor nieuwe cyclusduur van verkeerslicht.
 * @param nieuw Nieuwe cyclusduur (in seconden).
 * @precondition nieuw >= 0
 */
void Verkeerslicht::setCyclus(int nieuw) {
    cyclus = nieuw;
}

/**
 * @brief Sorteert een vector van verkeerslichten op basis van hun positie.
 * @param verkeerslichten Vector met verkeerslichten die gesorteerd moet worden.
 * @return Gesorteerde vector van verkeerslichten (oplopend op positie).
 */
vector<Verkeerslicht> Verkeerslicht::sortVerkeerslichten(vector<Verkeerslicht> verkeerslichten) {
    // Sorteer de verkeerslichten op positie
    sort(verkeerslichten.begin(), verkeerslichten.end(), [](Verkeerslicht a, Verkeerslicht b) {
        return a.getPositie() < b.getPositie();
    });
    return verkeerslichten;
};

/**
 * @brief Constructor voor een verkeerslicht.
 * @param baan De baan waar het verkeerslicht zich op bevindt.
 * @param positie De positie van het verkeerslicht op de baan.
 * @param cyclus De tijdscyclus van het verkeerslicht.
 */
Verkeerslicht::Verkeerslicht(string baan, double positie, int cyclus) {
    setNaamBaan(baan);
    setPositie(positie);
    setCyclus(cyclus);
}