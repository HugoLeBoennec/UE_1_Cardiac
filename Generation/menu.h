/*  Fichier     : menu.h
    Description : Fonctions permettant l'affichage du menu pour la création du param.h
    Auteur      : Matthieu Carteron
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// Déclaration du type d'affichage :
typedef enum FlickerType
{
    TYPE_ALL_LEDS,          // Clignotement de l'ensemble des LED en rythme avec les pulsations
    TYPE_ALL_LEDS_PLUS,     // Clignotement de l'ensemble des LED d'un seul coup
    TYPE_1LED_OVER2,        // Clignotement d'une LED sur deux en rythme avec les pulsations
    TYPE_1LED_OVER3,        // Clignotement d'une LED sur trois en rythme avec les pulsations
    TYPE_1LED,              // Clignotement d'une LED spécifiée
    TYPE_CHAIN,             // Allumage à la chaîne (mode chenille)
    TYPE_CHAIN_PLUS,        // Allumage à la chaîne d'un seul coup (mode chenille)
    TYPE_BATTEMENT          // Allumage de bas en haut à chaque pulsation
} FlickerType;

// Déclarations des fonctions :
void get_flickertype(FlickerType* type);
void get_lednumber(unsigned short* param);

#endif // MENU_H_INCLUDED
