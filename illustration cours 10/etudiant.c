//
// Created by stephane on 20/03/25.
//

#include "etudiant.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>

// Declaration de la structure privee
struct s_etudiant {
    unsigned int id;    //  4
    char *nom;          //  8
    double *notes;      //  8
    int nb_notes;       //  4
};                      //   = 24

// Definitions des fonctions publiques
t_etudiant *etudiant_creer_etudiant(unsigned int id, char *nom) {
    printf("sizeof(t_etudiant) = %d\n", sizeof(t_etudiant));

    t_etudiant *etu = malloc(sizeof(t_etudiant));
    assert(etu != NULL);

//    (*etu).id = id;
//    (*etu).notes = NULL;
//    (*etu).nb_notes = 0;
//   peut etre reecrit comme suit :

    etu->id = id;
    etu->notes = NULL;
    etu->nb_notes = 0;

    //(*etu).nom = nom;   // ATTENTION : marche pas !!!!

    etu->nom = malloc(strlen(nom) + 1);
    assert(etu->nom != NULL);
    strcpy(etu->nom, nom);

    printf("nom : %p\n", etu->nom);

    return etu;
}

void etudiant_afficher(t_etudiant *etu) {
    printf("id : %d\n", etu->id);
    printf("nom : %s\n", etu->nom);
    printf("%d notes.\n", etu->nb_notes);
    for (int i = 0; i < etu->nb_notes; i++) {
        printf("%lf ", etu->notes[i]);
    }
    printf("\n");
}

int etudiant_ajouter_note(t_etudiant *etu, double note) {
    if (note < 0 || note > 100) return -1;

    double *nouvelle_zone = realloc(etu->notes, (etu->nb_notes + 1) * sizeof(double));
    assert(nouvelle_zone != NULL);

    etu->notes = nouvelle_zone;

    etu->notes[etu->nb_notes] = note;  // on ajoute la nouvelle note a la fin
    etu->nb_notes++;    //  une note de plus !

    return 0;
}

void etudiant_supprimer(t_etudiant *etu) {
    free(etu->nom);
    free(etu->notes);
    free(etu);
}