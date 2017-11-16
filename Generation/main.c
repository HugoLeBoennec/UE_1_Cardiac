/*  Fichier     : main.c
    Description : Point d'entrée et affichage du menu console
    Auteur      : Matthieu Carteron
*/

#include "menu.h"
#include "generationCode.h"

int main(void)
{
    // Déclaration des variables :
    FlickerType type;           // Le type saisi par l'utilisateur
    unsigned short param = 0;   // Le paramètre optionel à passer

    get_flickertype(&type);

    // Si le type demande un paramètre supplémentaire :
    if (type == TYPE_1LED)
        get_lednumber(&param);

    // On écrit le fichier "param.h" :
    write_paramfiles(type, param);

    return 0;
}
