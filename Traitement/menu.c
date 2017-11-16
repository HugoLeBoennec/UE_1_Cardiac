/*  Fichier     : menu.c
    Description : Fonctions permettant l'affichage du menu
    Auteur      : Matthieu Carteron
*/

#include <stdio.h>
#include "menu.h"

// Permet de demander l'action à effectuer :
void get_type(ActionType* type)
{
    printf( "Veuillez entrer l'action a effectuer parmis celles ci-dessous :\n\
            0 : Quitter le programme\n\
            1 : Afficher les donnees brutes\n\
            2 : Afficher les donnees triees\n\
            3 : Afficher le nombre de donnees\n\
            4 : Rechercher le pouls a un temps particulier\n\
            5 : Calculer le pouls moyen arithmetique dans un intervalle\n\
            6 : Calculer le pouls moyen geometrique dans un intervalle\n\
            7 : Afficher le pouls minimal dans un intervalle\n\
            8 : Afficher le pouls maximal dans un intervalle\n\n\
            Entrez le nombre : ");

    scanf("%hd", (short*)type);
}

void get_time(unsigned long* time)
{
    printf("            Veuillez entrer le temps : ");
    scanf("%ld", time);
}

void get_timemin(unsigned long* time)
{
    printf("            Veuillez entrer le temps constituant la borne de minimum l'intervalle : ");
    scanf("%ld", time);
}

void get_timemax(unsigned long* time)
{
    printf("            Veuillez entrer le temps constituant la borne de maximum l'intervalle : ");
    scanf("%ld", time);
}
