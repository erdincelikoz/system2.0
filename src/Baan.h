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
    * Retourneert lengte van de baan
    * @return De lengte van de baan als double
    */
    double getLengteBaan();

    /**
     * Setter voor nieuwe naam van de baan
     * @param nieuw De nieuwe naam van de baan
     */
    void setNaamBaan(string nieuw);

    /**
    * Setter voor nieuwe lengte van de baan
    * @param nieuw De nieuwe lengte van de baan
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