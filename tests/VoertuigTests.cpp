#include "gtest/gtest.h"
#include "VoertuigRijden.h"
#include "XmlParser.h"
TEST(VoertuigTest, MinimaleVolgAfstand) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Afstand tussen twee auto's is minder dan de minimale volgafstand.") {
            FAIL();
        }
    }
}
TEST(VoertuigTest, OverlappendVertraagAfstand) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Een verkeerslicht mag niet in de vertraagafstand van een ander liggen") {
            FAIL();
        }
    }
}
TEST(VoertuigTest, NegatieveVolgAfstand) {
    XmlParser parser ("src/input.xml");
    try {
        parser.parse();
    } catch (const invalid_argument& exception) {
        if (std::string(exception.what()) == "Afstand tussen twee auto's is minder dan de minimale volgafstand.") {
            FAIL();
        }
    }
}
