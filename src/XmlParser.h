#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "Baan.h"
#include "Voertuig.h"
#include "Verkeerslicht.h"
#include <vector>
#include <string>
using namespace std;


class XmlParser {
private:
    string bestandsnaam;
    vector<Baan> parsedBanen;
    vector<Voertuig> parsedVoertuigen;
    vector<Verkeerslicht> parsedVerkeerslicht;

public:
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
