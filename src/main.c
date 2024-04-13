// #pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/structures.h"

int main() {
    int choix = 0;
    int nb_Equipes = 0;
    int nb_Joueurs = 0;
    while (choix != 8) {
        printf("1. Ajouter une equipe\n");
        printf("2. Ajouter un joueur\n");
        printf("3. Supprimer une equipe\n");
        printf("4. Supprimer un joueur\n");
        printf("5. Afficher toutes les equipes\n");
        printf("6. Afficher les joueurs\n");
        printf("7. Afficher les details d'un joueur\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        fflush(stdin);
        switch (choix) {
        case 1:
            ajouter_Equipe(&nb_Equipes);
            break;
        case 2:
            ajouter_Joueur(&nb_Joueurs);
            break;
        case 3:
            supprimer_Equipe(&nb_Equipes);
            break;
        case 4:
            supprimer_Joueur(&nb_Joueurs);
            break;
        case 5:
            afficher_Equipes(tableau_Equipes, nb_Equipes);
            break;
        case 6:
            afficher_Joueurs(tableau_Joueurs, nb_Joueurs);
            break;
        case 7:
            afficher_Joueur_details(tableau_Joueurs, nb_Joueurs);
            break;
        case 8:
            printf("Au revoir !\n");
            break;
        default:
            printf("Erreur : choix invalide.\n");
            break;
        }
    }
    return 0;
}
