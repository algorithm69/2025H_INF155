//
// Created by stephane on 27/02/25.
//

#ifndef ILLUSTRATION_DU_COURS_08_COMPLEXES_H
#define ILLUSTRATION_DU_COURS_08_COMPLEXES_H

//  Declarations des fonctions publiques
double module(double re, double im);

double angle(double re, double im);

void creer(double module, double angle,
           double *re, double *im);

void addition(double re1, double im1, double re2, double im2,
              double *re, double *im);

#endif //ILLUSTRATION_DU_COURS_08_COMPLEXES_H
