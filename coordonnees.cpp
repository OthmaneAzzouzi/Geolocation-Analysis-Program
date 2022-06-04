#include <math.h>
#include <assert.h>
#include "coordonnees.h"
#define RAYONTERRE 6371000  // en mètres
#define PI 3.14159265359

Coordonnees::Coordonnees(const Coordonnees& coor)
  : latitude(coor.latitude), longitude(coor.longitude)
{
}

Coordonnees::Coordonnees(double latitude_, double longitude_) 
  : latitude(latitude_), longitude(longitude_)
{
}

double Coordonnees::distance(const Coordonnees& coor) const {
    double s1 = sin((coor.latitude-latitude)/2);
    double s2 = sin((coor.longitude-longitude)/2);
    return 2*RAYONTERRE * asin(sqrt(s1*s1 + cos(latitude)*cos(coor.latitude)*s2*s2));
}

std::istream& operator >> (std::istream& is, Coordonnees& coor) {
    char po, vir, pf;
    is >> po;
    if(is){
        is >> coor.latitude >> vir >> coor.longitude >> pf;
        assert(po=='(');
        assert(vir==',');
        assert(pf==')');
        coor.longitude *= PI / 180.0;
        coor.latitude  *= PI / 180.0;
    }
    return is;
}

std::ostream& operator << (std::ostream& os, const Coordonnees& coor) {
    os << "(" 
       << (coor.latitude * 180.0 / PI)
       << "," 
       << (coor.longitude * 180.0 / PI)
       << ")";
    return os;
}


