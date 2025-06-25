/**
* @file Brandweerwagen.cpp
 * @brief Implementatie van de Brandweerwagen klasse.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#include "Brandweerwagen.h"
#include "DesignByContract.h"

Brandweerwagen::Brandweerwagen(string &baan, int positie)
        : Voertuig(baan, positie, "Brandweerwagen") {
    _initCheck = this;
    setLengte(10);
    setMaxSnelheid(14.6);
    setMaxVersnelling(1.33);
    setMaxRemFactor(4.56);
    setMinVolgAfstand(10);
    ENSURE(properlyInit(), "constructor must end in properlyInit state");
}

bool Brandweerwagen::properlyInit() const {
    return _initCheck == this;
}

int Brandweerwagen::getLengte() const {
    REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getLengte");
    return 10;
}

double Brandweerwagen::getMaxSnelheid() const {
    REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxSnelheid");
    return 14.6;
}

double Brandweerwagen::getMaxVersnelling() const {
    REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxVersnelling");
    return 1.33;
}

double Brandweerwagen::getMaxRemFactor() const {
    REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxRemFactor");
    return 4.56;
}

int Brandweerwagen::getMinVolgAfstand() const {
    REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMinVolgAfstand");
    return 10;
}