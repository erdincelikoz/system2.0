/**
 * @file Verkeerslicht.h
 * @brief Simpele verkeerslichtklasse nodig voor het innemen en verwerken van informatie in verband met de verkeerslicht(en).
 * @author Erdin Celikoz & Raj Shah
 * @date 1 mei 2025
 * @version 2.0
 */
#ifndef VERKEERSLICHT_H
#define VERKEERSLICHT_H

#include <string>
using namespace std;

/**
 * @brief Simpele verkeerslichtklasse nodig voor het innemen en verwerken van informatie in verband met de verkeerslicht(en).
 */
class Verkeerslicht {
private:
    string baan;
    double positie;
    int cyclus;

public:
    string getNaamBaan();
    double getPositie();
    int getCyclus();
    void setNaamBaan(string nieuw);
    void setPositie(double nieuw);
    void setCyclus(int nieuw);

    /**
     * @brief Constructor voor een verkeerslicht.
     * @param baan De baan waar het verkeerslicht zich op bevindt.
     * @param positie De positie van het verkeerslicht op de baan.
     * @param cyclus De tijdscyclus van het verkeerslicht.
     */
    Verkeerslicht(string baan, double positie, int cyclus);
};

#endif // VERKEERSLICHT_H