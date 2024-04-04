#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/structures.h"

// Fonction pour ajouter un joueur
void ajouter_Joueur(int* nb_Joueurs) {
    if (*nb_Joueurs < MAX_JOUEURS) {
        printf("Entrer l'identifiant du joueur : ");
        scanf("%d", &tableau_Joueurs[*nb_Joueurs].id);
        fflush(stdin);
        getchar(); // Ajout pour vider le tampon de stdin
        printf("Entrer le nom du joueur : ");
        fgets(tableau_Joueurs[*nb_Joueurs].nom, MAX_SIZE, stdin);
        tableau_Joueurs[*nb_Joueurs].nom[strcspn(tableau_Joueurs[*nb_Joueurs].nom, "\n")] = 0; // Suppression du caractère de retour à la ligne dans le nom du joueur
        printf("Entrer le prenom du joueur : ");
        fgets(tableau_Joueurs[*nb_Joueurs].prenom, MAX_SIZE, stdin);
        tableau_Joueurs[*nb_Joueurs].prenom[strcspn(tableau_Joueurs[*nb_Joueurs].prenom, "\n")] = 0;
        tableau_Joueurs[*nb_Joueurs].id_Equipe = 0;//initialisation de variable a 0
        tableau_Joueurs[*nb_Joueurs].supprime = 0;//initialisation de variable a 0
        (*nb_Joueurs)++;//incrémentation
    }
    else {
        printf("Erreur : le tableau de joueurs est plein.\n");
    }
}

// Fonction pour supprimer un joueur
void supprimer_Joueur(int* nb_Joueurs) {
    int id;
    printf("Entrer l'identifiant du joueur a supprimer : ");
    scanf("%d", &id);
    for (int i = 0; i < *nb_Joueurs; i++) {
        if (tableau_Joueurs[i].id == id && !tableau_Joueurs[i].supprime) {//verification joueur supprimé
            tableau_Joueurs[i].supprime = 1;
            break;
        }
    }
}

// Fonction pour afficher les joueurs
void afficher_Joueurs(struct Joueur tableau_Joueurs[], int nb_Joueurs) {
    for (int i = 0; i < nb_Joueurs; i++) {
        if (!tableau_Joueurs[i].supprime) {
            printf("Identifiant du joueur : %d\n", tableau_Joueurs[i].id);
            printf("Nom du joueur : %s\n", tableau_Joueurs[i].nom);
            printf("Prenom du joueur : %s\n", tableau_Joueurs[i].prenom);
            printf("---------------------\n");
        }
    }
}

// Fonction pour afficher les details d'un joueur
void afficher_Joueur_details(struct Joueur tableau_Joueurs[], int nb_Joueurs) {
    int id;
    printf("Entrer l'identifiant du joueur à afficher : ");
    scanf("%d", &id);
    for (int i = 0; i < nb_Joueurs; i++) {
        if (tableau_Joueurs[i].id == id && !tableau_Joueurs[i].supprime) {
            printf("Identifiant du joueur : %d\n", tableau_Joueurs[i].id);
            printf("ID de l'equipe : %d\n", tableau_Joueurs[i].id_Equipe);
            printf("Nom du joueur : %s\n", tableau_Joueurs[i].nom);
            printf("Prenom du joueur : %s\n", tableau_Joueurs[i].prenom);
            printf("---------------------\n");
            return;
        }
    }
    printf("Erreur : aucun joueur avec l'identifiant %d n'a ete trouve.\n", id);
}

// Fonction principale
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
