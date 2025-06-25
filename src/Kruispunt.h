//===========================//
// Kruispunt.h
//===========================//

/**
 * @file Kruispunt.h
 * @brief Klasse die een kruispunt modelleert.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#ifndef KRUISPUNT_H
#define KRUISPUNT_H

#include <string>
#include <vector>
using namespace std;

class Kruispunt {
private:
    vector<pair<string,int>> banenEnPosities;

public:

    bool properlyInit();

    /**
    *ENSURE(banenEnPosities[i].first != "","kruispunt baan name may not be empty");
    ENSURE(banenEnPosities[i].second >= 0, "kruispunt baan position may not be negative");
     */
    vector<pair<string, int>> *getBanenEnPosities();

    /**
    *REQUIRE(banen_en_posities[i].first != "","kruispunt baan name may not be set to empty")
    REQUIRE(banen_en_posities[i].second >= 0, "kruispunt baan position may not be set to negative")
     */
    void setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities);

    Kruispunt(pair<string, int> a, pair<string, int> b);
};

#endif //KRUISPUNT_H
