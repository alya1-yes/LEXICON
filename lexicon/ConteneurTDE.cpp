#include <iostream>
#include <cassert>
using namespace std;

#include "ConteneurTDE.h"

void initialiser(ConteneurTDE& c, unsigned int capa, unsigned int p) {
	assert((capa > 0) && (p > 0));//S'assurer que la capacité et le pas d'éxtension soient strictement positif
	c.capacite = capa;//attribuer cette valeur comme capacité du conteneur
	c.pasExtension = p;//Attribuer le pas
	c.tab = new Item[capa];
}

void detruire(ConteneurTDE& c) {//Meme principe que pour le conteneur TDE
	delete[] c.tab;
	c.tab = NULL;
}

Item lire(const ConteneurTDE& c, unsigned int i) {//Meme principe que pour le conteneur TDE
	assert(i < c.capacite);
	return c.tab[i];
}

void ecrire(ConteneurTDE& c, unsigned int i, const Item& it) {
	if (i >= c.capacite) {//Si l'indice est supérieur ou égale à la capacité
		unsigned int newTaille = (i + 1) * c.pasExtension;
		Item* newT = new Item[newTaille];
		for (unsigned int i = 0; i < c.capacite; ++i)
			newT[i] = c.tab[i];
		delete[] c.tab;
		c.tab = newT;
		c.capacite = newTaille;//Etendre le conteneur et y ecrire l'item
	}
	c.tab[i] = it;
}
