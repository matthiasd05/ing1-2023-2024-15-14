
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

    fprintf(fichier_sauvegarde,"%d ",SnoopyX);
    fprintf(fichier_sauvegarde,"%d ",SnoopyY);
    fprintf(fichier_sauvegarde,"%d ",murX);
    fprintf(fichier_sauvegarde,"%d ",murY);
    fprintf(fichier_sauvegarde,"%d ",mur_cassableX);
    fprintf(fichier_sauvegarde,"%d ",mur_cassableY);
    fprintf(fichier_sauvegarde,"%d ",mur_piegeX);
    fprintf(fichier_sauvegarde,"%d ",mur_piegeY);
    fprintf(fichier_sauvegarde,"%d ",balleX);
    fprintf(fichier_sauvegarde,"%d ",balleY);
    fprintf(fichier_sauvegarde,"%d ",oiseauX);
    fprintf(fichier_sauvegarde,"%d ",oiseauY);
    fprintf(fichier_sauvegarde,"%d ",oiseau1X);
    fprintf(fichier_sauvegarde,"%d ",oiseau1Y);
    fprintf(fichier_sauvegarde,"%d ",oiseau2X);
    fprintf(fichier_sauvegarde,"%d ",oiseau2Y);
    fprintf(fichier_sauvegarde,"%d ",oiseau3X);
    fprintf(fichier_sauvegarde,"%d ",oiseau3Y);

    // Cela va donc écrire les positions actuelles des éléments dans le fichier puis le fermer

    // Ferme le fichier après avoir écrit les informations
    fclose(fichier_sauvegarde);

    // Affiche un message indiquant que la partie a été sauvegardée dans le fichier spécifié
    printf("Partie sauvegardee dans le fichier : %s\n", nomFichier);
}


void chargerPartie(const char *nomFichier) {
    FILE *fichier_charge;
    fichier_charge = fopen(nomFichier,"r");

    // Lire les données du fichier pour restaurer l'état du jeu

    fscanf(fichier_charge,"%d ",&SnoopyX);
    fscanf(fichier_charge,"%d ",&SnoopyY);
    fscanf(fichier_charge,"%d ",&murX);
    fscanf(fichier_charge,"%d ",&murY);
    fscanf(fichier_charge,"%d ",&mur_cassableX);
    fscanf(fichier_charge,"%d ",&mur_cassableY);
    fscanf(fichier_charge,"%d ",&mur_piegeX);
    fscanf(fichier_charge,"%d ",&mur_piegeY);

    fscanf(fichier_charge,"%d ",&oiseauX);
    fscanf(fichier_charge,"%d ",&oiseauY);
    fscanf(fichier_charge,"%d ",&oiseau1X);
    fscanf(fichier_charge,"%d ",&oiseau1Y);
    fscanf(fichier_charge,"%d ",&oiseau2X);
    fscanf(fichier_charge,"%d ",&oiseau2Y);
    fscanf(fichier_charge,"%d ",&oiseau3X);
    fscanf(fichier_charge,"%d ",&oiseau3Y);

    Plateau[SnoopyX][SnoopyY] = 'S';
    Plateau[murX][murY] = 'M';
    Plateau[mur_cassableX][mur_cassableY] = 'C';
    Plateau[mur_piegeX][mur_piegeY] = 'X';
    Plateau[oiseauX][oiseauY] = 'O';
    Plateau[oiseau1X][oiseau1Y] = 'O';
    Plateau[oiseau2X][oiseau2Y] = 'O';
    Plateau[oiseau3X][oiseau3Y] = 'O';

    for (int i = 0; i < Longueur; ++i) {
        for (int j = 0; j < Largeur; ++j) {
            printf( "%c",Plateau[i][j]);
        }
    }

    // Fermer le fichier après avoir lu les données
    fclose(fichier_charge);


    // Met à jour le plateau avec les positions des éléments chargés


}

