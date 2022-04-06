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

/*int shuffle(int r) {
    return rand() % r;
}*/

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
    void set_signe(string signe) { this->signe = signe;};

    string get_couleur() { return this->couleur; };
    void set_couleur(string couleur) { this->couleur = couleur; };

    void toString(){
        cout << this->signe << this->chiffre << this->couleur << endl;
    }

    void afficher() {
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
            paquetCarte[i]->afficher();
        }
    }

    void randomShuffleMarcheSTP() {
        for (int i = 0; i < 52; i++) {
            swap(paquetCarte[i], paquetCarte[rand() % 52]);
        }
        this->afficherPaquet();
    }

//    void RougeNoir(){
//        if (paquetCarte.pop_back();) {
//
//        }
//    };
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

//    Purple *purple = new Purple;
//    purple->creerCarte();
//    purple->randomShuffleMarcheSTP();

    string guess = "rouge";

    Carte* carte = new Carte(8, "coeur", "rouge");

    if (guess == carte->get_couleur()) {
        cout << carte << endl;
        cout << "gagné" << endl;
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
