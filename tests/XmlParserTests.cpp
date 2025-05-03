#include "gtest/gtest.h"
#include "XmlParser.h"

// Test dat een XML-bestand correct geparsed wordt


TEST(XmlParserTest, ParseValidXmlFile) {
    XmlParser parser("tests/test_valid.xml");
    parser.parse();

    auto banen = parser.getParsedBanen();
    auto voertuigen = parser.getParsedVoertuigen();
    auto verkeerslichten = parser.getParsedVerkeerslichten();

    ASSERT_EQ(banen.size(), 1u);
    EXPECT_EQ(banen[0].getNaamBaan(), "A1");
    EXPECT_EQ(banen[0].getLengteBaan(), 0);

    ASSERT_EQ(voertuigen.size(), 1u);
    EXPECT_EQ(voertuigen[0].getType(), "auto");
    EXPECT_EQ(voertuigen[0].getPositie(), 10);

    ASSERT_EQ(verkeerslichten.size(), 1u);
    EXPECT_EQ(verkeerslichten[0].getPositie(), 15);
}

TEST(XmlParserTest, MissingBaanNaam) {
    XmlParser parser ("tests/test_missingnaam.xml");
    parser.parse();

    auto banen = parser.getParsedBanen();
    EXPECT_TRUE(banen.empty());
}
TEST(XmlParserTest, MissingBaanLengte) {
    XmlParser parser ("tests/test_misisnglengte.xml");
    parser.parse();

    auto banen = parser.getParsedBanen();
    EXPECT_TRUE(banen.empty());
}

TEST(XmlParserTest, LeegOfNegatieveBaanLengte) {
    XmlParser parser("tests/test_leegofnegatievebaan.xml");
    parser. parse();
    EXPECT_THROW(parser.parse(), invalid_argument);
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



