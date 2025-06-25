/**
* @file Brandweerwagen.h
 * @brief Definitie van de Brandweerwagen klasse die de Voertuig klasse erft.
 * @author Erdin Celikoz & Raj Shah
 * @date 23 June 2025
 * @version 1.0
 */

#ifndef BRANDWEERWAGEN_H
#define BRANDWEERWAGEN_H
#include "Voertuig.h"

class Brandweerwagen : public Voertuig {
private:
    Brandweerwagen* _initCheck;
public:
    /**
     * @brief Constructor voor Brandweerwagen.
     * @param baan Naam van de baan.
     * @param positie Beginpositie op de baan.
     */
    Brandweerwagen(string &baan, int positie);

    bool properlyInit() const;

    /**
 *REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getLengte");
 */
    int getLengte() const override;

    /**
 *REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxSnelheid");
 */
    double getMaxSnelheid() const override;

    /**
*REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxRemFactor");
*/
    double getMaxRemFactor() const override;

    /**
*REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMaxVersnelling");
*/
    double getMaxVersnelling() const override;

    /**
*REQUIRE(this->properlyInit(), "Brandweerwagen was not properly initialized before calling getMinVolgafstand");
*/
    int getMinVolgAfstand() const override;
};

#endif // BRANDWEERWAGEN_H