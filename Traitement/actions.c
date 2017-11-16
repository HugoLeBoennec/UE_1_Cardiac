/*  Fichier     : actions.c
    Description : Fonctions permettant le traitement des donn�es
    Auteur      : Matthieu Carteron
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "actions.h"

// Permet de trier les donn�es en fonction de leur pouls :
void sort(Data** tab, unsigned int n)
{
    unsigned int i, k, min;
    Data* tmp;

    for (i = 0; i < n-1; i++)
    {
        min = i;

        for (k = i+1; k < n; k++)
        {
            if (tab[k]->pouls < tab[min]->pouls)
                min = k;
        }

        tmp = tab[i];
        tab[i] = tab[min];
        tab[min] = tmp;
    }
}

// Permet de calculer la racine n-i�me :
double root(double a, double x, int n, int i)
{
    if (i > 0)
        return root(a, (1.0f / n) * ((n - 1.0f)*x + (a / pow(x, n-1))), n, i-1);

    return x;
}

// Permet d'afficher les donn�es brutes :
void action_display(Data* list)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste

    while (iterator != NULL)
    {
        printf("%ld ms  -  %.4lf pulsations/min\n", iterator->time, iterator->pouls);
        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("\n\n");
}

// Permet d'afficher les donn�es tri�es :
void action_displaysorted(Data* list)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste

    Data** sorted;                  // Un tableau repr�sentant une version tri�e de la liste

    unsigned int n = 0;             // Le compteur du nombre d'�lements
    unsigned int i = 0;             // L'it�rateur permettant de parcourir les tableaux

    // On commence par initialiser les tableaux de pointeurs d'�lements :
    while (iterator != NULL)
    {
        n++;
        iterator = iterator->next;  // On it�re vers la position suivante
    }

    sorted = malloc(sizeof(Data*) * n);

    // Ensuite, on remplit le tableau :
    iterator = list;

    while (iterator != NULL)
    {
        sorted[i] = iterator;
        iterator = iterator->next;  // On it�re vers la position suivante

        i++;
    }

    // On trie ce tableau :
    sort(sorted, n);

    // Enfin, on affiche les valeurs tri�es :
    for (i = 0; i < n; i++)
        printf("%.4lf pulsations/min  -  a %ld ms\n", sorted[i]->pouls, sorted[i]->time);

    printf("\n\n");

    // On lib�re la m�moire des tableaux :
    free(sorted);
}

// Permet d'afficher le nombre total d'�lements de la liste :
void action_displaysize(Data* list)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste
    unsigned int n = 0;             // Le compteur du nombre d'�lements

    while (iterator != NULL)
    {
        n++;
        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("Nombre de donnees : %d\n\n\n", n);
}

// Permet d'afficher une valeur de pouls pour un temps donn� :
void action_search(Data* list, unsigned long time)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste
    double pouls = 0.0d;             // La valeur du pouls actuel

    while (iterator != NULL)
    {
        // Lorsque la donn�e date du temps pass� celui de la recherche, on arr�te :
        if (iterator->time > time)
            break;

        pouls = iterator->pouls;      // On r�cup�re la valeur de pouls
        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("A %ld ms  -  pouls : %.4lf\n\n\n", time, pouls);
}

// Permet d'afficher le pouls moyen arithm�tique entre les temps "start" et "end" :
void action_average(Data* list, unsigned long start, unsigned long end)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste

    double sum = 0.0d;              // La somme des pouls
    unsigned int n = 0;             // Le compteur du nombre d'�lements

    // On positionne l'it�rateur au temps "start" :
    while (iterator != NULL)
    {
        if (iterator->time > start)
            break;

        iterator = iterator->next;
    }

    // On parcourt la liste jusqu'au temps "end" :
    while (iterator != NULL)
    {
        if (iterator->time > end)
            break;

        sum += iterator->pouls;
        n++;

        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("Entre %ld ms et %ld ms  -  pouls moyen : %.4lf\n\n\n", start, end, sum / n);
}

// Permet d'afficher le pouls moyen g�om�trique entre les temps "start" et "end" :
void action_geomaverage(Data* list, unsigned long start, unsigned long end)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste

    double product = 1.0d;          // Le produit des pouls
    unsigned int n = 0;             // Le compteur du nombre d'�lements

    // On positionne l'it�rateur au temps "start" :
    while (iterator != NULL)
    {
        if (iterator->time > start)
            break;

        iterator = iterator->next;
    }

    // On parcourt la liste jusqu'au temps "end" :
    while (iterator != NULL)
    {
        if (iterator->time > end)
            break;

        product *= iterator->pouls;
        n++;

        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("Entre %ld ms et %ld ms  -  pouls moyen : %.4lf\n\n\n", start, end, root(product, product / (n * 2.0d), n, 1000));
}

void action_minimum(Data* list, unsigned long start, unsigned long end)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste
    double min = iterator->pouls;    // La valeur minimale actuelle

    // On positionne l'it�rateur au temps "start" :
    while (iterator != NULL)
    {
        if (iterator->time > start)
            break;

        iterator = iterator->next;
    }

    // On parcourt la liste jusqu'au temps "end" :
    while (iterator != NULL)
    {
        // Si la valeur de pouls est plus petite que la valeur minimale actuelle, on la remplace :
        if (iterator->pouls < min)
            min = iterator->pouls;

        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("Entre %ld ms et %ld ms  -  pouls minimal : %.4lf\n\n\n", start, end, min);
}

void action_maximum(Data* list, unsigned long start, unsigned long end)
{
    Data* iterator = list;          // Un pointeur pour it�rer au travers de la liste
    double max = 0.0d;              // La valeur minimale actuelle

    // On positionne l'it�rateur au temps "start" :
    while (iterator != NULL)
    {
        if (iterator->time > start)
            break;

        iterator = iterator->next;
    }

    // On parcourt la liste jusqu'au temps "end" :
    while (iterator != NULL)
    {
        // Si la valeur de pouls est plus petite que la valeur minimale actuelle, on la remplace :
        if (iterator->pouls > max)
            max = iterator->pouls;

        iterator = iterator->next;  // On it�re vers la position suivante
    }

    printf("Entre %ld ms et %ld ms  -  pouls maximal : %.4lf\n\n\n", start, end, max);
}
