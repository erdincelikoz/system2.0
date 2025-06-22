#include "Simulatie.h"
#include <chrono>
#include <thread>
#include <cmath>
using namespace std::this_thread;
using namespace std::chrono;

/**
 * @brief Schakelt verkeerslichten van kleur op basis van hun cyclustijd.
 * @param verkeerslichten Vector met verkeerslichten die mogelijk van kleur moeten veranderen.
 * @param tijd De huidige simulatietijd.
 */
void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd) {
    for (Verkeerslicht& verkeerslicht : verkeerslichten)
        if (tijd%verkeerslicht.getCyclus()==0) {            //als tijd een veelvoud is van cyclustijd, wissel van kleur
            verkeerslicht.setKleur(verkeerslicht.getKleur()==true ? false : true);
        }
}

/**
 * @brief Initialiseert alle verkeerslichten met de groene kleur
 * @param verkeerslichten Vector met verkeerslichten die geïnitialiseerd moeten worden
 */
void defineKleur(vector<Verkeerslicht>& verkeerslichten) {
    for (Verkeerslicht& verkeerslicht : verkeerslichten) {
        verkeerslicht.setKleur(true);
    }
}

/**
 * @brief Voert de verkeerssimulatie uit.
 */
void runSimulation() {
    XmlParser parser("src/input.xml");
    parser.parse();
    int tijd = 0;
    VoertuigRijden temp;
    while (true) {
        if (tijd==0) {
            VoertuigRijden::defineGewensteMaxSnelheid(parser.getParsedVoertuigen());
            defineKleur(parser.getParsedVerkeerslichten());
        }
        string sTijd = to_string(tijd);
        cout << "Tijd: " << sTijd << endl;

        switchKleur(parser.getParsedVerkeerslichten(), tijd);

        for (unsigned int i=0; i < parser.getParsedVoertuigen().size(); i++) {
            string si = to_string(i+1);
            cout << "Voertuig " << si << endl;
            cout << "-> baan: " << parser.getParsedVoertuigen()[i].getNaamBaan() << endl;
            int iPositie = int(round(parser.getParsedVoertuigen()[i].getPositie()));
            string sPositie = to_string(iPositie);
            cout << "-> positie: " << sPositie << endl;
            string sSnelheid = to_string(parser.getParsedVoertuigen()[i].getSnelheid());
            cout << "-> snelheid: " << sSnelheid << endl;
    }
        temp.updateVoertuigen(parser.getParsedVoertuigen(), parser.getParsedVerkeerslichten(), tijd);
        sleep_for(microseconds(16600));
        tijd++;
    }
}

