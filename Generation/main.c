/*  Fichier     : main.c
    Description : Point d'entr�e et affichage du menu console
    Auteur      : Matthieu Carteron
*/

#include "menu.h"
#include "generationCode.h"

int main(void)
{
    // D�claration des variables :
    FlickerType type;           // Le type saisi par l'utilisateur
    unsigned short param = 0;   // Le param�tre optionel � passer

    get_flickertype(&type);

    // Si le type demande un param�tre suppl�mentaire :
    if (type == TYPE_1LED)
        get_lednumber(&param);

    // On �crit le fichier "param.h" :
    write_paramfiles(type, param);

    return 0;
}
