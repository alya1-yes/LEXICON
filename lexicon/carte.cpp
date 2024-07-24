#include<iostream>
#include<cassert>
#include<ctime>
using namespace std;
#include "carte.h"

void melanger(Carte*& paquet, unsigned int taille) {
    srand(time(0));
    unsigned int pos;
    for (unsigned int i = taille; i >= 2; i--) {
        pos = rand() % i;
        Carte tmp = paquet[i - 1];//Intevertir les cartes
        paquet[i - 1] = paquet[pos];
        paquet[pos] = tmp;
    }
}

