#include <stdio.h>
// Écrire un programme qui calcule la TPS et la TVQ d?un montant donné.
// Le montant ainsi que les valeurs calculées doivent être
// stockées dans des variables.

// § Note: En janvier 2018, la TPS vaut 5% du montant, tandis que la
// TVQ vaut 9.975% du montant incluant la TPS.

//  Taux de taxes en %
#define TAUX_TPS 5
#define TAUX_TVQ 9.975

int main(void) {
    //  Declaration des variables
    float montant_brut, montant_net;    //  les montants avant et apres taxes
    float tps, tvq;                     //  les montants de taxes

    //  Saisie des donnees
    printf("Saisir le montant_brut : ");
    scanf("%f", &montant_brut);

    //  Calculs
    tps = montant_brut * TAUX_TPS / 100;
    tvq = (montant_brut + tps) * TAUX_TVQ / 100;
    montant_net = montant_brut + tps + tvq;

    //  Affichage des resultats
    printf("Montant tps : %.2f$\n", tps);
    printf("Montant tvq : %.2f$\n", tvq);
    printf("Montant apres taxes : %.2f$\n", montant_net);

    return 0;
}
