/**
 * @file Verkeerslicht.h
 * @brief Simpele verkeerslichtklasse nodig voor het innemen en verwerken van informatie in verband met de verkeerslicht(en).
 * @author Erdin Celikoz & Raj Shah
 * @date 1 mei 2025
 * @version 2.0
 */
#ifndef VERKEERSLICHT_H
#define VERKEERSLICHT_H
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Simpele verkeerslichtklasse nodig voor het innemen en verwerken van informatie in verband met de verkeerslicht(en).
 */
class Verkeerslicht {
private:
    string baan;
    double positie;
    int cyclus;
    bool kleur;

public:
    /**
    * @brief Geeft de huidige kleur van het verkeerslicht terug.
    * @return Boolean waarde: true voor groen, false voor rood.
    */
    bool getKleur();

    /**
    * @brief Stelt de kleur van het verkeerslicht in.
    * @param kleur Boolean waarde: true voor groen, false voor rood.
    */
    void setKleur(bool kleur);

    /**
     * Retourneert naam van de baan waarop verkeerslicht is geplaatst
     * @return Naam van de baan als string
     */
    string getNaamBaan();

    /**
     * Retourneert positie van verkeerslicht
     * @return Positie van verkeerslicht
     */
    double getPositie();

    /**
     * Retourneert cyclus duur van verkeerslicht
     * @return Cyclus duur (in seconden)
     */
    int getCyclus();

    /**
     * Setter voor nieuwe naam van de baan
     * @param nieuw Nieuw baannaam
     */
    void setNaamBaan(string nieuw);

    /**
    * Setter voor nieuwe positie van verkeerslicht
    * @param nieuw Nieuwe positie van verkeerslicht
    */
    void setPositie(double nieuw);

    /**
    * Setter voor nieuwe cyclusduur van verkeerslicht
    * @param nieuw Nieuwe cyclusduur (in seconden)
    */
    void setCyclus(int nieuw);

    /**
    * @brief Sorteert een vector van verkeerslichten op basis van hun positie.
    * @param verkeerslichten Vector met verkeerslichten die gesorteerd moet worden.
    * @return Gesorteerde vector van verkeerslichten
    */
    static vector<Verkeerslicht> sortVerkeerslichten(vector<Verkeerslicht> verkeerslichten);

    /**
     * @brief Constructor voor een verkeerslicht.
     * @param baan De baan waar het verkeerslicht zich op bevindt.
     * @param positie De positie van het verkeerslicht op de baan.
     * @param cyclus De tijdscyclus van het verkeerslicht.
     */
    Verkeerslicht(string baan, double positie, int cyclus);
};

#endif // VERKEERSLICHT_H