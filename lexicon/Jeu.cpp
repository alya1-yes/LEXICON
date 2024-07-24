#include<iostream>
#include<cassert>
#include<fstream>
using namespace std;
#include"Jeu.h"
#pragma warning(disable : 4996)



void creerJeu(Pile& p) {

    const Carte paquet[MAX_CARTE] = {{'A', 10},{'A', 10},{'B', 2},{'B', 2},{'C', 8},{'C', 8},{'D', 6},{'D', 6},{'E', 10}, {'E', 10},{'E', 10},{'E', 10},{'E', 10},{'F', 2},{'G', 4},{'G', 4},{'H',8},{'H',8},{'I',10},{'I',10},{'I',10},{'I',10},{'J',6},{'K', 8},{'L', 8},{'L', 8},{'M', 8},{'N', 8},{'N', 8},{'N', 8},{'O', 8},{'O', 8},{'P', 8},{'Q', 4},{'R', 8},{'R', 8},{'R', 8},{'S', 8},{'S', 8},{'S', 8},{'T', 8}, {'T', 8}, {'T', 8},{'U', 8},{'U', 8},{'U', 8},{'V',  8},{'W', 8},{'X', 2},{'Y', 4},{'Z', 2},};
    assert(estVide(p));
    for (unsigned int i = 0; i < MAX_CARTE; i++) {
        Carte carte;
        carte = paquet[i];
        empiler(p, carte);
        

    }
}

void distribuer(Pile& p, ConteneurTS*& j, unsigned int nbJoueurs) {
    for (unsigned int i = 0; i < nbJoueurs; i++) {
        for (unsigned int y = 0; y < ConteneurTS::CAPACITE; y++) {
            Carte carte = sommet(p);
            depiler(p);
            ecrire(j[i], y, carte);
        }
        j[i].nbCartes = ConteneurTS::CAPACITE;
    }
}

bool finManche(Partie& partie) {
    //cout << "Le tour est fini jeu" << endl;
    //cout << "* Scores" << endl;
    unsigned int compteur = 0;
    for (unsigned int i = 0; i < partie.NbJoueurs; i++) {
        if (partie.joueurs[i].nbCartes <= 0) {
            compteur++;//Si un joueur a 0 ou - de carte incrémenter le compteur
        }
    }
    if (compteur > 0) {
        return 1;//1 si la manche est fini
    }
    else {
        return 0;
    }
}

void initialiser(Partie& partie, unsigned int nbJoueurs, ConteneurTS*& joueurs) {
    partie.NbJoueurs = nbJoueurs;
    partie.joueurs = joueurs;
    partie.nbMots = 0;

}

void detruire(Partie& partie) {
    partie.NbJoueurs = NULL;
    if (partie.nbMots > 0) {
        for (unsigned int i = 0; i < partie.nbMots; i++) {
            delete[] partie.mots[i];
        }
    }
    partie.nbMots = NULL;
}


void afficherPartie(Partie& partie, unsigned int ID, Pile& expose) {
    ID = ID - 1;
    cout << "* Joueur " << partie.joueurs[ID].ID << " (" << expose.tab[expose.sommet].lettre << ") ";
    for (unsigned int i = 0; i < partie.joueurs[ID].nbCartes; i++) {
        cout << partie.joueurs[ID].paquet[i].lettre;
    }
    cout << endl;
    if (partie.nbMots > 0) {
        for (unsigned int i = 0; i < partie.nbMots; i++) {
            cout << i + 1 << " - " << partie.mots[i]<< endl;
        }
    }
    cout << "> ";
}

bool existe(const char mot[CHARAMAX], ifstream& dico) {
	char motDico[CHARAMAX];
	dico.clear();
	dico.seekg(0, ios::beg);
	while (dico >> motDico) {
		if (strcmp(motDico, mot) == 0) {
			return true;
		}
	}
	return false;
}





bool dansMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]) {
	unsigned int frequence[LETTRES];
	for (unsigned int i = 0; i < LETTRES; i++)
		frequence[i] = 0;
	for (int i = 0; i < strlen(mot); ++i) {
		frequence[mot[i] - 'A']++;
	}
	for (int i = 0; i < ConteneurTS::CAPACITE; ++i) {
		if ((partie.joueurs[ID].paquet[i].lettre != '\0') && (frequence[partie.joueurs[ID].paquet[i].lettre - 'A'] != 0)) {
			frequence[partie.joueurs[ID].paquet[i].lettre - 'A']--;

			// Si le joueur n'a pas assez de cette lettre, le mot ne peut pas être formé
			if (frequence[partie.joueurs[ID].paquet[i].lettre - 'A'] < 0) {
				return false;
			}
		}
	}
	for (int i = 0; i < LETTRES; ++i) {
		if (frequence[i] > 0) {
			return false; // Il manque au moins une lettre du mot dans la main du joueur
		}
	}

	return true;
}


void supMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]) {
	unsigned int nbCartes = partie.joueurs[ID].nbCartes;
	Item newTab[ConteneurTS::CAPACITE];
	unsigned int w = 0;

	// Tableau pour enregistrer le nombre d'frequence de chaque lettre dans le mot
	unsigned int frequenceMot[26] = { 0 };

	// Compte les frequence dans le mot
	for (unsigned int i = 0; i < strlen(mot); i++) {
		frequenceMot[mot[i] - 'A']++;
	}

	// Ajuste la main en fonction des frequence dans le mot
	for (unsigned int i = 0; i < nbCartes; i++) {
		char lettreCourante = partie.joueurs[ID].paquet[i].lettre;

		// Si la lettre est utilisée dans le mot, et qu'il reste des frequence à enlever
		if (frequenceMot[lettreCourante - 'A'] > 0) {
			frequenceMot[lettreCourante - 'A']--;

		}
		else {
			newTab[w] = lire(partie.joueurs[ID], i);
			w++;
		}
	}

	// Mettre à jour la main du joueur
	partie.joueurs[ID].nbCartes = w;

	for (unsigned int i = 0; i < w; i++) {
		ecrire(partie.joueurs[ID], i, newTab[i]);
	}
}






void comparer(const char* mot1, const char* mot2, char* mot3) {
	int frequenceMot1[26] = { 0 };

	// Compte les frequence dans le premier mot
	for (size_t i = 0; i < strlen(mot1); ++i) {
		frequenceMot1[mot1[i] - 'A']++;
	}

	// Soustrait les frequence du deuxième mot
	for (size_t i = 0; i < strlen(mot2); ++i) {
		frequenceMot1[mot2[i] - 'A']--;
	}

	// Construit le mot résultant avec les lettres restantes
	size_t w = 0;
	for (size_t i = 0; i < 26; ++i) {
		while (frequenceMot1[i] > 0) {
			mot3[w++] = 'A' + i;
			frequenceMot1[i]--;
		}
	}

	// Ajoute le caractère nul à la fin du mot résultant
	mot3[w] = '\0';
}



void ajMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]) {
	Pile essai;
	initialiser(essai, MAX_CARTES);
	creerJeu(essai);
	Carte carte;
	for (unsigned int w = 0; w < strlen(mot); w++) {

		for (unsigned int y = 0; y < MAX_CARTES; y++) {
			if (mot[w] == essai.tab[y].lettre) {
				carte.lettre = essai.tab[y].lettre;
				carte.valeur = essai.tab[y].valeur;
				ecrire(partie.joueurs[ID], partie.joueurs[ID].nbCartes, carte);
				break;
			}
		}
	}

}

bool estEnOrdre(const char* mot1, const char* mot2) {


	int j = 0;

	for (int i = 0; i < strlen(mot1); ++i) {
		char lettreC = mot1[i];

		while (j < strlen(mot2) && mot2[j] != lettreC) {
			j++;
		}

		if (j == strlen(mot2)) {
			return false;
		}

		j++;
	}

	return true;
}

