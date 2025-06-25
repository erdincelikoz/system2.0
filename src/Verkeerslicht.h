/**
 * @file Verkeerslicht.h
 * @brief Klasse die een verkeerslicht voorstelt in de simulatie. Houdt o.a. cyclus, kleur, positie en baan bij.
 * @author Raj Shah and Erdin Celikoz
 * @date 23 juni 2025
 * @version 2.1
 */

#ifndef VERKEERSLICHT_H
#define VERKEERSLICHT_H

#include <vector>
#include <string>
using namespace std;

class Verkeerslicht {
private:
    string baan;
    double positie;
    int cyclus;
    bool kleur;
    Verkeerslicht*_initCheck;

public:
    /**
     * @brief Constructor voor een verkeerslicht.
     * @param baan De naam van de baan waarop het verkeerslicht zich bevindt.
     * @param positie De positie op de baan.
     * @param cyclus De tijdscyclus in seconden.
     */
    Verkeerslicht(string baan, double positie, int cyclus);

    bool properlyInit();

    /**
     * @brief Haalt de huidige kleur van het verkeerslicht op.
     * @return true voor groen, false voor rood.
     */
    bool getKleur();

    /**
     * @brief Wijzigt de kleur van het verkeerslicht.
     * @param kleur true voor groen, false voor rood.
     */
    void setKleur(bool kleur);

    /**
     * ENSURE(baan != "", "baan name must not be empty")
     */
    string getNaamBaan();

    /**
     * REQUIRE(nieuw != "", "baan name must not be set to empty")
     */
    void setNaamBaan(string nieuw);

    /**
     *ENSURE(positie >= 0, "Positie must not be less than zero")
     */
    double getPositie();

    /**
     *REQUIRE(nieuw >= 0, "Positie must not be set to less than zero")
     */
    void setPositie(double nieuw);

    /**
     *ENSURE(cyclus >= 0, "Cyclus must not be less than zero")
     */
    int getCyclus();

    /**
     *REQUIRE(nieuw >= 0, "Cyclus must not be set to less than zero")
     */
    void setCyclus(int nieuw);

    /**
     * @brief Sorteert een lijst van verkeerslichten op basis van hun positie.
     * @param verkeerslichten Vector van verkeerslichten.
     * @return Gesorteerde vector op positie.
     */
    static vector<Verkeerslicht> sortVerkeerslichten(vector<Verkeerslicht> verkeerslichten);
};

#endif // VERKEERSLICHT_H