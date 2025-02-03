#include <stdio.h>

int main(void) {
    int n;
    double x, somme = 0, moyenne;
    double min, max;

    /*  saisie du nombre de nombres */
    printf("Entrer un entier : ");
    scanf("%d", &n);

    if (n == 0) {
        printf("Il faut au moins un nombre !\n");
        return 0;
    }

    //  saisie des n nombres reels
    for (int i = 0; i < n; i++) {
        printf("  un nombre ? ");
        scanf("%lf", &x);

        //  mise a jour du minimum et du max
        if (i == 0) {
            min = x;
            max = x;
        }
        if (x < min) {
            min = x;
        }
        if (x > max) {
            max = x;
        }

        //  accumulation dans la variable de somme
        somme += x;
    }
    moyenne = somme / n;

    //  affichage des resultats
    //   min
    printf("Minimum = %lf\n", min);

    //  max
    printf("Maximum = %lf\n", max);

    //  moyenne
    printf("Moyenne = %lf\n", moyenne);

    return 0;
}
