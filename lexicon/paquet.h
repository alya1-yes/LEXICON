#pragma once

/**
 * @file paquet.h
 * @brief Composant d'un conteneur d'items de capacit� statique (connue � la compilation).
 */

#include "Item.h"

/** @brief Conteneur (de capacit� 15) g�n�ralis� � tout type d'item. */
struct ConteneurTS {//On utilisera surtout cette structure pour repr�senter les joueurs
	unsigned int ID;
	unsigned int nbCartes;
	static const unsigned int CAPACITE = 10;
	Item paquet[CAPACITE];//Repr�sente son paquet de carte(les items)	 
	unsigned int score;
	
};
//Un joueur est d�fini par son nombre de carte,son score et son identifiant et son paquet

/**
 * @brief Initialiser � vide un conteneur.
 * @param[out] c Le conteneur devant �tre initialis�.
 */
void initialiser(ConteneurTS& c);

/**
 * @brief R�cup�rer un item �tant stock� dans un conteneur.
 * @param[in] c Le conteneur devant �tre lu.
 * @param[in] i L'indice de l'item dans le conteneur.
 * @return L'item se trouvant � l'indice i dans c.
 * @pre i doit �tre strictement inf�rieur au nombre d'items d�j� stock�s.
 */
Item lire(const ConteneurTS& c, unsigned int i);

/**
 * @brief Stocker un item dans un conteneur.
 * @param[in,out] c Le conteneur o� stocker l'item.
 * @param[in] i L'indice o� �crire l'item.
 * @param[in] item L'item devant �tre stock�.
 * @pre L'indice i doit d�signer soit une case d�j� occup�e (et celle-ci sera mise � jour),
 * soit la premi�re case libre (et le conteneur contiendra un item de plus). Dans ce second
 * cas, La capacit� du conteneur ne doit pas �tre d�pass�e.
 */
void ecrire(ConteneurTS& c, unsigned int i, const Item& item);
