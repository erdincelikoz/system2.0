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

/**
 * Klasse voor het parsen van XML-bestanden die verkeerssimulatie-elementen bevatten.
 */
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
    /**
    * Geeft de geparste bushaltes terug.
    * @return Vector met bushaltes uit het XML-bestand
    */
    vector<Bushalte> getParsedBushaltes() const;

    /**
     * Stelt de vector met geparste bushaltes in.
     * @param parsed_bushaltes De vector met bushaltes om in te stellen
     */
    void setParsedBushaltes(const vector<Bushalte> &parsed_bushaltes);

    /**
     * Geeft de geparste kruispunten terug.
     * @return Vector met kruispunten uit het XML-bestand
     */
    vector<Kruispunt> getParsedKruispunten() const;

    /**
     * Stelt de vector met geparste kruispunten in.
     * @param parsed_kruispunten De vector met kruispunten om in te stellen
     */
    void setParsedKruispunten(const vector<Kruispunt> &parsed_kruispunten);

    /**
     * Geeft de geparste voertuiggeneratoren terug.
     * @return Vector met voertuiggeneratoren uit het XML-bestand
     */
    vector<Voertuiggenerator> getParsedVoertuiggeneratoren() const;

    /**
     * Stelt de vector met geparste voertuiggeneratoren in.
     * @param parsed_voertuiggenerator De vector met voertuiggeneratoren om in te stellen
     */
    void setParsedVoertuiggeneratoren(const vector<Voertuiggenerator> &parsed_voertuiggenerator);

    /**
     * Constructor voor de XmlParser.
     * @param inputnaam De bestandsnaam van het XML-bestand dat moet worden geparsed
     */
    XmlParser(string inputnaam);

    /**
     * Stelt de vector met geparste banen in.
     * @param tempBanen De vector met banen om in te stellen
     */
    void setParsedBanen(vector<Baan>);

    /**
     * Geeft de geparste banen terug.
     * @return Vector met banen uit het XML-bestand
     */
    vector<Baan> getParsedBanen();

    /**
     * Stelt de vector met geparste voertuigen in.
     * @param tempVoertuigen De vector met voertuigen om in te stellen
     */
    void setParsedVoertuigen(vector<Voertuig>);

    /**
     * Geeft de geparste voertuigen terug.
     * @return Referentie naar vector met voertuigen uit het XML-bestand
     */
    vector<Voertuig> &getParsedVoertuigen();

    /**
     * Geeft de geparste verkeerslichten terug.
     * @return Referentie naar vector met verkeerslichten uit het XML-bestand
     */
    vector<Verkeerslicht> &getParsedVerkeerslichten();

    /**
     * Stelt de vector met geparste verkeerslichten in.
     * @param parsed_verkeerslicht De vector met verkeerslichten om in te stellen
     */
    void setParsedVerkeerslichten(const vector<Verkeerslicht> &parsed_verkeerslicht);
    /**
    * Zoekt een baan op basis van de naam
    * @param baannaam De naam van de baan die moet worden gezoch
    * @return Pointer naar de baan als deze bestaat (anders nullptr)
    */
    Baan* getRelevanteBaan(const string& baannaam);

    /**
    * Parst het XML-bestand en laadt de elementen in de juiste vectoren.
    * @throw invalid_argument Als het bestand niet kan worden geladen of als er ongeldige elementen zijn
    */
    void parse();
};

#endif //XMLPARSER_H
