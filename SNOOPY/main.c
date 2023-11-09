#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define Longueur 10
#define Largeur 20
char Plateau[Longueur][Largeur];
int SnoopyX,SnoopyY;
int balleX,balleY;
int murX,murY;
int temps=120;
int mur_cassableX,mur_cassableY;
int mur_piegeX,mur_piegeY;
int oiseauX,oiseauY,oiseau1X,oiseau1Y,oiseau2X,oiseau2Y,oiseau3X,oiseau3Y,test_oiseau,test_oiseau1,test_oiseau2,test_oiseau3;
int compteur;
int droit_pousser;
int droit_casser;
int droit_bouger=1;
int droit_chronometrer=1;
int vie = 3;
char coeur= '$';
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
                else if(caractere_lu=='C'){
                    mur_cassableX = i;
                    mur_cassableY = j;
                    Plateau[i][j]='C';
                    printf("%c",Plateau[i][j]);

                }
                else if(caractere_lu=='X'){
                    mur_piegeX = i;
                    mur_piegeY = j;
                    Plateau[i][j]='X';
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
int temps_ecoule;
int temps_restant =120;
void chrono(){
    if(temps_ecoule<120){
        while(droit_bouger==1){
            Sleep(1000);
            temps_ecoule++;
        }
    }
    temps_restant=120-temps_ecoule;
    printf("Temps restant: %d",temps_restant);

}

void barre_vie(){
    for (int i = 0; i <vie; ++i) {
        printf("%c",coeur);
    }
    printf("\n");
    if(Plateau[balleX][balleY]==Plateau[SnoopyX][SnoopyY] || temps_restant==0){
        vie--;
    }
    else if(Plateau[SnoopyX][SnoopyY]==Plateau[mur_piegeX][mur_piegeY]){
        vie= vie-3;
    }
}
void scores(){
    while(temps_ecoule<120){
        if(droit_chronometrer==1){
            Sleep(1000);
            temps_ecoule++;
            temps_restant=120-temps_ecoule;
        }
    }
    printf("Votre score est de : %d",temps_restant*100);
}
void affichage(){
    for (int i = 0; i < Longueur; ++i) {
        for (int j = 0; j < Largeur; ++j) {
            printf("%c", Plateau[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("Nombre de vies : ");
    barre_vie();
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
    fprintf(fichier_sauvegarde, "Oiseau4 : (%d, %d)\n", oiseau3X, oiseau3Y);

    fclose(fichier_sauvegarde);

    printf("Partie sauvegardee dans le fichier : %s\n", nomFichier);

}

/*
 * Cette fonction va nous permettre de charger la partie sauvegardée par la fonction d'avant. Elle utilise la même logique sauf que là nous sommes en mode r(read), on va donc ressortir les éléments sauvegardés dans le fichier
 * */

void chargerPartie(const char *nomFichier) {
    FILE *fichier_charge = fopen(nomFichier, "r");
    FILE  *fichier = fopen("NIVEAU1.txt","r");
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

void murCassable(){
    if(droit_casser==1){
        if(Plateau[SnoopyX][SnoopyY+1]==Plateau[mur_cassableX][mur_cassableY]){
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
        else if(Plateau[SnoopyX][SnoopyY-1]==Plateau[mur_cassableX][mur_cassableY]){
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
        else if(Plateau[SnoopyX+1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
        else if(Plateau[SnoopyX-1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
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
            droit_pousser=1;
        }
        else if(Plateau[SnoopyX][SnoopyY-1]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murY--;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;
            droit_pousser=1;
        }
        else if(Plateau[SnoopyX+1][SnoopyY]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murX++;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;
            droit_pousser=1;
        }
        else if(Plateau[SnoopyX-1][SnoopyY]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            murX--;
            Plateau[murX][murY]= 'M';
            droit_bouger=1;
            droit_pousser=1;
        }
    }

}
void touches(char commande){
    switch (commande) {
        case 'r':{
            if( SnoopyX-1>0){
                if(droit_pousser>=1  && Plateau[SnoopyX-1][SnoopyY]==Plateau[murX][murY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else if(droit_casser==0 && Plateau[SnoopyX-1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else{
                    Plateau[SnoopyX][SnoopyY] = ' ';
                    SnoopyX--;
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
            }

            break;
        }
        case 'f':{
            if(SnoopyX+1<Longueur-1){
                if((droit_pousser>=1 || droit_casser==0)&&Plateau[SnoopyX+1][SnoopyY]==Plateau[murX][murY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else if(droit_casser==0 && Plateau[SnoopyX+1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else{
                    Plateau[SnoopyX][SnoopyY] = ' ';
                    SnoopyX++;
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
            }
            break;
        }
        case 'd':{
            if(SnoopyY-1>0){
                if((droit_pousser>=1 || droit_casser==0) && Plateau[SnoopyX][SnoopyY-1]==Plateau[murX][murY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else if(droit_casser==0 && Plateau[SnoopyX][SnoopyY-1]==Plateau[mur_cassableX][mur_cassableY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else{
                    Plateau[SnoopyX][SnoopyY] = ' ';
                    SnoopyY--;
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }

            }
            break;
        }
        case 'g':{
            if(SnoopyY+1<Largeur-1){
                if((droit_pousser>=1 || droit_casser==0) && Plateau[SnoopyX][SnoopyY+1]==Plateau[murX][murY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else if(droit_casser==0 && Plateau[SnoopyX][SnoopyY+1]==Plateau[mur_cassableX][mur_cassableY]){
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }
                else{
                    Plateau[SnoopyX][SnoopyY] = ' ';
                    SnoopyY++;
                    Plateau[SnoopyX][SnoopyY] = 'S';
                }

            }
            break;
    }
        case 's':{
            sauvegarde();
            break;
        }
        case'p':{
            droit_chronometrer=0;
            chrono();
            char reprendre =_getch();
            if(reprendre=='p'){
                droit_bouger = 1;
            }
            break;
        }
        case'b':{
            droit_casser=1;
            murCassable();
            break;
        }

}
}
void oiseau(){
    if(Plateau[SnoopyX][SnoopyY]== Plateau[oiseauX][oiseauY]||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau1X][oiseau1Y] ||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau2X][oiseau2Y] ||
       Plateau[SnoopyX][SnoopyY] == Plateau[oiseau3X][oiseau3Y]){
            printf("Vous avez un oiseau\n");
            compteur++;
    }
}
int decalage_1,decalage_2,decalage_3,decalage_4;
void balle(){
    Plateau[balleX][balleY] = ' '; // Effacer la position actuelle de la balle
    if(Plateau[balleX+1][balleY]!='#' && decalage_1<4){
        balleX++;
        balleY++;
        Plateau[balleX][balleY] ='B';
        decalage_1++;
    }
    else if(Plateau[balleX][balleY+1]!='#'&& decalage_2<4){
        balleX--;
        balleY++;
        Plateau[balleX][balleY] ='B';
        decalage_2++;
    }
    else if(Plateau[balleX-1][balleY]!='#'&& decalage_3<4){
        balleX--;
        balleY--;
        Plateau[balleX][balleY] ='B';
        decalage_3++;
    }
    else if(Plateau[balleX][balleY-1]!='#'&& decalage_4<4){
        balleX++;
        balleY--;
        Plateau[balleX][balleY] ='B';
        decalage_4++;
    }
    else{
        decalage_1=0;
        decalage_2=0;
        decalage_3=0;
        decalage_4=0;
    }

}

void boucle(){
    plateau();
    while (1){
        system("CLS");
        affichage();
        oiseau();
        balle();
        mur();
        char commande = _getch();
        touches(commande);

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
    switch (choix) {
        case 1:{
            printf("Les regles du jeu sont les suivantes:\n");
            break;
        }
        case 2:{
            plateau();
                while (1){
                    if(vie>0){
                        system("CLS");
                        affichage();
                        oiseau();
                        balle();
                        mur();
                        murCassable();
                        char commande = _getch();
                        if (commande == 'p'){
                            printf("Vous etes en pause");
                            chrono();
                            touches(commande);
                            menu();
                        }
                        else if(commande == 's'){
                            sauvegarde();
                            menu();
                        }
                        touches(commande);
                        if (compteur == 4) {
                            scores();
                            Sleep(1000);
                            compteur=0;
                            menu();
                        }
                    }
                    else{
                        printf("\n\nGAME OVER\n\n");
                        Sleep(500);
                        vie = 3;
                        menu();
                    }
            }
        }

        case 3:{
            char nomFichier[50];
            printf("Entrez le nom du fichier de sauvegarde à charger : ");
            scanf("%s", nomFichier);
            chargerPartie(nomFichier);
            boucle();
            break;

        }
        case 4:{
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
        case 5:{

        }
        case 6:{
            printf("Vous avez fini");
            break;
        }
}
}
int main() {
    menu();
}