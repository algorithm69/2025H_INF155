#include <stdio.h>
#include <string.h>

#define MAX_CHAINE 512

int main(void) {
    FILE *fichier = fopen("livres.csv", "r");
    char tampon[MAX_CHAINE];
    char *sous_chaine;

    while(fgets(tampon, MAX_CHAINE, fichier) != NULL) {
        tampon[strlen(tampon)-1] = '\0';
        printf("%s : ", tampon);

        //  Decoupage
        sous_chaine = strtok(tampon, ",");
        while(sous_chaine != NULL) {
            printf("%s | ", sous_chaine);
            sous_chaine = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(fichier);

    return 0;
}
