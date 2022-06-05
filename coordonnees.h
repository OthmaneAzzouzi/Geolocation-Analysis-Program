#if !defined(_COORDONNEES__H_)
#define _COORDONNEES__H_
#include <iostream>
#include <istream>



class Coordonnees {
  public:
    Coordonnees(){}
    Coordonnees(double latitude_, double longitude_,
                double tempsArrivee_);
    Coordonnees(const Coordonnees&);
    double distance(const Coordonnees&) const;

private:
    double latitude;
    double longitude;
    double tempsArrivee;

  friend std::ostream& operator << (std::ostream&, const Coordonnees&);
  friend std::istream& operator >> (std::istream&, Coordonnees&);
  friend int tp2(std::istream& in);
  friend class Personne;
};

#endif

