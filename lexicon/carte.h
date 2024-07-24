#pragma once

enum{LETTRES=26};//Constantes qui contien le nombre de lettres de l'alphabet
enum { MAX_CARTE = 51 };//
/** @brief Une carte est défini par sa lettre et
 *   sa valeur en points(qui ne peut etre négative)
 */
struct Carte{
    char lettre;
    unsigned int valeur;
};



/** @brief Mélange un paquet de carte en interverssant aléatoirement les positions
 *@param[in]  carte La Carte
 */
void melanger(Carte*& paquet, const unsigned int taille);

