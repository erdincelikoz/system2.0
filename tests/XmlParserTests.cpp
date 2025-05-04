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
        FAIL() << "Expected exception not thrown";
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
        FAIL() << "Expected exception not thrown";
    } catch (const invalid_argument& exception) {
        EXPECT_STREQ("Baan lengte is leeg", exception.what());
    }
}

TEST(XmlParserTest, NegatieveBaanLengte) {
    XmlParser parser("src/input.xml");

    try {
        parser.parse();
        FAIL() << "Expected exception not thrown";
    } catch (const invalid_argument& exception) {
        EXPECT_STREQ("Baan lengte is negatief", exception.what());
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

    auto voertuigen = parser.getParsedVoertuigen();
    EXPECT_TRUE(voertuigen.empty());
}



