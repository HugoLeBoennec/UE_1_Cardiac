/*  Fichier     : donnees.c
    Description : Fonctions permettant la manipulation des données et leur lecture
    Auteur      : Matthieu Carteron
*/

#include <stdlib.h>
#include <stdio.h>
#include "donnees.h"

// Déclare une macro correspondant au nom du fichier à lire :
#define FICHIER "data.csv"

// Permet de lire le fichier :
Data* readData()
{
    Data* list = NULL;          // La liste qui contiendra les données
    FILE* file = fopen(FICHIER, "r");

    // Déclaration des variables permettant de créer les structure composant la liste :
    unsigned long time;
    double pouls;

    // Vérification des erreurs :
    if (file == NULL)
    {
        printf("Erreur ! Impossible d'ouvrir le fichier !");
        exit(EXIT_FAILURE);
    }

    // On lit le fichier et ajoute les structures dans la liste chaînée :
    while (fscanf(file, "%ld;%lf;", &time, &pouls) > 0)
    {
        if (list == NULL)   // Si la liste n'est pas encore initialisée, on la créé
            list = list_create(time, pouls);
        else                // Sinon, on ajoute à la suite les données :
            list_add(list, time, pouls);
    }

    fclose(file);

    return list;
}

// Permet d'initialiser le premier élement de la liste :
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

// Permet d'ajouter un élement dans la liste chaînée :
void list_add(Data* list, unsigned long time, double pouls)
{
    Data* iterator = list;     // Un pointeur pour itérer au travers de la liste

    // On se positionne à la fin de la liste chaînée :
    while (iterator->next != NULL)
        iterator = iterator->next;

    // On créé l'élement :
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

// Permet de libérer la mémoire :
void list_free(Data* list)
{
    Data* iterator = list;      // Un pointeur pour itérer au travers de la liste

    while (iterator->next != NULL)
    {
        Data* tmp = iterator;   // On garde temporairement une réference sur l'élement afin de le libérer

        iterator = list->next;  // On itère vers la position suivante

        free(tmp);
    }

    free(iterator);
}
