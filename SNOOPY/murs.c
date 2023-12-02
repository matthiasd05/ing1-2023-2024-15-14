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
