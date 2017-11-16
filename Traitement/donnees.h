/*  Fichier     : donnees.h
    Description : Fonctions permettant la manipulation des données et leur lecture
    Auteur      : Matthieu Carteron
*/

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

// Déclaration des structures de données :
typedef struct Data
{
    unsigned long time;     // Le temps en millisecondes depuis le début de l'exécution
    double pouls;            // La fréquence cardiaque mesurée

    struct Data* next;      // Le prochain élement dans la liste chaînée
} Data;

Data* list_create(unsigned long time, double pouls);
void list_add(Data* list, unsigned long time, double pouls);
void list_free(Data* list);

Data* readData();

#endif // DONNEES_H_INCLUDED
