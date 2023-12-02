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
