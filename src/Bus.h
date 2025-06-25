/**
* @file Bus.h
 * @brief Definitie van de Bus klasse die de Voertuig klasse erft.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#ifndef BUS_H
#define BUS_H
#include "Voertuig.h"

class Bus : public Voertuig {
private:
    Bus* _initCheck;
public:
    /**
     * @brief Constructor voor Bus.
     * @param baan Naam van de baan.
     * @param positie Beginpositie op de baan.
     */
    Bus(string &baan, int positie);

    bool properlyInit() const;

    /**
* REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getLengte");
*/
    int getLengte() const override;

    /**
 * REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxSnelheid");
 */
    double getMaxSnelheid() const override;

    /**
 * REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxRemFactor");
 */
    double getMaxRemFactor() const override;

    /**
 * REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMaxVersnelling");
 */
    double getMaxVersnelling() const override;

    /**
 * REQUIRE(this->properlyInit(), "Bus was not properly initialized before calling getMinVolgAfstand");
 */
    int getMinVolgAfstand() const override;
};

#endif // BUS_H