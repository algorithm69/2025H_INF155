//
// Created by stephane on 13/03/25.
//

#ifndef ILLUSTRATION_COURS_09_ETUDIANT_H
#define ILLUSTRATION_COURS_09_ETUDIANT_H

typedef struct s_etudiant t_etudiant;

t_etudiant *t_etudiant_new();

void t_etudiant_set_note(t_etudiant *etu, int note);

#endif //ILLUSTRATION_COURS_09_ETUDIANT_H
