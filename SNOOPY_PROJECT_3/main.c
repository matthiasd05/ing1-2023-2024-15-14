#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Longueur 10
#define Largeur 20
char Plateau[Longueur][Largeur];
int SnoopyX,SnoopyY;
int balleX,balleY;
int murX,murY;
int mur_cassableX,mur_cassableY;
int mur_piegeX,mur_piegeY;
int oiseauX,oiseauY,oiseau1X,oiseau1Y,oiseau2X,oiseau2Y,oiseau3X,oiseau3Y,test_oiseau,test_oiseau1,test_oiseau2,test_oiseau3;
int compteur;
int droit_pousser;
int droit_casser;
int droit_bouger=1;
int droit_chronometrer=1;
int vie = 3;
int score_finale = 0;
char coeur= '$';
void plateau(){
    //On ouvre le fichier contenant notre plateau que l'on va associer à un tableau
    FILE *fichier;
    fichier= fopen("niveau1.txt","r");
    char caractere_lu;
    signed char texte[Longueur];
    // On parcourt toutes les cases du tableau
    for (int i = 0; i < Longueur ; ++i) {
        for (int j = 0; j <Largeur ; ++j) {
            //On lit chaque caractère de notre fichier texte et on les compare pour que les différents éléments soient affectés dans le tableau
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
        // On indique jusqu'où il est nécesaaire de lire le fichier
        fgets(texte,Longueur,fichier);
        printf("\n");
    }
    fclose(fichier);
}
int temps_ecoule;
int temps_restant =120;



void barre_vie(){
    printf("\n");// Saut a la ligne
    // Affiche le nombre de vies actuelles sous la forme de symboles de dollars
    printf("Nombre de vies : ");
    for (int i = 0; i < vie; ++i) {
        printf("%c", coeur);
    }
    printf("\n");// Saut de ligne
    // Vérifie certaines conditions pour ajuster le nombre de vies
    if(Plateau[balleX][balleY]==Plateau[SnoopyX][SnoopyY] || temps_restant==0){
        // Décrémente le nombre de vies si Snoopy est sur la même case que la balle ou si le temps est écoulé
        vie--;
    }
    else if(Plateau[SnoopyX][SnoopyY]==Plateau[mur_piegeX][mur_piegeY]){
        // Décrémente le nombre de vies de 3 si Snoopy est sur la même case qu'un block piège
        vie = vie - 3;
    }
}


void chrono(){
    // Le temps imparti est de 120 secondes cependant nous avons divisé les secondes en 5*0.2s pour permettre une meilleure expérience de jeu
    while (droit_chronometrer==1){
        if(temps_ecoule<600){
            //On incrémente à chaque fois notre temps coulé
            temps_ecoule++;
            Sleep(200);
            temps_restant = 600 - temps_ecoule;
            droit_chronometrer = 0;
        }
    }
    if(temps_ecoule%5 == 0){
        //On affiche le temps qu'il nous reste
        printf("%d secondes",temps_restant/5);
    }
    droit_chronometrer = 1;

}
void scores(){
    // Le score est en fonction du temps donc on compte les secondes comme dans la fonction précédente
    temps_ecoule++;
    Sleep(1000);
    temps_restant = 120 - temps_ecoule;
    int score = temps_restant*100;
    printf("VOTRE SCORE EST DE %d\n\n",score);
    score_finale=score_finale+score;
}
void affichage(){
    // La fonction comme son nom l'indique permet d'afficher les éléments nécessaires à l'écran
    for (int i = 0; i < Longueur; ++i) {
        for (int j = 0; j < Largeur; ++j) {
            printf("%c", Plateau[i][j]);
        }
        printf("\n");
    }
    barre_vie();
    printf("Temps restant : ");
    chrono();
}
void sauvegarde(){
    /*
     * On va créer un tableau pouvant contenir jusqu'à 50 caractères qui va représenter le nom du fichier créé en 1s
     */
    char nomFichier[50];
    // Invite l'utilisateur à entrer le nom du fichier de sauvegarde
    printf("Entrez le nom du fichier de sauvegarde : ");
    // Lit le nom du fichier à partir de l'entrée utilisateur et le stocke dans le tableau nomFichier
    scanf("%s", nomFichier);
    // Pause d'une seconde (1000 millisecondes)
    Sleep(1000);

    /* On va déclarer vers une structure FILE ce qui va nous permettre de pouvoir réaliser des opérations sur nos fichiers
     * puis on on ouvre (ici on le crée) et on le lit (w= write)
     */
    FILE *fichier_sauvegarde;
    fichier_sauvegarde = fopen(nomFichier, "w");

    // Cela va donc écrire les positions actuelles des éléments dans le fichier puis le fermer
    fprintf(fichier_sauvegarde, "Snoopy : (%d, %d)\n", SnoopyX, SnoopyY);
    fprintf(fichier_sauvegarde, "Oiseau1 : (%d, %d)\n", oiseauX, oiseauY);
    fprintf(fichier_sauvegarde, "Oiseau2 : (%d, %d)\n", oiseau1X, oiseau1Y);
    fprintf(fichier_sauvegarde, "Oiseau3 : (%d, %d)\n", oiseau2X, oiseau2Y);
    fprintf(fichier_sauvegarde, "Oiseau4 : (%d, %d)\n", oiseau3X, oiseau3Y);

    // Ferme le fichier après avoir écrit les informations
    fclose(fichier_sauvegarde);

    // Affiche un message indiquant que la partie a été sauvegardée dans le fichier spécifié
    printf("Partie sauvegardee dans le fichier : %s\n", nomFichier);
}


void chargerPartie(const char *nomFichier) {
    /*
     * Cette fonction va nous permettre de charger la partie sauvegardée par la fonction d'avant.
     * Elle utilise la même logique sauf que là nous sommes en mode r (read),
     * on va donc ressortir les éléments sauvegardés dans le fichier
     */

    // Ouvre le fichier spécifié en mode lecture (read)
    FILE *fichier_charge = fopen(nomFichier, "r");

    // Ouvre le fichier "NIVEAU1.txt" en mode lecture (read)
    FILE *fichier = fopen("NIVEAU1.txt", "r");

    // Variables pour stocker les données lues depuis le fichier
    int sX, sY, bX, bY, mX, mY, oX, oY, o1X, o1Y, o2X, o2Y, o3X, o3Y;

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
    oiseau3X = o3X;
    oiseau3Y = o3Y;

    // Met à jour le plateau avec les positions des éléments chargés
    Plateau[SnoopyX][SnoopyY] = 'S';
    Plateau[balleX][balleY] = 'B';
    Plateau[murX][murY] = 'M';
    Plateau[oiseauX][oiseauY] = 'O';
    Plateau[oiseau1X][oiseau1Y] = 'O';
    Plateau[oiseau2X][oiseau2Y] = 'O';
    Plateau[oiseau3X][oiseau3Y] = 'O';
}


void murCassable(){
    // Vérifie si le joueur a le droit de casser un mur
    if(droit_casser==1){
        // Vérifie si Snoopy est à côté d'un mur cassable (en haut)
        if(Plateau[SnoopyX][SnoopyY+1]==Plateau[mur_cassableX][mur_cassableY]){
            // Casse le mur en mettant à jour la case correspondante dans le plateau
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
            // Vérifie si Snoopy est à côté d'un mur cassable (en dessous)
        else if(Plateau[SnoopyX][SnoopyY-1]==Plateau[mur_cassableX][mur_cassableY]){
            // Casse le mur en mettant à jour la case correspondante dans le plateau
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
            // Vérifie si Snoopy est à côté d'un mur cassable (a droite)
        else if(Plateau[SnoopyX+1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
            // Casse le mur en mettant à jour la case correspondante dans le plateau
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
            // Vérifie si Snoopy est à côté d'un mur cassable (a gauche)
        else if(Plateau[SnoopyX-1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
            // Casse le mur en mettant à jour la case correspondante dans le plateau
            Plateau[mur_cassableX][mur_cassableY]=' ';
        }
    }
}


void mur(){
    static int droit_bouger=0;
    //Vérifie si le joueur a le droit de bouger un mur
    if(droit_bouger==0){
        //Vérifie si Snoopy est à côté d'un mur poussable (en haut)
        if(Plateau[SnoopyX][SnoopyY+1]==Plateau[murX][murY] && droit_bouger==0){
            Plateau[murX][murY]=' ' ;
            //Remplace l'ancienne case par un espace vide
            murY++;
            //Ajoute 1 à la coordonnée en Y (ordonnée du mur)
            Plateau[murX][murY]= 'M';
            //Mets la lettre M sur la nouvelle case
            droit_bouger=1;
        }
        droit_pousser=1;
    }

}
void touches(char commande){
    if (droit_bouger == 1){
        // La fonction s'occupe des déplacements, elle est appelée suite à la fnction getch qui détete l'appui du touche et permet donc les différents déplacements
        switch (commande) {
            case 'r':{
                if( SnoopyX-1>0){
                    //Permet d'éviter que Snoopy avance lorsqu'il n'a pas le droit
                    if(droit_pousser>=1  && Plateau[SnoopyX-1][SnoopyY]==Plateau[murX][murY]){
                        Plateau[SnoopyX][SnoopyY] = 'S';
                    }
                    else if(droit_casser==0 && Plateau[SnoopyX-1][SnoopyY]==Plateau[mur_cassableX][mur_cassableY]){
                        Plateau[SnoopyX][SnoopyY] = 'S';
                    }
                        // Si Snoopy peut se déplacer alors il n'y a qu'à effacer sa position puis l'afficher àla position suivante
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
                    if(droit_pousser>=1 &&Plateau[SnoopyX+1][SnoopyY]==Plateau[murX][murY]){
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
                    if(droit_pousser>=1 && Plateau[SnoopyX][SnoopyY-1]==Plateau[murX][murY]){
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
                    if(droit_pousser>=1&& Plateau[SnoopyX][SnoopyY+1]==Plateau[murX][murY]){
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
                //Appel de la fonction sauvegarde
                sauvegarde();
                break;
            }
            case'p':{
                char reprendre =_getch();
                if(reprendre=='p'){
                    droit_bouger = 1;
                }
                break;
            }
            case'c':{
                droit_casser=1;
                murCassable();
                break;
            }
        }
    }
}
int compte_oiseau1,compte_oiseau2,compte_oiseau3,compte_oiseau4;
void oiseau(){
    // Vérifie si Snoopy est sur la même case qu'un oiseau et si cet oiseau n'a pas encore été rencontré
    if(Plateau[SnoopyX][SnoopyY] == Plateau[oiseauX][oiseauY] && compte_oiseau1 == 0){
        // Affiche un message indiquant que Snoopy a rencontré un oiseau
        printf("Vous avez un oiseau\n");
        // Incrémente le compteur global des rencontres d'oiseaux
        compteur++;
        // Indique que cet oiseau a été rencontré en mettant à jour la variable de compte
        compte_oiseau1++;
    }
        // Répète le processus pour chaque oiseau, en vérifiant s'il est sur la même case que Snoopy et s'il n'a pas encore été rencontré
    else if(Plateau[SnoopyX][SnoopyY] == Plateau[oiseau1X][oiseau1Y] && compte_oiseau2 == 0){
        printf("Vous avez un oiseau\n");
        compteur++;
        compte_oiseau2++;
    }
    else if(Plateau[SnoopyX][SnoopyY] == Plateau[oiseau2X][oiseau2Y] && compte_oiseau3 == 0){
        printf("Vous avez un oiseau\n");
        compteur++;
        compte_oiseau3++;
    }
    else if(Plateau[SnoopyX][SnoopyY] == Plateau[oiseau3X][oiseau3Y] && compte_oiseau4 == 0){
        printf("Vous avez un oiseau\n");
        compteur++;
        compte_oiseau4++;
    }
}

int decalage_1,decalage_2,decalage_3,decalage_4;

void balle(){
    Plateau[balleX][balleY] = ' '; // Effacer la position actuelle de la balle
    if(Plateau[balleX+1][balleY]!='#' && decalage_1<4){
        balleX++; //Faire en sorte que la balle se déplace en incrémentant ses coordonnées
        balleY++;
        Plateau[balleX][balleY] ='B'; //Remplacer l'espace vide de la nouvelle case par un B qui symbolise la balle
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
    // La boucle est ici utilisée seulement pour les tests autre que lorsque l'on appuie sur 2
    plateau();
    while (1){
        system("CLS");
        affichage();
        oiseau();
        balle();
        mur();
        murCassable();
        if(kbhit()){
            char commande = _getch();
            touches(commande);
        }

    }
}
int continuer = 1;
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
            printf("Les regles du jeu sont les suivantes:\n"
                   "1. Informations générales\n"
                   "    Tout d'abord, le jeu Le Revanche de Snoopy se compose d'un plateau de jeu, du personnage de Snoopy, d'une balle, de différents types de murs, et de quatres oiseaux à récupérer.\n"
                   "    Un niveau se présente de la manière suivante : Snoopy doit se déplacer sur le plateau afin de récupérer les quatres oiseaux. Pour réussir un niveau il faut : récupérer\n"
                   "    l'ensemble des oiseaux présents sur le plateau de jeu en mois de 2 minutes, et sans se faire toucher par la balle, au quel cas, Snoopy perdra une vie sur les trois qu'il possède au début.\n"
                   "    De plus, si le joueur ne fini pas le niveau dans le temps imparti, il perd également une vie.\n"
                   "2. Snoopy\n"
                   "    Au début d'un niveau, Snoopy est placé sur une case du plateau et pour se déplacer et récupérer le oiseaux, il peut aller sur les cases se trouvant en haut, en bas, à gauche et à droit de sa position.\n"
                   "    Il ne peut donc pas se déplacer en diagonale, et ne peut pas non plus se déplacer plus d'une case à la fois. Finalement, il ne peut pas sortir du niveau en traversant les murs extérieurs du plateau.\n"
                   "3. La balle\n"
                   "    Contrairement à Snoopy, la balle peut se déplacer exclusivement en diagonale. Lorsqu'elle rencontre un mur délimitant le plateau, elle rebonit.\n"
                   "    La vitesse de la balle ne varie pas. Et la balle ne peut traverser tout ce qu'elle croise sur son chemein hormis les murs délimitant le plateau et Snoopy.\n"
                   "    En effet, lorsque la balle rencontre Snoopy, ce dernier perd une vie et retourne au début du niveau.\n"
                   "4. Les objets\n"
                   "    Il y a différents types de murs : les murs poussables, cassables, et piégés.\n"
                   "        - Les murs poussables : lorsque Snoopy se trouve à côté de ce type de bloc, il peut aller sur la case où se trouve le bloc et pousse donc le bloc sur la case d'après.\n"
                   "          Lorsqu'il se trouve à côté d'un mur délimitant le plateau, ce bloc ne peut pas être poussé en dehors du plateau.\n"
                   "        - Les murs cassables : lorsque Snoopy se trouve à côté d'un bloc poussable, ce bloc agit comme un bloc normal (comme un bloc qui délimite le plateau), mais lorsque le joueur appuis sur la touche 'c',\n"
                   "          le mur cassable à côté de Snoopy, se casse.\n"
                   "        - Les murs piégés : lorsque Snoopy rentre en contact avec un bloc piégé, Snoopy perd une vie et le joueur doit recommencer le niveau.\n"
                   "5. Victoire/Défaite\n"
                   "    Pour gagner, le joueur doit avoir récupérer tous les oiseaux sur le plateau en moins de 120 secondes. Lorsque c'est le cas, le niveau d'après se charge automatiquement.\n"
                   "    Lorsque le joueur n'a plus de vies, un écran 'GAME OVER' s'affiche et il revient au menu du jeu et recommence une nouvelle partie.\n"
                   "6. Le temps\n"
                   "    Pour chaque niveau, le joueur dispose de 120 secondes pour termier le niveau. Lorsqu'il atteint 0, le joueur perd une vie et recommence le niveau.\n"
                   "7. Scores\n"
                   "    Le scores se compte de la manière suivante : pour calculer le score, il faut prendre le nombre de secondes restante au niveau puis les multiplier par 100 ce qui constitue le score du niveau.\n"
                   "    Le score total est simplement la somme des scores obtenus à chaque niveau.\n"
                   "8. Sauvegarde et chargement de la partie sauvegardé\n"
                   "    À tout momentn le joueur peut appuier sur la touche 's' du clavier afin de sauvegarder la partie en cours. Le jeu demande donc sous quel nom le joueur veut sauvegarder la partie, puis le jeu sauvegarde la partie et retourne au menu principal\n"
                   "    Pour charger une partie, il faut aller dans le menu principal et aller dans l'onglet 'charger une partie' puis entrer le nom de la partie à charger.\n"
                   "9. Mot de passe\n"
                   "    Chaque niveau du jeu est accessible par un mot de passe défini par les réalisateurs du jeu.\n"
                   "10. Le mode pause\n"
                   "    Si le joueur appuis sur la touche 'p' du clavier, le jeu se met en pause, c'est-à-dire que le temps et la balle s'arrêtent et Snoopy ne peut plus se déplacer. Pour enlever le\n"
                   "    mode pause, le joueur doit appuier de nouveau sur la touche 'p' du clavier.\n"
                   "Fin des règles du jeu.");
            break;
        }
        case 2:{
            //Le fait d'appuyer sur 2 vanous afficher notre fichier texte qui est alors devenu un tableaau
            plateau();
            while (vie>0&& compteur<4){
                // Une boucle se met en route pour pouvoir jouer tant que les conditions sont réunies et le cls permet d'actualiser à chaque fois l'écran
                system("CLS");
                affichage();
                //Appel de toutes les fonctions annexes permettant une bonne exécution du jeu
                oiseau();
                balle();
                mur();
                murCassable();
                // La commande suivante va vérifier s'il y a eu une détection des touches
                if(kbhit()){
                    // S'il y a eu une touche, alors on va récupérer ce à quoi elle correspond puis après utiliser nos fonctions déjà définis permettant de bouger, la pause ou encore la sauvegarde
                    char commande = _getch();
                    if (commande == 'p'){
                        droit_chronometrer = 0;
                        droit_bouger = 0;
                        printf("Vous etes en pause");
                        menu();
                        printf("\n Appuyer sur n'importe quelle touche : ");
                        droit_bouger = 1;
                        droit_chronometrer = 1;
                    }
                    else if(commande == 's'){
                        sauvegarde();
                        menu();
                    }
                    // Si les touches appuyées sont différentes de celles précisées alors ce sont celles définies dans la fonction prévue
                    touches(commande);
                }
            }
            if (compteur == 4) {
                //On indique à l'utilisateur qu'il a fini le niveau en lui annoçant son score puis par la suite, il accédera au niveau 2
                printf("Bravo vous avez reussi le niveau !!");
                scores();
                Sleep(1000);
                printf("EN ATTENTE DU PROCHAIN NIVEAU");
                Sleep(3000);
                temps_ecoule = 0;
                compteur = 0;
                droit_bouger=0;
                droit_pousser = 0;
                vie = 3;
            }
            else if (vie<=0 ){
                // Ici, on indique à l'utilisateur qu'il a perdu, on le renvoit au menu et on réinitialise tout s'il veut recommencer une partie
                printf("\n\n**GAME OVER**\n\n");
                Sleep(500);
                vie = 3;
                temps_ecoule = 0;
                compteur = 0;
                droit_pousser = 0;
                continuer = 0;
                decalage_1=0;
                decalage_2=0;
                decalage_3=0;
                decalage_4=0;
                compte_oiseau1=0;
                compte_oiseau2= 0;
                compte_oiseau3 =0;
                compte_oiseau4 = 0;
                Plateau[SnoopyX][SnoopyY] = 'S';
                Plateau[murX][murY] = 'M';
                Plateau[balleX][balleY] = 'B';
                Plateau[mur_cassableX][mur_cassableY] = 'C';
                Plateau[mur_piegeX][mur_piegeY] = 'X';
                Plateau[oiseauX][oiseauY] = 'O';
                Plateau[oiseau1X][oiseau1Y] = 'O';
                Plateau[oiseau2X][oiseau2Y] = 'O';
                Plateau[oiseau3X][oiseau3Y] = 'O';
                menu();
            }
            continuer = 1;
            break;
        }

        case 3:{
            // On associe le nom du fichier à une chaine d'au plus 50 caractères et on appelle alors la fonction prévue pour la sauvegarde
            char nomFichier[50];
            printf("Entrez le nom du fichier à charger : ");
            scanf("%s", nomFichier);
            chargerPartie(nomFichier);
            boucle();
            break;

        }
        case 4:{
            //On utilise encore une fois une chaîne de caractères, en effet on va comparer le code entré avec le code voulu pour ainsi débloquer le niveau
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
                printf("Le mot de passe est incorrect !.\n Voulez-vous reessayer si Non:0/ si Oui:1");
                scanf("%d",&continuer);
            } while (continuer == 1);
            menu();

        }
        case 5:{
            printf("Votre score est de %d",score_finale);
        }
        case 6:{
            printf("Vous avez fini");
            break;
        }
    }
}
// On met notre menu qui regroupe lui-même toutes les fonctions dans le main
int main() {
    menu();
}