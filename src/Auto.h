/**
* @file Auto.h
 * @brief Definitie van de Auto klasse die de Voertuig klasse erft.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#ifndef AUTO_H
#define AUTO_H

#include "Voertuig.h"
#include "DesignByContract.h"

class Auto : public Voertuig {
private:
    Auto* _initCheck;
public:
    /**
     * @brief Constructor voor Auto.
     * @param baan Naam van de baan.
     * @param positie Beginpositie op de baan.
     */
    Auto(string &baan, int positie);

    bool properlyInit() const;

    /**
     *REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getLengte");
     */
    int getLengte() const override;

    /**
    *REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxSnelheid");
    */
    double getMaxSnelheid() const override;

    /**
    *REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxRemFactor");
    */
    double getMaxRemFactor() const override;

    /**
    *REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMaxVerSnelling");
    */
    double getMaxVersnelling() const override;

    /**
    *REQUIRE(this->properlyInit(), "Auto was not properly initialized before calling getMinVolgAfstand");
     */
    int getMinVolgAfstand() const override;

};

#endif // AUTO_H