#include <stdio.h>
#include "etudiant.h"
#include "groupe.h"

void test_etudiant() {
    t_etudiant *toto;
    toto = etudiant_creer_etudiant(38, "toto");

    printf("-----------------------------\n");
    etudiant_afficher(toto);

    etudiant_ajouter_note(toto, 79);
    etudiant_ajouter_note(toto, 93);
    etudiant_ajouter_note(toto, 86);
    etudiant_ajouter_note(toto, 96);

    printf("-----------------------------\n");
    etudiant_afficher(toto);

    double des_notes[] = {87, 83, 101, 49, 90};
    int res = etudiant_ajouter_notes(toto, des_notes, sizeof(des_notes) / sizeof(des_notes[0]));
    if (res == NOTE_ERRONEE) {
        printf("L'une des notes n'est pas correcte...\n");
        printf("Aucune notes ajoutee.\n");
    }

    printf("-----------------------------\n");
    etudiant_afficher(toto);

    double moy = etudiant_calculer_moyenne(toto);
    printf("Moyenne des notes de l'etudiant : %lf\n", moy);

    //  liberation memoire pour l'etudiant
    etudiant_supprimer(toto);
}

void test_groupe() {
    t_groupe *groupe;

    groupe = groupe_creer(24343);
    printf("------------------------------\n");
    groupe_afficher(groupe);

    t_etudiant *etu = etudiant_creer_etudiant(532, "tata");
    groupe_ajouter_etudiant(groupe, etu);

    etu = etudiant_creer_etudiant(55114, "john");
    groupe_ajouter_etudiant(groupe, etu);

    printf("------------------------------\n");
    groupe_afficher(groupe);

    groupe_supprimer(groupe);
}

void test_sauvegarde_etudiant() {
    t_etudiant *toto = etudiant_creer_etudiant(38, "toto");
    etudiant_ajouter_note(toto, 79);
    etudiant_ajouter_note(toto, 93);
    etudiant_ajouter_note(toto, 86);
    etudiant_ajouter_note(toto, 96);

    FILE *fichier = fopen("etudiant.txt", "w");
    etudiant_sauver(toto, fichier);
    fclose(fichier);

    t_etudiant *titi = etudiant_creer_etudiant(-1, "AA");
    fichier = fopen("etudiant.txt", "r");
    etudiant_restaurer1(titi, fichier);
    fclose(fichier);

    fichier = fopen("etudiant.txt", "r");
    t_etudiant *tata = etudiant_restaurer2(fichier);
    fclose(fichier);
}

//  Fonction principale
//  -------------------
void main(void) {
//    test_etudiant();
//    test_groupe();
    test_sauvegarde_etudiant();
}