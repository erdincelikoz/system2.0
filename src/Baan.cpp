#include "Baan.h"
#include <string>
#include <vector>

double Baan::getLengteBaan() {
    return lengte;
}
void Baan::setLengteBaan(double nieuw) {
    lengte = nieuw;
}
string Baan::getNaamBaan() {
    return naam;
}
void Baan::setNaamBaan(string nieuw) {
    naam = nieuw;
}
Baan::Baan(string naam, double lengte) {
    setNaamBaan(naam);
    setLengteBaan(lengte);
}
