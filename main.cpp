#include <iostream>
#include <vector>
#include <random>


using namespace std;




class Carte {
private:
    int chiffre;
    string signe;
    string couleur;
public:
    Carte(int chiffre, string signe, string couleur) {
        this -> chiffre = chiffre;
        this -> signe = signe;
        this -> couleur = couleur;
    }
    void afficher() {
        if (chiffre == 13) {
            cout << "Voici les cartes :" << " roi" << " de " << this->signe << endl;
        }
        else if (chiffre == 12) {
            cout << "Voici les cartes :" << " dame" << " de " << this->signe << endl;
        }
        else if (chiffre == 11) {
            cout << "Voici les cartes :" << " valet" << " de " << this->signe << endl;
        }
        else if (chiffre == 1) {
            cout << "Voici les cartes :" << " as" << " de " << this->signe << endl;
        }
        else {
            cout << "Voici les cartes :" << this->chiffre << " de " << this->signe << endl;
        }
    }
};

class Purple {
private:
    vector<Carte*> paquetCarte;
public:


    void ajouterCartes(Carte* carte) {

        this -> paquetCarte.push_back(carte);
    }
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

    void creerCarte(){
        for(int i = 1; i <= 13; i++) {
            Carte* carteTrefle = new Carte(i, "trefle", "noir");
            this ->ajouterCartes(carteTrefle);
            Carte* cartePique = new Carte(i, "pique", "noir");
            this ->ajouterCartes(cartePique);
            Carte* carteCaro = new Carte(i, "carreau", "rouge");
            this->ajouterCartes(carteCaro);
            Carte* carteCoeur = new Carte(i, "coeur", "rouge");
            this ->ajouterCartes(carteCoeur);
        }
    }

    void afficherPaquet(){
        creerCarte();
        for(int i = 0; i < paquetCarte.size(); i++) {
            paquetCarte[i]->afficher();
        }
    }

};

int main() {



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
        Purple *purple = new Purple();
        purple->afficherPaquet();
    return 0;
}
