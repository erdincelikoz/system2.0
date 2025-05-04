/**
 * @file Voertuig.h
 * @brief Simpele voertuigklasse nodig voor het innemen en verwerken van informatie in verband met de voertuig(en).
 * @author Erdin Celikoz & Raj Shah
 * @date 1 mei 2025
 * @version 2.0
 */
#ifndef VOERTUIG_H
#define VOERTUIG_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/**
 * @brief Simpele voertuigklasse nodig voor het innemen en verwerken van informatie in verband met de voertuig(en).
 */
class Voertuig {
public:
    Voertuig(const string &baan, int positie, const string &type);

private:
    string baan;
    double positie;
    double snelheid;
    double versnelling;
    double gewensteMaxSnelheid;
    string type;
    int lengte;
    double maxVersnelling;
    double maxSnelheid;
    double maxRemFactor;
    double minVolgAfstand;

public:
    string getNaamBaan();
    double getPositie();
    double getSnelheid();
    void setSnelheid(double snelheid);
    double getVersnelling();
    void setVersnelling(double versnelling);
    double getMaxSnelheid();
    double getGewensteMaxSnelheid();
    void setGewensteMaxSnelheid(double gewenste_v_max);
    double getMaxRemFactor();
    double getMinVolgAfstand();
    string getType();
    void setType(string newType);
    void setNaamBaan(string nieuw);
    void setPositie(double nieuw);
    double getMaxVersnelling();
    int getLengte();
    static vector<Voertuig> sortVoertuigen(vector<Voertuig> Voertuigen);

};



#endif // VOERTUIG_H