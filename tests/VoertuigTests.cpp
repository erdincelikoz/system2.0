#include "gtest/gtest.h"
#include "Voertuig.h"

// Test dat het voertuig correct geïnitialiseerd wordt
TEST(VoertuigTest, ConstructorInitializesCorrectValues) {
    Voertuig v("baan1", 10, "auto");

    EXPECT_EQ(v.getNaamBaan(), "baan1");
    EXPECT_EQ(v.getPositie(), 10);
    EXPECT_EQ(v.getType(), "auto");
    EXPECT_EQ(v.getLengte(), 4);
    EXPECT_DOUBLE_EQ(v.getMaxSnelheid(), 16.6);
}

// Test dat setters en getters werken
TEST(VoertuigTest, SettersAndGetters) {
    Voertuig v("baan2", 5, "ziekenwagen");

    v.setSnelheid(10.5);
    v.setVersnelling(0.8);
    v.setGewensteMaxSnelheid(14.0);
    v.setPositie(8);
    v.setNaamBaan("baan3");

    EXPECT_DOUBLE_EQ(v.getSnelheid(), 10.5);
    EXPECT_DOUBLE_EQ(v.getVersnelling(), 0.8);
    EXPECT_DOUBLE_EQ(v.getGewensteMaxSnelheid(), 14.0);
    EXPECT_EQ(v.getPositie(), 8);
    EXPECT_EQ(v.getNaamBaan(), "baan3");
}