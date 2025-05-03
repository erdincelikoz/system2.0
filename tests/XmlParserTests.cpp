#include "gtest/gtest.h"
#include "XmlParser.h"

// Test dat een XML-bestand correct geparsed wordt


TEST(XmlParserTest, ParseValidXmlFile) {
    XmlParser parser("src/input.xml");
    parser.parse();
}

TEST(XmlParserTest, MissingBaanNaamOfLengte) {
    XmlParser parser ("src/input.xml");

    try {
        parser.parse();
        FAIL() << "Expected exception not thrown";
    } catch (const invalid_argument& exception) {
        EXPECT_STREQ("BAAN element ontbreekt naam of lengte", exception.what());
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


TEST(XmlParsertTest, MissingBaanVoertuig) {
    XmlParser parser ("tests/test_missingnaam.xml");
    parser.parse();
    EXPECT_TRUE(parser.getParsedBanen().empty());
}
TEST(XmlParsertTest, MissingVoertuig) {
    XmlParser parser ("tests/test_missingvoertuig");
    parser.parse();

    auto voertuigen = parser.getParsedVoertuigen();
    EXPECT_TRUE(voertuigen.empty());
}



