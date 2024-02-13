#ifndef JEU2048_H
#define JEU2048_H

#include <iostream>
#include <cstdlib>
#include <ctime>

const int TAILLE = 4;
extern const int ETATS_DU_JEU;

class Jeu2048 {
private:
    int grille[TAILLE][TAILLE];
    int score;
public:
    Jeu2048();
    static const int PARTIE_GAGNEE = 1;
    static const int EN_COURS = 0;
    static const int PARTIE_PERDUE = -1;
    int ObtenirGrille(int _grille[][TAILLE]) const;
    int ObtenirScore() const;
    void FixerGrille(int i, int j, int valeur);
    void PlacerNouvelleTuile();
    bool Calculer(char direction);
    void Deplacer(char direction);
    int CalculezScore() const;
    int RechercherFinDePartie() const;
    void Afficher() const;
};

#endif // JEU2048_H