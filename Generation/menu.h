/*  Fichier     : menu.h
    Description : Fonctions permettant l'affichage du menu pour la cr�ation du param.h
    Auteur      : Matthieu Carteron
*/

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

// D�claration du type d'affichage :
typedef enum FlickerType
{
    TYPE_ALL_LEDS,          // Clignotement de l'ensemble des LED en rythme avec les pulsations
    TYPE_ALL_LEDS_PLUS,     // Clignotement de l'ensemble des LED d'un seul coup
    TYPE_1LED_OVER2,        // Clignotement d'une LED sur deux en rythme avec les pulsations
    TYPE_1LED_OVER3,        // Clignotement d'une LED sur trois en rythme avec les pulsations
    TYPE_1LED,              // Clignotement d'une LED sp�cifi�e
    TYPE_CHAIN,             // Allumage � la cha�ne (mode chenille)
    TYPE_CHAIN_PLUS,        // Allumage � la cha�ne d'un seul coup (mode chenille)
    TYPE_BATTEMENT          // Allumage de bas en haut � chaque pulsation
} FlickerType;

// D�clarations des fonctions :
void get_flickertype(FlickerType* type);
void get_lednumber(unsigned short* param);

#endif // MENU_H_INCLUDED
