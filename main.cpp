#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>
#include <algorithm>
#include <random>

//Faire le paquet : OK
//Mélanger le paquet : OK
//Pas besoin de remagner le paquet car dès qu'on ped le paquet est remélangé pour éviter la triche hehe
//Rouge ou noir :
//+ ou - :
//purple :
//le tout qui marche :



using namespace std;


/* ----- CLASS CRÉATION DE CRATE ----- */

class Carte {
private:
    int chiffre;
    string signe;
    string couleur;
public:
    Carte(int chiffre, string signe, string couleur) {
        this->chiffre = chiffre;
        this->signe = signe;
        this->couleur = couleur;
    }

    int get_chiffre() { return this->chiffre; };

    void set_chiffre(int chiffre) { this->chiffre = chiffre; };

    string get_signe() { return this->signe; };

    void set_signe(string signe) { this->signe = signe; };

    string get_couleur() { return this->couleur; };

    void set_couleur(string couleur) { this->couleur = couleur; };


    void toString() {
        if (chiffre == 13) {
            cout << "Voici les cartes :" << " roi" << " de " << this->signe << endl;
        } else if (chiffre == 12) {
            cout << "Voici les cartes :" << " dame" << " de " << this->signe << endl;
        } else if (chiffre == 11) {
            cout << "Voici les cartes :" << " valet" << " de " << this->signe << endl;
        } else if (chiffre == 1) {
            cout << "Voici les cartes :" << " as" << " de " << this->signe << endl;
        } else {
            cout << "Voici les cartes : " << this->chiffre << " de " << this->signe << endl;
        }
    }
};

/* ----- CLASS PURPLE - PAQUET DE CARTE ----- */

class Purple {
private:
    vector<Carte *> paquetCarte;
public:

    void ajouterCartes(Carte *carte) {
        this->paquetCarte.push_back(carte);
    }
    /*
    void retirerCarte(){
        this->paquetCarte.pop_back();
    }
     */
    /*void creerCarteCoeur(){
        for(int i = 1; i <= 13; i++) {
            Carte* carteCoeur = new Carte(i, "coeur", "rouge");
            this ->ajouterCartes(carteCoeur);
        }
    }
    void creerCarteCaro(){
        for(int i = 1; i <= 13; i++) {
            Carte* carteCaro = new Carte(i, "carreau", "rouge");
            this->ajouterCartes(carteCaro);
        }
    }
    void creerCartePique(){
        for(int i = 1; i <= 13; i++) {
            Carte* cartePique = new Carte(i, "pique", "rouge");
            this ->ajouterCartes(cartePique);
        }
    }
    void creerCarteTrefle(){
        for(int i = 1; i <= 13; i++) {
            Carte* carteTrefle = new Carte(i, "trefle", "rouge");
            this ->ajouterCartes(carteTrefle);
        }
    }*/

    void creerCarte() {
        for (int i = 1; i <= 13; i++) {
            Carte *carteTrefle = new Carte(i, "trefle", "noir");
            this->ajouterCartes(carteTrefle);
            Carte *cartePique = new Carte(i, "pique", "noir");
            this->ajouterCartes(cartePique);
            Carte *carteCaro = new Carte(i, "carreau", "rouge");
            this->ajouterCartes(carteCaro);
            Carte *carteCoeur = new Carte(i, "coeur", "rouge");
            this->ajouterCartes(carteCoeur);
        }
    }

    void afficherPaquet() {
        for (int i = 0; i < paquetCarte.size(); i++) {
            cout << i;
            paquetCarte[i]->toString();
        }
    }

    void randomShuffleMarcheSTP() {
        for (int i = 0; i < 52; i++) {
            swap(paquetCarte[i], paquetCarte[rand() % 52]);
        }
        //this->afficherPaquet();
    }

    Carte *prendUneCarte() {
        Carte *result = this->paquetCarte[paquetCarte.size() - 1];
        this->paquetCarte.pop_back();
        return result;
    }
};


/* ----- CLASS JOUEUR ----- */

class Joueur {
private:
    string nom;
    int points;

public:

    Joueur(string nom, int points) {
        this->nom = nom;
        this->points = points;
    }

    string get_nom() { return this->nom; };

    void set_nom(string nom) { this->nom = nom; };

    int get_points() { return this->points; };

    void set_points(int points) { this->points = points; };


    int guessSTR() {
        int guessSTR;
        cout << "Joue: 1-rouge | 2-noir ";
        cin >> guessSTR;
        return guessSTR;
    }

    int guessINT() {
        int guessINT;
        cout << "Joue: + | -";
        cin >> guessINT;
        return guessINT;
    }


    int startingGuess() {
        int userChoice;

        cout
                << "1- rouge ou noir | 2- + ou - | 3- purple (pas encore fonctionnel lol) | 4- stop (pour arreter tout le temps) :)"
                << endl;
        cin >> userChoice;
        if (userChoice == 1) {
            guessSTR();
        } else if (userChoice == 2) {
            guessINT();
        } else if (userChoice == 3) {
            // A FAIRIEIOZINJDSKFJDPJGDPJ
        } else {
            cout << "ok bye" << endl;
        }
        return userChoice;
    }


};

int main() {
    srand((unsigned) time(0));



/*
    Carte *asco = new Carte(1, "coeur", "rouge");
    Carte *deuxco = new Carte(2, "coeur", "rouge");
    Carte *troisco = new Carte(3, "coeur", "rouge");
    Carte *quatreco = new Carte(4, "coeur", "rouge");
    Carte *cinqco = new Carte(5, "coeur", "rouge");
    Carte *sixco = new Carte(6, "coeur", "rouge");
    Carte *septco = new Carte(7, "coeur", "rouge");
    Carte *huitco = new Carte(8, "coeur", "rouge");
    Carte *neufco = new Carte(9, "coeur", "rouge");
    Carte *dixco = new Carte(10, "coeur", "rouge");
    Carte *onzeco = new Carte(11, "coeur", "rouge");
    Carte *douze = new Carte(12, "coeur", "rouge");
    Carte *treizeco = new Carte(13, "coeur", "rouge");
     */
/*
    for (int i = 0; i < 10; ++i) {
        int valeur = rand();
        cout << "valeur full rand mais pas trop lolilol" << valeur << endl;
    }
*/
/*
    srand((unsigned int) time(0));

    for (int i = 0; i < 10; ++i) {
        int valeur = rand();
        cout << "valeur full rand mais pas trop lolilol" << valeur << endl;
    }
*/

    Purple *purple = new Purple;
    purple->creerCarte();
    purple->randomShuffleMarcheSTP();

    Joueur *joueur = new Joueur("Marin", 0);


    Carte *carte = purple->prendUneCarte();

    while (joueur->startingGuess() != 4) {
//        if (joueur->startingGuess() == joueur->guessSTR()) {
        string carte_couleur;
        if (joueur->guessSTR() == 1) { carte_couleur = "rouge"; } else { carte_couleur = "noir"; };
        if (carte->get_couleur() == carte_couleur) {
            cout << "t'as eu bon gros rat" << endl;
            carte->toString();
            return 0;
        } else if (carte->get_chiffre() == joueur->guessINT()) {
            cout << "t'as aussi eu bon rahh" << endl;
            carte->toString();
            return 0;
        }

    }

/*
Purple* main_maitre;
Purple* table;

Carte* carte = main_maitre->retirerCarte();
table->ajouterCartes(carte);
Compare la carte avec la prédiction d jouer...
*/

    return 0;
}
