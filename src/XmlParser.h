#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include "Voertuiggenerator.h"
#include "Bushalte.h"
#include "Kruispunt.h"
#include <vector>
#include <string>
using namespace std;


class XmlParser {
private:
    string bestandsnaam;
    vector<Baan> parsedBanen;
    vector<Voertuig> parsedVoertuigen;
    vector<Verkeerslicht> parsedVerkeerslichten;
    vector<Voertuiggenerator> parsedVoertuiggenerator;
    vector<Bushalte> parsedBushaltes;
    vector<Kruispunt> parsedKruispunten;

public:
    vector<Bushalte> getParsedBushaltes() const;

    void setParsedBushaltes(const vector<Bushalte> &parsed_bushaltes);

    vector<Kruispunt> getParsedKruispunten() const;

    void setParsedKruispunten(const vector<Kruispunt> &parsed_kruispunten);

    vector<Voertuiggenerator> getParsedVoertuiggeneratoren() const;

    void setParsedVoertuiggeneratoren(const vector<Voertuiggenerator> &parsed_voertuiggenerator);

    XmlParser(string inputnaam);

    void setParsedBanen(vector<Baan>);
    vector<Baan> getParsedBanen();
    void setParsedVoertuigen(vector<Voertuig>);

    vector<Voertuig> &getParsedVoertuigen();
    vector<Verkeerslicht> getParsedVerkeerslichten() const;
    void setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht);
    Baan* getRelevanteBaan(const string& baannaam);
    void parse();
};



#endif //XMLPARSER_H
