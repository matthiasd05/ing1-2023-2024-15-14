
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
    FILE *fichier_charge;
    fichier_charge = fopen(nomFichier,"r");

    // Lire les données du fichier pour restaurer l'état du jeu
    fscanf(fichier_charge, "Snoopy : (%d, %d)\n", &SnoopyX, &SnoopyY);
    fscanf(fichier_charge, "Balle : (%d, %d)\n", &balleX, &balleY);
    fscanf(fichier_charge, "Mur : (%d, %d)\n", &murX, &murY);
    fscanf(fichier_charge, "Oiseau1 : (%d, %d)\n", &oiseauX, &oiseauY);
    fscanf(fichier_charge, "Oiseau2 : (%d, %d)\n", &oiseau1X, &oiseau1Y);
    fscanf(fichier_charge, "Oiseau3 : (%d, %d)\n", &oiseau2X, &oiseau2Y);
    fscanf(fichier_charge, "Oiseau4 : (%d, %d)\n", &oiseau3X, &oiseau3Y);

    // Fermer le fichier après avoir lu les données
    fclose(fichier_charge);


    // Met à jour le plateau avec les positions des éléments chargés
    Plateau[SnoopyX][SnoopyY] = 'S';
    Plateau[balleX][balleY] = 'B';
    Plateau[murX][murY] = 'M';
    Plateau[oiseauX][oiseauY] = 'O';
    Plateau[oiseau1X][oiseau1Y] = 'O';
    Plateau[oiseau2X][oiseau2Y] = 'O';
    Plateau[oiseau3X][oiseau3Y] = 'O';
}

