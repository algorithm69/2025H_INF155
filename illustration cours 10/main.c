#include <stdio.h>
#include "etudiant.h"
#include <string.h>

t_etudiant *test() {
    char nom[] = "toto";
    printf("%p\n", nom);
    return etudiant_creer_etudiant(1, nom);
}

void f() {
    int n = 90;
    printf("%d en %p\n", n, &n);
}

void main(void) {
    t_etudiant *toto;
    toto = test();
    f();

    printf("-----------------------------\n");
    etudiant_afficher(toto);

    etudiant_ajouter_note(toto, 92);
    etudiant_ajouter_note(toto, -7);
    etudiant_ajouter_note(toto, 79);

    printf("-----------------------------\n");
    etudiant_afficher(toto);

}