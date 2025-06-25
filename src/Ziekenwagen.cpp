/**
* @file Ziekenwagen.cpp
 * @brief Implementatie van Politiecombi klasse.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */
#include "Ziekenwagen.h"
#include "DesignByContract.h"

Ziekenwagen::Ziekenwagen(std::string& baan, int positie)
        : Voertuig(baan, positie, "Ziekenwagen") {
    _initCheck = this;
    setLengte(8);
    setMaxSnelheid(15.5);
    setMaxVersnelling(1.44);
    setMaxRemFactor(4.47);
    setMinVolgAfstand(8);
    ENSURE(properlyInit(), "constructor must end in properlyInit state");
}

bool Ziekenwagen::properlyInit() const {
    return _initCheck == this;
}

int Ziekenwagen::getLengte() const {
    REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getLengte");
    return 8;
}
double Ziekenwagen::getMaxSnelheid() const {
    REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxSnelheid");
    return 15.5;
}
double Ziekenwagen::getMaxVersnelling() const {
    REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxVersnelling");
    return 1.44;
}
double Ziekenwagen::getMaxRemFactor() const {
    REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxRemFactor");
    return 4.47;
}
int Ziekenwagen::getMinVolgAfstand() const {
    REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMinVolgAfstand");
    return 8;
}