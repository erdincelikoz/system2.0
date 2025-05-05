#include "VoertuigRijden.h"
#include <cmath>
#include <iostream>

/**
 * Deze functie werkt de positie en snelheid van alle voertuigen bij op basis van hun onderlinge interacties en verkeerslichten.
 * @param voertuigen De vector met alle voertuigen in de simulatie
 * @param verkeerslichten De vector met alle verkeerslichten in de simulatie
 * @param tijd De huidige simulatietijd
 * @exception invalid_argument Als de afstand tussen twee auto's minder is dan de minimale volgafstand
 * @exception invalid_argument Als de volgafstand negatief is
 */
void VoertuigRijden::updateVoertuigen(vector<Voertuig>& voertuigen, vector<Verkeerslicht>& verkeerslichten, int tijd) {

    for (unsigned int i=0; i < voertuigen.size(); i++) {
        if (i!=0) {
            if (voertuigen[i-1].getPositie() - voertuigen[i].getPositie() <= voertuigen[i].getMinVolgAfstand()) {
                throw invalid_argument("Afstand tussen twee auto's is minder dan de minimale volgafstand.");
            }
        }
        if (tijd==0) {
            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid());
        }
        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166 < 0) {
            voertuigen[i].setPositie(voertuigen[i].getPositie()
                                        -(pow(voertuigen[i].getSnelheid(),2))
                                        /(2*voertuigen[i].getVersnelling()));
            voertuigen[i].setSnelheid(0);
        }


        //bereken versnelling:
        if (i == 0) {
            voertuigen[i].setVersnelling(voertuigen[i].getMaxVersnelling()
                                            *(1- pow((voertuigen[i].getSnelheid()
                                            /voertuigen[i].getGewensteMaxSnelheid()),4)));
        }

        else {
            double volgafstand = voertuigen[i-1].getPositie() - voertuigen[i].getPositie() - voertuigen[i].getLengte();
            if (volgafstand <= 0) {
                throw invalid_argument("Volgafstand kan niet negatief zijn");
            }

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


        //snelheid
        if (voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166 >= 0)
        voertuigen[i].setSnelheid(voertuigen[i].getSnelheid() + voertuigen[i].getVersnelling()*0.0166);
        if (voertuigen[i].getSnelheid() > voertuigen[i].getMaxSnelheid()) {


            voertuigen[i].setSnelheid(voertuigen[i].getMaxSnelheid()); // als snelheid te hoog is wordt hij terug gereset naar max snelheid
        }


//vertragen & stoppen
        for (unsigned int j=0; j < verkeerslichten.size(); j++) {
            Verkeerslicht tempVerkeerslicht = verkeerslichten[j];

            bool isPrioriteit = (voertuigen[i].getType() == "brandweerwagen" ||
            voertuigen[i].getType() == "ziekenwagen" ||
            voertuigen[i].getType() == "politiecombi");

            if (i==0 && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() > 7.5
                    && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() <= 50
                    && !isPrioriteit) {

                Voertuig& eersteAutoVoorVerkeerslicht = voertuigen[i];

                if (tempVerkeerslicht.getKleur()) {
                    eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(eersteAutoVoorVerkeerslicht.getMaxSnelheid());
                    eersteAutoVoorVerkeerslicht.setStopped(false);
                }
                else if (!tempVerkeerslicht.getKleur()) { //als rood is
                    if (15 < tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie()
                            && tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie() <= 50) { //

                        eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(0.4*eersteAutoVoorVerkeerslicht.getMaxSnelheid()); //vertraagt
                        eersteAutoVoorVerkeerslicht.setStopped(true);

                    }

                    else if (tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie() <= 15) { //1ste auto moet stoppen
                        eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(0.4*eersteAutoVoorVerkeerslicht.getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht.setVersnelling(-((eersteAutoVoorVerkeerslicht.getMaxRemFactor()
                                                                        *eersteAutoVoorVerkeerslicht.getSnelheid())
                                                                        /eersteAutoVoorVerkeerslicht.getGewensteMaxSnelheid()));
                        eersteAutoVoorVerkeerslicht.setStopped(true);

                    }
                }

        }
            else if (i!=0 && tempVerkeerslicht.getPositie() - voertuigen[i-1].getPositie() < 7.5
                    && tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() <= 50
                    && !isPrioriteit) {
                Voertuig& eersteAutoVoorVerkeerslicht = voertuigen[i];

                if (tempVerkeerslicht.getKleur()) {
                    eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(eersteAutoVoorVerkeerslicht.getMaxSnelheid());
                }
                else if (!tempVerkeerslicht.getKleur()) {
                    if (15 < tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie()
                            && tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie() <= 50) {

                        eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(0.4*eersteAutoVoorVerkeerslicht.getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht.setStopped(true);

                    }

                    else if (tempVerkeerslicht.getPositie() - eersteAutoVoorVerkeerslicht.getPositie() <= 15) {
                        eersteAutoVoorVerkeerslicht.setGewensteMaxSnelheid(0.4*eersteAutoVoorVerkeerslicht.getMaxSnelheid());
                        eersteAutoVoorVerkeerslicht.setVersnelling(-((eersteAutoVoorVerkeerslicht.getMaxRemFactor()
                                                                        *eersteAutoVoorVerkeerslicht.getSnelheid())
                                                                        /eersteAutoVoorVerkeerslicht.getGewensteMaxSnelheid()));
                        eersteAutoVoorVerkeerslicht.setStopped(true);

                    }
                }

            }

            if (tempVerkeerslicht.getPositie() - voertuigen[i].getPositie() < 0 && !voertuigen[i].getStopped()) {
                voertuigen[i].setGewensteMaxSnelheid(voertuigen[i].getMaxSnelheid()); // blijft doorrijden
            }

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
        cout << voertuigen[i].getVersnelling() << endl;


    }
}



    /*
     *Verwachte functionaliteit:
     *Postie updaten:
     *als snelheid + versnelling*0.0166 < 0
     *snelheid = 0
     *positie = pos - snelheid^2 / 2*versnelling
     *
     *als dat niet zo is
     *snelheid = snelheid + versnelling*0.0166
     *en dan positie = pos + snelheid*0.0166 + ( versnelling * (0.0166)^2 ) / 2
     *
     *3 opties voor versnelling:
     *normale optie zie B3
     *normale optie gemodificeerd als voertuig het eerste is
     *optie van verkeerslicht + eerste auto die voor het verkeerslicht staat
     *
     */


/**
 * Deze functie stelt de gewenste maximale snelheid in voor alle voertuigen.
 * @param voertuigen De vector met de voertuigen waarvoor de gewenste maximale snelheid ingesteld moet worden
 */
void VoertuigRijden::defineGewensteMaxSnelheid(vector<Voertuig>& voertuigen) {
    for (unsigned int i = 0; i < voertuigen.size(); i++) {
        voertuigen[i].setGewensteMaxSnelheid(voertuigen[i].getMaxSnelheid());
    }
}
/**
 * Deze functie stelt de gestopte status in voor alle voertuigen.
 * @param voertuigen De vector met alle voertuigen waarvoor de gestopte status ingesteld moet worden
 */
void VoertuigRijden::defineStopped(vector<Voertuig>& voertuigen) {
    for (unsigned int i = 0; i < voertuigen.size(); i++) {
        voertuigen[i].setStopped(false);
    }
}
