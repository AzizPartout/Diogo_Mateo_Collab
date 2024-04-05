# Langage et logique de programmation 2
Collaboration d'étudiants sur Github pour un cours sur le langage C de l'HEPL :sleeping:

## :clap: Comment participer ?

### Makefile
En sachant qu'il y a plusieurs fichiers et dossiers qui composent ce projet il faut déjà savoir comment compiler tout ces fichiers pour faire notre exécutable final. 
C'est le but du Makefile se trouvant dans le dossier racine, il va prendre tous les fichiers à compiler, en faire des fichiers objets (.o) et avec ceux-ci créer l'exécutable. Pour lancer ce processus, les deux commandes : 
```
$ make    // Pour faire l'exécutable
$ ./main  // Pour lancer l'exécutable
```

### Git & github
D'abord il faut cloner le [projet](https://github.com/AzizPartout/Diogo_Mateo_Collab) sur votre IDE (VSC, Visual Code).
>**Remarque** : Il faut faire partie des collaborators du repository pour pouvoir push tes modifications par la suite. 
Pour ça, créez un dossier, ouvrez-le sur votre IDE, ouvrez un terminal et faites la commande :
```
git clone https://github.com/AzizPartout/Diogo_Mateo_Collab.git
```
Ensuite, regardez la vidéo [Apprendre à utiliser GIT](https://www.youtube.com/watch?v=A5_kJps4qjc) pour plus d'explications.

>**Important** : A chaque fois que vous revenez travailler sur le projet faites un git pull pour reprendre toutes les modifications apportées par les autres. Ensuite travailler sur la branche de la feature sur laquelle vous voulez travailler ! Ne travaillez pas sur le main. Ensuite faites un git push à chaque fois que vous arrêtez de travailler sur le projet (genre à chaque fin de journée).

 ## :tongue: Structure du programme
Séparez votre programme en plusieurs petits fichiers pour faciliter la compréhension.
Dans les headers c'est soit les créations de structures, soit les prototypes des fonctions.
Comme ca dans les fichiers du dossiers src, vous mettez les includes qui importe seulement les
structures ou fonctions que vous avez besoin.
Le dossier bin ca sera pour mettre les fichiers binaires. 

## :mechanical_arm: Mécanisme du programme
J'etofferai ça mais on va utiliser des malloc et des free pour stocker les joueurs et équipes dans la heap et juste faire free va supprimer les données.