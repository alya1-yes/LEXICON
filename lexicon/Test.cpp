#include <iostream>
#include <cassert>
#include <fstream>
#include" Jeu.h"
#include "coups.h"
int main() {
    ifstream dico("votre_fichier_dictionnaire.txt");

    assert(existe("MOT", dico) == true);
    assert(existe("INEXISTANT", dico) == false);


    // Test avec des mots en ordre
    assert(estEnOrdre("ABC", "ABC") == true);
    assert(estEnOrdre("AB", "ABC") == true);
    assert(estEnOrdre("AB", "ACB") == true);
    assert(estEnOrdre("ABC", "DEFGABC") == true);

    // Test avec des mots qui ne sont pas en ordre
    assert(estEnOrdre("ABC", "BCA") == false);
    assert(estEnOrdre("ABC", "ACBD") == false);
    assert(estEnOrdre("ABC", "ABD") == false);
    assert(estEnOrdre("ABC", "ABCE") == false);

    // Test avec des mots vides
    assert(estEnOrdre("", "") == true);
    assert(estEnOrdre("", "ABC") == true);
    assert(estEnOrdre("ABC", "") == false);

   

    int main() {
        // Création d'une partie fictive avec une main pour le joueur
        Partie partie;
        partie.NbJoueurs = 1;
        partie.joueurs = new ConteneurTS[1];
        partie.joueurs[0].ID = 1;
        partie.joueurs[0].nbCartes = 5;
        partie.joueurs[0].paquet[0] = { 'A', 1 };
        partie.joueurs[0].paquet[1] = { 'B', 2 };
        partie.joueurs[0].paquet[2] = { 'C', 3 };
        partie.joueurs[0].paquet[3] = { 'D', 4 };
        partie.joueurs[0].paquet[4] = { 'E', 5 };

        // Test avec un mot existant dans la main du joueur
        assert(dansMain(partie, 0, "ABCDE") == true);

        // Test avec un mot inexistant dans la main du joueur
        assert(dansMain(partie, 0, "XYZ") == false);

        // Test avec un mot qui a plus de lettres que la main du joueur
        assert(dansMain(partie, 0, "ABCDEF") == false);

        // Test avec une main vide
        partie.joueurs[0].nbCartes = 0;
        assert(dansMain(partie, 0, "XYZ") == false);

    

        // Nettoyage de la mémoire
        delete[] partie.joueurs;

        return 0;
    }
}
