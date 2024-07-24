#include <cassert>

#include "paquet.h"

/**
 * @file paquet.cpp
 * @brief Composant d'un conteneur d'items de capacité statique (connue à la compilation).
 */

void initialiser(ConteneurTS& c) {
	c.nbCartes = 0;
}

Item lire(const ConteneurTS& c, unsigned int i) {
	assert(i < c.nbCartes);//S'assurer que i représente un indice que l'on peut lire
	return c.paquet[i];//Lire la valeur stocké à l'indice i du paquet
}

void ecrire(ConteneurTS& c, unsigned int i, const Item& item) {
	assert(i <= c.nbCartes && i < ConteneurTS::CAPACITE);
	c.paquet[i] = item;//ecrire l'item à l'indice i du paquet
	if (i == c.nbCartes)//si l'indice vaut le nombre de carte
		c.nbCartes++;//incrémenter le nombre de carte
}