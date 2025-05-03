#ifndef XMLPARSER_H
#define XMLPARSER_H
#include "Baan.h"
#include "Voertuig.h"
#include <vector>
#include <string>
using namespace std;


class XmlParser {
private:
    string bestandsnaam;
    vector<Baan> parsedBanen;
    vector<Voertuig> parsedVoertuigen;
public:
    XmlParser(string inputnaam);

    void setParsedBanen(vector<Baan>);
    vector<Baan> getParsedBanen();
    void setParsedVoertuigen(vector<Voertuig>);
    vector<Voertuig> getParsedVoertuigen();
    Baan* getRelevanteBaan(const string& baannaam);
    void parse();
};



#endif //XMLPARSER_H
