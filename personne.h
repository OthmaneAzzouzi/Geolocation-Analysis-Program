#if !defined(__PERSONNE_H__)
#define __PERSONNE_H__

#include <iostream>
#include <string>
#include "coordonnees.h"
#include "tableau.h"

class Personne{
  public:
    //Vous pouvez ajouter autant de fonctions publiques que vous le désirez.
    std::string getNom() const;
    std::string getTypeRelation(const Personne& autre) const;


  private:
    //À compléter : partie privée de la classe personne.

    friend std::istream& operator >>(std::istream&, Personne&);
};

#endif
