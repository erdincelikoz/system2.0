# --- Compiler settings ---
CXX = g++
CXXFLAGS = -O2 -g -Wall -Werror -std=c++11 -fmessage-length=0
INCL = -Isrc -Igtest/include
TLIBPATH = -Lgtest/lib
TLIBS = -lgtest -lgtest_main -lpthread

# --- Source files ---
SRC_DIR = src
TEST_DIR = tests

# Main program sources
MAIN_SRCS = $(SRC_DIR)/main.cpp \
            $(SRC_DIR)/Baan.cpp \
            $(SRC_DIR)/XmlParser.cpp \
            $(SRC_DIR)/Voertuig.cpp \
            $(SRC_DIR)/Verkeerslicht.cpp \
            $(SRC_DIR)/Voertuiggenerator.cpp \
            $(SRC_DIR)/tinyxml.cpp \
            $(SRC_DIR)/tinystr.cpp \
            $(SRC_DIR)/tinyxmlparser.cpp \
            $(SRC_DIR)/tinyxmlerror.cpp \
            $(SRC_DIR)/Bushalte.cpp \
            $(SRC_DIR)/Kruispunt.cpp \
            $(SRC_DIR)/VoertuigRijden.cpp \
            $(SRC_DIR)/Simulatie.cpp

# Test program sources
TEST_SRCS = $(TEST_DIR)/VoertuigTests.cpp \
            $(TEST_DIR)/XmlParserTests.cpp \
            $(MAIN_SRCS)

# --- Object files ---
MAIN_OBJS = $(MAIN_SRCS:.cpp=.o)
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

# --- Targets ---
TARGETS = system2_0 verkeers_tests

# --- Primary target ---
.PHONY: all
all: $(TARGETS)

# --- Main executable ---
system2_0: $(MAIN_OBJS)
	$(CXX) $(CXXFLAGS) $(INCL) -o $@ $(MAIN_OBJS)

# --- Test executable ---
verkeers_tests: $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) $(INCL) $(TLIBPATH) -o $@ $(TEST_OBJS) $(TLIBS)

# --- Compilation rule ---
%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INCL) -c -o $@ $<

# --- Clean targets ---
.PHONY: clean
clean:
	rm -f $(TARGETS) $(SRC_DIR)/*.o $(TEST_DIR)/*.o

.PHONY: cleantests
cleantests:
	rm -f verkeers_tests $(TEST_OBJS)

# --- Dependencies ---
.PHONY: depend
depend:
	$(CXX) -MM $(INCL) $(MAIN_SRCS) $(TEST_SRCS) > Makefile.dep

-include Makefile.dep