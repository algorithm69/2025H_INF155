#include <stdio.h>
#include <math.h>
#include <time.h>

void question01() {
    //  TODO
}

//  Question 02 : fonctions de calcul du logarithme a base b quelconque
//  La reponse a la question est simplement ln(x)/ln(b) pour calculer le logarithme a base b de x
//    note log_b(x) en math...
//  Ici, on veut tester plusieurs fonctions pour obtenir le meme resultat

#define EPSILON 0.000001

double log_avec_formule(double x, int base) {
    //  On cherche y tel que base^y = x
    //  On a donc, e^(y*ln(base)) = x
    //  Donc y*ln(base) = ln(x)
    //  C'est ourquoi y = ln(x) / ln(base)
    //  Dans math.h, ln(x) est la fonction double log(double x) (la base est e=2.71828..., le nombre d'Euler)
    return log(x) / log(base);
}

double log_pas_a_pas(double x, int base) {
    //  on part de 0, et, par pas de EPSILON, on va chercher le plus petit nombre res tel que pow(base, res) >= x
    double res;
    for (res = 0; pow(base, res) < x; res += EPSILON);
    return res;
}

double log_par_dichotomie(double x, int base) {
    double min = 0, max = 1000000;
    while (max - min > EPSILON) {
        double milieu = (min + max) / 2; //  calcul du milieu
        double exp = pow(base, milieu);  //  calcul de l'image en ce milieu
        if (exp < x) {  //  on va chercher d'un cote ou de l'autre en fonction de l'image
            min = milieu;   //  la valeur trouvee est trop petite -> on doit chercher a droite du milieu
        } else {
            max = milieu;   //  la valeur trouvee est trop grande -> on doit chercher a gauche du milieu
        }
    }
    return min;
}

//  Macro pour les calculs de temps ecoule
#define TIME(exp) do {                                                                      \
    struct timespec start, end;                                                             \
    clock_gettime(CLOCK_MONOTONIC, &start);                                                 \
    exp;                                                                                    \
    clock_gettime(CLOCK_MONOTONIC, &end);                                                   \
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1.0e9;   \
    printf("Elapsed time: %.9f seconds\n", elapsed);                                        \
} while(0)

void question02() {
    int b;
    double x, y;

    printf("base ? ");
    scanf("%d", &b);

    printf("X = ? ");
    scanf("%lf", &x);

    TIME(y = log_avec_formule(x, b));
    printf("log_%d(%lf) = %lf\n", b, x, y);

    TIME(y = log_pas_a_pas(x, b));
    printf("log_%d(%lf) = %lf\n", b, x, y);

    TIME(y = log_par_dichotomie(x, b));
    printf("log_%d(%lf) = %lf\n", b, x, y);
}

void question03() {
//  TODO
}

void question04() {

}

void question05() {

}

void question06() {

}

void question07() {

}

void question08() {

}

void question09() {

}

void question10() {

}

int main(void) {
    question01();
    question02();
    question03();
    question04();
    question05();
    question06();
    question07();
    question08();
    question09();
    question10();

    return 0;
}


void test_time() {
    time_t s = time(NULL);
    while (time(NULL) < s + 1);
    s++;

    struct timespec start, end;
    clock_gettime(CLOCK_MONOTONIC, &start);
    while (time(NULL) < s + 1);
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start.tv_sec) + (end.tv_nsec - start.tv_nsec) / 1.0e9;
    printf("Elapsed time: %.9f seconds\n", elapsed);
}
