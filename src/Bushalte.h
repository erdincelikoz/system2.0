#ifndef BUSHALTE_H
#define BUSHALTE_H

#include <string>
using namespace std;

/**
 * @brief Klasse die een bushalte modelleert op een bepaalde positie van een baan.
 */
class Bushalte {
private:
    string baanNaam;

public:
    /**
     * @brief Constructor voor een bushalte.
     * @param baan_naam De naam van de baan waarop de bushalte zich bevindt.
     * @param positie De positie van de bushalte op de baan.
     * @param wachttijd De wachttijd in seconden die een bus moet wachten bij deze halte.
     */
    Bushalte(const string &baan_naam, int positie, int wachttijd);

private:
    int positie;
    int wachttijd;

public:
    /**
     * @brief Geeft de naam van de baan terug waarop de bushalte zich bevindt.
     * @return De naam van de baan als string.
     */
    string getNaamBaan() const;

    /**
     * @brief Stelt de naam van de baan in waarop de bushalte zich bevindt.
     * @param baan_naam De nieuwe naam van de baan.
     */
    void setNaamBaan(const string &baan_naam);

    /**
     * @brief Geeft de positie van de bushalte op de baan terug.
     * @return De positie als integer.
     */
    int getPositie() const;

    /**
     * @brief Stelt de positie van de bushalte op de baan in.
     * @param positie De nieuwe positie.
     */
    void setPositie(int positie);

    /**
     * @brief Geeft de wachttijd terug die een bus moet wachten bij deze halte.
     * @return De wachttijd in seconden als integer.
     */
    int getWachttijd() const;

    /**
     * @brief Stelt de wachttijd in die een bus moet wachten bij deze halte.
     * @param wachttijd De nieuwe wachttijd in seconden.
     */
    void setWachttijd(int wachttijd);
};

#endif //BUSHALTE_H
