/**
 * @file Voertuig.h
 * @brief Definitie van de klasse Voertuig voor simulatie van verkeersscenario's.
 *
 * Bevat methodes en attributen die voertuigen beschrijven zoals positie, snelheid,
 * acceleratie en gedrag t.o.v. verkeerslichten.
 *
 * @author Raj Shah
 * @author Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#ifndef VOERTUIG_H
#define VOERTUIG_H

#include <string>
#include <vector>
#include "Verkeerslicht.h"
using namespace std;

class Voertuig {
public:
/**
 *
 * @param baan Naam van de baan waarop het voertuig staat
 * @param positie Positie van het voertuig
 * @param type Type van het voertuig
 */
    Voertuig(string &baan, int positie, const string &type);


private:
    string baan;
    double positie;
    double snelheid;
    double versnelling;
    double gewensteMaxSnelheid;
    string type;
    int lengte;
    double maxVersnelling;
    double maxSnelheid;
    double maxRemFactor;
    double minVolgAfstand;
    int huidigeBaanLengte;
    bool stopped;

public:
    bool properlyInit();

    bool getStopped() const;

    void setStopped(bool stopped);

    int getHuidigeBaanLengte() const;

    void setHuidigeBaanLengte(int huidige_baan_lengte);

/**
 *ENSURE(gewensteMaxSnelheid==16.6||gewensteMaxSnelheid==16.6*0.4, "gewensteMaxSnelheid does not match vehicle type")
 *ENSURE(gewensteMaxSnelheid==14.6||gewensteMaxSnelheid==14.6*0.4, "gewensteMaxSnelheid does not match vehicle type")
 *ENSURE(gewensteMaxSnelheid==11.4||gewensteMaxSnelheid==11.4*0.4, "gewensteMaxSnelheid does not match vehicle type")
 *ENSURE(gewensteMaxSnelheid==15.5||gewensteMaxSnelheid==15.5*0.4, "gewensteMaxSnelheid does not match vehicle type")
 *ENSURE(gewensteMaxSnelheid==17.2||gewensteMaxSnelheid==17.2*0.4, "gewensteMaxSnelheid does not match vehicle type")
 */
    double getGewensteMaxSnelheid();
/**
 *REQUIRE(gewensteMaxSnelheid==16.6||gewensteMaxSnelheid==16.6*0.4, "set gewensteMaxSnelheid does not match vehicle type")
 *REQUIRE(gewensteMaxSnelheid==14.6||gewensteMaxSnelheid==14.6*0.4, "set gewensteMaxSnelheid does not match vehicle type")
 *REQUIRE(gewensteMaxSnelheid==11.4||gewensteMaxSnelheid==11.4*0.4, "set gewensteMaxSnelheid does not match vehicle type")
 *REQUIRE(gewensteMaxSnelheid==15.5||gewensteMaxSnelheid==15.5*0.4, "setgewensteMaxSnelheid does not match vehicle type")
 *REQUIRE(gewensteMaxSnelheid==17.2||gewensteMaxSnelheid==17.2*0.4, "set gewensteMaxSnelheid does not match vehicle type")
 */
    void setGewensteMaxSnelheid(double gewenste_max_snelheid);

/**
 *ENSURE(baan != "", "baan name must not be empty")
 */
    string getNaamBaan();

/**
 *REQUIRE(nieuw != "", "baan name must not be set to empty")
 */
    void setNaamBaan(string &nieuw);

/**
 *ENSURE(positie >= 0, "Positie must not be less than zero")
 */
    double getPositie();

/**
 *REQUIRE(nieuw >= 0, "Positie must not be set to less than zero")
 */
    void setPositie(double nieuw);

/**
 *ENSURE(snelheid >= 0, "voertuig snellheid must not be negative");
 */
    double getSnelheid();

/**
 *REQUIRE(snelheid >= 0, "voertuig snellheid must not be set to negative");
 */
    void setSnelheid(double snelheid);

    double getVersnelling();

    void setVersnelling(double versnelling);

/**
 *ENSURE(maxSnelheid>=11.4, "maxSnelheid must not be set to less than 11.4");
 */
    virtual double getMaxSnelheid() const;

/**
 *ENSURE(maxRemFactor>=4.29, "maxRemFactor must not be set to less than 4.29");
 */
    virtual double getMaxRemFactor() const;

/**
 *ENSURE(minVolgAfstand >= 4, "minVolgAfstand must not be set less than 4");
 */
    virtual int getMinVolgAfstand() const;

/**
 *ENSURE(type!="", "voertuig type must not be empty");
 */
    string getType();

/**
 *REQUIRE(type!="", "voertuig type must not be set to empty");
 */
void setType(string newType);

/**
 *ENSURE(maxVersnelling>=1.22, "maxVersnelling must not be set to less than 1.22");
 */
    virtual double getMaxVersnelling() const;

/**
 *ENSURE(lengte>=4, "lengte must not be less than 4");
 */
    virtual int getLengte() const;

    /**
    * @brief Sorteert voertuigen op positie (hoog naar laag)
    * @param Voertuigen Vector van voertuigen om te sorteren
    * @return Gesorteerde vector van voertuigen
    * @pre Voertuigen vector is niet leeg
    * @post Voertuigen zijn gesorteerd op positie
    */
    static vector<Voertuig> sortVoertuigen(vector<Voertuig> Voertuigen);

/**
 *REQUIRE(l>=4, "lengte must not be set to less than 4");
 */
    void setLengte(int lengte);

/**
 *REQUIRE(s>=11.4, "maxSnelheid must not be set to less than 11.4");
 */
    void setMaxSnelheid(double s);

/**
 *REQUIRE(a>=1.22, "maxVersnelling must not be set to less than 1.22");
 */
    void setMaxVersnelling(double a);

/**
 *REQUIRE(r>=4.29, "maxRemFactor must not be set to less than 4.29");
 */
    void setMaxRemFactor(double r);

/**
 *REQUIRE(afstand >= 4, "minVolgAfstand must not be set less than 4");
 */
    void setMinVolgAfstand(int afstand);

    /**
     * @brief Werkt de staat van alle voertuigen bij op basis van hun omgeving.
     *
     * @param voertuigen Vector van voertuigen die moeten worden geüpdatet.
     * @param verkeerslichten Vector van verkeerslichten.
     * @param tijd De huidige simulatie-tijdstap.
     *
     * @pre voertuigen en verkeerslichten mogen geen nullpointers bevatten.
     * @post voertuigen zijn aangepast op basis van versnelling, remmen en verkeerslichtstatus.
     * @throws invalid_argument bij ongeldige volgafstand.
     */
    static void updateVoertuigen(vector<Voertuig>& voertuigen, vector <Verkeerslicht>& verkeerslichten, int tijd);

    void vertragen(vector<Voertuig>& voertuigen);

    void versnellen(vector<Voertuig>& voertuigen);

    void stoppen(vector<Voertuig>& voertuigen);

/**
 *ENSURE(voertuigen[i].getGewensteMaxSnelheid()==voertuigen[i].getMaxSnelheid(), "voertuig has undefined gewensteMaxsnelheid");
 */
    static void defineGewensteMaxSnelheid(vector<Voertuig>& voertuigen);

/**
 *ENSURE(!voertuigen[i].getStopped(), "voertuig stopped is undefined");
 */
static void defineStopped(vector<Voertuig>& voertuigen);
};

#endif // VOERTUIG_H