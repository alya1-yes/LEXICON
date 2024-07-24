#include<iostream>
#include<fstream>
#include<cassert>
using namespace std;
#include "Jeu.h"
#include "paquet.h"
#include "coups.h"


int main(int argc, char* argv[]) {
	//int tour = -1;
	int tour;
	ifstream dico;
	dico.open("ods4.txt", ios::in);
	if (dico.fail()) {
		cerr << "Impossible d'ouvrir le fichier dictionnaire. " << endl;
		exit(1);
	}
	if (argc != 2) {
		cerr << "il n'y a pas de parametre" << endl;
	}
	unsigned int nbJoueurs = atoi(argv[1]);
	assert(nbJoueurs > 1 && nbJoueurs <= 4);
	ConteneurTS* joueurs = new ConteneurTS[nbJoueurs];
	for (unsigned int i = 0; i < nbJoueurs; i++) {
		initialiser(joueurs[i]);
		joueurs[i].ID = i + 1;
		joueurs[i].score = 0;

	}

	while (nbJoueurs > 1) {
		Pile talon;
		initialiser(talon, MAX_CARTES);
		creerJeu(talon);
		melanger(talon.tab, MAX_CARTES);
		distribuer(talon, joueurs, nbJoueurs);
		Pile expose;
		initialiser(expose, MAX_CARTES);
		Carte carte = sommet(talon);
		depiler(talon);
		empiler(expose, carte);
		Partie partie;
		initialiser(partie, nbJoueurs, joueurs);


		unsigned int nbtours = 1;
		char com[CHARAMAX];
		cout << "(Commandes valides : TEPRC)" << endl;
		do {//interpréteur de commande
			unsigned int ID = nbtours % nbJoueurs;
			if (nbtours % nbJoueurs == 0) {
				ID = nbJoueurs;
			}
			afficherPartie(partie, ID, expose);
			cin >> com;
			if (strcmp(com, "T") == 0) { //appel fonction Talon
				Talon(partie, talon, expose, ID, nbtours);
			}
			if (strcmp(com, "E") == 0) { //appel fonction Exposée
				exposee(partie, expose, ID, nbtours);
			}
			if (strcmp(com, "P") == 0) { //appel fonction Poser
				poser(partie, ID, dico, nbtours);
			}
			if (strcmp(com, "R") == 0) { //appel fonction Remplacer
				remplacer(partie, ID, dico, nbtours);
			}
			if (strcmp(com, "C") == 0) { //appel fonction Compléter
				compléter(partie, ID, dico, nbtours);
			}
			else if ((strcmp(com, "C") != 0) && (strcmp(com, "R") != 0) && (strcmp(com, "P") != 0) && (strcmp(com, "E") != 0) && (strcmp(com, "T") != 0)) {
				std::cout << "Coup invalide, recommencez" << endl;
			}

			tour = ID;
			if (talon.sommet == 0) {
				melanger(expose.tab, expose.sommet);
				for (unsigned int i = 0; i < expose.sommet; i++) {
					Carte carte = sommet(expose);
					depiler(expose);
					empiler(talon, carte);
				}
				Carte carte = sommet(talon);
				depiler(talon);
				empiler(expose, carte);
			}

		} while (finManche(partie) == 0);
		for (unsigned int i = 0; i < partie.NbJoueurs; i++) {
			for (unsigned int y = 0; y < partie.joueurs[i].nbCartes; y++) {
				partie.joueurs[i].score = partie.joueurs[i].score + partie.joueurs[i].paquet[y].valeur;
			}
		}

		if (finManche) {
			std::cout << "Le tour est fini main " << endl;
			std::cout << "* Scores" << endl;
			for (unsigned int i = 0; i < partie.NbJoueurs; i++) {
				std::cout << "Joueur " << partie.joueurs[i].ID << " : " << partie.joueurs[i].score << " score" << endl;
			}

			for (unsigned int i = 0; i < partie.NbJoueurs; i++) {
				unsigned int w = 0;
				if (partie.joueurs[i].score >= MAXPOINTS) {
					nbJoueurs--;
				}
			}

			detruire(talon);
			detruire(expose);
			for (unsigned int i = 0; i < partie.nbMots; i++) {	//Ne pas oublier de delete toutes les listes construites (les mots)
				delete[] partie.mots[i];
			}
			detruire(partie);
			std::cout << "La partie est finie" << endl;
			delete[] joueurs;
			dico.close();
		}

	}
}




