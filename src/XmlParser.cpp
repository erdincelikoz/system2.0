#include "XmlParser.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include "Voertuiggenerator.h"
using namespace std;

XmlParser::XmlParser(string inputnaam) {
    bestandsnaam = inputnaam;
}
void XmlParser::setParsedBanen(vector<Baan> tempBanen) {
    parsedBanen = tempBanen;
}
void XmlParser::setParsedVoertuigen(vector<Voertuig> tempVoertuigen) {
    parsedVoertuigen = tempVoertuigen;
}
vector<Verkeerslicht> XmlParser::getParsedVerkeerslichten() const {
    return parsedVerkeerslichten;
}
void XmlParser::setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht) {
    parsedVerkeerslichten = parsed_verkeerslicht;
}
vector<Baan> XmlParser::getParsedBanen() {
    return parsedBanen;
}
vector<Voertuig> XmlParser::getParsedVoertuigen() {
    return parsedVoertuigen;
}

vector<Bushalte> XmlParser::getParsedBushaltes() const {
    return parsedBushaltes;
}

void XmlParser::setParsedBushaltes(const vector<Bushalte> &parsed_bushaltes) {
    parsedBushaltes = parsed_bushaltes;
}

vector<Kruispunt> XmlParser::getParsedKruispunten() const {
    return parsedKruispunten;
}

void XmlParser::setParsedKruispunten(const vector<Kruispunt> &parsed_kruispunten) {
    parsedKruispunten = parsed_kruispunten;
}

vector<Voertuiggenerator> XmlParser::getParsedVoertuiggeneratoren() const {
    return parsedVoertuiggenerator;
}

void XmlParser::setParsedVoertuiggeneratoren(const vector<Voertuiggenerator> &parsed_voertuiggenerator) {
    parsedVoertuiggenerator = parsed_voertuiggenerator;
}

Baan* XmlParser::getRelevanteBaan(const string& baannaam) {
    for (unsigned int i=0; i < getParsedBanen().size(); i++) {
        if (getParsedBanen()[i].getNaamBaan() == baannaam) {
            return &getParsedBanen()[i];
        }
    }
    return nullptr;
}

void XmlParser::parse() {
    TiXmlDocument doc(bestandsnaam.c_str());



    //Checks voor geldigheid voordat we parsen
    if (!doc.LoadFile()) {
        cerr << "Failed to load file" << endl; //moeten weg bij eindresultaat wanneer gtest toegevoegd wordt
        exit(-1);
    }
    // Get Root element van XML file
    TiXmlElement* root = doc.FirstChildElement();
    if (!root) {
        cerr << "No root element found" << endl; //moeten weg bij eindresultaat wanneer gtest toegevoegd wordt
        exit(-2);
    }

    if (root->FirstChildElement() == NULL) {
        cerr << "No  element found" << endl; //moeten weg bij eindresultaat wanneer gtest toegevoegd wordt
        exit(-3);
    }



    vector<Baan> tempBanen;
    vector<Voertuig> tempVoertuigen;
    vector<Verkeerslicht> tempVerkeerslichten;
    vector<Voertuiggenerator> tempVoertuiggeneratoren;
    vector<Bushalte> tempBushaltes;
    vector<Kruispunt> tempKruispunten;
    for (TiXmlElement* element = root-> FirstChildElement(); element != NULL; element = element->NextSiblingElement()) {
        string elementType = element-> Value();

        if (elementType == "BAAN") {
            // Baan informatie process
            TiXmlElement* naamElement = element-> FirstChildElement("naam");
            TiXmlElement* lengteElement = element->FirstChildElement("lengte");



            if (lengteElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (naamElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (naamElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (lengteElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }



            string naam = naamElement->GetText();
            int lengte = stoi(lengteElement->GetText());

            if (lengte < 0 || naam == "") {
                throw invalid_argument("Baan lengte is leeg of negatief");
            }

            Baan temp(naam,lengte);
            tempBanen.push_back(temp);
        }



        if (elementType == "VOERTUIG") {
            // Voertuig informatie process

            TiXmlElement* baanNaamElement = element-> FirstChildElement("baan");
            TiXmlElement* positieElement = element-> FirstChildElement("positie");
            TiXmlElement* typeElement = element-> FirstChildElement("type");



            if (baanNaamElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (positieElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (typeElement == nullptr) {
                continue;
            }

            if (baanNaamElement->GetText() == nullptr) {
                continue;
            }

            if (positieElement->GetText() == nullptr) {
                continue;
            }

            if (typeElement->GetText() == nullptr) {
                continue;
            }


            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            string type = typeElement->GetText();
            Voertuig temp(baanNaam, positie, type);
            tempVoertuigen.push_back(temp);
        }

        if (elementType == "VERKEERSLICHT") {
            TiXmlElement* baanNaamElement = element->FirstChildElement("baan");
            TiXmlElement* positieElement = element->FirstChildElement("positie");
            TiXmlElement* cyclusElement = element-> FirstChildElement("cyclus");



            if (baanNaamElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (positieElement == nullptr) {
                ///
            }

            if (cyclusElement == nullptr) {
                ///
            }

            if (baanNaamElement->GetText() == nullptr) {
                ///
            }

            if (positieElement->GetText() == nullptr) {
                ///
            }

            if (cyclusElement->GetText() == nullptr) {
                ///
            }
            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            int cyclus = stoi(cyclusElement->GetText());

            if (cyclus < 0) {
                ///
            }

            Verkeerslicht temp(baanNaam, positie, cyclus);
            tempVerkeerslichten.push_back(temp);
        }
        if (elementType=="VOERTUIGGENERATOR") {

            TiXmlElement* baanNaamElement = element-> FirstChildElement("baan");
            TiXmlElement* frequentieElement = element-> FirstChildElement("frequentie");
            TiXmlElement* typeElement = element-> FirstChildElement("type");



            if (baanNaamElement == nullptr) {
                ///
            }

            if (frequentieElement == nullptr) {
                ///
            }

            if (typeElement == nullptr) {
                ///
            }

            if (baanNaamElement->GetText() == nullptr) {
                ///
            }

            if (frequentieElement->GetText() == nullptr) {
                ///
            }

            if (typeElement->GetText() == nullptr) {
                ///
            }



            string baanNaam = baanNaamElement->GetText();
            int frequentie = stoi(frequentieElement->GetText());

            if (frequentie < 0) {
                ///
            }
            string type = typeElement->GetText();
            Voertuiggenerator temp(baanNaam, frequentie, type);
            tempVoertuiggeneratoren.push_back(temp);
        }

        if (elementType == "Bushalte") {
            TiXmlElement* baanNaamElement = element-> FirstChildElement("baan");
            TiXmlElement* positieElement = element-> FirstChildElement("positie");
            TiXmlElement* wachttijdElement = element-> FirstChildElement("wachttijd");



            if (baanNaamElement == nullptr) {
                ///
            }

            if (positieElement == nullptr) {
                ///
            }

            if (wachttijdElement == nullptr) {
                ///
            }

            if (baanNaamElement->GetText() == nullptr) {
                ///
            }

            if (positieElement->GetText() == nullptr) {
                ///
            }

            if (wachttijdElement->GetText() == nullptr) {
                ///
            }



            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            int wachttijd = stoi(wachttijdElement->GetText());

            if (wachttijd < 0) {
                ///
            }

            Bushalte temp(baanNaam, positie, wachttijd);
            tempBushaltes.push_back(temp);
        }
    }



    //Parsed Baan
    setParsedBanen(tempBanen);



    //Parsed Voertuig
    for (int i=tempVoertuigen.size()-1; i >= 0 ; i--) {
        Voertuig* temp = &tempVoertuigen[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            ///
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            ///
                }
        if (temp->getLengte()==-1 || temp->getMaxVersnelling()==-1 || temp->getMaxSnelheid()==-1 ||
                temp->getMaxRemFactor()==-1 || temp->getMinVolgAfstand()==-1) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            ///
                }
    }
    setParsedVoertuigen(tempVoertuigen);



    //Parsed Verkeerslicht
    for (int i=tempVerkeerslichten.size()-1; i >= 0 ; i--) {
        Verkeerslicht* temp = &tempVerkeerslichten[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            ///
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            ///
        }
    }
    setParsedVerkeerslichten(tempVerkeerslichten);



    //Parsed Voertuiggenerator
    for (int i=tempVoertuiggeneratoren.size()-1; i >= 0 ; i--) {
        Voertuiggenerator* temp = &tempVoertuiggeneratoren[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVoertuiggeneratoren.erase(tempVoertuiggeneratoren.begin()+i);
            ///
        }
        string type = tempVoertuiggeneratoren[i].getType();
        if (type != "auto" && type != "bus" && type != "brandweerwagen" && type != "ziekenwagen" && type != "politiecombi") {
            tempVoertuiggeneratoren.erase(tempVoertuiggeneratoren.begin()+i);
            ///
        }
    }
    setParsedVoertuiggeneratoren(tempVoertuiggeneratoren);



    //Parsed Bushalte
    for (int i=tempBushaltes.size()-1; i >= 0 ; i--) {
        Bushalte* temp = &tempBushaltes[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempBushaltes.erase(tempBushaltes.begin()+i);
            ///
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempBushaltes.erase(tempBushaltes.begin()+i);
            ///
        }
    }
    setParsedBushaltes(tempBushaltes);


    //Parsed Kruispunt

    doc.Clear();
}
