#include "plateau.h"
#include <iostream>

int main() {
    Plateau plateau;
    plateau.Afficher();
    while (true) {
        if (plateau.JouerCoup()) {
            std::cout << "Voulez-vous relancer une nouvelle partie ? (O/N): ";
            char choix;
            std::cin >> choix;
            if (toupper(choix) == 'O') {
                plateau = Plateau();
                plateau.Afficher();
            } else {
                std::cout << "Merci d'avoir jouE ! Au revoir." << std::endl;
                break;
            }
        }
    }
    return 0;
}