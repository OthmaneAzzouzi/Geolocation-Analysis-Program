#include <cstdlib>
#include <iostream>
#include <istream>
#include <fstream>
#include "tableau.h"
#include "personne.cpp"


using namespace std;

int tp2(istream& in){
    Tableau<Personne> personnes;

    while(in){ 
        Personne nouvellePersonne;
        in >> nouvellePersonne;
        if(in.eof()) break;
        personnes.ajouter(nouvellePersonne);
    }

    //  À Compléter : 2 boucles imbriquées pour déterminer et afficher le type de relation entre chaque personne.
    for(int i = 0; i < personnes.taille(); i++) {

        for(int j = i + 1; j < personnes.taille(); j++){

            string typeRelation = personnes[i].getTypeRelation(personnes[j]);
            if(typeRelation != "")
                std::cout << personnes[i].getNom() + " et " +  personnes[j].getNom() + " sont des " + typeRelation + "." << std::endl;
        }

    }



    return 0; // fin normale
}

/**
int tp2(istream& in){
    Tableau<Personne> personnes;

    while(in){
        Personne nouvellePersonne;
        in >> nouvellePersonne;
        if(in.eof()) break;
        personnes.ajouter(nouvellePersonne);
    }

    std::cout << personnes[0][0].longitude << std::endl;
    std::cout << personnes[1][3].latitude << std::endl;
    std::cout << personnes[2][2].longitude << std::endl;


    return 0; // fin normale
}
**/

int main(int argc, const char** argv)
{

    if(argc<2)
        return tp2(cin);
    else{
        ifstream fichierPresences(argv[1]);
        return tp2(fichierPresences);
    }
}
