#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE 100
#define MAX 6

/*ALGO Jeu du pendue
BUT faire un jeu du pendue en mode textuel
ENTREE le mot à chercher et les lettres
SORTIE victoire ou défaite

VAR :

    //Mot à trouver
        MotChercher:CHAINE

    //Progression du joueur 2
        MotAff:CHAINE

    //i sert à parcourir les chaines de caractère, vie=nombre d'essais restant
        i,vie:ENTIER

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
                i<-0
                cpt<-0
                vie<-MAX
                MotChercher<-""
                MotAff<-""

            //Demande du mot à trouvé au joueur 1
                ECRIRE "Joueur 1, veuillez entrer le mot à trouver :"
                LIRE MotChercher

            //Initialisation du mot afficher au joueur 2
                MotAff=MotChercher
                POUR i DE 1 A longueur(MotAff) FAIRE
                    MotAff[i]<-'_'
                FINPOUR

            //Tours du joueur 2
                TANT QUE ((vie!=0) ET (MotAff!=MotChercher)) FAIRE

                    //Demande de saisie d'une lettre au joueur 2
                        ECRIRE "Joueur 2, veuillez entrer une lettre :"
                        LIRE lettre

                    //Initialisation du compteur
                        cpt<-0

                    //Mise à jour de MotAff
                        POUR i DE 1 A longueur(MotChercher) FAIRE
                            SI ((MotChercher[i]=lettre) ET (MotAff[i]!=lettre))ALORS
                                MotAff[i]<-lettre
                                cpt<-cpt+1
                            FINSI
                        FINPOUR

                    //Si la lettre n'est pas présente dans le mot alors le joueur 2 perd une vie
                        SI (cpt=0) ALORS
                            vie<-vie-1
                        FINSI

                    //Si il reste au moins un essai au joueur 2 alors on affiche sa progression
                        SI (vie!=0) ALORS
                            ECRIRE "Voici les lettres trouver :"&MotAff
                            ECRIRE "Il vous reste :"&vie&"vies."
                            CAS vie PARMIS
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
                        FINSI

                FINTANTQUE

            //Affichage de la victoire ou de la défaite du joueur 2
                SI (vie=0) ALORS
                    ECRIRE "Joueur 2 a perdue."
                    ECRIRE"_______  "
                    ECRIRE" |    |  "
                    ECRIRE" |    O  "
                    ECRIRE" |   /|\ "
                    ECRIRE" |   / \ "
                    ECRIRE" |       "
                    ECRIRE" |_______"
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

int main()
{

    //Progression du joueur 2
        char MotAff[TAILLE]="";

    //Mot à trouver
        char MotChercher[TAILLE]="";

    //i sert à parcourir les chaines de caractère, vie=nombre d'essais restant
        int i=0,vie=MAX;

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
                i=0;
                cpt=0;
                lettre=' ';

            //Demande du mot à trouvé au joueur 1
                printf("Joueur 1, veuillez entrer le mot a trouver :\n");
                fflush(stdin);
                gets(MotChercher);
                system("@cls||clear");

            //Initialisation du mot afficher au joueur 2
                for(i=0;i<strlen(MotChercher);i++){

                    MotAff[i]='_';

                }

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
                        for (i=0;i<strlen(MotChercher);i++){
                            if ((MotChercher[i]==lettre) && (MotAff[i]!=lettre)){
                                MotAff[i]=lettre;
                                cpt=cpt+1;
                            }
                        }

                    //Si la lettre n'est pas présente dans le mot alors le joueur 2 perd une vie
                        if(cpt==0){
                            vie=vie-1;
                        }

                    //Si il reste au moins un essai au joueur 2 alors on affiche sa progression
                        if(vie!=0){
                            printf("Voici les lettres trouver : %s\n\n",MotAff);
                            printf("Il vous reste : %d vies.\n\n",vie);
                            switch (vie) {
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

                }

            //Affichage de la victoire ou de la défaite du joueur 2
                if(vie==0){
                    printf("Joueur 2 a perdue.\n\n");
                    printf("_______  \n");
                    printf(" |    |  \n");
                    printf(" |    O  \n");
                    printf(" |   /|\\ \n");
                    printf(" |   / \\ \n");
                    printf(" |       \n");
                    printf(" |_______\n");
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
