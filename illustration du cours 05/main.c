#include <stdio.h>

#define NB_NOTES 8
#define SEUIL_BONNE_NOTE 80

void question1() {
    int notes[NB_NOTES] = {70, 89, 72, 65, 92, 77, 81, 78};

    int nb_bonnes_notes = 0;

    for (int i = 0; i < NB_NOTES; i++) {
        if (notes[i] > SEUIL_BONNE_NOTE) {
            nb_bonnes_notes++;
        }
    }

    printf("Il y a %d bonnes notes.\n", nb_bonnes_notes);

}

void question2() {
    double fibonacci[100];

    //  mise en place des 2 premiers termes de la suite
    fibonacci[0] = 0;
    fibonacci[1] = 1;

    //  calcul des 98 termes suivants
    for (int n = 2; n <= 99; n++) {
        fibonacci[n] = fibonacci[n - 2] + fibonacci[n - 1];
    }

    //  affichage de tous les termes de la suite
    for (int n = 0; n <= 99; n++) {
        printf("fib(%d) = %lf\n", n, fibonacci[n]);
    }

}

void question3() {
    int tab[10] = {1, 2, 3};

    printf("tab     = %p\n", tab);
    printf("&tab[0] = %p\n", &tab[0]);

    printf("*tab     = %d\n", *tab);
    printf("*(&tab[0]) = %d\n", *(&tab[0]));

    tab[2] = 70;
    *(tab + 2) = 70;

    printf("&tab = %p\n", &tab);
}

int main(void) {
    question1();
    question2();
    question3();

    return 0;
}
