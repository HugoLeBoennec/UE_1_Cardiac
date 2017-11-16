/*  Fichier     : actions.h
    Description : Fonctions permettant le traitement des donn�es
    Auteur      : Matthieu Carteron
*/

#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include "donnees.h"

// D�claration du type d'action :
typedef enum ActionType
{
    ACT_QUIT,               // Quitte le programme
    ACT_DISPLAY,            // Affichage des donn�es brutes
    ACT_DISPLAY_SORTED,     // Affichage des donn�es tri�es
    ACT_DISPLAY_SIZE,       // Affiche le nombre total de lignes de donn�es dans la m�moire
    ACT_SEARCH_TIME,        // Rechercher le pouls pour un temps donn�
    ACT_AVERAGE,            // Calculer le pouls moyen arithm�tique dans un intervalle de temps donn�e
    ACT_GEOMAVERAGE,        // Calculer le pouls moyen g�om�trique dans un intervalle de temps donn�e
    ACT_MINIMUM,            // Affiche le pouls minimum et son temps
    ACT_MAXIMUM             // Affiche le pouls maximum et son temps
} ActionType;

void action_display(Data* list);
void action_displaysorted(Data* list);
void action_displaysize(Data* list);

void action_search(Data* list, unsigned long time);

void action_average(Data* list, unsigned long start, unsigned long end);
void action_geomaverage(Data* list, unsigned long start, unsigned long end);

void action_minimum(Data* list, unsigned long start, unsigned long end);
void action_maximum(Data* list, unsigned long start, unsigned long end);

#endif // ACTIONS_H_INCLUDED
