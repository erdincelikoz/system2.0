#ifndef KRUISPUNT_H
#define KRUISPUNT_H
#include <string>
#include <vector>
using namespace std;


class Kruispunt {
private:
    vector<pair<string,int>> banenEnPosities;

public:
    vector<pair<string, int>> *getBanenEnPosities();

    void setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities);
    Kruispunt(pair<string, int> a, pair<string, int> b);


};



#endif //KRUISPUNT_H
