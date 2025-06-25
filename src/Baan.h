/**
 * @file Baan.h
 * @brief Simpele baanklasse nodig voor het innemen en verwerken van informatie in verband met de baan/banen.
 * @author Erdin Celikoz & Raj Shah
 * @date 1 mei 2025
 * @version 2.0
 */
#ifndef BAAN_H
#define BAAN_H
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Simpele baanklasse nodig voor het innemen en verwerken van informatie in verband met de baan/banen.
 */
class Baan {
private:
    string naam;
    double lengte;

public:
    /**
    * Retourneert naam van de baan
    * @return De naam van de baan als string
    */
    string getNaamBaan();

    /**
    *ENSURE(lengte >= 0, "baan length must not be less than zero")
    */
    double getLengteBaan();

    /**
     *REQUIRE(nieuw != "", "baan name must not be set to empty")
     */
    void setNaamBaan(string nieuw);

    /**
     *REQUIRE(nieuw >= 0, "baan length must not be set to less than zero")
    */
    void setLengteBaan(double nieuw);

    /**
     * @brief Constructor voor de klasse Baan.
     * @param naam De naam van de baan.
     * @param lengte De lengte van de baan.
     */
    Baan(string naam, double lengte);
};

#endif // BAAN_H