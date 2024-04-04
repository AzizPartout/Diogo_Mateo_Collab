#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_EQUIPES 100
#define MAX_JOUEURS 100
#define MAX_SIZE 40 // Pas besoin de 100 pour un nom ou prénom
// Lis le readme


struct Equipe {
    int id;
    char nom[MAX_SIZE]; 
    char prenom[MAX_SIZE];
    int supprime;
};

struct Joueur {
    int id;
    int id_Equipe;
    char nom[MAX_SIZE];
    char prenom[MAX_SIZE];
    int supprime;
};

// Tableau de structure pour les joueurs et équipes
struct Equipe tableau_Equipes[MAX_EQUIPES];
struct Joueur tableau_Joueurs[MAX_JOUEURS];

// Prototypes des fonctions
void ajouter_Equipe(int* nb_Equipes);
void ajouter_Joueur(int* nb_Joueurs);
void supprimer_Equipe(int* nb_Equipes);
void supprimer_Joueur(int* nb_Joueurs);
void afficher_Equipes(struct Equipe tableau_Equipes[], int nb_Equipes);
void afficher_Joueurs(struct Joueur tableau_Joueurs[], int nb_Joueurs);
void afficher_Joueur_details(struct Joueur tableau_Joueurs[], int nb_Joueurs);

#endif