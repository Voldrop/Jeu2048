#ifndef PLATEAU_H
#define PLATEAU_H

#include "jeu2048.h"

class Plateau {
private:
    Jeu2048 leJeu;
    int nbCoups;
    int score;

public:
    Plateau();

    int ObtenirNbCoups() const;
    int ObtenirScore() const;

    void FixerNbCoups(int nbCoups);
    void FixerScore(int score);

    void Afficher() const;
    bool JouerCoup();
};

#endif // PLATEAU_H