#include <cassert>

#include "paquet.h"

/**
 * @file paquet.cpp
 * @brief Composant d'un conteneur d'items de capacit� statique (connue � la compilation).
 */

void initialiser(ConteneurTS& c) {
	c.nbCartes = 0;
}

Item lire(const ConteneurTS& c, unsigned int i) {
	assert(i < c.nbCartes);//S'assurer que i repr�sente un indice que l'on peut lire
	return c.paquet[i];//Lire la valeur stock� � l'indice i du paquet
}

void ecrire(ConteneurTS& c, unsigned int i, const Item& item) {
	assert(i <= c.nbCartes && i < ConteneurTS::CAPACITE);
	c.paquet[i] = item;//ecrire l'item � l'indice i du paquet
	if (i == c.nbCartes)//si l'indice vaut le nombre de carte
		c.nbCartes++;//incr�menter le nombre de carte
}