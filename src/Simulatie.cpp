#include "Simulatie.h"
#include <chrono>
#include <thread>
#include <cmath>
using namespace std::this_thread;
using namespace std::chrono;

void switchKleur(vector<Verkeerslicht>& verkeerslichten, int tijd) {
    for (Verkeerslicht& verkeerslicht : verkeerslichten)
        if (tijd%verkeerslicht.getCyclus()==0) {
            verkeerslicht.setKleur(verkeerslicht.getKleur()==true ? false : true);
        }
}
void defineKleur(vector<Verkeerslicht>& verkeerslichten) {
    for (Verkeerslicht& verkeerslicht : verkeerslichten) {
        verkeerslicht.setKleur(true);
    }
}

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

        temp.updateVoertuigen(parser.getParsedVoertuigen(), tijd);
        sleep_for(microseconds(166));
        tijd++;
    }
}

