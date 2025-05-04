#include "VoertuigRijden.h"
#include <cmath>
#include <iostream>

void VoertuigRijden::updateVoertuigen(vector<Voertuig>& voertuigen, int tijd) {
    for (unsigned int i=0; i < voertuigen.size(); i++) {
        if (tijd==0) {
            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid());
        }
        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166 < 0) {
            voertuigen[i].setPositie(voertuigen[i].getPositie()
                                        -(pow(voertuigen[i].getSnelheid(),2))
                                        /(2*voertuigen[i].getVersnelling()));
        }


        //bereken versnelling:
        if (i == 0) {
            voertuigen[i].setVersnelling(voertuigen[i].getMaxVersnelling()
                                            *(1- pow((voertuigen[i].getSnelheid()
                                            /voertuigen[i].getMaxSnelheid()),4)));
        }

        else {
            double volgafstand = voertuigen[i-1].getPositie() - voertuigen[i].getPositie() - voertuigen[i].getLengte();

            double snelheidsverschil = voertuigen[i].getSnelheid()-voertuigen[i-1].getSnelheid();

            double interactieterm = (voertuigen[i].getMinVolgAfstand() +
                                        max(0.0,voertuigen[i].getSnelheid()
                                        +((voertuigen[i].getSnelheid()
                                        *snelheidsverschil)
                                        /(2*sqrt(voertuigen[i].getMaxVersnelling()
                                        *voertuigen[i].getMaxRemFactor())))))
                                        /volgafstand;

            voertuigen[i].setVersnelling(voertuigen[i].getMaxVersnelling()
                                            *(1- pow((voertuigen[i].getSnelheid()
                                            /voertuigen[i].getGewensteMaxSnelheid()),4))
                                            -pow(interactieterm,2));
        }



        voertuigen[i].setSnelheid(voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166);
        if (voertuigen[i].getSnelheid() > voertuigen[i].getMaxSnelheid()) {

            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid()); // als snelheid te hoog is wordt hij terug gereset naar max snelheid
        }
        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166 > 0) {
            voertuigen[i].setPositie(voertuigen[i].getPositie()
                                        +voertuigen[i].getSnelheid()*0.0166
                                        +(voertuigen[i].getVersnelling()*pow(0.0166,2))
                                        /2);

        }
        if (voertuigen[i].getHuidigeBaanLengte() < voertuigen[i].getPositie()) {
            voertuigen.erase(voertuigen.begin()+i);
        }
    }
}
void VoertuigRijden::vertragen(vector<Voertuig>& voertuigen) {
    voertuigen[0].setGewensteMaxSnelheid(0.4 * voertuigen[0].getMaxSnelheid());

}

void VoertuigRijden::versnellen(vector<Voertuig>& voertuigen) {
    if (voertuigen.size() > 0) {
        voertuigen[0].setGewensteMaxSnelheid(voertuigen[0].getMaxSnelheid());
    }
}
void VoertuigRijden::stoppen(vector<Voertuig>& voertuigen) {
    for (unsigned int j = 0; j < voertuigen.size(); j++) {
        double versnelling  = (-1 * voertuigen[j].getMaxRemFactor() * voertuigen[j].getSnelheid()) / (voertuigen[j].getMaxSnelheid());

        voertuigen[j].setVersnelling(versnelling);
    }
}
void VoertuigRijden::defineGewensteMaxSnelheid(vector<Voertuig>& voertuigen) {
    for (unsigned int k = 0; k < voertuigen.size(); k++) {
        voertuigen[k].setGewensteMaxSnelheid(voertuigen[k].getMaxSnelheid());
        cout << voertuigen[k].getGewensteMaxSnelheid() << endl;
    }

}
