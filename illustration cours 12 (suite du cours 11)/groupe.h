//
// Created by stephane on 27/03/25.
//

#ifndef ILLUSTRATION_COURS_10_GROUPE_H
#define ILLUSTRATION_COURS_10_GROUPE_H

#include "etudiant.h"

//  Declaration de la structure publique de groupe
typedef struct s_groupe t_groupe;

//  Declarations des fonctions publiques
t_groupe *groupe_creer(unsigned int num);

void groupe_afficher(const t_groupe *groupe);

void groupe_ajouter_etudiant(t_groupe *groupe, t_etudiant *etu);

void groupe_supprimer(t_groupe *groupe);

#endif //ILLUSTRATION_COURS_10_GROUPE_H
