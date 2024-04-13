#include "../headers/structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Fonction pour ajouter une equipe
void ajouter_Equipe(int* nb_Equipes) {
    if (*nb_Equipes < MAX_EQUIPES) {
                printf("Entrer l'identifiant de l'équipe: ");
        if (scanf("%d", &(tableau_Equipes[*nb_Equipes].id)) != 1) {
            fprintf(stderr, "Erreur lors de la saisie de l'identifiant de l'équipe.\n");
            exit(EXIT_FAILURE);
        }
        getchar(); // Ajout pour vider le tampon de stdin
        
        printf("Entrer le nom de l'équipe :");
        if (!fgets(tableau_Equipes[*nb_Equipes].nom, MAX_SIZE, stdin)) {
            fprintf(stderr, "Erreur lors de la saisie du nom de l'équipe.\n");
            exit(EXIT_FAILURE);
        }
        // Suppression du caractère de retour à la ligne dans le nom de l'equipe
        tableau_Equipes[*nb_Equipes].nom[strcspn(tableau_Equipes[*nb_Equipes].nom, "\n")] = 0;
        
        printf("Entrer le diminutif de l'équipe :");
        if (!fgets(tableau_Equipes[*nb_Equipes].prenom, MAX_SIZE, stdin)) {
            fprintf(stderr, "Erreur lors de la saisie du diminutif de l'équipe.\n");
            exit(EXIT_FAILURE);
        }
        tableau_Equipes[*nb_Equipes].prenom[strcspn(tableau_Equipes[*nb_Equipes].prenom, "\n")] = 0;
        tableau_Equipes[*nb_Equipes].supprime = 0; // Initialisation du "mode" supprimé à false
        (*nb_Equipes)++; // Augmente le nombre d'équipes de 1
    }
    else {
        fprintf(stderr, "Erreur : le tableau d'équipes est plein.\n");
        exit(EXIT_FAILURE);
    }
}

// Fonction pour supprimer une equipe
// Pour ca je vais modifier plus tard mais il suffit de faire un malloc (ca alloue de la mémoire dans la heap)
// pour stocker une équipe puis faire free (ca libère la mémoire allouée)
void supprimer_Equipe(int* nb_Equipes) {
    int id;
    printf("Entrer l'identifiant de l'equipe à supprimer : ");
    scanf("%d", &id);
    for (int i = 0; i < *nb_Equipes; i++) {
        if (tableau_Equipes[i].id == id && !tableau_Equipes[i].supprime) {
            tableau_Equipes[i].supprime = 1;
            break;
        }
    }
}

// Fonction pour afficher toutes les equipes
void afficher_Equipes(struct Equipe tableau_Equipes[], int nb_Equipes) {
    for (int i = 0; i < nb_Equipes; i++) {
        if (!tableau_Equipes[i].supprime) {
            printf("Identifiant de l'equipe : %d\n", tableau_Equipes[i].id);
            printf("Nom de l'equipe : %s\n", tableau_Equipes[i].nom);
            printf("diminutif de l'equipe : %s\n", tableau_Equipes[i].prenom);
            printf("---------------------\n");
        }
    }
}