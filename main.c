#include <stdio.h>

int main() {

    //Déclarations
    int joueur = 1;
    char choixJoueur[2] = {'X','O'};
    int choixTaille = 3, tailleReel = 0;
    int positionRemplie = 0;
    int test = 0;
    char posChoisie = ' ';

    //Définition de la taille réel
    tailleReel = choixTaille * choixTaille;

    //Déclaration de la grille
    char grille[tailleReel];

    //Initialisation de la grille
    for (int i = 0; i < tailleReel; ++i) {
        grille[i] = (char)(i+49);
    }

    while (1){

        //Remise à zéro de la sauvegarde de remplissage
        positionRemplie = 0;

        //Affichage de la grille
        for (int i = 0; i < tailleReel; ++i) {
            printf("%c|",grille[i]);
            if((i+1)%choixTaille == 0 ){
                printf("\n");
            }
        }

        //Demande de saisi aux joueurs
        printf("Joueur %d : (%c)", joueur,choixJoueur[joueur-1]);
        scanf(" %c",&posChoisie);

        //Affectation si case vide
        for (int i = 0; i < tailleReel; ++i) {
            //Si la valeur existe, remplissage
            if(grille[i] == posChoisie){
                //Remplissage de la grille
                grille[i] = choixJoueur[joueur-1];
                //Variable qui sauvegarde le remplissage
                positionRemplie = 1;
            }
        }

        //Vérification ligne par ligne
        for (int i = 0; i < tailleReel; i++) {test = 0;
            if(i%choixTaille == 0){
                for (int j = 0; j < (tailleReel/choixTaille) ; j++) {
                    if(grille[i+j] == choixJoueur[joueur-1]){
                        test++;
                    }
                }
            }
            if(test == choixTaille){
                break;
            }
        }
        if(test == choixTaille){
            break;
        }

        //Vérification colonne par colonne
        int i = 0;
        while (i != choixTaille){
            test = 0;
            if(i%choixTaille != 0 || i == 0) {
                for (int j = i; j < tailleReel; j += choixTaille) {
                    if(grille[i+j] == choixJoueur[joueur-1]){
                        test++;
                    }
                }
                if(test == choixTaille){
                    break;
                }
            }
            i++;
        }
        if(test == choixTaille){
            break;
        }

        //Vérification diagonal 1
        test = 0;
        for (int j = 0; j < tailleReel; j += choixTaille+1) {
            if(grille[j] == choixJoueur[joueur-1]){
                test++;
            }
        }
        if(test == choixTaille){
            break;
        }
        //Vérification diagonal 2
        test = 0;
        for (int j = choixTaille-1; j < tailleReel-1; j += choixTaille-1) {
            if(grille[j] == choixJoueur[joueur-1]){
                test++;
            }
        }
        if(test == choixTaille){
            break;
        }

        //Changement de joueur
        if(positionRemplie == 1) {
            if (joueur == 1) {
                joueur = 2;
            } else {
                joueur = 1;
            }
        }

    }

    if(test == choixTaille){
        printf("Joueur %d a gagné ! ",joueur);
    }


    return 0;
}
