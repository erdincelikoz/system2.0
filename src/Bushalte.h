//===========================//
// Bushalte.h
//===========================//

/**
 * @file Bushalte.h
 * @brief Klasse die een bushalte modelleert.
 * @author Raj Shah and Erdin Celikoz
 * @date 2025-06-23
 * @version 1.0
 */

#ifndef BUSHALTE_H
#define BUSHALTE_H

#include <string>
using namespace std;

class Bushalte {
private:
    string baanNaam;
    int positie;
    int wachttijd;

public:
    Bushalte(const string &baan_naam, int positie, int wachttijd);

    bool properlyInit();

    /**
     *ENSURE(baanNaam != "", "baan naam must not be empty");
     */
    string getNaamBaan() const;

    /**
     *REQUIRE(baan_naam != "", "baan naam must not be set to empty")
     */
    void setNaamBaan(const string &baan_naam);

    /**
     *ENSURE(positie>=0, "positie must not be less than 0")
     */
    int getPositie() const;

    /**
     *REQUIRE(positie>=0, "positie must not be set to less than 0")
     */
    void setPositie(int positie);

    /**
     *ENSURE(wachttijd>=0, "wachttijd must not be less than 0")
     */
    int getWachttijd() const;

    /**
     *REQUIRE(wachttijd>=0, "wachttijd must not be set to less than 0")
     */
    void setWachttijd(int wachttijd);
};

#endif //BUSHALTE_H
