/*  Fichier     : main.c
    Description : Point d'entr�e
    Auteur      : Matthieu Carteron
*/

#include <stdlib.h>
#include <stdio.h>

#include "menu.h"
#include "donnees.h"
#include "actions.h"

int main(void)
{
    // D�claration des variables :
    Data* listData;             // Liste cha�n�e contenant l'ensemble des donn�es dans la m�moire
    ActionType type;            // Type d'action demand� par l'utilisateur
    unsigned long time[2];      // Les param�tres suppl�mentaires requis pour certaines actions

    listData = readData();      // Lecture du fichier .csv

    // Boucle d'action :
    do
    {
        get_type(&type);        // Demande du type d'action � effectuer

        // Ex�cution de l'action choisie :
        switch (type)
        {
            case ACT_DISPLAY        : printf("\n"); action_display(listData); break;
            case ACT_DISPLAY_SORTED : printf("\n"); action_displaysorted(listData); break;
            case ACT_DISPLAY_SIZE   : printf("\n"); action_displaysize(listData); break;
            case ACT_SEARCH_TIME    :

                get_time(&time[0]);

                printf("\n");
                action_search(listData, time[0]);

                break;
            case ACT_AVERAGE        :

                get_timemin(&time[0]);
                get_timemax(&time[1]);

                printf("\n");
                action_average(listData, time[0], time[1]);

                break;
            case ACT_GEOMAVERAGE    :

                get_timemin(&time[0]);
                get_timemax(&time[1]);

                printf("\n");
                action_geomaverage(listData, time[0], time[1]);

                break;
            case ACT_MINIMUM        :

                get_timemin(&time[0]);
                get_timemax(&time[1]);

                printf("\n");
                action_minimum(listData, time[0], time[1]);

                break;
            case ACT_MAXIMUM        :

                get_timemin(&time[0]);
                get_timemax(&time[1]);

                printf("\n");
                action_maximum(listData, time[0], time[1]);

                break;
            default                 : break;
        }
    } while (type != ACT_QUIT);

    list_free(listData);

    return 0;
}
