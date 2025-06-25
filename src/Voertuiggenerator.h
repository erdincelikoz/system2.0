/**
* @file Voertuiggenerator.h
 * @brief Klasse die voertuigen genereert op een bepaalde baan met een ingestelde frequentie en type voertuig. Gebruikt in de simulatie om dynamisch verkeer te creëren.
 * @author Raj Shah and Erdin Celikoz
 * @date 23 juni 2025
 * @version 1.1
 */

#ifndef VOERTUIGGENERATOR_H
#define VOERTUIGGENERATOR_H

#include <string>
using namespace std;

class Voertuiggenerator {
private:
    string baanNaam;
    int frequentie;
    string type;
    Voertuiggenerator* _initCheck;

public:
    /**
     * @brief Constructor voor voertuiggenerator.
     * @param baan Naam van de baan.
     * @param frequentie Aantal voertuigen per tijdseenheid.
     * @param type Het type voertuig (bv. Bus, Brandweerwagen, ...).
     */
    Voertuiggenerator(const string &baan, int frequentie, const string &type);

    bool properlyInit();

    /**
    *ENSURE(type =="auto"||type=="brandweerwagen"||type=="bus"||type=="politiecombi"||type=="ziekenwagen",
        "vehicle type must be a valid type");
*/
    string getType() const;

    /**
    *REQUIRE(type =="auto"||type=="brandweerwagen"||type=="bus"||type=="politiecombi"||type=="ziekenwagen",
        "vehicle type must be set to a valid type");
*/
    void setType(const string &type);

    /**
    *ENSURE(baanNaam != "", "baan name must not be empty")
    */
    string getNaamBaan() const;

    /**
    *REQUIRE(baanNaam != "", "baan name must not be set to empty")
    */
    void setBaanNaam(string nieuwBaan);

    /**
    *ENSURE(frequentie >= 0, "Frequentie must not be less than zero");
    */
    int getFrequentie() const;

    /**
    *REQUIRE(frequentie >= 0, "Frequentie must not be set to less than zero");
    */
    void setFrequentie(int nieuwFrequentie);
};

#endif // VOERTUIGGENERATOR_H