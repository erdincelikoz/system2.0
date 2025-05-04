#include "gtest/gtest.h"
#include "XmlParser.h"

// Test dat een XML-bestand correct geparsed wordt


//----------------------------------------------TEMPLATE--------------------------------------------------
TEST(XmlParserTest, MissingBaanNaamOfLengte) {                                                          //
    XmlParser parser ("src/input.xml");                                                     //
                                                                                                        //
    try {                                                                                               //
        parser.parse();                                                                                 //
                                                                                                        //
    } catch (const invalid_argument& exception) {                                                       //
        if (std::string(exception.what()) == "BAAN element ontbreekt naam of lengte") {               //
            FAIL();                                                                                     //
        }                                                                                               //
    }                                                                                                   //
}                                                                                                       //
//--------------------------------------------------------------------------------------------------------


TEST(XmlParserTest, LeegBaanNaam) {
    XmlParser parser("src/input.xml");

    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baan naam is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegBaanLengte) {
    XmlParser parser("src/input.xml");

    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) ==  "Baan lengte is leeg") {
            FAIL();
        }
    }
}

TEST(XmlParserTest, NegatieveBaanLengte) {
    XmlParser parser("src/input.xml");

    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baan lengte is negatief") {
            FAIL();
        }
    }
}

 //======== VOERTUIG========= //

TEST(XmlParserTest, MissingBaanVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt baannaam") {
            FAIL();
        }
    }
}

TEST(XmlParserTest, MissingPositieVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt positie") {
            FAIL();
        }
    }
}

TEST(XmlParserTest, MissingTypeVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt type") {
            FAIL();
        }
    }
}

// probeer nog test te schrijven om te testen of er voertuigen op de baan zijn

TEST(XmlParserTest, LeegBaanNaamVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van het voertuig is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegPositieVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van het voertuig is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegTypeVoertuig) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van het voertuig is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidBaan) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) =="Voertuig heeft geen geldige baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidPositie) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van voertuig is ongeldig") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidParameters) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Voertuig heeft ongeldige type") {
            FAIL();
        }
    }
}
//============= VERKEERSLICHT ===========//

TEST(XmlParserTest, MissingBaanVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt baannaam") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingPositieVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt positie") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingCyclusVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt cyclus") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van het verkeerslicht is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegPositieVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van het verkeerslicht is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegCyclusVerkeerslicht) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Cyclus van het voertuig is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, NegatieveCyclusVerkeerslicht) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Cyclus van verkeerslicht is negatief") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VerkeerkeerslichtInvalidBaan) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Verkeerslicht heeft geen geldige baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VerkeerslichtInvalidPositie) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van verkeerslicht is ongeldig") {
            FAIL();
        }
    }
}

// ============VOERTUIGGENERATOR========== //

TEST(XmlParserTest, MissingBaanVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt baannaam") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingFrequentieVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt frequentie") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingTypeVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt type") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van de voertuiggenerator is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegFrequentieVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Frequentie van de voertuiggenerator is leeg") {
        FAIL();
        }
    }
}
TEST(XmlParserTest, LeegTypeVoertuigGenerator) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van de voertuiggenerator is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, NegatieveFrequentieVoertuigGenerator) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Frequentie van voertuiggenerator is negatief") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VoertuigGeneratorInvalidBaan) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Voertuiggenerator heeft geen geldige baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, VoertuigGeneratorInvalidType) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van voertuiggenerator is ongeldig") {
            FAIL();
        }
    }
}

//============ BUSHALTE===========//

TEST(XmlParserTest, MissingBaanBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt baannaam") {
        FAIL();
        }
    }
}
TEST(XmlParserTest, MissingPositieBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt positie") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingWachtTijdBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt wachttijd") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van de bushalte is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegPositieBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van de bushalte is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegWachttijdBushalte) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Wachttijd van de bushalte is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, NegatieveWachttijdBushalte) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Wachttijd van de bushalte is negatief") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, BushalteInvalidBaan) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Bushalte heeft geen geldige baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, BushalteInvalidPositie) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van bushalte is ongeldig") {
            FAIL();
        }
    }
}

// ====== KRUISPUNTEN ===== //
TEST(XmlParserTest, MissingEersteBaanKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT ontbreekt eerste baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingTweedeBaanKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT ontbreekt tweede baan") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MeerdereBanenKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT bevat meer dan twee banen") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingPositieEersteBaanKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Eerste baan in kruispunt mist positie-attribuut") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, MissingPositieTweedeBaanKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Tweede baan in kruispunt mist positie-attribuut") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Tweede baan in kruispunt mist positie-attribuut") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, EersteBaanNaamLeegKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Naam van eerste baan in kruispunt is leeg") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, TweedeBaanNaamLeegKruispunt) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Naam van tweede baan in kruispunt is leeg") {
            FAIL();
        }
    }
}



