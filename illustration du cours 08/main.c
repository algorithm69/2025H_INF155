#include <stdio.h>
#include <math.h>
#include "complexes.h"

int main(void) {
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

    mu

    return 0;
}
