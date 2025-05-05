#ifndef KRUISPUNT_H
#define KRUISPUNT_H
#include <string>
#include <vector>
using namespace std;

/**
 * @brief Klasse die een kruispunt tussen verschillende banen creëert.
 */
class Kruispunt {
private:
    vector<pair<string,int>> banenEnPosities;

public:
    /**
    * @brief Geeft de vector met banen en hun posities terug
    * @return Pointer naar de vector met paren van baannamen en hun posities
    */
    vector<pair<string, int>> *getBanenEnPosities();

    /**
    * @brief Stelt de vector met banen en hun posities in
    * @param banen_en_posities De nieuwe vector met paren van baannamen en hun posities
    */
    void setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities);

    /**
    * @brief Constructor voor een nieuw kruispunt tussen twee banen
    * @param a Eerste paar van baannaam en positie
    * @param b Tweede paar van baannaam en positie
    */
    Kruispunt(pair<string, int> a, pair<string, int> b);
};

#endif //KRUISPUNT_H
