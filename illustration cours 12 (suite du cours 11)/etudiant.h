//
// Created by stephane on 20/03/25.
//

#ifndef ILLUSTRATION_COURS_10_ETUDIANT_H
#define ILLUSTRATION_COURS_10_ETUDIANT_H

#define NOTE_ERRONEE    -1
#define NOTE_CORRECTE    0
#define NOTES_CORRECTES    0

typedef struct s_etudiant t_etudiant;

// Declarations des fonctions publiques
t_etudiant *etudiant_creer_etudiant(unsigned int id, char *nom);

void etudiant_afficher(const t_etudiant *e);

int etudiant_ajouter_note(t_etudiant *etu, double note);

/**
 * @name etudiant_ajouter_notes
 * @param etu l'adresse de l'etudiant auquel on veut ajouter des notes
 * @param notes le tablaeu des notes a ajouter
 * @param nb_notes le nombre de notes a ajouter
 * @return NOTE_ERRONEE si l'une des notes est erronee, NOTES_CORRECTES sinon
 */
int etudiant_ajouter_notes(t_etudiant *etu, double *notes, int nb_notes);

double etudiant_calculer_moyenne(t_etudiant *etu);

void etudiant_supprimer(t_etudiant *etu);

int etudiant_sauver(t_etudiant *etu, FILE *fichier);

void etudiant_restaurer1(t_etudiant *etu, FILE *fichier);

t_etudiant *etudiant_restaurer2(FILE *fichier);

#endif //ILLUSTRATION_COURS_10_ETUDIANT_H
