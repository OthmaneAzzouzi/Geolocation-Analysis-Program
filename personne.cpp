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
    bool auMemeEndroit = false;
    int dureeRecontre = 0;
    int nombreDeLieux = 0;
    int t1 = 0;
    int t1Apres = 1440;
    int t2 = 0;
    int t2Apres = 1440;
    int duree2 = 0;
    int duree1 = 0;


    for( int i = 0; i < listeCoordonnees->taille(); ++i ) {
        Coordonnees x = listeCoordonnees->operator[](i);
        t1 = x.tempsArrivee;
        if (i + 1 < listeCoordonnees->taille()) {
            t1Apres = listeCoordonnees->operator[](i + 1).tempsArrivee;
        }
        for (int j = 0; j < autre.listeCoordonnees->taille(); ++j) {
            Coordonnees y = autre.listeCoordonnees->operator[](j);

            if (x.distance(y) <= 25) {
                auMemeEndroit = true;
                nombreDeLieux += 1;
                t2 = y.tempsArrivee;
                if (j + 1 < autre.listeCoordonnees->taille()) {
                    t2Apres = listeCoordonnees->operator[](j + 1).tempsArrivee;
                }
                if (t1Apres < t2Apres) {
                    duree2 = t1Apres;
                } else {
                    duree2 = t2Apres;
                }

                if (t2 > t1) {
                    duree1 = t2;
                } else {
                    duree1 = t1;
                }

                dureeRecontre = duree2 - duree1;
                if (dureeRecontre < 120) {
                    return "";
                }
                if (nombreDeLieux == 0) {
                    return "";
                }
                if (nombreDeLieux == 1) {
                    return "connaissances";
                }
                if (dureeRecontre > 1) {
                    return "amis";
                }
                return "";

            }
        }
    }


            //t2 = y.tempsArrivee;
            //if (auMemeEndroit) {
            //    dureeRecontre = dureeRecontre + (t2 - t1);
            //}
            //Etape 1: verifier si meme position (1 ou plusieurs)
            //Etape 2: Verifier si t >= 120 min durant la journee



    return "";
}

int Personne::getTypeRelationTest(const Personne& autre) const{
    bool auMemeEndroit = false;
    int dureeRecontre = 0;
    int nombreDeLieux = 0;
    int t1 = 0;
    int t1Apres = 1440;
    int t2 = 0;
    int t2Apres = 1440;
    int duree2 = 0;
    int duree1 = 0;


    for( int i = 0; i < listeCoordonnees->taille(); ++i ) {
        Coordonnees x = listeCoordonnees->operator[](i);
        t1 = x.tempsArrivee;
        if (i + 1 < listeCoordonnees->taille()) {
            t1Apres = listeCoordonnees->operator[](i + 1).tempsArrivee;
        }
        for (int j = 0; j < autre.listeCoordonnees->taille(); ++j) {
            Coordonnees y = autre.listeCoordonnees->operator[](j);

            if (x.distance(y) <= 25) {
                auMemeEndroit = true;
                nombreDeLieux += 1;
                t2 = y.tempsArrivee;
                if (j + 1 < autre.listeCoordonnees->taille()) {
                    t2Apres = listeCoordonnees->operator[](j + 1).tempsArrivee;
                }
                if (t1Apres < t2Apres) {
                    duree2 = t1Apres;
                } else {
                    duree2 = t2Apres;
                }

                if (t2 > t1) {
                    duree1 = t2;
                } else {
                    duree1 = t1;
                }

                dureeRecontre = duree2 - duree1;
                std::cout << " x: " <<  duree1 << " " << " y: " <<  duree2 << " dureeRecontre : " << dureeRecontre << std::endl;

            }
        }
    }

    return dureeRecontre;
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

