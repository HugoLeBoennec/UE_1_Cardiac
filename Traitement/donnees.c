/*  Fichier     : donnees.c
    Description : Fonctions permettant la manipulation des donn�es et leur lecture
    Auteur      : Matthieu Carteron
*/

#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"

// D�clare une macro correspondant au nom du fichier � lire :
#define FICHIER "data.csv"

// Permet de lire le fichier :
Data* readData()
{
    Data* list = NULL;          // La liste qui contiendra les donn�es
    FILE* file = fopen(FICHIER, "r");

    // D�claration des variables permettant de cr�er les structure composant la liste :
    unsigned long time;
    double pouls;

    // V�rification des erreurs :
    if (file == NULL)
    {
        printf("Erreur ! Impossible d'ouvrir le fichier !");
        exit(EXIT_FAILURE);
    }

    // On lit le fichier et ajoute les structures dans la liste cha�n�e :
    while (fscanf(file, "%ld;%lf;", &time, &pouls) > 0)
    {
        if (list == NULL)   // Si la liste n'est pas encore initialis�e, on la cr��
            list = list_create(time, pouls);
        else                // Sinon, on ajoute � la suite les donn�es :
            list_add(list, time, pouls);
    }

    fclose(file);

    return list;
}

// Permet d'initialiser le premier �lement de la liste :
Data* list_create(unsigned long time, double pouls)
{
    Data* list = malloc(sizeof(Data));

    if (list == NULL)
    {
        printf("Erreur ! Impossible d'initialiser la liste !\n");
        exit(EXIT_FAILURE);
    }

    list->time = time;
    list->pouls = pouls;
    list->next = NULL;

    return list;
}

// Permet d'ajouter un �lement dans la liste cha�n�e :
void list_add(Data* list, unsigned long time, double pouls)
{
    Data* iterator = list;     // Un pointeur pour it�rer au travers de la liste

    // On se positionne � la fin de la liste cha�n�e :
    while (iterator->next != NULL)
        iterator = iterator->next;

    // On cr�� l'�lement :
    iterator->next = malloc(sizeof(Data));

    if (iterator->next == NULL)
    {
        printf("Erreur ! Impossible d'ajouter l'element !\n");
        exit(EXIT_FAILURE);
    }

    iterator->next->time = time;
    iterator->next->pouls = pouls;
    iterator->next->next = NULL;
}

// Permet de lib�rer la m�moire :
void list_free(Data* list)
{
    Data* iterator = list;      // Un pointeur pour it�rer au travers de la liste

    while (iterator->next != NULL)
    {
        Data* tmp = iterator;   // On garde temporairement une r�ference sur l'�lement afin de le lib�rer

        iterator = list->next;  // On it�re vers la position suivante

        free(tmp);
    }

    free(iterator);
}
