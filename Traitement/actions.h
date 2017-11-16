/*  Fichier     : actions.h
    Description : Fonctions permettant le traitement des données
    Auteur      : Matthieu Carteron
*/

#ifndef ACTIONS_H_INCLUDED
#define ACTIONS_H_INCLUDED

#include "donnees.h"

// Déclaration du type d'action :
typedef enum ActionType
{
    ACT_QUIT,               // Quitte le programme
    ACT_DISPLAY,            // Affichage des données brutes
    ACT_DISPLAY_SORTED,     // Affichage des données triées
    ACT_DISPLAY_SIZE,       // Affiche le nombre total de lignes de données dans la mémoire
    ACT_SEARCH_TIME,        // Rechercher le pouls pour un temps donné
    ACT_AVERAGE,            // Calculer le pouls moyen arithmétique dans un intervalle de temps donnée
    ACT_GEOMAVERAGE,        // Calculer le pouls moyen géométrique dans un intervalle de temps donnée
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
