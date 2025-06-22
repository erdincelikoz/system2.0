#include "Voertuig.h"
#include <string>
#include <iostream>
using namespace std;

/**
 * @brief Geeft de huidige snelheid van het voertuig terug.
 * @return De snelheid in meters per seconde.
 */
double Voertuig::getSnelheid() {
    return snelheid;
}

/**
 * @brief Stelt de snelheid van het voertuig in.
 * @param snelheid De nieuwe snelheid in meters per seconde.
 */
void Voertuig::setSnelheid(double snelheid) {
    this->snelheid = snelheid;
}

/**
 * @brief Geeft de versnelling van het voertuig terug.
 * @return De versnelling in meters per seconde kwadraat.
 */
double Voertuig::getVersnelling() {
    return versnelling;
}

/**
 * @brief Stelt de versnelling van het voertuig in
 * @param versnelling De nieuwe versnelling
 */
void Voertuig::setVersnelling(double versnelling) {
    this->versnelling = versnelling;
}

/**
 * @brief Geeft de maximale snelheid van het voertuig terug.
 * @return De maximale snelheid in meters per seconde.
 */
double Voertuig::getMaxSnelheid() {
    return maxSnelheid;
}

/**
 * @brief Geeft de gewenste maximale snelheid terug.
 * @return De gewenste maximale snelheid in meters per seconde.
 */
double Voertuig::getGewensteMaxSnelheid() {
    return gewensteMaxSnelheid;
}

/**
* @brief Geeft aan of het voertuig gestopt is
* @return Boolean die aangeeft of het voertuig gestopt is
*/
bool Voertuig::getStopped() const {
    return stopped;
}

/**
 * @brief Stelt in of het voertuig gestopt is
 * @param stopped Boolean die aangeeft of het voertuig gestopt is
 */
void Voertuig::setStopped(bool stopped) {
    this->stopped = stopped;
}
/**
 * @brief Geeft de lengte van de huidige baan terug.
 * @return De lengte van de huidige baan in meters.
 */
int Voertuig::getHuidigeBaanLengte() const {
    return huidigeBaanLengte;
}

/**
 * @brief Stelt de lengte van de huidige baan in.
 * @param huidige_baan_lengte De lengte van de huidige baan in meters.
 */
void Voertuig::setHuidigeBaanLengte(int huidige_baan_lengte) {
    huidigeBaanLengte = huidige_baan_lengte;
}

/**
 * @brief Stelt de gewenste maximale snelheid in.
 * @param gewenste_v_max De gewenste maximale snelheid in meters per seconde.
 */
void Voertuig::setGewensteMaxSnelheid(double gewenste_v_max) {
    gewensteMaxSnelheid = gewenste_v_max;
}

/**
 * @brief Geeft de maximale remfactor van het voertuig terug.
 * @return De maximale remfactor.
 */
double Voertuig::getMaxRemFactor() {
    return maxRemFactor;
}

/**
 * @brief Geeft de minimale volgafstand van het voertuig terug.
 * @return De minimale volgafstand in meters.
 */
double Voertuig::getMinVolgAfstand() {
    return minVolgAfstand;
}

/**
 * @brief Geeft de maximale versnelling van het voertuig terug.
 * @return De maximale versnelling in meters per seconde kwadraat.
 */
double Voertuig::getMaxVersnelling() {
    return maxVersnelling;
}

/**
 * @brief Geeft de naam van de baan terug waarop het voertuig zich bevindt.
 * @return De naam van de baan als string.
 */
string Voertuig::getNaamBaan() {
    return baan;
}

/**
 * @brief Stelt de naam van de baan in waarop het voertuig zich bevindt.
 * @param nieuw De nieuwe naam van de baan.
 */
void Voertuig::setNaamBaan(string nieuw) {
    baan = nieuw;
}

/**
 * @brief Geeft de positie van het voertuig op de baan terug.
 * @return De positie (in meters)
 */
double Voertuig::getPositie() {
    return positie;
}

/**
 * @brief Stelt de positie van het voertuig op de baan in.
 * @param nieuw De nieuwe positie
 */
void Voertuig::setPositie(double nieuw){
    positie = nieuw;
}

/**
 * @brief Geeft het type van het voertuig terug
 * @return Het type als string
 */
string Voertuig::getType() {
    return type;
}
/**
 * @brief Stelt het type van het voertuig in.
 * @param t Het nieuw type als string.
 */
void Voertuig::setType(string t) {
    type  = t;
}
/**
 * @brief Geeft de lengte van het voertuig terug.
 * @return De lengte in meters.
 */
int Voertuig::getLengte(){
    return lengte;
}

/**
 * @brief Sorteert een vector van voertuigen op basis van hun positie
 * @param voertuigen Vector met voertuigen die gesorteerd moet worden
 * @return Gesorteerde vector van voertuigen (aflopend op positie)
 */
vector<Voertuig> Voertuig::sortVoertuigen(vector<Voertuig> voertuigen) {
    sort(voertuigen.begin(), voertuigen.end(), [](Voertuig a, Voertuig b) {
        return a.getPositie() > b.getPositie();
    });
    return voertuigen;
}

void Voertuig::setLengte(int l) {
    lengte = l;
}
void Voertuig::setMaxSnelheid(double s) {
    maxSnelheid = s;
}
void Voertuig::setMaxVersnelling(double a) {
    maxVersnelling = a;
}
void Voertuig::setMaxRemFactor(double r) {
    maxRemFactor = r;
}
void Voertuig::setMinVolgAfstand(int afstand) {
    minVolgAfstand = afstand;
}

/**
 * @brief Constructor voor een nieuw voertuig.
 * @param baan De naam van de baan waarop het voertuig zich bevindt.
 * @param positie De beginpositie van het voertuig op de baan.
 * @param type Het type van het voertuig (auto, bus, brandweerwagen, ziekenwagen, politiecombi).
 */
Voertuig::Voertuig(const string &baan, int positie, const string &type):
/*
 *Voor alle duidelijkheid, constanten kunnen alleen gelijkgesteld worden aan iets bij 1. De moment dat ze gedefinieerd worden of 2. In de 'constructor initializer list'
 *In dit geval is het dus duidelijk 2. ? ... : ... is de 'ternary operator' die de if-conditie vervangt in de initializer omdat we hier geen normale if mogen gebruiken.
 *Werking van de ternary operator: (conditie) ? waarde_als_true : waarde_als_false;
 */
lengte(type=="auto" ? 4 : type=="bus" ? 12 : type=="brandweerwagen" ? 10 :
    type=="ziekenwagen" ? 8 : type=="politiecombi" ? 6 : -1),

maxVersnelling(type=="auto" ? 1.44 : type=="bus" ? 1.22 : type=="brandweerwagen" ? 1.33 :
    type=="ziekenwagen" ? 1.44 : type=="politiecombi" ? 1.55 : -1),

maxSnelheid(type=="auto" ? 16.6 : type=="bus" ? 11.4 : type=="brandweerwagen" ? 14.6 :
    type=="ziekenwagen" ? 15.5 : type=="politiecombi" ? 17.2 : -1),

maxRemFactor(type=="auto" ? 4.61 : type=="bus" ? 4.29 : type=="brandweerwagen" ? 4.56 :
    type=="ziekenwagen" ? 4.47 : type=="politiecombi" ? 4.92 : -1),

minVolgAfstand(type=="auto" ? 4 : type=="bus" ? 12 : type=="brandweerwagen" ? 10 :
    type=="ziekenwagen" ? 8 : type=="politiecombi" ? 6 : -1) {

    setNaamBaan(baan);
    setPositie(positie);
    setType(type);
}

