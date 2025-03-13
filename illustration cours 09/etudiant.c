//
// Created by stephane on 13/03/25.
//
#include "etudiant.h"
#include <stdlib.h>

//  Structure pour un etudiant
struct s_etudiant {
    char *nom;
    char *prenom;
    int note;
};

//  Definitions des fonctions publiques
//  -----------------------------------
t_etudiant *t_etudiant_new() {
    //  allocation dynamique d'une zone de la taille d'un etudiant dans le tas (pas la pile !)
    return malloc(sizeof(t_etudiant));
}

void t_etudiant_set_note(t_etudiant *etu, int note) {
    //  verification de la validite de la note
    if (note >= 0 && note <= 100) {
        (*etu).note = note;
        etu->note = note;
    }
}