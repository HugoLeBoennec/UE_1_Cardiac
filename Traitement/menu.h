/*  Fichier     : menu.h
    Description : Fonctions permettant l'affichage du menu
    Auteur      : Matthieu Carteron
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "actions.h"

// Déclarations des fonctions :
void get_type(ActionType* type);

void get_time(unsigned long* time);
void get_timemin(unsigned long* time);
void get_timemax(unsigned long* time);

#endif // MENU_H_INCLUDED
