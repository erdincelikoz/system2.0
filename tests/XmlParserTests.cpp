#include "gtest/gtest.h"
#include "XmlParser.h"

// Test dat een XML-bestand correct geparsed wordt


TEST(XmlParserTest, RootElementCheckerParser) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "No root element found") {
            FAIL();
        }
    }
}
TEST(XmlParserTest, FirstChildCheckerParser) {
    XmlParser parser("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "No root element found") {
            FAIL();
        }
    }
}

TEST(XmlParserTest, MissingBaanNaamOfLengte) {
    XmlParser parser("src/xmlfiles/BaanXmls/MissingBaan.xml");

    EXPECT_THROW({
        parser.parse();
    }, invalid_argument);
}


TEST(XmlParserTest, LeegBaanNaam) {
    XmlParser parser("src/xmlfiles/BaanXmls/LeegBaanNaam.xml");

    EXPECT_THROW({
        parser.parse();
    }, invalid_argument);
}

TEST(XmlParserTest, LeegBaanLengte) {
    XmlParser parser("src/xmlfiles/BaanXmls/LeegBaanLengte.xml");

    EXPECT_THROW({
        parser.parse();
    }, invalid_argument);
}


 //======== VOERTUIG========= //

TEST(XmlParserTest, MissingBaanVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/MissingVoertuigBaanNaam.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt baannaam") {
            SUCCEED();
        }
    }
}

TEST(XmlParserTest, MissingPositieVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/MissingVoertuigPositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt positie") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingTypeVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/MissingVoertuigType.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG element ontbreekt type") {
            SUCCEED();
        }
    }
}


TEST(XmlParserTest, LeegBaanNaamVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/LeegVoertuigBaanNaam.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van het voertuig is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegPositieVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/LeegVoertuigPositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van het voertuig is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegTypeVoertuig) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/LeegVoertuigType.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van het voertuig is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidBaan) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/OngeldigeVoertuigBaan.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Voertuig heeft geen geldige baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidPositie) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/OngeldigeVoertuigPositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van voertuig is ongeldig") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VoertuigInvalidType) {
    XmlParser parser ("src/xmlfiles/VoertuigXmls/OngeldigeVoertuigType.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIG heeft geen geldige type") {
            SUCCEED();
        }
    }
}
//============= VERKEERSLICHT ===========//

TEST(XmlParserTest, MissingBaanVerkeerslicht) {
    XmlParser parser("src/xmlfiles/VerkeerslichtXmls/MissingBaanVerkeerslicht.xml");

    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt baannaam") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingPositieVerkeerslicht) {
    XmlParser parser ("src/xmlfiles/VerkeerslichtXmls/MissingPositieVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt positie") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingCyclusVerkeerslicht) {
    XmlParser parser ("src/xmlfiles/VerkeerslichtXmls/MissingCyclusVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VERKEERSLICHT element ontbreekt cyclus") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamVerkeerslicht) {
    XmlParser parser ("src/xmlfiles/VerkeerslichtXmls/LeegBaanNaamVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van het verkeerslicht is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegPositieVerkeerslicht) {
    XmlParser parser ("src/xmlfiles/VerkeerslichtXmls/LeegPositieVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van het verkeerslicht is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegCyclusVerkeerslicht) {
    XmlParser parser ("src/xmlfiles/VerkeerslichtXmls/LeegCyclusVerkeerslicht.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Cyclus van het voertuig is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, NegatieveCyclusVerkeerslicht) {
    XmlParser parser("src/xmlfiles/VerkeerslichtXmls/NegatieveCyclusVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Cyclus van verkeerslicht is negatief") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VerkeerkeerslichtInvalidBaan) {
    XmlParser parser("src/xmlfiles/VerkeerslichtXmls/OngeldigeBaanVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Verkeerslicht heeft geen geldige baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VerkeerslichtInvalidPositie) {
    XmlParser parser("src/xmlfiles/VerkeerslichtXmls/OngeldigePositieVerkeerslicht.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van verkeerslicht is ongeldig") {
            SUCCEED();
        }
    }
}

// ============VOERTUIGGENERATOR========== //

TEST(XmlParserTest, MissingBaanVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/MissingBaanVoertuigGenerator.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt baannaam") {

        }
    }
}
TEST(XmlParserTest, MissingFrequentieVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/MissingFrequentieVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt frequentie") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingTypeVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/MissingTypeVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "VOERTUIGGENERATOR element ontbreekt type") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/LeegBaanNaamVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van de voertuiggenerator is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegFrequentieVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/LeegFrequentieVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Frequentie van de voertuiggenerator is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegTypeVoertuigGenerator) {
    XmlParser parser ("src/xmlfiles/VoertuigGeneratorXmls/LeegTypeVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van de voertuiggenerator is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, NegatieveFrequentieVoertuigGenerator) {
    XmlParser parser("src/xmlfiles/VoertuigGeneratorXmls/NegatieveFrequentieVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Frequentie van voertuiggenerator is negatief") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VoertuigGeneratorInvalidBaan) {
    XmlParser parser("src/xmlfiles/VoertuigGeneratorXmls/OngeldigeBaanVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Voertuiggenerator heeft geen geldige baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, VoertuigGeneratorInvalidType) {
    XmlParser parser("src/xmlfiles/VoertuigGeneratorXmls/OngeldigeTypeVoertuigGenerator.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Type van voertuiggenerator is ongeldig") {
            SUCCEED();
        }
    }
}

//============ BUSHALTE===========//

TEST(XmlParserTest, MissingBaanBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/MissingBushalteBaan.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt baannaam") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingPositieBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/MissingBushaltePositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt positie") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingWachtTijdBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/MissingBushalteWachttijd.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "BUSHALTE element ontbreekt wachttijd") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegBaanNaamBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/LeegBushalteBaan.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Baannaam van de bushalte is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegPositieBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/LeegBushaltePositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van de bushalte is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, LeegWachttijdBushalte) {
    XmlParser parser ("src/xmlfiles/BushalteXmls/LeegBushalteWachttijd.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Wachttijd van de bushalte is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, NegatieveWachttijdBushalte) {
    XmlParser parser("src/xmlfiles/BushalteXmls/NegatieveBushalteWachttijd.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const std::exception& e) {
        if (std::string(e.what()) == "Wachttijd van bushalte is negatief") {
            SUCCEED();
        }
    }
}

TEST(XmlParserTest, BushalteInvalidBaan) {
    XmlParser parser("src/xmlfiles/BushalteXmls/OngeldigeBushalteBaan.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Bushalte heeft geen geldige baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, BushalteInvalidPositie) {
    XmlParser parser("src/xmlfiles/BushalteXmls/OngeldigeBushaltePositie.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Positie van bushalte is ongeldig") {
            SUCCEED();
        }
    }
}

// ========= KRUISPUNTEN ========== //
TEST(XmlParserTest, MissingEersteBaanKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/MissingEersteBaanKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT ontbreekt eerste baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingTweedeBaanKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/MissingTweedeBaanKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT ontbreekt tweede baan") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MeerdereBanenKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/MeerdereBanenKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "KRUISPUNT bevat meer dan twee banen") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingPositieEersteBaanKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/MissingPositieEersteBaanKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Eerste baan in kruispunt mist positie-attribuut") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, MissingPositieTweedeBaanKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/MissingPositieTweedeBaanKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Tweede baan in kruispunt mist positie-attribuut") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, EersteBaanNaamLeegKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/LeegEersteBaanNaamKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Naam van eerste baan in kruispunt is leeg") {
            SUCCEED();
        }
    }
}
TEST(XmlParserTest, TweedeBaanNaamLeegKruispunt) {
    XmlParser parser("src/xmlfiles/KruispuntenXmls/LeegTweedeBaanNaamKruispunt.xml");
    try {
        parser.parse();
        FAIL();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Naam van tweede baan in kruispunt is leeg") {
            SUCCEED();
        }
    }
}



