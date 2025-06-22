#include "Bushalte.h"

/**
 * @brief Geeft de naam van de baan terug waarop de bushalte zich bevindt.
 * @return De naam van de baan als string.
 */
string Bushalte::getNaamBaan() const {
    return baanNaam;
}

/**
 * @brief Stelt de naam van de baan in waarop de bushalte zich bevindt.
 * @param baan_naam De nieuwe naam van de baan.
 */
void Bushalte::setNaamBaan(const string &baan_naam) {
    baanNaam = baan_naam;
}

/**
 * @brief Geeft de positie van de bushalte op de baan terug.
 * @return De positie als integer.
 */
int Bushalte::getPositie() const {
    return positie;
}

/**
 * @brief Stelt de positie van de bushalte op de baan in.
 * @param positie De nieuwe positie.
 */
void Bushalte::setPositie(int positie) {
    this->positie = positie;
}

/**
 * @brief Geeft de wachttijd terug die een bus moet wachten bij deze halte.
 * @return De wachttijd in seconden als integer.
 */
int Bushalte::getWachttijd() const {
    return wachttijd;
}

/**
 * @brief Stelt de wachttijd in die een bus moet wachten bij deze halte.
 * @param wachttijd De nieuwe wachttijd in seconden.
 */
void Bushalte::setWachttijd(int wachttijd) {
    this->wachttijd = wachttijd;
}

/**
 * @brief Constructor voor een bushalte.
 * @param baan_naam De naam van de baan waarop de bushalte zich bevindt.
 * @param positie De positie van de bushalte op de baan.
 * @param wachttijd De wachttijd in seconden die een bus moet wachten bij deze halte.
 */
Bushalte::Bushalte(const string &baan_naam, int positie, int wachttijd) {
    setNaamBaan(baan_naam);
    setPositie(positie);
    setWachttijd(wachttijd);
}