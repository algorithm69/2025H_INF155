//
// Created by stephane on 27/03/25.
//
#include <malloc.h>
#include <assert.h>

#include "groupe.h"
#include "etudiant.h"

//  Definition de la structure privee de groupe
struct s_groupe {
    unsigned int num;
    t_etudiant **etudiants;
    int nb_etudiants;
    int max_etudiants;
};

//  Definitions des fonctions publiques
t_groupe *groupe_creer(unsigned int num) {
    t_groupe *groupe = malloc(sizeof(t_groupe));
    assert(groupe != NULL);

    groupe->num = num;
    groupe->etudiants = NULL;
    groupe->nb_etudiants = 0;
    groupe->max_etudiants = 0;

    return groupe;
}

void groupe_afficher(const t_groupe *groupe) {
    printf("Groupe #%d :\n", groupe->num);
    printf("  %d etudiant(s).\n", groupe->nb_etudiants);

    for (int i = 0; i < groupe->nb_etudiants; i++) {
        etudiant_afficher(groupe->etudiants[i]);
    }
}

void groupe_ajouter_etudiant(t_groupe *groupe, t_etudiant *etu) {
    if (groupe->nb_etudiants == groupe->max_etudiants) {
        int nouvelle_taille = 2 * groupe->nb_etudiants + 1;

        t_etudiant **nouvelle_zone = realloc(groupe->etudiants,
                                             nouvelle_taille * sizeof(t_etudiant *));
        assert(nouvelle_zone != NULL);

        groupe->etudiants = nouvelle_zone;
        groupe->max_etudiants = nouvelle_taille;
    }

    groupe->etudiants[groupe->nb_etudiants] = etu;
    groupe->nb_etudiants++;
}

void groupe_supprimer(t_groupe *groupe) {
    //  liberation de tous les etudiants
    for (int i = 0; i < groupe->nb_etudiants; i++) {
        etudiant_supprimer(groupe->etudiants[i]);
    }
    free(groupe->etudiants);
    free(groupe);
}