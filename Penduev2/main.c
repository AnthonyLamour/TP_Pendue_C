#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100
#define MAX 6

/*ALGO Jeu du pendue
BUT faire un jeu du pendue en mode textuel
ENTREE le mot à chercher et les lettres
SORTIE victoire ou défaite

//CONST
    MAX=6

//METHODE

    procedure aff_dessin(vie:ENTIER)
    //BUT afficher le dessin
    //ENTREE nombre de vie restantes
    //SORTIE le dessin

    DEBUT

        CAS vie PARMIS
            0:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |   /|\ "
              ECRIRE" |   / \ "
              ECRIRE" |       "
              ECRIRE" |_______"
            1:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |   /|\ "
              ECRIRE" |   /   "
              ECRIRE" |       "
              ECRIRE" |_______"
            2:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |   /|\ "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |_______"
            3:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |   /|  "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |_______"
            4:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |   /   "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |_______"
            5:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |    O  "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |_______"
            6:ECRIRE"_______  "
              ECRIRE" |    |  "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |       "
              ECRIRE" |_______"
        FINCASPARMIS

    FINPROCEDURE

    fonction init_aff(MotAff:CHAINE):CHAINE
    //BUT initialiser le mot afficher
    //ENTREE mot à afficher
    //SORTIE mot à afficher modifié

    var
        i:ENTIER

    DEBUT

        i<-0
        POUR i DE 1 A longueur(MotAff) FAIRE
            MotAff[i]<-'_'
        FINPOUR
        init_aff<-MotAff

    FINPROCEDURE

    fonction MAJ_aff(var MotAff:CHAINE,MotChercher:CHAINE,lettre:CARACTERE):ENTIER
    //BUT modifié le mot afficher
    //ENTREE mot à afficher et mot à chercher
    //SORTIE mot à afficher modifié

    var
        i,cpt:ENTIER

    DEBUT

        i<-0
        cpt<-0
        POUR i DE 1 A longueur(MotChercher) FAIRE
            SI ((MotChercher[i]=lettre) ET (MotAff[i]!=lettre))ALORS
                MotAff[i]<-lettre
                cpt<-cpt+1
            FINSI
        FINPOUR
        MAJ_aff<-cpt

    FINFONCTION

    fonction init_Mot(MotChercher:CHAINE):CHAINE
    //BUT initialiser le mot à chercher
    //ENTREE le mot à chercher
    //SORTIE le mot à cherhcer modifié

    DEBUT

        ECRIRE "Joueur 1, veuillez entrer le mot à trouver :"
        LIRE MotChercher
        init_Mot<-MotChercher

    FINFONCTION

VAR :

    //Mot à trouver
        MotChercher:CHAINE

    //Progression du joueur 2
        MotAff:CHAINE

    //vie=nombre d'essais restant
        vie:ENTIER

    //cpt compte le nombre de fois où la lettre est présente dans le mot, test permet de faire plusieurs parties
        cpt,test:ENTIER

    //lettre=lettre entrée par le joueur 2
        lettre:CARACTERE

DEBUT

    //Initialisation de test
        test<-1

    //Boucle de parties
        TANT QUE (test!=0) FAIRE

            //Initialisation des variables
                cpt<-0
                vie<-MAX
                MotChercher<-""
                MotAff<-""

            //Demande du mot à trouvé au joueur 1
                MotChercher<-init_Mot(MotChercher)

            //Initialisation du mot afficher au joueur 2
                MotAff=MotChercher
                MotAff<-init_aff(MotAff);

            //Tours du joueur 2
                TANT QUE ((vie!=0) ET (MotAff!=MotChercher)) FAIRE

                    //Demande de saisie d'une lettre au joueur 2
                        ECRIRE "Joueur 2, veuillez entrer une lettre :"
                        LIRE lettre

                    //Initialisation du compteur
                        cpt<-0

                    //Mise à jour de MotAff
                        cpt<-MAJ_aff(MotAff,MotChercher,lettre)

                    //Si la lettre n'est pas présente dans le mot alors le joueur 2 perd une vie
                        SI (cpt=0) ALORS
                            vie<-vie-1
                        FINSI

                    //Si il reste au moins un essai au joueur 2 alors on affiche sa progression
                        SI (vie!=0) ALORS
                            ECRIRE "Voici les lettres trouver :"&MotAff
                            ECRIRE "Il vous reste :"&vie&"vies."
                            aff_dessin(vie)
                        FINSI

                FINTANTQUE

            //Affichage de la victoire ou de la défaite du joueur 2
                SI (vie=0) ALORS
                    ECRIRE "Joueur 2 a perdue."
                    aff_dessin(vie)
                SINON
                    ECRIRE "Joueur 2 a gagné."
                FINSI

            //Demande si les joueurs veulent faire une autre partie
                ECRIRE "Entrer 0 pour quitter le programme."
                LIRE test

        FINTANTQUE

    //remerciment
        ECRIRE "Merci d'avoir joué."

FIN

*/

//prototypes
    void aff_dessin(int vie);
    void init_aff(char MotAff[TAILLE],char MotChercher[TAILLE]);
    int MAJ_aff(char MotAff[TAILLE],char MotChercher[TAILLE],char lettre);
    void init_Mot(char MotChercher[TAILLE]);

int main()
{

    //Progression du joueur 2
        char MotAff[TAILLE]="";

    //Mot à trouver
        char MotChercher[TAILLE]="";

    //vie=nombre d'essais restant
        int vie=MAX;

    //cpt compte le nombre de fois où la lettre est présente dans le mot, test permet de faire plusieurs parties
        int cpt=0,test=1;

    //lettre=lettre entrée par le joueur 2
        char lettre=' ';

    //Boucle de parties
        while (test!=0){

            //clear screen
                system("@cls||clear");

            //Initialisation des variables
                vie=MAX;
                cpt=0;
                lettre=' ';

            //Demande du mot à trouvé au joueur 1
                init_Mot(MotChercher);

            //Initialisation du mot afficher au joueur 2
                init_aff(MotAff,MotChercher);

            //Tours du joueur 2
                while ( (vie!=0) && (strcmp(MotAff,MotChercher)!=0) ){

                    //Demande de saisie d'une lettre au joueur 2
                        printf("Joueur 2, veuillez entrer une lettre :\n");
                        fflush(stdin);
                        scanf("%c",&lettre);

                    //Initialisation du compteur
                        cpt=0;

                    //clear screen
                        system("@cls||clear");

                    //Mise à jour de MotAff
                        cpt=MAJ_aff(MotAff,MotChercher,lettre);

                    //Si la lettre n'est pas présente dans le mot alors le joueur 2 perd une vie
                        if(cpt==0){
                            vie=vie-1;
                        }

                    //Si il reste au moins un essai au joueur 2 alors on affiche sa progression
                        if(vie!=0){
                            printf("Voici les lettres trouver : %s\n\n",MotAff);
                            printf("Il vous reste : %d vies.\n\n",vie);
                            aff_dessin(vie);
                        }

                }

            //Affichage de la victoire ou de la défaite du joueur 2
                if(vie==0){
                    printf("Joueur 2 a perdue.\n\n");
                    aff_dessin(vie);
                }else{
                    printf("Victoire de Joueur 2.\n\n");
                }

            //Demande si les joueurs veulent faire une autre partie
                printf("Entrez 0 pour quitter le programme :");
                scanf("%d",&test);

        }

    //remerciment
        printf("\nMerci d'avoir jouer.\n\n");

    //pause avant de quitter le programme
        system("pause");

    return 0;
}

void aff_dessin(int vie){
    //BUT afficher le dessin
    //ENTREE nombre de vie
    //SORTIE le dessin

    switch (vie) {
       case 0:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |   /|\\ \n");
              printf(" |   / \\ \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 1:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |   /|\\ \n");
              printf(" |   /   \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 2:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |   /|\\ \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 3:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |   /|  \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 4:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |    |  \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 5:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |    O  \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
       case 6:printf("_______  \n");
              printf(" |    |  \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |       \n");
              printf(" |_______\n");
              break;
    }


}

void init_aff(char MotAff[TAILLE],char MotChercher[TAILLE]){
    //BUT initialiser le mot afficher
    //ENTREE mot à chercher
    //SORTIE mot à afficher


    int i=0;
    for(i=0;i<strlen(MotChercher);i++){

        MotAff[i]='_';

    }

}

int MAJ_aff(char MotAff[TAILLE],char MotChercher[TAILLE],char lettre){
    //BUT modifié le mot afficher
    //ENTREE mot à afficher et mot à chercher
    //SORTIE mot à afficher modifié

    int i=0;
    int cpt=0;
    for (i=0;i<strlen(MotChercher);i++){
        if ((MotChercher[i]==lettre) && (MotAff[i]!=lettre)){
            MotAff[i]=lettre;
            cpt=cpt+1;
        }
    }
    return cpt;

}

void init_Mot(char MotChercher[TAILLE]){
    //BUT initialiser le mot à chercher
    //ENTREE le mot à chercher
    //SORTIE le mot à cherhcer modifié

    printf("Joueur 1, veuillez entrer le mot a trouver :\n");
    fflush(stdin);
    gets(MotChercher);
    system("@cls||clear");


}

