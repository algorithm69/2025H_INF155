#include <stdio.h>

double f(double x) {
    return x * x;
}

double integrale(double a, double b, int n) {
    double somme = 0;
    double largeur_bande = (b - a) / n;

    //  parcours des bandes
    for (int i = 0; i < n; i++) {
        double x = a + i * largeur_bande;
        somme += f(x);
    }
    somme *= largeur_bande;
    return somme;
}

int main(void) {
    double a = 1;
    double b = 3;
    double n = 10000000;
    printf("integrale entre %lf et %lf = %.20lf\n", a, b,
           integrale(a, b, n));
    return 0;
}
