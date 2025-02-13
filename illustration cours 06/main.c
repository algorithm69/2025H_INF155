#include <stdio.h>

#define MAX_COL 10

double moyenne_tab(int tab[][MAX_COL],
                   int sup_gauche_l, int sup_gauche_c,
                   int inf_droit_l, int inf_droit_c);

int main(void) {
    int tab[5][MAX_COL] = {
            {1, 2, 4, 5},
            {8, 4, 3, 2},
            {7, 0, 0, 1}
    };

    double moyenne = moyenne_tab(tab, 0, 1, 2, 2);
    printf("Moyenne : %lf\n", moyenne);

    return 0;
}

double moyenne_tab(int tab[][MAX_COL],
                   int sup_gauche_l, int sup_gauche_c,
                   int inf_droit_l, int inf_droit_c) {
    int somme = 0;

    for (int ligne = sup_gauche_l; ligne <= inf_droit_l; ligne++) {
        for (int colonne = sup_gauche_c; colonne <= inf_droit_c; colonne++) {
            somme += tab[ligne][colonne];
        }
    }

    int nb_cases = (inf_droit_c - sup_gauche_c + 1) * (inf_droit_l - sup_gauche_l + 1);

    return (double) somme / nb_cases;
}
