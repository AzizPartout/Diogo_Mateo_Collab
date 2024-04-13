#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/structures.h"

/* 
Fonction pour ajouter des joueurs.
@args: size_t* nb_Joueurs = Pointeur vers un size_t représentant le nombre de joueur actuel.
@return:    -2 = nombre de joueurs passé en argument est négatif.
            -1 = Pointeur retourné par malloc est NULL.
             0 = Tableau de joueurs complet.
             1 = Joueur ajouté.
*/

int ajouter_Joueur(size_t* nb_Joueurs){
    if(*nb_Joueurs<0){
        return -2;
    }
    
    if(*nb_Joueurs<MAX_JOUEURS){

        // Alloue de la mémoire pour un nouveau joueur
        joueur_t* nv_Joueur = (joueur_t*)malloc(sizeof(joueur_t)); // Alloue une zone de mémoire dans la heap pour stocker le nouveau joueur
        // Toujours check si le malloc a marché
        if(nv_Joueur == NULL){
            return -1;
        }
        // Demande des coordonnées du nouveau joueur
        printf("Entrez le nom du joueur : ");
        scanf("%s", nv_Joueur->nom);
        printf("Entrez le prénom du joueur : ");
        scanf("%s", nv_Joueur->prenom);
        // Assigne un identifiant au joueur
        nv_Joueur->id = *nb_Joueurs;

        // Ajouter le nouveau joueur dans la liste de joueurs
        // Le fait d'avoir une liste de pointeur va nous donner 
        // un acces direct au joueur et pas à une copie
        tableau_Joueurs[*nb_Joueurs] = nv_Joueur;

        (*nb_Joueurs)++;
        return 1;
    }else{
        printf("Erreur : le tableau de joueurs est plein.\n");
        return 0;
    }
}

/* 
Fonction pour supprimer des joueurs.
Si la liste de joueurs est déjà vide, alors print un message pour informer
mais ne fait rien.
@args: size_t* nb_Joueurs = Pointeur vers un size_t représentant le nombre de joueur actuel.
@return: 
        -1 = nombre de joueurs passé en argument est négatif.
        0 = liste de joueur vide / aucun joueur trouvé à cet identifiant.
        1 = Joueur supprimé.
*/
int supprime_Joueur(size_t* nb_Joueurs){
    // Conditions de départ pour supprimer un joueur
    if(nb_Joueurs<0){
        return -1;
    }
    
    if(nb_Joueurs==0){
        return 0;
    }
    
    int id_joueur;
    printf("Entrez l'identifiant du joueur à supprimer : ");
    scanf("%d", &id_joueur);

    for(size_t i=0;i<nb_Joueurs;i++){
        // Sélectionne le bon joueur parmis les joueurs de la liste
        if(tableau_Joueurs[i]->id==id_joueur){
            free(tableau_Joueurs[i]);

            // Déplacer les joueurs suivants dans le tableau vers la gauche
            // Pour éviter d'avoir des trous dans la liste 
            for (size_t j = i; j < *nb_Joueurs - 1; j++) {
                tableau_Joueurs[j] = tableau_Joueurs[j + 1];
            }
            // Mettre à jour le nombre total de joueur.
            (*nb_Joueurs)--;
            return 1;
        }
    }
    printf("Aucun joueur trouvé avec l'identifiant donné.\n");
    return 0;
}

/* 
Fonction pour afficher les joueurs.
@args:  
        joueur_ t* tableauJoueurs = Tableau de pointeurs vers la structure joueur_t représentant la liste de joueurs.
        size_t* nb_Joueurs = Pointeur vers un size_t représentant le nombre de joueur actuel.
@return:
        -1 = nombre de joueurs passé en argument est négatif.
        0 = liste de joueur vide.
 */
int afficher_Joueurs(joueur_t* tableauJoueurs[], size_t nb_Joueurs){
    if(nb_Joueurs<0){
        return -1;
    }
    if(nb_Joueurs==0){
        return 0;
    }

    for (size_t i = 0; i < nb_Joueurs; i++) {
        printf("Identifiant du joueur : %d\n", tableauJoueurs[i]->id);
        printf("Nom du joueur : %s\n", tableauJoueurs[i]->nom);
        printf("Prenom du joueur : %s\n", tableauJoueurs[i]->prenom);
        printf("---------------------\n");
    }
}

/* 
Fonction pour afficher les détails d'un joueur.
@args:         
        joueur_ t* tableauJoueurs = Tableau de pointeurs vers la structure joueur_t représentant la liste de joueurs.
        size_t* nb_Joueurs = Pointeur vers un size_t représentant le nombre de joueur actuel.
@return: 
        -1 = nombre de joueurs passé en argument est négatif.
        0 = liste de joueur vide / aucun joueur trouvé à cet identifiant.
        1 = détails du joueur affichés.
*/
int afficher_Joueur_details(joueur_t* tableauJoueurs[], int nb_Joueurs) {
    
    if(nb_Joueurs<0){
        return -1;
    }
    if(nb_Joueurs==0){
        return 0;
    }
    
    int id_joueur;
    printf("Entrer l'identifiant du joueur à afficher : ");
    scanf("%d", &id_joueur);
    for (int i = 0; i < nb_Joueurs; i++) {
        if (tableauJoueurs[i]->id == id_joueur) {
            printf("Identifiant du joueur : %d\n", tableauJoueurs[i]->id);
            printf("ID de l'equipe : %d\n", tableauJoueurs[i]->id_Equipe);
            printf("Nom du joueur : %s\n", tableauJoueurs[i]->nom);
            printf("Prenom du joueur : %s\n", tableauJoueurs[i]->prenom);
            printf("---------------------\n");
            return 1;
        }
    }
    printf("Erreur : aucun joueur avec l'identifiant %d n'a été trouvé.\n", id_joueur);
    return 0;
}

