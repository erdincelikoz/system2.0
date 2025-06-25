#include "XmlParser.h"
#include "tinyxml.h"
#include <iostream>
#include <string>
#include "Baan.h"
#include "Voertuig.h"
#include "Auto.h"
#include "Bus.h"
#include "Brandweerwagen.h"
#include "Ziekenwagen.h"
#include "Politiecombi.h"
#include "Verkeerslicht.h"
#include "Voertuiggenerator.h"
#include "DesignByContract.h"
using namespace std;

XmlParser::XmlParser(string inputnaam) {
    _initCheck = this;
    bestandsnaam = inputnaam;
    ENSURE(properlyInit(), "constructor must end in properlyInit state");
}

bool XmlParser::properlyInit() {
    return _initCheck == this;
}

void XmlParser::setParsedBanen(vector<Baan> tempBanen) {
    parsedBanen = tempBanen;
}


void XmlParser::setParsedVoertuigen(vector<Voertuig> tempVoertuigen) {
    parsedVoertuigen = tempVoertuigen;
}

vector<Verkeerslicht>& XmlParser::getParsedVerkeerslichten() {
    return parsedVerkeerslichten;
}

void XmlParser::setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht) {
    parsedVerkeerslichten = parsed_verkeerslicht;
}
/**
 * Geeft de geparste banen terug.
 * @return Vector met banen uit het XML-bestand
 */
vector<Baan> XmlParser::getParsedBanen() {
    return parsedBanen;
}

/**
 * Geeft de geparste voertuigen terug.
 * @return Referentie naar vector met voertuigen uit het XML-bestand
 */
vector<Voertuig> &XmlParser::getParsedVoertuigen() {
    return parsedVoertuigen;
}

/**
 * Geeft de geparste bushaltes terug.
 * @return Vector met bushaltes uit het XML-bestand
 */
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
/**
 * Zoekt een baan op basis van de naam.
 * @param baannaam De naam van de baan die moet worden gezocht
 * @return Pointer naar de baan als deze bestaat, anders nullptr
 */
Baan* XmlParser::getRelevanteBaan(const string& baannaam) {
    for (unsigned int i=0; i < getParsedBanen().size(); i++) {
        if (getParsedBanen()[i].getNaamBaan() == baannaam) {
            return &getParsedBanen()[i];
        }
    }
    return nullptr;
}

/**
 * Parst het XML-bestand en laadt de elementen in de juiste vectoren.
 * @throw invalid_argument Als het bestand niet kan worden geladen of als er ongeldige elementen zijn
 */
void XmlParser::parse() {
    TiXmlDocument doc(bestandsnaam.c_str());

    //Checks voor geldigheid voordat we parsen
    if (!doc.LoadFile()) {
        throw invalid_argument("Failed to load file");
    }
    // Get Root element van XML file
    TiXmlElement* root = doc.FirstChildElement();
    if (!root) {
        throw invalid_argument("No root element found");
    }

    if (root->FirstChildElement() == NULL) {
        throw invalid_argument("No  element found");
    }

    vector<Baan> tempBanen;
    vector<Voertuig> tempVoertuigen;
    vector<bool> typeOngeldig;
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

            if (naamElement == nullptr || lengteElement == nullptr) {
                throw invalid_argument("BAAN element ontbreekt naam of lengte");
            }

            // Check for empty text
            if (naamElement->GetText() == nullptr) {
                throw invalid_argument("Baan naam is leeg");
            }

            if (lengteElement->GetText() == nullptr) {
                throw invalid_argument("Baan lengte is leeg");
            }

            string naam = naamElement->GetText();
            string lengteStr = lengteElement->GetText();

            // Check voor lengte string
            if (lengteStr.empty()) {
                throw invalid_argument("Baan lengte is leeg");
            }

            // Convert and validate lengte
            int lengte;
            try {
                lengte = stoi(lengteStr);
            } catch (const exception& e) {
                throw invalid_argument("Ongeldige lengte waarde: " + string(e.what()));
            }

            if (lengte < 0) {
                throw invalid_argument("Baan lengte is negatief");
            }

            if (naam.empty()) {
                throw invalid_argument("Baan naam is leeg");
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
                throw invalid_argument("VOERTUIG element ontbreekt baannaam");
            }

            if (positieElement == nullptr) {
                throw invalid_argument("VOERTUIG element ontbreekt positie");
            }

            if (typeElement == nullptr) {
                throw invalid_argument("VOERTUIG element ontbreekt type");
            }

            if (baanNaamElement->GetText() == nullptr) {
                throw invalid_argument("Baannaam van het voertuig is leeg");
            }

            if (positieElement->GetText() == nullptr) {
                throw invalid_argument("Positie van het voertuig is leeg");
            }

            if (typeElement->GetText() == nullptr) {
                throw invalid_argument("Type van het voertuig is leeg");
            }


            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            string type = typeElement->GetText();
            if (type == "auto") {
                Auto temp(baanNaam, positie);
                tempVoertuigen.push_back(temp);
                typeOngeldig.push_back(0);
            }
            else if (type == "bus") {
                Bus temp(baanNaam, positie);
                tempVoertuigen.push_back(temp);
                typeOngeldig.push_back(0);
            }
            else if (type == "brandweerwagen") {
                Brandweerwagen temp(baanNaam, positie);
                tempVoertuigen.push_back(temp);
                typeOngeldig.push_back(0);
            }
            else if (type == "ziekenwagen") {
                Ziekenwagen temp(baanNaam, positie);
                tempVoertuigen.push_back(temp);
                typeOngeldig.push_back(0);
            }
            else if (type == "politiecombi") {
                Politiecombi temp(baanNaam, positie);
                tempVoertuigen.push_back(temp);
                typeOngeldig.push_back(0);
            }
            else {
                throw invalid_argument ("VOERTUIG heeft geen geldige type");
                typeOngeldig.push_back(1);
            }
        }


        if (elementType == "VERKEERSLICHT") {
            TiXmlElement* baanNaamElement = element->FirstChildElement("baan");
            TiXmlElement* positieElement = element->FirstChildElement("positie");
            TiXmlElement* cyclusElement = element-> FirstChildElement("cyclus");

            if (baanNaamElement == nullptr) {
                throw invalid_argument("VERKEERSLICHT element ontbreekt baannaam");
            }

            if (positieElement == nullptr) {
                throw invalid_argument("VERKEERSLICHT element ontbreekt positie");
            }

            if (cyclusElement == nullptr) {
                throw invalid_argument("VERKEERSLICHT element ontbreekt cyclus");
            }

            if (baanNaamElement->GetText() == nullptr) {
                throw invalid_argument("Baannaam van het verkeerslicht is leeg");
            }

            if (positieElement->GetText() == nullptr) {
                throw invalid_argument("Positie van het verkeerslicht is leeg");
            }

            if (cyclusElement->GetText() == nullptr) {
                throw invalid_argument("Cyclus van het verkeerslicht is leeg");
            }
            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            int cyclus = stoi(cyclusElement->GetText());

            if (cyclus < 0) {
                throw invalid_argument("Cyclus van verkeerslicht is negatief");
            }

            Verkeerslicht temp(baanNaam, positie, cyclus);
            tempVerkeerslichten.push_back(temp);
        }


        if (elementType=="VOERTUIGGENERATOR") {

            TiXmlElement* baanNaamElement = element-> FirstChildElement("baan");
            TiXmlElement* frequentieElement = element-> FirstChildElement("frequentie");
            TiXmlElement* typeElement = element-> FirstChildElement("type");



            if (baanNaamElement == nullptr) {
                throw invalid_argument("VOERTUIGGENERATOR element ontbreekt baannaam");
            }

            if (frequentieElement == nullptr) {
                throw invalid_argument("VOERTUIGGENERATOR element ontbreekt frequentie");
            }

            if (typeElement == nullptr) {
                throw invalid_argument("VOERTUIGGENERATOR element ontbreekt type");
            }

            if (baanNaamElement->GetText() == nullptr) {
                throw invalid_argument("Baannaam van de voertuiggenerator is leeg");
            }

            if (frequentieElement->GetText() == nullptr) {
                throw invalid_argument("Frequentie van de voertuiggenerator is leeg");
            }

            if (typeElement->GetText() == nullptr) {
                throw invalid_argument("Type van de voertuiggenerator is leeg");
            }


            string baanNaam = baanNaamElement->GetText();
            int frequentie = stoi(frequentieElement->GetText());

            if (frequentie < 0) {
                throw invalid_argument("Frequentie van de voertuiggenerator is negatief");
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
                throw invalid_argument("BUSHALTE element ontbreekt baannaam");
            }

            if (positieElement == nullptr) {
                throw invalid_argument("BUSHALTE element ontbreekt positie");
            }

            if (wachttijdElement == nullptr) {
                throw invalid_argument("BUSHALTE element ontbreekt wachttijd");
            }

            if (baanNaamElement->GetText() == nullptr) {
                throw invalid_argument("Baannaam van de bushalte is leeg");
            }

            if (positieElement->GetText() == nullptr) {
                throw invalid_argument("Positie van de bushalte is leeg");
            }

            if (wachttijdElement->GetText() == nullptr) {
                throw invalid_argument("Wachttijd van de bushalte is leeg");
            }


            string baanNaam = baanNaamElement->GetText();
            int positie = stoi(positieElement->GetText());
            int wachttijd = stoi(wachttijdElement->GetText());

            if (wachttijd < 0) {
                throw invalid_argument("Wachttijd van bushalte is negatief");
            }

            Bushalte temp(baanNaam, positie, wachttijd);
            tempBushaltes.push_back(temp);
        }


        if (elementType == "KRUISPUNT") {
            TiXmlElement* baanElement1 = element->FirstChildElement("baan");
            TiXmlElement* baanElement2 = baanElement1->NextSiblingElement("baan");


            if (baanElement1 == nullptr) {
                throw invalid_argument("KRUISPUNT ontbreekt eerste baan");
            }

            if (baanElement2 == nullptr) {
                throw invalid_argument("KRUISPUNT ontbreekt tweede baan");
            }

            if (baanElement2->NextSiblingElement("baan") != nullptr) {
                throw invalid_argument("KRUISPUNT bevat meer dan twee banen");
            }

            if (baanElement1->Attribute("positie") == nullptr) {
                throw invalid_argument("Eerste baan in kruispunt mist positie-attribuut");
            }
            if (baanElement2->Attribute("positie") == nullptr) {
                throw invalid_argument("Tweede baan in kruispunt mist positie-attribuut");
            }

            if (baanElement1->GetText()==nullptr) {
                throw invalid_argument("Naam van eerste baan in kruispunt is leeg");
            }
            if (baanElement2->GetText()==nullptr) {
                throw invalid_argument("Naam van tweede baan in kruispunt is leeg");
            }



            string baanNaam1 = baanElement1->GetText();
            string baanNaam2 = baanElement2->GetText();
            int positie1 = stoi(baanElement1->Attribute("positie"));
            int positie2 = stoi(baanElement2->Attribute("positie"));
            pair<string,int> baan1(baanNaam1, positie1);
            pair<string,int> baan2(baanNaam2,positie2);
            Kruispunt temp(baan1,baan2);
            tempKruispunten.push_back(temp);
        }
    }


    //Parsed Baan
    setParsedBanen(tempBanen);



    //Parsed Voertuig
    for (int i=tempVoertuigen.size()-1; i >= 0 ; i--) {
        Voertuig* temp = &tempVoertuigen[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            throw invalid_argument("Voertuig heeft geen geldige baan");
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
            throw invalid_argument("Positie van voertuig is ongeldig");
                }
        if (typeOngeldig[i]) {
            tempVoertuigen.erase(tempVoertuigen.begin()+i);
        }
        Baan* tempBaan = getRelevanteBaan(temp->getNaamBaan());
        int tempBaanLengte = tempBaan->getLengteBaan();
        temp->setHuidigeBaanLengte(tempBaanLengte);
    }
    setParsedVoertuigen(Voertuig::sortVoertuigen(tempVoertuigen));



    //Parsed Verkeerslicht
    for (int i=tempVerkeerslichten.size()-1; i >= 0 ; i--) {
        Verkeerslicht* temp = &tempVerkeerslichten[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            throw invalid_argument("Verkeerslicht heeft geen geldige baan");
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan()) -> getLengteBaan()) {
            tempVerkeerslichten.erase(tempVerkeerslichten.begin()+i);
            throw invalid_argument("Positie van verkeerslicht is ongeldig");
        }
    }
    setParsedVerkeerslichten(Verkeerslicht::sortVerkeerslichten((tempVerkeerslichten)));



    //Parsed Voertuiggenerator
    for (int i=tempVoertuiggeneratoren.size()-1; i >= 0 ; i--) {
        Voertuiggenerator* temp = &tempVoertuiggeneratoren[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempVoertuiggeneratoren.erase(tempVoertuiggeneratoren.begin()+i);
            throw invalid_argument("Voertuiggenerator heeft geen geldige baan");
        }
        string type = tempVoertuiggeneratoren[i].getType();
        if (type != "auto" && type != "bus" && type != "brandweerwagen" && type != "ziekenwagen" && type != "politiecombi") {
            tempVoertuiggeneratoren.erase(tempVoertuiggeneratoren.begin()+i);
            throw invalid_argument("Type van voertuiggenerator is ongeldig");
        }
    }
    setParsedVoertuiggeneratoren(tempVoertuiggeneratoren);



    //Parsed Bushalte
    for (int i=tempBushaltes.size()-1; i >= 0 ; i--) {
        Bushalte* temp = &tempBushaltes[i];
        if (getRelevanteBaan(temp->getNaamBaan()) == nullptr) {
            tempBushaltes.erase(tempBushaltes.begin()+i);
            throw invalid_argument("Bushalte heeft geen geldige baan");
        }
        if (temp->getPositie() < 0 ||
                temp->getPositie() > getRelevanteBaan(temp->getNaamBaan())->getLengteBaan()) {
            tempBushaltes.erase(tempBushaltes.begin()+i);
            throw invalid_argument("Positie van bushalte is ongeldig");
        }
    }
    setParsedBushaltes(tempBushaltes);


    //Parsed Kruispunt
    setParsedKruispunten(tempKruispunten);

    doc.Clear();
}
