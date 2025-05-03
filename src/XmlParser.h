#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include "Voertuiggenerator.h"
#include <vector>
#include <string>
using namespace std;


class XmlParser {
private:
    string bestandsnaam;
    vector<Baan> parsedBanen;
    vector<Voertuig> parsedVoertuigen;
    vector<Verkeerslicht> parsedVerkeerslicht;
    vector<Voertuiggenerator> parsedVoertuiggenerator;

public:
    vector<Voertuiggenerator> getParsedVoertuiggeneratoren() const;

    void setParsedVoertuiggeneratoren(const vector<Voertuiggenerator> &parsed_voertuiggenerator);

    XmlParser(string inputnaam);

    void setParsedBanen(vector<Baan>);
    vector<Baan> getParsedBanen();
    void setParsedVoertuigen(vector<Voertuig>);
    vector<Voertuig> getParsedVoertuigen();
    vector<Verkeerslicht> getParsedVerkeerslichten() const;
    void setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht);
    Baan* getRelevanteBaan(const string& baannaam);
    void parse();
};



#endif //XMLPARSER_H
