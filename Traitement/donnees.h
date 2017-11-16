/*  Fichier     : donnees.h
    Description : Fonctions permettant la manipulation des donn�es et leur lecture
    Auteur      : Matthieu Carteron
*/

#ifndef DONNEES_H_INCLUDED
#define DONNEES_H_INCLUDED

// D�claration des structures de donn�es :
typedef struct Data
{
    unsigned long time;     // Le temps en millisecondes depuis le d�but de l'ex�cution
    double pouls;            // La fr�quence cardiaque mesur�e

    struct Data* next;      // Le prochain �lement dans la liste cha�n�e
} Data;

Data* list_create(unsigned long time, double pouls);
void list_add(Data* list, unsigned long time, double pouls);
void list_free(Data* list);

Data* readData();

#endif // DONNEES_H_INCLUDED
