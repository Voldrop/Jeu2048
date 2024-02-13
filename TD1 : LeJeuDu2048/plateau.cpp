#include "plateau.h"
#include "jeu2048.h"
#include <iostream>
#include <iomanip>
#include <cstring>

Plateau::Plateau() {
    nbCoups = 0;
    score = 0;
}

int Plateau::ObtenirNbCoups() const {
    return nbCoups;
}

int Plateau::ObtenirScore() const {
    return score;
}

void Plateau::FixerNbCoups(int nbCoups) {
    this->nbCoups = nbCoups;
}

void Plateau::FixerScore(int score) {
    this->score = score;
}

void Plateau::Afficher() const {
    int laGrille[TAILLE][TAILLE];
    leJeu.ObtenirGrille(laGrille);
    system("clear");
    std::cout << "| Score : " << score << " | Nombre de coups : " << nbCoups << " |" << std::endl;
    std::cout << std::endl;
    for (int ligne = 0; ligne < TAILLE; ligne++) {
        std::cout << " +";
        for (int indice = 0; indice < TAILLE; indice++)
            std::cout << std::setw(9) << std::setfill('-') << '+';
        std::cout << std::endl;
        for (int indice = 0; indice < TAILLE; indice++) {
            std::cout << " |" << std::setw(7) << std::setfill(' ');
            if (laGrille[ligne][indice] != 0) {
                std::cout << laGrille[ligne][indice];
            } else {
                std::cout << " ";
            }
        }
        std::cout << "| " << std::endl;
    }
    std::cout << " +";
    for (int indice = 0; indice < TAILLE; indice++)
        std::cout << std::setw(9) << std::setfill('-')<< '+';
    std::cout << std::endl;
    std::cout << "Controles : " << std::endl;
    std::cout << "H - Haut, B - Bas, G - Gauche, D - Droite, F - Fin de jeu" << std::endl;
}

bool Plateau::JouerCoup() {
    bool retour = false;
    char touche;
    std::cin >> touche;
    touche = toupper(touche);
    if (strchr("BHGD", touche) != nullptr) {
        nbCoups++;
        int ancienneGrille[TAILLE][TAILLE];
        leJeu.ObtenirGrille(ancienneGrille);
        leJeu.Deplacer(touche);
        if (leJeu.Calculer(touche)) {
            leJeu.Deplacer(touche);
        }
        if (leJeu.ObtenirGrille(ancienneGrille) != 0) {
            leJeu.PlacerNouvelleTuile();
            score = leJeu.CalculezScore();
            Afficher();
        }
        int etatPartie = leJeu.RechercherFinDePartie();
        if (etatPartie == Jeu2048::PARTIE_GAGNEE) {
            std::cout << "Felicitations ! Vous avez gagne !" << std::endl;
            retour = true;
        } else if (etatPartie == Jeu2048::PARTIE_PERDUE) {
            std::cout << "Partie terminee. Vous avez perdu." << std::endl;
            retour = true;
        }
    }
    if (touche == 'F') {
        retour = true;
    }
    return retour;
}