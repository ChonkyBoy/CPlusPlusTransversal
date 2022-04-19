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
//Rouge ou noir : OK
//+ ou - : OK
//purple :
//le tout qui marche :
// coms : ~ ok




using namespace std;

/* ----- CLASS CRÉATION DE CRATE ----- */

class Carte {
private:
    int chiffre;
    char symb;
    string couleur;
public:
    // Mon créateur de crate
    Carte(int chiffre, char symb, string couleur) {
        this->chiffre = chiffre;
        this->symb = symb;
        this->couleur = couleur;
    }


    int get_chiffre() { return this->chiffre; };

    void set_chiffre(int chiffre) { this->chiffre = chiffre; };

    char get_signe() { return this->symb; };

    void set_signe(char symb) { this->symb = symb; };

    string get_couleur() { return this->couleur; };

    void set_couleur(string couleur) { this->couleur = couleur; };

    // Fonction pour afficher mes cartes
    void toString() {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        cout << "Voici le(s) carte(s): ";
        if (this->symb == 3 || this->symb == 4) {
            SetConsoleTextAttribute(hConsole, 244); //Pour changer en rouge
            if (chiffre == 13) {
                cout << "Roi de " << this->symb << endl;
            } else if (chiffre == 12) {
                cout << "Dame de " << this->symb << endl;
            } else if (chiffre == 11) {
                cout << "Valet de " << this->symb << endl;
            } else if (chiffre == 1) {
                cout << "As de " << this->symb << endl;
            } else {
                cout << this->chiffre << " de " << this->symb << endl;
            }
            SetConsoleTextAttribute(hConsole, 7);
        } else {
            SetConsoleTextAttribute(hConsole, 240); // Pour changer en noir
            if (chiffre == 13) {
                cout << "Roi de " << this->symb << endl;
            } else if (chiffre == 12) {
                cout << "Dame de " << this->symb << endl;
            } else if (chiffre == 11) {
                cout << "Valet de " << this->symb << endl;
            } else if (chiffre == 1) {
                cout << "As de " << this->symb << endl;
            } else {
                cout << this->chiffre << " de " << this->symb << endl;
            }
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
};

/* ----- CLASS PURPLE - PAQUET DE CARTE ----- */

class Purple {
private:
    // Mon vector pour mettre mes 52 cartes différentes en ordre
    vector<Carte *> paquetCarte;
public:

    // Fonction qui ajoute les cartes dans le vector paquetCarte
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

    // Ma fonction qui permet d'attribuer mes chiffres, signes et couleurs à mes différents cartes
    void creerCarte() {
        char symb[] = {5, 6, 4, 3, '\0'};
        for (int i = 1; i <= 13; i++) {
            Carte *carteTrefle = new Carte(i, symb[0], "noir");
            this->ajouterCartes(carteTrefle);
            Carte *cartePique = new Carte(i, symb[1], "noir");
            this->ajouterCartes(cartePique);
            Carte *carteCaro = new Carte(i, symb[2], "rouge");
            this->ajouterCartes(carteCaro);
            Carte *carteCoeur = new Carte(i, symb[3], "rouge");
            this->ajouterCartes(carteCoeur);
        }
    }

    // Ma fonction qui affiche la paquet (pas mélangé)
    void afficherPaquet() {
        for (int i = 0; i < paquetCarte.size(); i++) {
            cout << i;
            paquetCarte[i]->toString();
        }
    }

    // Ma fonction (avec un nom pourri) qui me permet de mélanger le paquet (et de l'affichre si je décommente la ligne 133)
    void randomShuffleMarcheSTP() {
        for (int i = 0; i < 52; i++) {
            swap(paquetCarte[i], paquetCarte[rand() % 52]);
        }
        //this->afficherPaquet();
    }

    // Fonction qui me permet de prendre une carte de mon paquet et de l'enlever après
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
    // Carétaur de joueur
    Joueur(string nom, int points) {
        this->nom = nom;
        this->points = points;
    }

    string get_nom() { return this->nom; };
    void set_nom(string nom) { this->nom = nom; };

    int get_points() { return this->points; };
    void set_points(int points) { this->points = points; };


    /*
    int guessSTR() {
        int guessSTR;
        cout << "Joue: 1-rouge ou 2-noir " << endl;
        cin >> guessSTR;
        return guessSTR;
    }

    int guessINT() {
        int guessINT;
        cout << "Joue: + ou - " << endl;
        cin >> guessINT;
        return guessINT;
    }
     */
    // Fonction simple qui affiche les règles à chaque fois que le programme est lancé
    void rules() {
        cout
                << "Voici les regles : Le purple est un jeu de carte base sur le chance et les probabilites, il y a quelque regles a savoir.Premierement, au premier tour, tu dois dire rouge ou noir, ensuite, tu as plusieurs choix, soit tu peux dire rouge ou noir, + ou - mais la carte precedente ou bien purple, qui, simplement, est deux carte tirees a la suite, mais les deux doivent obligatoirement etre une rouge et une noir, peut importe l'ordre. Maintenant que tu as les regles en tete, je te laise tenter ta chance!"
                << endl;
        cout << "Comme precedement ennonce, tu dois jouer rouge ou noir: " << endl;
    }

    // Fonction du choix de départ (rouge ou noir)
    int startingGuess(Carte *carte) {
        string userChoice;
        rules();
        cout << "1: rouge 2: noir" << endl;
        cin >> userChoice;

        if (userChoice == "1") {
            carte->toString();
            return carte->get_couleur() == "rouge";
        } else if (userChoice == "2") {
            carte->toString();

            return carte->get_couleur() == "noir";
        } else
            return 0;
    }

    // Fonciton qui permet de faire les différents choix (tous sauf le choix de départ (startingGuess))
    int guesses(Carte *carte, Carte *cartePrecedente, Carte *purpleCard, Carte *purpleCard2) {
        string userChoice;
        cout << "1: rouge ou noir | 2: + ou - | 3: purple | 4- stop" << endl;
        cin >> userChoice;

        if (userChoice == "1") {
            cout << "1: rouge; 2: noir" << endl;
            cin >> userChoice;

            carte->toString();
            if (userChoice == "1") {
                return carte->get_couleur() == "rouge";
            } else if (userChoice == "2") {
                return carte->get_couleur() == "noir";
            } else {
                return 0;
            }
        } else if (userChoice == "2") {
            cout << "1: + | 2: -" << endl;
            cin >> userChoice;
            carte->toString();
            if (userChoice == "1") {
                if (carte->get_chiffre() > cartePrecedente->get_chiffre()) {
                    return 1;
                } else {
                    return 0;
                }
            } else if (userChoice == "2") {
                if (carte->get_chiffre() < cartePrecedente->get_chiffre()) {
                    return 1;
                } else {
                    return 0;
                }
            } else {
                return 0;
            }
        } else if (userChoice == "3") {
            purpleCard->toString();
            purpleCard2->toString();
            if (purpleCard->get_couleur() == purpleCard2->get_couleur()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }

        // Fonction qui nous permet de dire qqch si on gagne ou on perd, et qui compte les points
        void hasWon(int score) {
            if (score == 0) {
                cout << "haha t'as perdu" << endl;
            } else {
                cout << "bien ouej, rejoue" << endl;
            }
        }

    };

    int main() {
        int score = 0;
        srand((unsigned) time(0));
        string quit;


        while (quit != "n") {
            Purple *purple = new Purple;
            purple->creerCarte();
            purple->randomShuffleMarcheSTP();

            Joueur *joueur = new Joueur("Marin", 0);
            Carte *carte = purple->prendUneCarte(); // le jeu prend un carte

            score = joueur->startingGuess(carte);
            joueur->hasWon(score);
            joueur->set_points(joueur->get_points() + score);
            Carte *cartePrecedente = carte;

            while (score) {
                Carte *purpleCard = purple->prendUneCarte();
                Carte *purpleCard2 = purple->prendUneCarte();
                Carte *carte = purple->prendUneCarte(); // le jeu prend un carte
                //le joueur essaie de deviner
                score = joueur->guesses(carte, cartePrecedente, purpleCard, purpleCard2);
                joueur->set_points(joueur->get_points() + score);
                joueur->hasWon(score);
                cout << "t'as " << joueur->get_points() << " points!" << endl;
                delete (cartePrecedente);
                delete (purpleCard);
                delete (purpleCard2);
                cartePrecedente = carte;
            }
            cout << "Tu veux refaire une partie ? (y/n)" << endl;
            cin >> quit;
        }
/*
   if (resultOfSTG != 4) {
        if (resultOfSTG == 1) {
            string carte_couleur;
            if (joueur->guessSTR() == 1) {
                carte_couleur = "rouge";
                if (carte->get_couleur() == carte_couleur) {
                    cout << "t'as eu bon" << endl;
                    carte->toString();
                } else {
                    cout << "t'as perdu bois" << endl;
                    carte->toString();
                    return 0;
                }
            } else if (joueur->guessSTR() == 2) {
                carte_couleur = "noir";
                if (carte->get_couleur() == carte_couleur) {
                    cout << "t'as eu bon" << endl;
                    carte->toString();
                } else {
                    cout << "t'as perdu bois" << endl;
                    carte->toString();
                    return 0;
                }

//                cout << (carte->get_couleur() == carte_couleur ? "t'as eu bon gros rat" : "Perdu haha bois stp")
//                     << endl;
//                carte->toString();

            }
        }
   }

   while (resultOfG != 4)
       if (resultOfSTG == 1) {
           string carte_couleur;
           if (joueur->guessSTR() == 1) {
               carte_couleur = "rouge";
               if (carte->get_couleur() == carte_couleur) {
                   cout << "t'as eu bon" << endl;
                   carte->toString();
               } else {
                   cout << "t'as perdu bois" << endl;
                   carte->toString();
                   return 0;
               }
           } else if (joueur->guessSTR() == 2) {
               carte_couleur = "noir";
               if (carte->get_couleur() == carte_couleur) {
                   cout << "t'as eu bon" << endl;
                   carte->toString();
               } else {
                   cout << "t'as perdu bois" << endl;
                   carte->toString();
                   return 0;
               }
           }
       } else if (resultOfG == 2) {
            int carte_chiffre = 0;
            if (joueur->guessINT() == '+') {
                carte_chiffre = '+';
                if (joueur->guessINT() > carte_chiffre) {
                    cout << "t'as eu bon" << endl;
                    carte->toString();
                    return 0;
                } else if (carte->get_chiffre() < carte_chiffre) {
                    cout << "perdu, tu bois" << endl;
                    carte->toString();
                    return 0;
                } else {
                    cout << "cul sec haha" << endl;
                    carte->toString();
                    return 0;
                }
            } else if (joueur->guessINT() == '-') {
                carte_chiffre = '-';
                if (joueur->guessINT() < carte->get_chiffre()) {
                    cout << "t'as eu bon" << endl;
                    carte->toString();
                    return 0;
                } else if (joueur->guessINT() > carte_chiffre) {
                    cout << "perdu, tu bois" << endl;
                    carte->toString();
                    return 0;
                } else {
                    cout << "cul sec haha" << endl;
                    carte->toString();
                    return 0;
                }

            }
        }
   */
        cout << "ok looser, c'est ciao gros naze" <<
             endl;
        return 0;

    }
