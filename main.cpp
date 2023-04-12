#include <cstdlib>
#include <iostream>
#include <fstream>
#include "tableau.h"
#include "personne.h"

using namespace std;

int solution(std::istream& in){
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
            std::string typeRelation = personnes[i].getTypeRelation(personnes[j]);
            if(typeRelation != "") {
                std::cout << personnes[i].getNom() + " et " +  personnes[j].getNom() + " sont des " + typeRelation + "." << std::endl;
            }
        }

    }
    // vider la memoire
    for(int j = 0; j < personnes.taille(); ++j){
        delete personnes[j].listeCoordonnees;
    }

    return 0; // fin normale
}

int main(int argc, const char** argv)
{
    if(argc<2)
        return solution(std::cin);
    else{
        std::ifstream fichierPresences(argv[1]);
        return solution(fichierPresences);
    }
}
