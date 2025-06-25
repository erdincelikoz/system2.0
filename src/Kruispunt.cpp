//===========================//
// Kruispunt.cpp
//===========================//

/**
 * @file Kruispunt.cpp
 * @brief Implementatie van Kruispunt klasse met Design by Contract.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#include "Kruispunt.h"
#include "DesignByContract.h"

vector<pair<string, int>> *Kruispunt::getBanenEnPosities() {
    for (unsigned int i = 0; i < banenEnPosities.size(); i++) {
        ENSURE(banenEnPosities[i].first != "","kruispunt baan name may not be empty");
        ENSURE(banenEnPosities[i].second >= 0, "kruispunt baan position may not be negative");
    }
    return &banenEnPosities;
}

void Kruispunt::setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities) {
    banenEnPosities = banen_en_posities;
}

Kruispunt::Kruispunt(pair<string, int> a, pair<string, int> b) {
    _initCheck = this;
    banenEnPosities.push_back(a);
    banenEnPosities.push_back(b);
    ENSURE(properlyInit(),"constructor must end in properlyInit state");
}
