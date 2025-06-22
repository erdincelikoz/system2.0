#include "Kruispunt.h"

/**
 * @brief Geeft de vector met banen en hun posities terug
 * @return Pointer naar de vector met paren van baannamen en hun posities
 */
vector<pair<string, int>> *Kruispunt::getBanenEnPosities(){
    return &banenEnPosities;
}

/**
 * @brief Stelt de vector met banen en hun posities in
 * @param banen_en_posities De nieuwe vector met paren van baannamen en hun posities
 */
void Kruispunt::setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities) {
    banenEnPosities = banen_en_posities;
}

/**
 * @brief Constructor voor een nieuw kruispunt tussen twee banen
 * @param a Eerste paar van baannaam en positie
 * @param b Tweede paar van baannaam en positie
 */

Kruispunt::Kruispunt(pair<string, int> a, pair<string, int> b) {
    getBanenEnPosities()->push_back(a);
    getBanenEnPosities()->push_back(b);
}

