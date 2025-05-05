#include "Baan.h"
#include <string>
#include <vector>

/**
 * @brief Retourneert lengte van de baan.
 * @return De lengte van de baan als double.
 */
double Baan::getLengteBaan() {
    return lengte;
}

/**
 * @brief Setter voor nieuwe lengte van de baan.
 * @param nieuw De nieuwe lengte van de baan.
 */
void Baan::setLengteBaan(double nieuw) {
    lengte = nieuw;
}

/**
 * @brief Retourneert naam van de baan.
 * @return De naam van de baan als string.
 */
string Baan::getNaamBaan() {
    return naam;
}

/**
 * @brief Setter voor nieuwe naam van de baan.
 * @param nieuw De nieuwe naam van de baan.
 */
void Baan::setNaamBaan(string nieuw) {
    naam = nieuw;
}

/**
 * @brief Constructor voor de klasse Baan.
 * @param naam De naam van de baan.
 * @param lengte De lengte van de baan.
 */
Baan::Baan(string naam, double lengte) {
    setNaamBaan(naam);
    setLengteBaan(lengte);
}