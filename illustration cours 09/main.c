#include <stdio.h>
#include "etudiant.h"

//
//void f1(const int * p) {
//    p = 0;
//    *p = 12;
//}
//
//void f2(int * const p) {
//    p = 0;
//    *p = 12;
//}
//
//void f3(const int * const p) {
//    p = 0;
//    *p = 12;
//}


int main(void) {
//    const int n = 78;
//
//    f(&n);

    t_etudiant *toto;
    toto = t_etudiant_new();

    t_etudiant_set_note(toto, 12354);


    return 0;
}
