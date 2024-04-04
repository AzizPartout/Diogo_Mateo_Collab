Séparez votre programme en plusieurs petits fichiers pour faciliter la compréhension
Dans les headers c'est soit les créations de structures, soit les prototypes des fonctions
Comme ca dans les fichiers du dossiers src, vous mettez les includes qui importe seulement les
structures ou fonctions que vous avez besoin.
Vu que vous aurez plein de fichiers à compiler en même temps pour que votre projet marche
il faudra faire un Makefile que je ferai qui fera justement toute la compilation à votre place. 
Le dossier bin ca sera pour mettre les fichiers binaires. 
Et il y a aussi les malloc et les free que je rajouterai plus tard