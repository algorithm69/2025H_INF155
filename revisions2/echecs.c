#include <stdio.h>

typedef enum {
    TOUR_B = 01, CAVALIER_B, FOU_B, REINE_B, ROI_B, PION_B,
    TOUR_N = 11, CAVALIER_N, FOU_N, REINE_N, ROI_N, PION_N
} t_piece;

typedef t_piece t_echiquier[8][8];

typedef enum {
    BLANC, NOIR
} t_camp;

//  Declarations des focntions
void initialiser(t_echiquier e);

void afficher(t_echiquier e);

int compter_pieces(t_echiquier e, t_camp camp);

void jouer(t_echiquier e, char *depart, char *arrivee);

//  Definintion de la fonction main
int main(void) {
    t_echiquier echiquier = {};

    initialiser(echiquier);
    afficher(echiquier);

    return 0;
}

//  Definition des fonctions
void initialiser(t_echiquier e) {
    t_piece pieces[] = {TOUR_N, CAVALIER_N, FOU_N, REINE_N, ROI_N, FOU_N, CAVALIER_N, TOUR_N};

    //  placement des pions noirs
    for (int c = 0; c < 8; c++) {
        e[1][c] = PION_N;
        e[6][c] = PION_B;
        e[0][c] = pieces[c];
        e[7][c] = pieces[c] - 10;
    }
}

void afficher(t_echiquier e) {
    for (int l = 0; l < 8; l++) {
        for (int c = 0; c < 8; c++) {
            switch (e[l][c] % 10) {
                case PION_B:
                    printf("P");
                    break;
                case TOUR_B:
                    printf("R");
                    break;
                case CAVALIER_B:
                    printf("N");
                    break;
                case FOU_B:
                    printf("B");
                    break;
                case ROI_B:
                    printf("K");
                    break;
                case REINE_B:
                    printf("Q");
                    break;
                default:
                    printf(" ");
            }
            if (e[l][c] >= 10) {
                printf("n");
            } else if (e[l][c] >= 1) {
                printf("b");
            } else {
                printf(" ");
            }
            printf(" ");
        }
        printf("\n");
    }
}


int compter_pieces(t_echiquier e, t_camp camp) {}

void jouer(t_echiquier e, char *depart, char *arrivee) {}
