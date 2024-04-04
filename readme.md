Séparez votre programme en plusieurs petits fichiers pour faciliter la compréhension.

Dans les headers c'est soit les créations de structures, soit les prototypes des fonctions.

Comme ca dans les fichiers du dossiers src, vous mettez les includes qui importe seulement les
structures ou fonctions que vous avez besoin.

Le dossier bin ca sera pour mettre les fichiers binaires. 

Et il y a aussi les malloc et les free que je rajouterai plus tard.

Pour créer l'executable dans le dossier de base :
$ make
Pour executer : 
$./main

