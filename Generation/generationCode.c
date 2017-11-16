/*  Fichier     : generationCode.c
    Description : Fonctions nécessaires pour la génération de param.h
    Auteur      : Matthieu Carteron
*/

#include <stdlib.h>
#include <stdio.h>
#include "generationCode.h"

// Déclare une macro correspondant au nom du fichier à génerer :
#define FICHIER "param.h"

// Permet de génerer le fichier :
void write_paramfiles(FlickerType type, unsigned short param)
{
    FILE* file = fopen(FICHIER, "w");

    // Vérification des erreurs :
    if (file == NULL)
    {
        printf("Erreur ! Impossible d'ouvrir le fichier !");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "/*  Ce fichier a ete genere par le programme de generation.\n\
    */\n\n\
    #ifndef PARAM_INCLUDED\n\
    #define PARAM_INCLUDED\n\n");

    switch (type)
    {
        case TYPE_ALL_LEDS      : fprintf(file, "#define MODE_CLIGNOTEMENT\n\n"); break;
        case TYPE_ALL_LEDS_PLUS : fprintf(file, "#define MODE_CLIGNOTEMENTP\n\n"); break;
        case TYPE_1LED_OVER2    : fprintf(file, "#define MODE_LED2\n\n"); break;
        case TYPE_1LED_OVER3    : fprintf(file, "#define MODE_LED3\n\n"); break;
        case TYPE_CHAIN         : fprintf(file, "#define MODE_CHENILLE\n\n"); break;
        case TYPE_CHAIN_PLUS    : fprintf(file, "#define MODE_CHENILLEP\n\n"); break;
        case TYPE_BATTEMENT     : fprintf(file, "#define MODE_BATTEMENT\n\n"); break;
        case TYPE_1LED          :
            fprintf(file, "#define MODE_LED1\n");
            fprintf(file, "#define LED_NUMBER %hd\n\n", param);
            break;
    }

    fprintf(file, "#endif\n");

    // On ferme le fichier :
    fclose(file);
}
