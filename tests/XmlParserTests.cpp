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
    EXPECT_EQ(banen[0].getNaamBaan(), "baanA");

    ASSERT_EQ(voertuigen.size(), 1u);
    EXPECT_EQ(voertuigen[0].getType(), "auto");
    EXPECT_EQ(voertuigen[0].getPositie(), 10);

    ASSERT_EQ(verkeerslichten.size(), 1u);
    EXPECT_EQ(verkeerslichten[0].getPositie(), 15);
}