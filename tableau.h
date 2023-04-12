// Ces deux lignes permettent d'éviter d'inclure 2 fois ce .h à la compilation.
#if !defined(__TABLEAU_H__)
#define __TABLEAU_H__
#include <assert.h>
template <class T>
class Tableau{


public:

// Constructeurs
    Tableau(int capacite_initiale=8);
    Tableau(const Tableau<T>&);

// Destructeur
    ~Tableau();

// Fonctions de modifications
    void           ajouter(const T& element);
    void           vider();
    void           inserer(const T& element, int _index=0);
    void           enlever(int _index=0);
    void           enlever_dernier();
    void           quickSort(T arr[], int start, int end);
    int            partition(T arr[], int start, int end);
    void           sort();
    ;
// Opérateurs d'accès []
    T&             operator[] (int index);
    const T&       operator[] (int index) const;
//



// Fonctions utilitaires
    bool           vide() const {return nbElements==0;}
    int            taille() const {return nbElements;}
    int            chercher(const T& element) const; // retourne indice première occurrence
    bool           contient(const T& element) const;

// Opérateurs
    Tableau<T>&    operator = (const Tableau<T>& autre);
    bool           operator == (const Tableau<T>& autre) const;

// Fonctionnalités spécifiques 
    int  compter(const T& element) const; // retourne le nb d'occurrences de element

private:
    int            capacite;
    int            nbElements;
    T*             elements;


};


// ---------- Définitions -------------

/**
 * Constructeur de la classe
 * @tparam T Type générique
 * @param capacite_ taille du tableau
 */
template <class T>
Tableau<T>::Tableau(int capacite_)
{
    capacite = capacite_;
    nbElements = 0;
    elements = new T[capacite];
}

/**
 * Constructeur par copie.
 * @tparam T Type générique.
 * @param autre tableau qui va être copié.
 */
template <class T>
Tableau<T>::Tableau(const Tableau& autre)
{
    capacite = autre.nbElements;
    nbElements = autre.nbElements;
    elements = new T[capacite];
    for(int i=0;i<nbElements;i++)
        elements[i] = autre.elements[i];

}

/**
 * Destructeur de la classe.
 * @tparam T Type générique
 */
template <class T>
Tableau<T>::~Tableau()
{
    delete[] elements;
    elements = NULL; // cela est optionnel
}


template <class T>
void Tableau<T>::sort() {
    heapSort(elements ,nbElements);
}





/**
 * Fonction qui ajoute des éléments au tableau
 * elements.
 * @tparam T Type générique
 * @param item élément à ajouter.
 */
template <class T>
void Tableau<T>::ajouter(const T& item)
{
    if(nbElements >= capacite){
        capacite = capacite + 1;
        T* temp = new T[capacite];
        for(int i=0;i<nbElements;i++)
            temp[i] = elements[i];
        delete [] elements;
        elements = temp;
    }
    elements[nbElements++] = item;
}


/**
 * Fonction qui insère des éléments dans le tableau.
 * @tparam T Type générique
 * @param element élément à ajouter.
 * @param _index table des indices.
 */
template <class T>
void Tableau<T>::inserer(const T& element, int _index)
{
    assert(_index<=nbElements);
    if(nbElements >= capacite){
        capacite *= 2;
        T* temp = new T[capacite];
        for(int i=0;i<_index;i++)
            temp[i] = elements[i];
        temp[_index] = element;
        for(int i=_index;i<nbElements;i++)
            temp[i+1] = elements[i];
        delete [] elements;
        nbElements++;
        elements = temp;
    }else{
        for(int i=nbElements;i>_index;i--)
            elements[i] = elements[i-1];
        elements[_index] = element;
        nbElements++;
    }
}

/**
 * Fonction qui supprime les éléments du tableau
 * @tparam T Type générique
 * @param _index table des indices.
 */
template <class T>
void Tableau<T>::enlever(int _index)
{
    assert(nbElements>0);
    nbElements--;
    for(int i=_index;i<nbElements;i++)
        elements[i] = elements[i+1];
}

/**
 * Fonction qui supprime le dernier élément du tableau
 * @tparam T Type générique
 */
template <class T>
void Tableau<T>::enlever_dernier()
{
    enlever(nbElements - 1);
}

/**
 * Rechercher un éléments du tableau elements.
 * si une table d'index triée existe une recherche binaire sera utilisée.
 *
 * l'algorithme de recharche binaire a été inspiré de l'algorithme
 * disponible sur le site GeeksforGeeks.com
 * @tparam T Type générique
 * @param element élément à rechercher
 * @return indice de l'élément recherché
 */
template <class T>
int Tableau<T>::chercher(const T& element) const
{

    for(int i=0;i<nbElements;i++)
        if(elements[i]==element)
            return i;
    return -1;

}

/**
 * vérifier si le tableau elements contient un élément
 * @tparam T Type générique
 * @param element élément à rechercher
 * @return si trouvé renvoie vrai sinon renvoie faux.
 */
template <class T>
bool Tableau<T>::contient(const T& element) const{
    return chercher(element)!=-1;
}

/**
 * Réinitialiser le tableau en mettant 0 dans nbElements.
 * @tparam T Type générique
 */
template <class T>
void Tableau<T>::vider()
{
    nbElements = 0;
}

/**
 * Compter le nombre d'éléments dans le tableau.
 * @tparam T Type générique
 * @param element élément recherché et compté
 * @return nombre d'occurrences
 */
template <class T>
int  Tableau<T>::compter(const T& element) const {


    int sortie = 0;
    for (int i = 0; i < this->taille() - 1; ++i) {
        if (elements[i] == element) {
            ++sortie;
        }
    }
    return sortie;

}

/**
 * Pour entasser un sous-arbre dont la racine est un nœud qui
 * est un indice dans arr[]. n est la taille du tas.
 *
 * le tableau index[] contenant tous les index du arr[] sera
 * réajusté par le tri.
 *
 * l'algorithme a été inspiré de l'algorithme heapify disponible
 * sur le site GeeksforGeeks.com
 *
 * @tparam T Type générique
 * @param index tableau d'indice du tableau arr[]
 * @param arr tableau à trier
 * @param n dernier indice du tableau arr[] & avant dernier
 * indice du tableau index[]
 * @param i indice dans le tableau index[]
 */
template <class T>
void heapify(T arr[], int n, int i)
{
    int largest = i; // Initialiser la variable largest en tant que racine
    int l = 2 * i + 1; // gauche = 2*i + 1
    int r = 2 * i + 2; // droite = 2*i + 2

    // Si l'enfant gauche est plus grand que la racine
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // Si l'enfant droit est plus grand que la variable largest
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // Si largest n'est pas la racine
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        // Heapifier récursivement le sous-arbre affecté
        heapify(arr, n, largest);
    }
}

/**
 * Fonction principale pour faire un tri de tas (heap sort).
 *
 * le tableau index[] contenant tous les indice du arr[] sera
 * réajusté par le tri.
 *
 * l'algorithme a été inspiré de l'algorithme heapSort disponible
 * sur le site GeeksforGeeks.com
 *
 * @tparam T Type générique
 * @param index tableau d'indice du tableau arr[]
 * @param arr tableau à trier
 * @param n dernier indice du tableau arr[] & avant dernier
   indice du tableau index[]
 */
template <class T>
void heapSort(T arr[], int n)
{
    // Construire le heap (réorganiser le tableau)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extraire les éléments un par un du tas
    for (int i = n - 1; i >= 0; i--) {
        //Déplacer la racine actuelle vers la fin
        std::swap(arr[0], arr[i]);


        //appeler max heapify sur le tas réduit
        heapify(arr, i, 0);
    }
}


/**
 * Surcharge de l'opérateur [] pour la classe Tableau
 * @param index indice de l'élément
 * @return la valeur contenue dans le tableau à l'indice choisi.
 */
template <class T>
const T& Tableau<T>::operator[] (int index) const
{
    assert(index<nbElements);
    return chercher(elements[index]);
}

/**
 * Surcharge de l'opérateur [] pour la classe Tableau
 * @param index indice de l'élément
 * @return la valeur contenue dans le tableau à l'indice choisi.
 */
template <class T>
T& Tableau<T>::operator[] (int index)
{
    //assert(index<nbElements);
    return elements[index];
}

/**
 * Surcharge de l'opérateur = pour la classe Tableau
 * @tparam T Type générique
 * @param autre l'autre objet Tableau table à évaluer
 * @return adresse de l'objet courant
 */
template <class T>
Tableau<T>& Tableau<T>::operator = (const Tableau<T>& autre)
{
    if(this==&autre) return *this;

    nbElements = autre.nbElements;
    if(capacite<autre.nbElements || autre.nbElements*2<capacite)
    {
        delete[] elements;
        capacite = autre.capacite;
        elements = new T[capacite];
    }
    for(int i=0;i<nbElements;i++)
        elements[i] = autre.elements[i];
    return *this;
}

/**
 * Surcharge de l'opérateur == pour la classe Tableau
 * @tparam T Type générique
 * @param autre l'autre objet Tableau table à évaluer
 * @return renvoie true ou false en fonction de l'égalité
 * des tableau
 */
template <class T>
bool Tableau<T>::operator == (const Tableau<T>& autre) const
{
    if(this == &autre) return true;
    if(nbElements != autre.nbElements) return false;
    for(int i=0;i<nbElements;i++)
        if(!(elements[i]==autre.elements[i]))
            return false;
    return true;
}

#endif

