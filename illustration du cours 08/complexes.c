//
// Created by stephane on 27/02/25.
//
#include <math.h>
#include "complexes.h"

//  Declarations des fonctions privees
void multiplication(double re1, double im1, double re2, double im2,
                    double *re, double *im);

//  Definitions des fonctions privees et publiques
double module(double re, double im) {
    return sqrt(re * re + im * im);
}

double angle(double re, double im) {
    return atan2(im, re);
}

void creer(double module, double angle, double *re, double *im) {
    *re = module * cos(angle);
    *im = module * sin(angle);
}

void addition(double re1, double im1, double re2, double im2,
              double *re, double *im) {
    *re = re1 + re2;
    *im = im1 + im2;
}

void multiplication(double re1, double im1, double re2, double im2,
                    double *re, double *im) {
    *re = re1 * re2 - im1 * im2;
    *im = re1 * im2 + re2 * im1;
}

