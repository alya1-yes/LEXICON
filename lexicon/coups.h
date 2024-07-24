#pragma once

#include "Jeu.h"
/**
 * @brief Tirer une carte du talon et l'expose en rempla�ant une carte de la main du joueur.
 * @param[in,out] partie,la partie en cours.
 * @param[in,out] talon
 * @param[in,out] expose, les cartes exposees.
 * @param[in] ID L'identifiant du joueur
 * @param[in,out] numTour num�ro de tour actuel
 *
 */
void Talon(Partie& partie, Pile& talonT, Pile& expose, unsigned int ID, unsigned int& numTour);


/**
 * @brief Pose un mot enti�rement cr�� par le joueur.
 * Cette fonction g�re le d�pot du mot d'un joueur .
 * Le joueur saisit un mot, et la fonction effectue les v�rifications n�cessaires
 * pour valider ou non le d�pot.
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur .
 * @param[in] dico Flux de fichier texte repr�sentant le dictionnaire fran�ais.
 * @param[in,out] numTour, num�ro du tour.
 *
 * @note Cette fonction utilise la fonction dansMain pour v�rifier si le mot est dans la main du joueur,
 *       et la fonction existe pour v�rifier si le mot existe dans le dictionnaire.
 */

void poser(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);
/**
 * @brief Exposer une carte en rempla�ant une carte de la main du joueur.
 * @param[in,out] partie, la partie en cours.
 * @param[in,out] Les cartes exposees.
 * @param[in] ID L'identifiant du joueur
 * @param[in,out] numTour num�ro de tour actuel
 *
 */
void exposee(Partie& partie, Pile& expose, unsigned int ID, unsigned int& numTour);
/**
 * @brief Remplace un mot existant avec un nouveau mot en utilisant les lettres de la main du joueur.
 *
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in] dico Flux de fichier texte repr�sentant le dictionnaire fran�ais.
 * @param[in,out] numTour num�ro du tour
 *
 */
void remplacer(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);

/**
 * @brief Compl�te un mot existant avec des lettres de la main du joueur.
 *
 * @param[in,out] partie en cours.
 * @param[in] ID L'identifiant du joueur
 * @param[in] dico Flux de fichier texte repr�sentant le dictionnaire fran�ais.
 * @param[in,out] numTour num�ro du tour
 */
void compl�ter(Partie& partie, unsigned int ID, ifstream& dico, unsigned int& numTour);

