
#ifndef VOERTUIGRIJDEN_H
#define VOERTUIGRIJDEN_H
#include "Voertuig.h"
#include <vector>

using namespace std;

/**
 * @brief Klasse voor het behandelen van rijden van voertuigen in de simulatie
 */
class VoertuigRijden {
public:
    void updateVoertuigen(vector<Voertuig>& voertuigen);

    void vertragen(vector<Voertuig>& voertuigen, double s);

    void versnellen(vector<Voertuig>& voertuigen);

    void stoppen(vector<Voertuig>& voertuigen);
};



#endif //VOERTUIGRIJDEN_H
