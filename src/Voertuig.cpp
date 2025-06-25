/**
 * @file Voertuig.cpp
 * @brief Implementatie van de klasse Voertuig.
 *
 * Bevat de logica voor voertuigdynamiek, interacties met verkeerslichten
 * en gedrag gebaseerd op positie, snelheid en versnelling.
 *
 * @author Raj Shah
 * @author Erdin Celikoz
 * @date 23/06/2025
 * @version 2.1
 */

#include "Voertuig.h"
#include <string>
#include <iostream>
#include <cmath>
#include <algorithm>
#include "DesignByContract.h"
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

double Voertuig::getGewensteMaxSnelheid() {
    return gewensteMaxSnelheid;
}

void Voertuig::setGewensteMaxSnelheid(double gewenste_v_max) {
    if (getType()=="auto") {
        REQUIRE(gewensteMaxSnelheid==16.6||gewensteMaxSnelheid==16.6*0.4, "set gewensteMaxSnelheid does not match vehicle type");
    }
    if (getType()=="brandweerwagen") {
        REQUIRE(gewensteMaxSnelheid==14.6||gewensteMaxSnelheid==14.6*0.4, "set gewensteMaxSnelheid does not match vehicle type");
    }
    if (getType()=="bus") {
        REQUIRE(gewensteMaxSnelheid==11.4||gewensteMaxSnelheid==11.4*0.4, "set gewensteMaxSnelheid does not match vehicle type");
    }
    if (getType()=="ziekenwagen") {
        REQUIRE(gewensteMaxSnelheid==15.5||gewensteMaxSnelheid==15.5*0.4, "set gewensteMaxSnelheid does not match vehicle type");
    }
    if (getType()=="politiecombi") {
        REQUIRE(gewensteMaxSnelheid==17.2||gewensteMaxSnelheid==17.2*0.4, "set gewensteMaxSnelheid does not match vehicle type");
    }
    gewensteMaxSnelheid = gewenste_v_max;
}

bool Voertuig::getStopped() const {
    return stopped;
}

void Voertuig::setStopped(bool stopped) {
    this->stopped = stopped;
}

int Voertuig::getHuidigeBaanLengte() const {
    return huidigeBaanLengte;
}

void Voertuig::setHuidigeBaanLengte(int huidige_baan_lengte) {
    huidigeBaanLengte = huidige_baan_lengte;
}


string Voertuig::getNaamBaan() {
    ENSURE(baan != "", "baan name must not be empty");
    return baan;
}

void Voertuig::setNaamBaan(string &nieuw) {
    REQUIRE(nieuw != "", "baan name must not be set to empty");
    baan = nieuw;
}

double Voertuig::getPositie() {
    ENSURE(positie >= 0, "Positie must not be less than zero");
    return positie;
}

void Voertuig::setPositie(double nieuw) {
    REQUIRE(nieuw >= 0, "Positie must not be set to less than zero");
    this->positie = nieuw;
}

string Voertuig::getType() {
    return type;
}

void Voertuig::setType(string type) {
    REQUIRE(type!="", "voertuig type must not be set to empty");
    this->type = type;
}

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
    REQUIRE(r>=4.29, "maxRemFactor must not be set to less than 4.29");
    maxRemFactor = r;
}

void Voertuig::setMinVolgAfstand(int afstand) {
    REQUIRE(afstand >= 4, "minVolgAfstand must not be set less than 4");
    minVolgAfstand = afstand;
}


int Voertuig::getLengte() const {
    ENSURE(lengte>=4, "lengte must not be less than 4");
    return lengte;
}

double Voertuig::getMaxSnelheid() const {
    ENSURE(maxSnelheid>=11.4, "maxSnelheid must not be set to less than 11.4");
    return maxSnelheid;
}

double Voertuig::getMaxVersnelling() const {
    ENSURE(maxVersnelling>=1.22, "maxVersnelling must not be set to less than 1.22");
    return maxVersnelling;
}

double Voertuig::getMaxRemFactor() const {
    ENSURE(maxRemFactor>=4.29, "maxRemFactor must not be set to less than 4.29");
    return maxRemFactor;
}

int Voertuig::getMinVolgAfstand() const {
    ENSURE(minVolgAfstand >= 4, "minVolgAfstand must not be set less than 4");
    return minVolgAfstand;
}

Voertuig::Voertuig(string &baan, int positie, const string &type) {
    _initCheck=this;
    setNaamBaan(baan);
    setPositie(positie);
    setType(type);
    ENSURE(properlyInit(),"constructor must be properlyInit state");
}

void Voertuig::updateVoertuigen(vector<Voertuig>& voertuigen, vector<Verkeerslicht>& verkeerslichten, int tijd) {

    for (unsigned int i = 0; i < voertuigen.size(); i++) {
        if (i != 0) {
            if (voertuigen[i - 1].getPositie() - voertuigen[i].getPositie() <= voertuigen[i].getMinVolgAfstand()) {
                throw invalid_argument("Afstand tussen twee auto's is minder dan de minimale volgafstand.");
            }
        }

        if (tijd == 0) {
            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid());
        }

        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling() * 0.0166 < 0) {
            voertuigen[i].setPositie(voertuigen[i].getPositie() -
                (pow(voertuigen[i].getSnelheid(), 2) /
                    (2 * voertuigen[i].getVersnelling())));
            voertuigen[i].setSnelheid(0);
        }

        if (i == 0) {
            voertuigen[i].setVersnelling(voertuigen[i].getMaxVersnelling()
                * (1 - pow((voertuigen[i].getSnelheid()
                    / voertuigen[i].getGewensteMaxSnelheid()), 4)));
        } else {
            double volgafstand = voertuigen[i - 1].getPositie() - voertuigen[i].getPositie() - voertuigen[i - 1].getLengte();
            if (volgafstand <= 0) {
                throw invalid_argument("Volgafstand kan niet negatief zijn");
            }

            double snelheidsverschil = voertuigen[i].getSnelheid() - voertuigen[i - 1].getSnelheid();

            double interactieterm = (voertuigen[i].getMinVolgAfstand() +
                max(0.0, voertuigen[i].getSnelheid()
                    + ((voertuigen[i].getSnelheid()
                        * snelheidsverschil)
                        / (2 * sqrt(voertuigen[i].getMaxVersnelling()
                            * voertuigen[i].getMaxRemFactor())))))
                / volgafstand;

            voertuigen[i].setVersnelling(voertuigen[i].getMaxVersnelling()
                * (1 - pow((voertuigen[i].getSnelheid()
                    / voertuigen[i].getGewensteMaxSnelheid()), 4))
                - pow(interactieterm, 2));
        }

        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling() * 0.0166 >= 0) {
            voertuigen[i].setSnelheid(voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling() * 0.0166);
        }
        if (voertuigen[i].getSnelheid() > voertuigen[i].getMaxSnelheid()) {
            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid());
        }

        for (unsigned int j = 0; j < verkeerslichten.size(); j++) {
            Verkeerslicht tempVerkeerslicht = verkeerslichten[j];

            bool isPrioriteit = (voertuigen[i].getType() == "brandweerwagen" ||
                voertuigen[i].getType() == "ziekenwagen" ||
                voertuigen[i].getType() == "politiecombi");

            if ((i == 0 && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() > 7.5
                && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() <= 50
                && !isPrioriteit) || (i == 0 && voertuigen[i].getStopped())) {

                Voertuig* eersteAutoVoorVerkeerslicht = &voertuigen[i];

                if (tempVerkeerslicht.getKleur()) {
                    eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                    eersteAutoVoorVerkeerslicht->setStopped(false);
                } else {
                    if (15 < tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie()
                        && tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie() <= 50) {
                        eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(0.4 * eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht->setStopped(true);
                    } else if (tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie() <= 15) {
                        eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(0.4 * eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht->setVersnelling(-((eersteAutoVoorVerkeerslicht->getMaxRemFactor()
                            * eersteAutoVoorVerkeerslicht->getSnelheid())
                            / eersteAutoVoorVerkeerslicht->getGewensteMaxSnelheid()));
                        eersteAutoVoorVerkeerslicht->setStopped(true);
                    }
                }
            } else if ((i != 0
                && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() <= 50
                && (!isPrioriteit)
                && ((tempVerkeerslicht.getPositie() - voertuigen[i - 1].getPositie() < 0)
                    || ((tempVerkeerslicht.getPositie() - voertuigen[i - 1].getPositie() <= 7.5)
                        && (tempVerkeerslicht.getPositie() - voertuigen[i - 1].getPositie() >= 0)
                        && !voertuigen[i - 1].getStopped())))
                || (i != 0 && voertuigen[i].getStopped())) {

                Voertuig* eersteAutoVoorVerkeerslicht = &voertuigen[i];

                if (tempVerkeerslicht.getKleur()) {
                    eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                    eersteAutoVoorVerkeerslicht->setStopped(false);
                } else {
                    if (15 < tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie()
                        && tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie() <= 50) {
                        eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(0.4 * eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht->setStopped(true);
                    } else if (tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht->getPositie() <= 15) {
                        eersteAutoVoorVerkeerslicht->setGewensteMaxSnelheid(0.4 * eersteAutoVoorVerkeerslicht->getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht->setVersnelling(-((eersteAutoVoorVerkeerslicht->getMaxRemFactor()
                            * eersteAutoVoorVerkeerslicht->getSnelheid())
                            / eersteAutoVoorVerkeerslicht->getGewensteMaxSnelheid()));
                        eersteAutoVoorVerkeerslicht->setStopped(true);
                    }
                }
            }

            if (tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() < 0 && !voertuigen[i].getStopped()) {
                voertuigen[i].setGewensteMaxSnelheid(voertuigen[i].getMaxSnelheid());
            }
        }

        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling() * 0.0166 > 0) {
            voertuigen[i].setPositie(voertuigen[i].getPositie()
                + voertuigen[i].getSnelheid() * 0.0166
                + (voertuigen[i].getVersnelling() * pow(0.0166, 2)) / 2);
        }

        if (voertuigen[i].getHuidigeBaanLengte() < voertuigen[i].getPositie()) {
            voertuigen.erase(voertuigen.begin() + i);
        }
    }
}

void Voertuig::defineGewensteMaxSnelheid(vector<Voertuig>& voertuigen) {
    for (unsigned int i = 0; i < voertuigen.size(); i++) {
        voertuigen[i].setGewensteMaxSnelheid(voertuigen[i].getMaxSnelheid());
        ENSURE(voertuigen[i].getGewensteMaxSnelheid()==voertuigen[i].getMaxSnelheid(), "voertuig has undefined gewensteMaxsnelheid");
    }
}

void Voertuig::defineStopped(vector<Voertuig>& voertuigen) {
    for (unsigned int i = 0; i < voertuigen.size(); i++) {
        voertuigen[i].setStopped(false);
        ENSURE(!voertuigen[i].getStopped(), "voertuig stopped is undefined");
    }
}