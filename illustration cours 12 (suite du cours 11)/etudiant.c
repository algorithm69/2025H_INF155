//
// Created by stephane on 20/03/25.
//

#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "etudiant.h"

// Declaration de la structure privee
// -----------------------------------
struct s_etudiant {
    unsigned int id;    //  4
    char *nom;          //  8
    double *notes;      //  8
    int nb_notes;       //  4
};                      //   = 24

//  Declaration des fonctions privees
//  ---------------------------------
bool est_correcte(int note);

// Definitions des fonctions publiques
// -----------------------------------
t_etudiant *etudiant_creer_etudiant(unsigned int id, char *nom) {
    t_etudiant *etu = malloc(sizeof(t_etudiant));
    assert(etu != NULL);

    etu->id = id;
    etu->notes = NULL;
    etu->nb_notes = 0;

    etu->nom = malloc(strlen(nom) + 1);
    assert(etu->nom != NULL);
    strcpy(etu->nom, nom);

    return etu;
}

void etudiant_afficher(const t_etudiant *etu) {
    printf("id : %d\n", etu->id);
    printf("nom : %s\n", etu->nom);
    printf("%d notes.\n", etu->nb_notes);
    for (int i = 0; i < etu->nb_notes; i++) {
        printf("%lf ", etu->notes[i]);
    }
    printf("\n");
}

int etudiant_ajouter_note(t_etudiant *etu, double note) {
    int res = NOTE_ERRONEE;

    if (est_correcte(note)) {
        res = NOTE_CORRECTE;

        double *nouvelle_zone = realloc(etu->notes, (etu->nb_notes + 1) * sizeof(double));
        assert(nouvelle_zone != NULL);

        etu->notes = nouvelle_zone;

        etu->notes[etu->nb_notes] = note;  // on ajoute la nouvelle note a la fin
        etu->nb_notes++;    //  une note de plus !
    }

    return res;
}

int etudiant_ajouter_notes(t_etudiant *etu, double *notes, int nb_notes) {
    int res = NOTE_ERRONEE;

    //  Verification que toutes les notes sont correctes
    int i = 0;
    while (i < nb_notes && est_correcte(notes[i])) {
        i++;
    }

    if (i == nb_notes) {    // ajout des notes si elles sont toutes correctes
        for (int i = 0; i < nb_notes; i++) {
            etudiant_ajouter_note(etu, notes[i]);
        }
        res = NOTES_CORRECTES;
    }

    return res;
}

double etudiant_calculer_moyenne(t_etudiant *etu) {
    double somme = 0;
    for (int i = 0; i < etu->nb_notes; i++) {
        somme += etu->notes[i];
    }
    return somme / etu->nb_notes;
}

void etudiant_supprimer(t_etudiant *etu) {
    free(etu->nom);
    free(etu->notes);
    free(etu);
}

// Definitions des fonctions publiques
// -----------------------------------
bool est_correcte(int note) {
    return note >= 0 && note <= 100;
}

int etudiant_sauver(t_etudiant *etu, FILE *fichier) {
    fprintf(fichier, "%d\n", etu->id);
    fprintf(fichier, "%s\n", etu->nom);
    fprintf(fichier, "%d\n", etu->nb_notes);
    for (int i = 0; i < etu->nb_notes; i++) {
        fprintf(fichier, "%lf ", etu->notes[i]);
    }
    fprintf(fichier, "\n");
}

void etudiant_restaurer1(t_etudiant *etu, FILE *fichier) {
    fscanf(fichier, "%d", &etu->id);

    char tampon[1000];
    fscanf(fichier, "%s", tampon);
    if (strlen(etu->nom) < strlen(tampon)) {
        free(etu->nom);
        etu->nom = malloc(strlen(tampon) + 1);
    }
    strcpy(etu->nom, tampon);

    etu->nb_notes = 0;
    free(etu->notes);
    etu->notes = NULL;

    int nb_notes;
    fscanf(fichier, "%d", &nb_notes);

    for (int i = 0; i < nb_notes; i++) {
        double note;
        fscanf(fichier, "%lf", &note);
        etudiant_ajouter_note(etu, note);
    }
}

t_etudiant *etudiant_restaurer2(FILE *fichier) {
    int id;
    fscanf(fichier, "%d", &id);

    char nom[1000];
    fscanf(fichier, "%s", nom);

    t_etudiant *etu = etudiant_creer_etudiant(id, nom);

    int nb_notes;
    fscanf(fichier, "%d", &nb_notes);

    for (int i = 0; i < nb_notes; i++) {
        double note;
        fscanf(fichier, "%lf", &note);
        etudiant_ajouter_note(etu, note);
    }

    return etu;
}