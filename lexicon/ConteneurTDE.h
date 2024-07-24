#pragma once

/**
 * @file ConteneurTDE.h
 * @brief Composant d'un conteneur d'items de capacit� extensible.
 */

#include "Item.h"

/** @brief Conteneur d'items allou�s en m�moire dynamique
 *  de capacit� extensible suivant un pas d'extension.
 */ 
struct ConteneurTDE {
	/// Capacit� du conteneur (>0).
    unsigned int capacite; 	   
	/// Pas d'extension du conteneur (>0).
	unsigned int pasExtension; 
	/// Conteneur allou� en m�moire dynamique.
	Item* tab;				   
};

/**
 * @brief Initialise un conteneur d'items.
 * Allocation en m�moire dynamique du conteneur d'items
 * de capacit� (capa) extensible par pas d'extension (p).
 * @see detruire, pour sa d�sallocation en fin d'utilisation. 
 * @param[out] c Le conteneur d'items.
 * @param [in] capa Capacit� du conteneur.
 * @param [in] p Pas d'extension de capacit�.
 * @pre capa > 0 et p > 0.
 */
void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p);

/**
 * @brief D�salloue un conteneur d'items en m�moire dynamique.
 * @see initialiser. 
 * @param[in,out] c Le conteneur d'items.
 */
void detruire(ConteneurTDE& c); 

/**
 * @brief Lecture d'un item d'un conteneur d'items.
 * @param[in] c Le conteneur d'items.
 * @param[in] i La position de l'item dans le conteneur.
 * @return L'item � la position i.
 * @pre i < c.capacite
 */
 Item lire(const ConteneurTDE& c, unsigned int i);

/**
 * @brief Ecrire un item dans un conteneur d'items.
 * @param[in,out] c Le conteneur d'items.
 * @param[in] i La position o� ajouter/modifier l'item.
 * @param[in] it L'item � �crire.
 */
void ecrire(ConteneurTDE& c, unsigned int i, const Item& it);
