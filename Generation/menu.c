/*  Fichier     : menu.c
    Description : Fonctions permettant l'affichage du menu pour la création du param.h
    Auteur      : Matthieu Carteron
*/

#include <stdio.h>
#include "menu.h"

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) > (b)) ? (a) : (b))

// Permet de demander le type :
void get_flickertype(FlickerType* type)
{
    printf( "Veuillez entrer le type d'affichage desire parmis ceux ci-dessous :\n\
            0 : Clignotement de toutes les LED\n\
            1 : Clignotement de toutes les LED d'un seul coup\n\
            2 : Clignotement d'une LED sur deux\n\
            3 : Clignotement d'une LED sur trois\n\
            4 : Clignotement d'une LED (specifiable par parametre)\n\
            5 : Allumage en mode \"Chenille\"\n\n\
            6 : Allumage en mode \"Chenille\" d'un seul coup\n\n\
            7 : Allumage de haut en bas\n\n\
            Entrez le nombre : ");

    scanf("%d", (int*)type);
}

// Permet de demander le numéro de la LED à allumer (paramètre supplémentaire) :
void get_lednumber(unsigned short* param)
{
    printf("Veuillez entrer le numero de LED : ");
    scanf("%hd", param);

    *param = min(max(*param, 1), 10);

    // Le port 1 étant un "port cavalier" on préfère la brancher sur le port 11 :
    if (*param == 1)
        *param = 11;
}
