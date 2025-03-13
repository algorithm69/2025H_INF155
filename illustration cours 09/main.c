#include "etudiant.h"

int main(void) {
    t_etudiant *toto;
    toto = t_etudiant_new();

    t_etudiant_set_note(toto, 12354);

    return 0;
}
