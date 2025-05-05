
#ifndef VOERTUIGRIJDEN_H
#define VOERTUIGRIJDEN_H
#include "Voertuig.h"
#include "XmlParser.h"
#include <vector>

using namespace std;

/**
 * @brief Klasse voor het behandelen van rijden van voertuigen in de simulatie
 */
class VoertuigRijden {
public:
     /**
     * Deze functie werkt de positie en snelheid van alle voertuigen bij op basis van hun onderlinge interacties en verkeerslichten.
     * @param voertuigen De vector met alle voertuigen in de simulatie
     * @param verkeerslichten De vector met alle verkeerslichten in de simulatie
     * @param tijd De huidige simulatietijd
     */
    void updateVoertuigen(vector<Voertuig>& voertuigen, vector <Verkeerslicht>& verkeerslichten, int tijd);

    /**
     * Deze functie vertraagt de voertuigen in de simulatie.
     * @param voertuigen De vector met de voertuigen die vertraagd moeten worden
     */
    void vertragen(vector<Voertuig>& voertuigen);

    /**
     * Deze functie versnelt de voertuigen in de simulatie.
     * @param voertuigen De vector met de voertuigen die versneld moeten worden
     */
    void versnellen(vector<Voertuig>& voertuigen);

    /**
     * Deze functie stopt de voertuigen in de simulatie.
     * @param voertuigen De vector met de voertuigen die gestopt moeten worden
     */
    void stoppen(vector<Voertuig>& voertuigen);

    /**
     * Deze functie stelt de gewenste maximale snelheid in voor de voertuigen.
     * @param voertuigen De vector met de voertuigen waarvoor de gewenste maximale snelheid ingesteld moet worden
     */
    static void defineGewensteMaxSnelheid(vector<Voertuig>& voertuigen);

    /**
     * Deze functie stelt de gestopte status in voor alle voertuigen.
     * @param voertuigen De vector met alle voertuigen waarvoor de gestopte status ingesteld moet worden
     */
    static void defineStopped(vector<Voertuig>& voertuigen);
};

#endif //VOERTUIGRIJDEN_H
