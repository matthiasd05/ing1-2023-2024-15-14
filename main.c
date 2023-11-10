#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Longueur 10
#define Largeur 20
char Plateau[Longueur][Largeur];
int SnoopyX;
int SnoopyY;
int balleX;
int balleY;
int murX;
int murY;
int murCX;
int mur CY;
int oiseauX;
int oiseauY;
int test_oiseau;
int test_oiseau1;
int test_oiseau2;
int test_oiseau3;
int oiseau1X;
int oiseau1Y;
int oiseau2X;
int oiseau2Y;
int oiseau3X;
int oiseau3Y;
int compteur;
void plateau(){
    FILE *fichier;
    fichier= fopen("niveau1.txt","r");
    char caractere_lu;
    signed char texte[Longueur];
    for (int i = 0; i < Longueur ; ++i) {
        for (int j = 0; j <Largeur ; ++j) {
            caractere_lu = fgetc(fichier);
            if(caractere_lu != EOF){
                if(caractere_lu== '#'){
                    Plateau[i][j] = '#';
                    printf("%c",Plateau[i][j]);
                }
                else if(caractere_lu=='S'){
                    SnoopyX = i;
                    SnoopyY = j;
                    Plateau[i][j]='S';
                    printf("%c",Plateau[i][j]);

                }
                else if(caractere_lu=='B'){
                    balleX = i;
                    balleY = j;
                    Plateau[i][j]='B';
                    printf("%c",Plateau[i][j]);

                }
                else if(caractere_lu=='O'){
                    if(test_oiseau==0){
                        oiseauX = i;
                        oiseauY = j;
                        Plateau[i][j]='O';
                        printf("%c",Plateau[i][j]);
                        test_oiseau++;
                    }
                    else if(test_oiseau1==0){
                        oiseau1X = i;
                        oiseau1Y = j;
                        Plateau[i][j]='O';
                        printf("%c",Plateau[i][j]);
                        test_oiseau1++;
                    }
                    else if(test_oiseau2==0){
                        oiseau2X = i;
                        oiseau2Y = j;
                        Plateau[i][j]='O';
                        printf("%c",Plateau[i][j]);
                        test_oiseau2++;
                    }
                    else if(test_oiseau3==0){
                        oiseau3X = i;
                        oiseau3Y = j;
                        Plateau[i][j]='O';
                        printf("%c",Plateau[i][j]);
                        test_oiseau3++;
                    }

                }
                else if(caractere_lu=='M'){
                    murX = i;
                    murY = j;
                    Plateau[i][j]='M';
                    printf("%c",Plateau[i][j]);

                }
                else if(caractere_lu== ' '){
                    Plateau[i][j] = ' ';
                    printf("%c",Plateau[i][j]);
                }
            }

        }
        fgets(texte,Longueur,fichier);
        printf("\n");
    }
    fclose(fichier);

}
void sauvegarde(){
    /*
     * On va créer un tableau pouvant contenir jusqu'à 50 caractères qui va représenter le nom du fichier créé en 1s
     */
    char nomFichier[50];
    printf("Entrez le nom du fichier de sauvegarde : ");
    scanf("%s", nomFichier);
    Sleep(1000);
    /*On va déclarer vers une structure FILE ce qui va nous permettre de pouvoir réaliser des opérations sur nos fichiers puis on on ouvre (ici on le crée)et on le lit (w= write)*/
    FILE *fichier_sauvegarde;
    fichier_sauvegarde = fopen(nomFichier, "w");

    // Cela va donc écrire les positions actuelles des éléments dans le fichier puis le fermer
    fprintf(fichier_sauvegarde, "Snoopy : (%d, %d)\n", SnoopyX, SnoopyY);
    fprintf(fichier_sauvegarde, "Oiseau1 : (%d, %d)\n", oiseauX, oiseauY);
    fprintf(fichier_sauvegarde, "Oiseau2 : (%d, %d)\n", oiseau1X, oiseau1Y);
    fprintf(fichier_sauvegarde, "Oiseau3 : (%d, %d)\n", oiseau2X, oiseau2Y);
    fprintf(fichier_sauvegarde, "Oiseau3 : (%d, %d)\n", oiseau3X, oiseau3Y);

    fclose(fichier_sauvegarde);

    printf("Partie sauvegardee dans le fichier : %s\n", nomFichier);

}

/*
 * Cette fonction va nous permettre de charger la partie sauvegardée par la fonction d'avant. Elle utilise la même logique sauf que là nous sommes en mode r(read), on va donc ressortir les éléments sauvegardés dans le fichier
 * */

void chargerPartie(const char *nomFichier) {
    FILE *fichier_charge = fopen(nomFichier, "r");

    // Variables pour stocker les données lues depuis le fichier
    int sX, sY, bX, bY, mX, mY,oX, oY, o1X, o1Y, o2X, o2Y, o3X, o3Y;

    // Lire les données du fichier pour restaurer l'état du jeu
    fscanf(fichier_charge, "Snoopy : (%d, %d)\n", &sX, &sY);
    fscanf(fichier_charge, "Balle : (%d, %d)\n", &bX, &bY);
    fscanf(fichier_charge, "Mur : (%d, %d)\n", &mX, &mY);
    fscanf(fichier_charge, "Oiseau1 : (%d, %d)\n", &oX, &oY);
    fscanf(fichier_charge, "Oiseau2 : (%d, %d)\n", &o1X, &o1Y);
    fscanf(fichier_charge, "Oiseau3 : (%d, %d)\n", &o2X, &o2Y);
    fscanf(fichier_charge, "Oiseau4 : (%d, %d)\n", &o3X, &o3Y);


    // Fermer le fichier après avoir lu les données
    fclose(fichier_charge);

    // Restaurer les valeurs pour la partie en cours
    SnoopyX = sX;
    SnoopyY = sY;
    balleX = bX;
    balleY = bY;
    murX = mX;
    murY = mY;
    oiseauX = oX;
    oiseauY = oY;
    oiseau1X = o1X;
    oiseau1Y = o1Y;
    oiseau2X = o2X;
    oiseau2Y = o2Y;
    oiseau2X = o3X;
    oiseau2Y = o3Y;

    Plateau[SnoopyX][SnoopyY] = 'S';
    Plateau[balleX][balleY] = 'B';
    Plateau[murX][murY] = 'M';
    Plateau[oiseauX][oiseauY] = 'O';
    Plateau[oiseau1X][oiseau1Y] = 'O';
    Plateau[oiseau2X][oiseau2Y] = 'O';
    Plateau[oiseau3X][oiseau3Y] = 'O';


}

void touches(char commande){
    switch (commande) {
        case 'r':{
            if( SnoopyX-1>0){
                Plateau[SnoopyX][SnoopyY] = ' ';
                SnoopyX--;
                Plateau[SnoopyX][SnoopyY] = 'S';
            }
            break;
        }
        case 'f':{
            if(SnoopyX+1<Longueur-1){
                Plateau[SnoopyX][SnoopyY] = ' ';
                SnoopyX++;
                Plateau[SnoopyX][SnoopyY] = 'S';
            }
            break;
        }
        case 'd':{
            if(SnoopyY-1>0){
                Plateau[SnoopyX][SnoopyY] = ' ';
                SnoopyY--;
                Plateau[SnoopyX][SnoopyY] = 'S';
            }
            break;
        }
        case 'g':{
            if(SnoopyY+1<Largeur-1){
                Plateau[SnoopyX][SnoopyY] = ' ';
                SnoopyY++;
                Plateau[SnoopyX][SnoopyY] = 'S';
            }
            break;
    }
        case 's':{
            sauvegarde();
            break;
        }
}
}
void oiseau(){
    if(Plateau[SnoopyX][SnoopyY]== Plateau[oiseauX][oiseauY]||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau1X][oiseau1Y] ||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau2X][oiseau2Y] ||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau3X][oiseau3Y]){
            printf("Vous avez un oiseau");
            compteur++;
    }
}
void affichage(){
    for (int i = 0; i < Longueur; ++i) {
        for (int j = 0; j < Largeur; ++j) {
            printf("%c", Plateau[i][j]);
        }
        printf("\n");
    }

}
void mur(){
    static int droit_bouger=0;
    if(droit_bouger==0){
        if(Plateau[SnoopyX][SnoopyY+1]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murY++;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;

        }
        else if(Plateau[SnoopyX][SnoopyY-1]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murY--;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;

        }
        else if(Plateau[SnoopyX+1][SnoopyY]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murX++;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;
        }
        else if(Plateau[SnoopyX-1][SnoopyY]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murX--;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;
        }
    }
}

void murCassable(){
    static int droit_casser=0;
    if(droit_casser==0){
        if(Plateau[SnoopyX][SnoopyY+1]==Plateau[murCX][murCY] && droit_casser==0){
            //Plateau[murX][murY]=' ' ;
            char commande = _getch();
            if(commande == 'b'){
                Plateau[murCX][murCY]= ' ';
                droit_casser=1;
            }
        }
        else if(Plateau[SnoopyX][SnoopyY-1]==Plateau[murCX][murCY] && droit_casser==0){
            Plateau[murCX][murCY]=' ' ;
            char commande = _getch();
            if(commande == 'b'){
                Plateau[murCX][murCY]= ' ';
                droit_casser=1;
            }
        }
        else if(Plateau[SnoopyX+1][SnoopyY]==Plateau[murCX][murCY] && droit_casser==0){
            Plateau[murCX][murCY]=' ' ;
            char commande = _getch();
            if(commande == 'b'){
                Plateau[murCX][murCY]= ' ';
                droit_casser=1;
            }
        }
        else if(Plateau[SnoopyX-1][SnoopyY]==Plateau[murCX][murCY] && droit_casser==0){
            Plateau[murCX][murCY]=' ' ;
            char commande = _getch();
            if(commande == 'b'){
                Plateau[murCX][murCY]= ' ';
                droit_casser=1;
            }
        }
    }
}

void balle(){
    //La boucle se répète tant que la balle n'est pas au même endroit que Snoopy
    while(Plateau[balleX][balleY]!= Plateau[SnoopyX][SnoopyY]){
        //On définit 4 boucles qui vont faire en sorte que la balle se déplace sur toute la carte, selon les
        //coordonnées X et Y
        //Lorsque la balle se déplace son ancienne case est remplacée par un espace vide, et l'espace de la nouvelle
        //case devient un B
        for (int i = 0; i <=7 ; ++i) {
            Plateau[balleX][balleY]=' ';
            balleX++;
            balleY++;
            Plateau[balleX][balleY]='B';
        }
        for (int i = 0; i <=4 ; ++i) {
            Plateau[balleX][balleY]=' ';
            balleX--;
            balleY++;
            Plateau[balleX][balleY]='B';
        }
        for (int i = 0; i <=3 ; ++i) {
            Plateau[balleX][balleY]=' ';
            balleX--;
            balleY--;
            Plateau[balleX][balleY]='B';
        }
        for (int i = 0; i <=5; ++i) {
            Plateau[balleX][balleY]=' ';
            balleX++;
            balleY--;
            Plateau[balleX][balleY]='B';
        }
    }
}

//On définit un menu qui va grâce à un switch permettre à l'utilisateur de faire ce qu'il veut selon ses choix
void menu(){
    int choix;
    printf("BIENVENUE DANS L'EXPEREIENCE SNOOPY!!!\n\n");
    printf("@@@@@@@@@@@@@@@@@@@@@@&#5J??J5#@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@@@&G7.      :75&@@@@@@\n"
           "@@@@@@@@@@@&BG5555Y7^            ^G@@@@@\n"
           "@@@@@@@@@B?:                    : :B@@@@\n"
           "@@@@@@@&J.         ~P       ..!P5G!?@@@@\n"
           "@@@@@@@J           .7.     :7JBG#BG^#@@@\n"
           "@@@@BYB^                   J7#GB##B^B@@@\n"
           "@@@P^JB!              .?. :YJ&####7?&@@@\n"
           "@@@#G&&#?:           :~^  .Y7&##B77&@@@@\n"
           "@@@@@@@@@&G5J?7!~~~^^:   ~Y#?JYJJG@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@&BY. .P@@@@##&@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@@@@P?5@@@@@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@@@B!:7@@@@@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@@Y:   P@@@@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@J   ...P@@@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@B.   7^ ~#@@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@B    J. ~G&@@@@@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@&J:. J!^!5&B#&&@@@@@@@@\n"
           "@@@@@@@@@@@@@@@@@@@&G77?!G@&5?7?G@@@@@@@\n"
           "@@@@@@@@@@@@&B5JP5YYY^7! J##&@@@@@@@@@@@\n"
           "@@@@@@@@@@@&?!!J!^.: ...  .:~P@@@@@@@@@@\n"
           "@@@@@@@@@@@@##&#BGGBPPGGGGG##&@@@@@@@@@@\n");
    printf("\n1.Regles du jeu\n2.Lancer un nouveau Jeu\n3.Charger une partie\n4.Mot de passe\n5.Scores\n6.Quitter\n");
    scanf("%d",&choix);
    switch (choix) { //ce choix permet de choisir ce que l'on veut faire entre les 6 choix proposés
        case 1:{
            printf("Les regles du jeu sont les suivantes:\n"); 
            break;
        }
       
        case 2:{ //ce choix permet de lancer un nouveau jeu, on va ensuite appeler toutes les fonctions qui permettent 
            // au jeu de fonctionner : le plateau qui va imprimer la carte, puis tous les objets utilisés dans le jeu
            //ainsi que les fonctions de déplacements et de jeu
            plateau();
            while (1){
                affichage();
                oiseau();
                mur();
                char commande = _getch();
                if(commande == 's'){
                    touches(commande);
                    menu();
                }
                touches(commande);
                if (compteur == 4) {
                    printf("Le niveau est fini");
                    Sleep(1000);
                    menu();
                }
            }
        }

        case 3:{ //ce choix appelle la fonction sauvegarde
            char nomFichier[50];
            printf("Entrez le nom du fichier de sauvegarde à charger : "); 
            scanf("%s", nomFichier);
            chargerPartie(nomFichier);
            boucle();
            break;
        }
        
        case 4:{ //ce choix appelle la fonction mot de passe
            char mdp[20];
            int continuer =1;
            do {
                printf("Entrer le mode passe: ");
                scanf("%s",mdp);
                if(strcmp(mdp,"NIVEAU1")==0){
                    boucle();
                }
                else if(strcmp(mdp,"NIVEAU2")==0){

                }
                else if(strcmp(mdp,"NIVEAU3")==0){

                }
                printf("Ce n'est pas le bon mot de passe.\n Voulez vous reessayer Non:0/ Oui:1");
                scanf("%d",&continuer);
            } while (continuer == 1);
            menu();

        }
        case 5:{ //ce choix permet d'afficher les scores

        }
        case 6:{ //ce choix permet de quitter le jeu
            printf("Vous avez fini");
            break;
        }
}
int main() {
    menu();
}
