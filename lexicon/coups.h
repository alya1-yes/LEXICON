#pragma once

#include "Jeu.h"
/**
 * @brief Tirer une carte du talon et l'expose en remplaçant une carte de la main du joueur.
 * @param[in,out] partie,la partie en cours.
 * @param[in,out] talon
 * @param[in,out] expose, les cartes exposees.
 * @param[in] ID L'identifiant du joueur
 * @param[in,out] numTour numéro de tour actuel
 *
 */
void Talon(Partie& partie, Pile& talonT, Pile& expose, unsigned int ID, unsigned int& numTour);


/**
 * @brief Pose un mot entièrement créé par le joueur.
 * Cette fonction gère le dépot du mot d'un joueur .
 * Le joueur saisit un mot, et la fonction effectue les vérifications nécessaires
 * pour valider ou non le dépot.
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur .
 * @param[in] dico Flux de fichier texte représentant le dictionnaire français.
 * @param[in,out] numTour, numéro du tour.
 *
 * @note Cette fonction utilise la fonction dansMain pour vérifier si le mot est dans la main du joueur,
 *       et la fonction existe pour vérifier si le mot existe dans le dictionnaire.
 */

void poser(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);
/**
 * @brief Exposer une carte en remplaçant une carte de la main du joueur.
 * @param[in,out] partie, la partie en cours.
 * @param[in,out] Les cartes exposees.
 * @param[in] ID L'identifiant du joueur
 * @param[in,out] numTour numéro de tour actuel
 *
 */
void exposee(Partie& partie, Pile& expose, unsigned int ID, unsigned int& numTour);
/**
 * @brief Remplace un mot existant avec un nouveau mot en utilisant les lettres de la main du joueur.
 *
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in] dico Flux de fichier texte représentant le dictionnaire français.
 * @param[in,out] numTour numéro du tour
 *
 */
void remplacer(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);

/**
 * @brief Complète un mot existant avec des lettres de la main du joueur.
 *
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in] dico Flux de fichier texte représentant le dictionnaire français.
 * @param[in,out] numTour numéro du tour
 */
void compléter(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);

