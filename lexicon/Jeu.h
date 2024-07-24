#pragma once
#include "Pile.h"
#include"paquet.h"


enum { CHARAMAX = 50, MAXPOINTS = 100 };//Constantes: format maximum d'un mot,maximum de points atteignable

/*Une partie est représenté par son nombre de joueur
*Les joueurs en question
* Les différents mots qui seront posé sur la table
* Le nombre de mot sur la table
*/
struct Partie {
	unsigned int NbJoueurs;
	ConteneurTS* joueurs;
	//Mots sur la table
	char* mots[CHARAMAX];
	unsigned int nbMots;
};


/**
 * @brief Initialise une partie
 * @param[in,out] partie  à initialiser.
 * @param[in] nbJoueurs Le nombre de joueurs participant à la partie.
 * @param[in] joueurs Un tableau de conteneurs de lettres représentant les mains des joueurs.
 */
void initialiser(Partie& partie, unsigned int nbJoueurs, ConteneurTS*& joueurs);


/**
 * @brief Libère la mémoire allouée dynamiquement pour une partie.
 * @param[in,out] partie, partie à détruire.
 */
void detruire(Partie& partie);


/**
 * @brief Crée un jeu de cartes Lexicon
 * @param[out] p La pile à initialiser avec le jeu de cartes.
 * @note La fonction utilise un tableau constant de cartes `paquet` pour créer le jeu.
 *       Chaque carte est ensuite empilée sur la pile.
 */
void creerJeu(Pile& p);

/**
 * @brief Distribue aux joueurs le nombre initial
 * @param[out] p La pile
 * @param[out] j Le tableau de joueurs
 * @param[in] nbJoueurs le nombre de joueurs
*/
void distribuer(Pile& p, ConteneurTS*& j, const unsigned int nbJoueurs);

/**
 * @brief Vérifie si la manche est terminée en vérifiant le nombre de cartes restantes pour chaque joueur.
 * @param[in] partie, la partie en cours.
 *
 * @return Vrai si la manche est terminée, Faux  sinon.
 *
 */
bool finManche(Partie& partie);



/**
 * @brief Affiche sous forme de prompt l'etat actuelle de la partie :le numéro du joueur, sa main, les sur la table,
 * @param[in] ID joueur
 * @param[in] La carte expose
*/
void afficherPartie(Partie& partie, unsigned int ID, Pile& expose);




/*Structures de données et fonctions permettant l'implémentation et la vérification des mots*/
/*Ici, chaque mot est une liste chainée de cartes permettant ainsi, de plus facilement insérer une nouvelle carte entre 2*/



/**
*@brief Vérifie si un mot appartient à la langue française.
*
* Cette fonction compare le mot avec les mots présents dans le dictionnaire français,
*@param[in] mot Le mot que l'on souhaite vérifier.
* @param[in] dico Flux de fichier texte représentant le dictionnaire français.
*@return Vrai si le mot existe dans le dictionnaire français, faux sinon.
* @note Cette fonction utilise un flux de fichier(ifstream) représentant le dictionnaire français.
* Elle parcourt le dictionnaire mot par mot, comparant chaque mot avec le mot spécifié.
*/
bool existe(const char mot[CHARAMAX], ifstream& dico);


/**
 * @brief Vérifie si un mot peut être formé avec les lettres  d'un joueur.
 * Cette fonction vérifie si un mot peut être formé en utilisant les lettres disponibles dans la main du joueur spécifié.
 * @param[in] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in]  mot que l'on souhaite vérifier s'il peut être formé avec les lettres du joueur
 *
 * @return Vrai si le mot peut être formé avec les lettres disponibles dans la main du joueur, faux sinon.
 *
 */
bool dansMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]);



/**
 * @brief  Cette fonction actualise le paquet du joueur en suprimant les cartes qu'il a utilise
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in]  mot pour lequel les cartes doivent être supprimées de la main du joueur.
 */
void supMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]);


/**
 * @brief Ajoute les cartes  d'un mot à la main d'un joueur.
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in]  mot pour lequel les cartes doivent être ajouté de la main du joueur.
 */
void ajMain(Partie& partie, unsigned int ID, const char mot[CHARAMAX]);

/**
 * @brief Vérifie si les lettres d'un mot apparaissent dans le même ordre dans un autre mot.
 * @param[in] mot1 Le premier mot à comparer.
 * @param[in] mot2 Le deuxième mot à comparer.
 *
 * @return Vrai si les lettres du premier mot apparaissent dans le même ordre dans le deuxième mot, faux sinon.
 */
bool estEnOrdre(const char* mot1, const char* mot2);



/**
 * @brief Compare deux mots .
 * @param[in] mot1 Le premier mot à comparer.
 * @param[in] mot2 Le deuxième mot à comparer.
 * @param[out] mot3 Le mot résultat
 *
 */
void comparer(const char* mot, const char* motRemplacé, char* motLettresJoueurs);