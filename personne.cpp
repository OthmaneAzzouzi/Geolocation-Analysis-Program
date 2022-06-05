#include <algorithm>
#include "personne.h"


#define nbLieuxMinimum 2
#define nbTempsMinimum 120
#define seuilProximite 25

Personne::Personne() {}

Personne::Personne(std::string _nom, Tableau<Coordonnees> &_listeCoordonnees)
:nom(_nom),listeCoordonnees(&_listeCoordonnees)
{}

std::string Personne::getNom() const{
    return this->nom;
}

std::string Personne::getTypeRelation(const Personne& autre) const{
    //À Compléter
    return "?";
}

std::istream& operator >>(std::istream& is, Personne& p){

    std::string nom;
    Coordonnees coor;
    int index = 0;
    Tableau<Coordonnees> liste;
    bool condition = true;

    is >> nom;
    if(nom.empty() || is.eof()) return is;
    p.nom = nom;

    while(condition){

        char c;
        is >> c;

        if(c=='-' && is.get()=='-') {
            condition = false;
        }else {
            is.unget();
            is >> coor;
            liste.ajouter(coor);
            index++;
        }
    }
    Tableau<Coordonnees> *temp = new Tableau<Coordonnees>(liste);

    p.listeCoordonnees = temp;

    return is;
}


Coordonnees& Personne::operator[] (int index)
{
    return this->listeCoordonnees->operator[](index);
}


const Coordonnees& Personne::operator[] (int index) const
{
    return this->listeCoordonnees->operator[](index);
}

