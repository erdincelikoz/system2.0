#ifndef BUSHALTE_H
#define BUSHALTE_H

#include <string>
using namespace std;

class Bushalte {
private:
    string baanNaam;

public:
    Bushalte(const string &baan_naam, int positie, int wachttijd);

private:
    int positie;
    int wachttijd;

public:
    string getNaamBaan() const;

    void setNaamBaan(const string &baan_naam);

    int getPositie() const;

    void setPositie(int positie);

    int getWachttijd() const;

    void setWachttijd(int wachttijd);


};



#endif //BUSHALTE_H
