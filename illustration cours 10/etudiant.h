//
// Created by stephane on 20/03/25.
//

#ifndef ILLUSTRATION_COURS_10_ETUDIANT_H
#define ILLUSTRATION_COURS_10_ETUDIANT_H

/*
 * Un �tudiant est constitu� de :
? son identifiant (entier positif)
? son nom (une cha�ne de caract�res)
? ses notes (des nombres r�els)
 */
typedef struct s_etudiant t_etudiant;

// Declarations des fonctions publiques
t_etudiant *etudiant_creer_etudiant(unsigned int id,
                                    char *nom);

void etudiant_afficher(t_etudiant *e);

int etudiant_ajouter_note(t_etudiant *etu, double note);

void etudiant_supprimer(t_etudiant *etu);

#endif //ILLUSTRATION_COURS_10_ETUDIANT_H
