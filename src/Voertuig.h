/**
 * @file Voertuig.h
 * @brief Simpele voertuigklasse nodig voor het innemen en verwerken van informatie in verband met de voertuig(en).
 * @author Erdin Celikoz & Raj Shah
 * @date 1 mei 2025
 * @version 2.0
 */
#ifndef VOERTUIG_H
#define VOERTUIG_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Simpele voertuigklasse nodig voor het innemen en verwerken van informatie in verband met de voertuig(en).
 */
class Voertuig {
public:
    /**
    * @brief Constructor voor een nieuw voertuig
    * @param baan De naam van de baan waarop het voertuig zich bevindt
    * @param positie De positie van het voertuig op de baan
    * @param type Het type van het voertuig
    */
    Voertuig(const string &baan, int positie, const string &type);

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
    /**
    * @brief Geeft aan of het voertuig gestopt is
    * @return Boolean die aangeeft of het voertuig gestopt is
    */
    bool getStopped() const;

    /**
     * @brief Stelt in of het voertuig gestopt is
     * @param stopped Boolean die aangeeft of het voertuig gestopt is
     */
    void setStopped(bool stopped);

    /**
     * @brief Geeft de lengte van de huidige baan terug
     * @return De lengte van de huidige baan in meters
     */
    int getHuidigeBaanLengte() const;

    /**
     * @brief Stelt de lengte van de huidige baan in.
     * @param huidige_baan_lengte De lengte van de huidige baan in meters.
     */
    void setHuidigeBaanLengte(int huidige_baan_lengte);

    /**
     * @brief Stelt de gewenste maximale snelheid in.
     * @param gewenste_max_snelheid De gewenste maximale snelheid in meters per seconde.
     */
    void setGewensteMaxSnelheid(double gewenste_max_snelheid);

    /**
     * @brief Geeft de naam van de baan terug waarop het voertuig zich bevindt.
     * @return De naam van de baan als string.
     */
    string getNaamBaan();

    /**
     * @brief Retourneert de positie van het voertuig op de baan
     * @return De positie van het voertuig op de baan.
     */
    double getPositie();

    /**
     * @brief Geeft de huidige snelheid van het voertuig terug
     * @return De snelheid in meters per seconde
     */
    double getSnelheid();

    /**
     * @brief Stelt de snelheid van het voertuig in
     * @param snelheid De nieuwe snelheid in meters per seconde
     */
    void setSnelheid(double snelheid);

    /**
     * @brief Geeft de huidige versnelling van het voertuig terug
     * @return De versnelling in meters per seconde kwadraat
     */
    double getVersnelling();

    /**
     * @brief Stelt de versnelling van het voertuig in.
     * @param versnelling De nieuwe versnelling.
     */
    void setVersnelling(double versnelling);

    /**
     * @brief Geeft de maximale snelheid van het voertuig terug
     * @return De maximale snelheid in meter per seconde
     */
    double getMaxSnelheid();

    /**
     * @brief Geeft de gewenste maximale snelheid terug.
     * @return De gewenste maximale snelheid in meter per seconde
     */
    double getGewensteMaxSnelheid();

    /**
     * @brief Geeft de maximale remfactor van het voertuig terug.
     * @return De maximale remfactor.
     */
    double getMaxRemFactor();

    /**
     * @brief Geeft de minimale volgafstand van het voertuig terug.
     * @return De minimale volgafstand (in meters).
     */
    double getMinVolgAfstand();

    /**
     * @brief Geeft het type van het voertuig terug.
     * @return Het type als string.
     */
    string getType();

    /**
     * @brief Stelt het type van het voertuig in.
     * @param newType Het nieuw type van het voertuig als string.
     */
    void setType(string newType);

    /**
     * @brief Stelt de naam van de baan in waarop het voertuig zich bevindt.
     * @param nieuw De nieuwe naam van de baan.
     */
    void setNaamBaan(string nieuw);

    /**
     * @brief Stelt de positie van het voertuig op de baan in.
     * @param nieuw De nieuwe positie in meters.
     */
    void setPositie(double nieuw);

    /**
     * @brief Geeft de maximale versnelling van het voertuig terug.
     * @return De maximale versnelling in meters per seconde kwadraat.
     */
    double getMaxVersnelling();

    /**
     * @brief Geeft de lengte van het voertuig terug.
     * @return De lengte in meters.
     */
    int getLengte();

    /**
     * @brief Sorteert een vector van voertuigen op basis van hun positie.
     * @param Voertuigen Vector met voertuigen die gesorteerd moet worden.
     * @return Gesorteerde vector van voertuigen (aflopend op positie).
     */
    static vector<Voertuig> sortVoertuigen(vector<Voertuig> Voertuigen);

    void setLengte(int lengte);

    void setMaxSnelheid(double s);

    void setMaxVersnelling(double a);

    void setMaxRemFactor(double r);

    void setMinVolgAfstand(int afstand);
};
#endif // VOERTUIG_H