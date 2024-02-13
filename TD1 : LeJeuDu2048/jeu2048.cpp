#include "jeu2048.h"
#include <cstdlib>
#include <ctime>

const int ETATS_DU_JEU = 0;

Jeu2048::Jeu2048() {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            grille[i][j] = 0;
        }
    }
    score = 0;
    srand(time(nullptr));
    PlacerNouvelleTuile();
}

int Jeu2048::ObtenirGrille(int _grille[][TAILLE]) const {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            _grille[i][j] = grille[i][j];
        }
    }
}

int Jeu2048::ObtenirScore() const {
    return score;
}

void Jeu2048::FixerGrille(int i, int j, int valeur) {
    grille[i][j] = valeur;
}

void Jeu2048::PlacerNouvelleTuile() {
    int ligne, colonne;
    do {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;
    } while (grille[ligne][colonne] != 0);

    grille[ligne][colonne] = (((rand() % 2) + 1) * 2);
}

bool Jeu2048::Calculer(char direction) {
    bool mouvementEffectue = false;
    Deplacer(direction);
    for (int ligne = 0; ligne < 4; ligne++) {
        for (int colonne = 0; colonne < 3; colonne++) {
            if (grille[ligne][colonne] == grille[ligne][colonne + 1] && grille[ligne][colonne] != 0) {
                grille[ligne][colonne] *= 2;
                grille[ligne][colonne + 1] = 0;
                mouvementEffectue = true;
            }
        }
    }
    Deplacer(direction);
    return mouvementEffectue;
}

void Jeu2048::Deplacer(char _direction) {
    int ligne;
    int colonne;
    for (int indice = 0; indice < 4; indice++) {
        switch (_direction) {
            case 'G':
                for (ligne = 0; ligne < 4; ligne++) {
                    for (colonne = 0; colonne < 3; colonne++) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne][colonne + 1];
                            grille[ligne][colonne + 1] = 0;
                        } else if (grille[ligne][colonne] == grille[ligne][colonne + 1]) {
                            grille[ligne][colonne] *= 2;
                            grille[ligne][colonne + 1] = 0;
                        }
                    }
                }
                break;
            case 'D':
                for (ligne = 0; ligne < 4; ligne++) {
                    for (colonne = 3; colonne > 0; colonne--) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne][colonne - 1];
                            grille[ligne][colonne - 1] = 0;
                        } else if (grille[ligne][colonne] == grille[ligne][colonne - 1]) {
                            grille[ligne][colonne] *= 2;
                            grille[ligne][colonne - 1] = 0;
                        }
                    }
                }
                break;
            case 'H':
                for (colonne = 0; colonne < 4; colonne++) {
                    for (ligne = 0; ligne < 3; ligne++) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne + 1][colonne];
                            grille[ligne + 1][colonne] = 0;
                        } else if (grille[ligne][colonne] == grille[ligne + 1][colonne]) {
                            grille[ligne][colonne] *= 2;
                            grille[ligne + 1][colonne] = 0;
                        }
                    }
                }
                break;
            case 'B':
                for (colonne = 0; colonne < 4; colonne++) {
                    for (ligne = 3; ligne > 0; ligne--) {
                        if (grille[ligne][colonne] == 0) {
                            grille[ligne][colonne] = grille[ligne - 1][colonne];
                            grille[ligne - 1][colonne] = 0;
                        } else if (grille[ligne][colonne] == grille[ligne - 1][colonne]) {
                            grille[ligne][colonne] *= 2;
                            grille[ligne - 1][colonne] = 0;
                        }
                    }
                }
                break;
        }
    }
}

int Jeu2048::CalculezScore() const {
    int somme = 0;
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            somme += grille[i][j];
        }
    }
    return somme;
}

int Jeu2048::RechercherFinDePartie() const {
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (grille[i][j] == 2048) {
                return PARTIE_GAGNEE;
            }
        }
    }
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE; ++j) {
            if (grille[i][j] == 0) {
                return EN_COURS;
            }
        }
    }
    for (int i = 0; i < TAILLE; ++i) {
        for (int j = 0; j < TAILLE - 1; ++j) {
            if (grille[i][j] == grille[i][j + 1] || grille[j][i] == grille[j + 1][i]) {
                return EN_COURS;
            }
        }
    }
    return PARTIE_PERDUE;
}