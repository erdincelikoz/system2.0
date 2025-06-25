/**
* @file Ziekenwagen.h
 * @brief Klasse die een politiewagen representeert.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#ifndef ZIEKENWAGEN_H
#define ZIEKENWAGEN_H

#include <cassert>
#include "Voertuig.h"

class Ziekenwagen : public Voertuig {
private:
    Ziekenwagen* _initCheck;
public:
   /**
 * @brief Constructor voor Ziekenwagen.
 * @param baan Naam van de baan.
 * @param positie Beginpositie op de baan.
 */
    Ziekenwagen(std::string& baan, int positie);

    bool properlyInit() const;

    /**
 *REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getLengte");
 */
    int getLengte() const override;

    /**
 *REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxSnelheid");
 */
    double getMaxSnelheid() const override;

    /**
 *REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxRemFactor");
 */
    double getMaxRemFactor() const override;

    /**
 *REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMaxVersnelling");
 */
    double getMaxVersnelling() const override;

   /**
 *REQUIRE(this->properlyInit(), "Ziekenwagen was not properly initialized before calling getMinVolgAfstand");
 */
    int getMinVolgAfstand() const override;
};

#endif // ZIEKENWAGEN_H