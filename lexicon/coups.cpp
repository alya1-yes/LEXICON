#include<iostream>
#include<cassert>
#include<fstream>
using namespace std;
#include"Jeu.h"
#include"coups.h"
#pragma warning(disable : 4996)

void Talon(Partie& partie, Pile& talonT, Pile& expose, unsigned int ID, unsigned int& numTour) {
    ID = ID - 1;
    char lettre;
    unsigned int compteur;

    cin >> lettre;
    compteur = 0;

    for (unsigned int i = 0; i < partie.joueurs[ID].nbCartes; i++) {
        if (lettre == partie.joueurs[ID].paquet[i].lettre) {
            ++compteur;
        }
    }

    if (compteur == 0) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    Carte carte;
    unsigned int pos;
    for (unsigned int i = 0; i < partie.joueurs[ID].nbCartes; i++) {
        if (lettre == partie.joueurs[ID].paquet[i].lettre) {
            carte = lire(partie.joueurs[ID], i);
            pos = i;
        }
    }
    empiler(expose, carte);
    Carte tal = sommet(talonT);
    depiler(talonT);
    ecrire(partie.joueurs[ID], pos, tal);
    numTour++;

}

void exposee(Partie& partie, Pile& expose, unsigned int ID, unsigned int& numTour) {
    ID = ID - 1;
    char lettre;
    unsigned int compteur;
    cin >> lettre;
    compteur = 0;

    for (unsigned int i = 0; i < partie.joueurs[ID].nbCartes; i++) {
        if (lettre == partie.joueurs[ID].paquet[i].lettre) {
            ++compteur;
        }
    }

    if (compteur == 0) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    Carte carte;
    unsigned int pos;
    for (unsigned int i = 0; i < partie.joueurs[ID].nbCartes; i++) {
        if (lettre == partie.joueurs[ID].paquet[i].lettre) {
            carte = lire(partie.joueurs[ID], i);
            pos = i;
        }
    }
    Carte exp = sommet(expose);
    depiler(expose);
    empiler(expose, carte);
    ecrire(partie.joueurs[ID], pos, exp);
    numTour++;

}
void poser(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour) {
    ID = ID - 1;
    char mot[CHARAMAX];
    cin >> mot;

    if (!dansMain(partie, ID, mot)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }


    if (!existe(mot, dico)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        partie.joueurs[ID].score = partie.joueurs[ID].score + 3;
        numTour++;
        return;
    }

    partie.mots[partie.nbMots] = new char[CHARAMAX];
    strcpy(partie.mots[partie.nbMots], mot);
    supMain(partie, ID, mot);
    partie.nbMots++;
    numTour++;
}
void compléter(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour) {
    ID = ID - 1;
    unsigned int numero;
    char mot[CHARAMAX];
    cin >> numero >> mot;

    if ((numero == 0) || (numero > partie.nbMots)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    if (!existe(mot, dico)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        partie.joueurs[ID].score = partie.joueurs[ID].score + 3;
        numTour++;
        //continue;
    }

    char motMainJoueur[CHARAMAX];
    comparer(mot, partie.mots[numero - 1], motMainJoueur);

    if (!dansMain(partie, ID, motMainJoueur)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    if (!estEnOrdre(partie.mots[numero - 1], mot)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    if (strcmp(mot, motMainJoueur) == 0) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    strcpy(partie.mots[numero - 1], mot);
    supMain(partie, ID, motMainJoueur);
    numTour++;
}

void remplacer(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour) {
    ID = ID - 1;
    unsigned int numero;
    char mot[CHARAMAX];
    unsigned int tailleMot, tailleMotJeu;
    cin >> numero >> mot;
    tailleMot = strlen(mot);

    if ((numero == 0) || (numero > partie.nbMots)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    unsigned int pos = numero - 1;
    tailleMotJeu = strlen(partie.mots[pos]);

    if ((tailleMot != tailleMotJeu)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }

    if (!existe(mot, dico)) {
        cout << "Mot invalide, vous passez votre tour" << endl;
        partie.joueurs[ID].score = partie.joueurs[ID].score + 3;
        numTour++;
        return;
    }

    char motMainJoueur[CHARAMAX];
    comparer(mot, partie.mots[pos], motMainJoueur);

    if (!dansMain(partie, ID, motMainJoueur)) {
        cout << "Coup invalide, recommencez" << endl;
        return;
    }
    supMain(partie, ID, motMainJoueur);

    char motAjouterDansMain[CHARAMAX];
    comparer(partie.mots[pos], mot, motAjouterDansMain);
    ajMain(partie, ID, motAjouterDansMain);
    strcpy(partie.mots[numero - 1], mot);
    numTour++;

}