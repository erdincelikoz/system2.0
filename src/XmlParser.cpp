#include "XmlParser.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
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
    return parsedVerkeerslicht;
}
void XmlParser::setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht) {
    parsedVerkeerslicht = parsed_verkeerslicht;
}
vector<Baan> XmlParser::getParsedBanen() {
    return parsedBanen;
}
vector<Voertuig> XmlParser::getParsedVoertuigen() {
    return parsedVoertuigen;
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
                cerr << "[Ongeldige informatie]" << endl; //moeten weg bij eindresultaat wanneer gtest toegevoegd wordt
                continue;
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
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (baanNaamElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (positieElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (typeElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
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
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (cyclusElement == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (baanNaamElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (positieElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }

            if (cyclusElement->GetText() == nullptr) {
                cerr << "[Onherkenbaar element]" << endl;
                continue;
            }
            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            int cyclus = stoi(cyclusElement->GetText());

            if (cyclus < 0) {
                cerr << "[Ongeldige informatie]" << endl;
                continue;
            }

            Verkeerslicht temp(baanNaam, positie, cyclus);
            tempVerkeerslichten.push_back(temp);
        }
    }
    //Parsed baan
    setParsedBanen(tempBanen);


    //Parsed Voertuig
    for (int i=tempVoertuigen.size()-1; i >= 0 ; i--) {
        Voertuig* temp = &tempVoertuigen[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            cerr << "[Ongeldige informatie]" << endl;
            continue;
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            cerr << "[Ongeldige informatie]" << endl;
            continue;
        }
        if (temp->getLengte()==-1 || temp->getMaxVersnelling()==-1 || temp->getMaxSnelheid()==-1 ||
                temp->getMaxRemFactor()==-1 || temp->getMinVolgAfstand()==-1) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            cerr << "[Ongeldige informatie]" << endl;
        }
    }
    setParsedVoertuigen(tempVoertuigen);


    //Parsed Verkeerslicht
    for (int i=tempVerkeerslichten.size()-1; i >= 0 ; i--) {
        Verkeerslicht* temp = &tempVerkeerslichten[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            cerr << "[Ongeldige informatie]" << endl;
            continue;
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            cerr << "[Ongeldige informatie]" << endl;
            continue;
        }
    }
    setParsedVerkeerslichten(tempVerkeerslichten);

    doc.Clear();
}