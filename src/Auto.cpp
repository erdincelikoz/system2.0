/**
* @file Auto.cpp
 * @brief Implementatie van de Auto klasse.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#include "Auto.h"
#include "Voertuig.h"

Auto::Auto(string &baan, int positie)
    : Voertuig(baan, positie, "Auto") {
    _initCheck = this;
    setLengte(4);
    setMaxSnelheid(16.6);
    setMaxVersnelling(1.44);
    setMaxRemFactor(4.61);
    setMinVolgAfstand(4);
    ENSURE(properlyInit(), "constructor must end in properlyInit state");
}

bool Auto::properlyInit() const {
    return _initCheck == this;
}


int Auto::getLengte() const {
    REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getLengte");
    return 4;
}

double Auto::getMaxSnelheid() const {
    REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxSnelheid");
    return 16.6;
}

double Auto::getMaxVersnelling() const {
    REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxVersnelling");
    return 1.44;
}

double Auto::getMaxRemFactor() const {
    REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxRemFactor");
    return 4.61;
}

int Auto::getMinVolgAfstand() const {
    REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMinVolgAfstand");
    return 4;
}



