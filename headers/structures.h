#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_EQUIPES 100
#define MAX_JOUEURS 100
#define MAX_SIZE 40 // Pas besoin de 100 pour un nom ou prénom
// Lis le readme


typedef struct Equipe {
    int id;
    char nom[MAX_SIZE]; 
    char prenom[MAX_SIZE];
    int supprime;
} equipe_t;

// Utiliser typedef pour eviter de devoir mettre des struc Joueur partout et juste mettre joueur_t
typedef struct Joueur {
    int id;
    int id_Equipe;
    char nom[MAX_SIZE];
    char prenom[MAX_SIZE];
    int supprime;
} joueur_t;

// Tableau de structure pour les joueurs et équipes
equipe_t* tableau_Equipes[MAX_EQUIPES];
joueur_t* tableau_Joueurs[MAX_JOUEURS];

// Prototypes des fonctions
void ajouter_Equipe(int* nb_Equipes);
int ajouter_Joueur(size_t* nb_Joueurs);
int supprimer_Equipe(int* nb_Equipes);
void supprimer_Joueur(int* nb_Joueurs);
void afficher_Equipes(struct Equipe tableau_Equipes[], int nb_Equipes);
int afficher_Joueurs(struct Joueur tableau_Joueurs[], int nb_Joueurs);
int afficher_Joueur_details(struct Joueur tableau_Joueurs[], int nb_Joueurs);

#endif