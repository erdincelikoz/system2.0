#include "Voertuig.h"
#include <string>
#include <iostream>
using namespace std;

double Voertuig::getSnelheid() {
    return snelheid;
}

void Voertuig::setSnelheid(double snelheid) {
    this->snelheid = snelheid;
}

double Voertuig::getVersnelling() {
    return versnelling;
}

void Voertuig::setVersnelling(double versnelling) {
    this->versnelling = versnelling;
}

double Voertuig::getMaxSnelheid() {
    return maxSnelheid;
}

double Voertuig::getGewensteMaxSnelheid() {
    return gewensteMaxSnelheid;
}

void Voertuig::setGewensteMaxSnelheid(double gewenste_v_max) {
    gewensteMaxSnelheid = gewenste_v_max;
}

double Voertuig::getMaxRemFactor() {
    return maxRemFactor;
}

double Voertuig::getMinVolgAfstand() {
    return minVolgAfstand;
}

double Voertuig::getMaxVersnelling() {
    return maxVersnelling;
}

string Voertuig::getNaamBaan() {
    return baan;
}

void Voertuig::setNaamBaan(string nieuw) {
    baan = nieuw;
}

double Voertuig::getPositie() {
    return positie;
}

void Voertuig::setPositie(double nieuw){
    positie = nieuw;
}

string Voertuig::getType() {
    return type;
}

void Voertuig::setType(string t) {
    type  = t;
}

int Voertuig::getLengte(){
    return lengte;
}

vector<Voertuig> Voertuig::sortVoertuigen(vector<Voertuig> voertuigen) {
    sort(voertuigen.begin(), voertuigen.end(), [](Voertuig a, Voertuig b) {
        return a.getPositie() > b.getPositie();
    });
    return voertuigen;
}

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
