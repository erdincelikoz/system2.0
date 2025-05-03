#include "Kruispunt.h"

vector<pair<string, int>> *Kruispunt::getBanenEnPosities(){
    return &banenEnPosities;
}

void Kruispunt::setBanenEnPosities(const vector<pair<string, int>> &banen_en_posities) {
    banenEnPosities = banen_en_posities;
}

Kruispunt::Kruispunt(pair<string, int> a, pair<string, int> b) {
    getBanenEnPosities()->push_back(a);
    getBanenEnPosities()->push_back(b);
}

