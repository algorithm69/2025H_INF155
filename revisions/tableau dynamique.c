#include <stdio.h>
#include <malloc.h>
#include <assert.h>

#define PI  3.14159265
#define MAX(a, b) ((a)>(b) ? (a) : (b))
#define AIRE(r) (PI*(r)*(r))

void test_macros() {
    MAX(4, 5);
    printf("%lf\n", AIRE(2) * 2);
}

// ------------------------------------------------
typedef enum {
    OK, PLUS_DE_PLACE
} t_statut;

typedef struct s_TD {
    int *tab; // adresse du tableau contenant les entiers
    int taille; // nombre d'entiers dans le tableau
    int cap; // nombre de cases du tableau
} t_TD;

typedef t_TD *t_ptr_TD;

//  Declarations des fonctions
t_ptr_TD TD_creer(int cap);

t_statut TD_ajouter(t_ptr_TD ptr, int valeur);

void TD_afficher(const t_ptr_TD ptr);

void TD_liberer(t_ptr_TD ptr);

t_statut TD_supprimer(t_ptr_TD ptr, int valeur);

//  Definition de la fonction main
int main(void) {
    t_ptr_TD p = TD_creer(1);

    TD_ajouter(p, 45);
    TD_ajouter(p, -25);
    TD_ajouter(p, 5);
    TD_ajouter(p, 111);
    TD_afficher(p);

    TD_supprimer(p, -25);
    TD_afficher(p);
    TD_supprimer(p, 111);
    TD_afficher(p);
    TD_supprimer(p, 45);
    TD_afficher(p);
    TD_supprimer(p, 5);
    TD_afficher(p);

    TD_liberer(p);

    return 0;
}

//  Definitions des fonctions
t_TD *TD_creer(int cap) {
    t_ptr_TD ptr = (t_ptr_TD) malloc(sizeof(t_TD));

//    assert(ptr != NULL);
    if (ptr != NULL) {
        ptr->taille = 0;
        ptr->cap = cap;
        ptr->tab = malloc(cap * sizeof(int));

//    assert(ptr->tab != NULL)
        if (ptr->tab == NULL) {
            free(ptr);
            ptr = NULL;
        }
    }

    return ptr;
}

t_statut TD_redim(t_ptr_TD ptr, int nouvelle_cap) {
    t_ptr_TD tmp = (t_ptr_TD) realloc(ptr->tab, nouvelle_cap * sizeof(int));

    if (tmp == NULL) {
        return PLUS_DE_PLACE;
    }

    ptr->tab = tmp;
    ptr->cap = nouvelle_cap;
}

t_statut TD_ajouter(t_ptr_TD ptr, int valeur) {
    if (ptr->taille == ptr->cap) {
        if (TD_redim(ptr, ptr->taille * 2 + 1) == PLUS_DE_PLACE) {
            return PLUS_DE_PLACE;
        }
    }

    ptr->tab[ptr->taille] = valeur;
    // qui equivaut a
    // (*ptr).tab[(*ptr).taille] = valeur

    ptr->taille++;
}

void TD_afficher(const t_ptr_TD ptr) {
    printf("TD de %d/%d entiers : ", ptr->taille, ptr->cap);
    for (int i = 0; i < ptr->taille; i++) {
        printf("%d ", ptr->tab[i]);
    }
    printf("\n");
}

void TD_liberer(t_ptr_TD ptr) {
    free(ptr->tab);
    free(ptr);
}

t_statut TD_supprimer(t_ptr_TD ptr, int valeur) {
    t_statut status = OK;

    int i = 0;
    while (i < ptr->taille && ptr->tab[i] != valeur) {
        i++;
    }

    if (i < ptr->taille) {
        ptr->tab[i] = ptr->tab[ptr->taille - 1];
        ptr->taille--;

        if (2 * ptr->taille < ptr->cap) {
            if (TD_redim(ptr, (ptr->cap - 1) / 2) == PLUS_DE_PLACE) {
                status = PLUS_DE_PLACE;
            }
        }
    }

    return status;
}
