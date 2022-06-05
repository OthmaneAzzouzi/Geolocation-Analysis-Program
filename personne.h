#if !defined(__PERSONNE_H__)
#define __PERSONNE_H__

#include <iostream>
#include <string>
#include "coordonnees.cpp"
#include "tableau.h"

class Personne{
  public:
    //Vous pouvez ajouter autant de fonctions publiques que vous le désirez.

    Personne();
    Personne(std::string _nom, Tableau<Coordonnees> &_listeCoordonnees);
    std::string getNom() const;
    std::string getTypeRelation(const Personne& autre) const;
    int getTypeRelationTest(const Personne& autre) const;


    Coordonnees&	           operator[] (int index);
    const Coordonnees&         operator[] (int index) const;



private:
    //À compléter : partie privée de la classe personne.
    std::string nom;
    Tableau<Coordonnees> *listeCoordonnees;

    friend std::istream& operator >>(std::istream&, Personne&);
    friend class Coordonnees;

};

#endif
