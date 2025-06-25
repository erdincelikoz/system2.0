/**
* @file Bus.cpp
 * @brief Implementatie van de Bus klasse.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#include "Bus.h"
#include "DesignByContract.h"

Bus::Bus(string &baan, int positie)
        : Voertuig(baan, positie, "Bus") {
    _initCheck = this;
    setLengte(12);
    setMaxSnelheid(11.4);
    setMaxVersnelling(1.22);
    setMaxRemFactor(4.29);
    setMinVolgAfstand(12);
    ENSURE(properlyInit(), "constructor must end in properlyInit state");
}

bool Bus::properlyInit() const {
    return _initCheck == this;
}

int Bus::getLengte() const {
    REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getLengte");
    return 12;
}

double Bus::getMaxSnelheid() const {
    REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxSnelheid");
    return 11.4;
}

double Bus::getMaxVersnelling() const {
    REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxVersnelling");
    return 1.22;
}

double Bus::getMaxRemFactor() const {
    REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxRemFactor");
    return 4.29;
}

int Bus::getMinVolgAfstand() const {
    REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMinVolgAfstand");
    return 12;
}