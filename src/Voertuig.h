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
using namespace std;

/**
 * @brief Simpele voertuigklasse nodig voor het innemen en verwerken van informatie in verband met de voertuig(en).
 */
class Voertuig {
public:
    Voertuig(const string &baan, int positie, const string &type);

private:
    string baan;
    int positie;
    double snelheid;
    double versnelling;
    double gewensteMaxSnelheid;
    string type;
    const int lengte;
    const double maxVersnelling;
    const double maxSnelheid;
    const double maxRemFactor;
    const double minVolgAfstand;

public:
    string getNaamBaan();
    int getPositie();
    double getSnelheid() const;
    void setSnelheid(double snelheid);
    double getVersnelling() const;
    void setVersnelling(double versnelling);
    double getMaxSnelheid() const;
    double getGewensteMaxSnelheid() const;
    void setGewensteMaxSnelheid(double gewenste_v_max);
    double getMaxRemFactor() const;
    double getMinVolgAfstand() const;
    string getType();
    void setType(string newType);
    void setNaamBaan(string nieuw);
    void setPositie(int nieuw);
    double getMaxVersnelling() const;
    int getLengte() const;


};



#endif // VOERTUIG_H