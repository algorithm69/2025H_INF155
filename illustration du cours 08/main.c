#include <stdio.h>
#include <math.h>
#include <string.h>
#include "complexes.h"

void test_module() {
    //  test de la fonction module
    printf("module : module(1, 1) = %lf\n", module(1, 1));

    //  test de la fonction angle
    printf("angle : angle(1, 1) = %lf\n", angle(1, 1));

    //  test de la fonction creer
    double re, im;
    creer(1, M_PI / 4, &re, &im);
    printf("creer : complexe = (%lf; %lf)\n", re, im);

    //  test de la fonction addition
    addition(1, 3, 5, -3, &re, &im);
    printf("addition : complexe = (%lf; %lf)\n", re, im);
}

void test_fgets() {
    char chaine[100];

    printf("Dites quelque chose ? ");
    fgets(chaine, 100, stdin);

    int l = strlen(chaine);

    //  remplacer le caractere '\n' par un zero de fin de chaine
    chaine[l - 1] = '\0';

    printf("|%s|", chaine);
}

void main(void) {
    test_module();
    test_fgets();
}

