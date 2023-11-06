#include <stdio.h>
#include <conio.h>
#include <windows.h>
#define Longueur 10
#define Largeur 20

int SnoopyX;
int SnoopyY;
int oiseauX;
int oiseauY;
int balleX;
int balleY;
int murX;
int murY;
char Plateau[Longueur][Largeur];
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
                    oiseauX = i;
                    oiseauY = j;
                    Plateau[i][j]='O';
                    printf("%c",Plateau[i][j]);

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

}
void deplacementBalle() {
    if (balleX - 1 >= 0 && balleY - 1 >= 0) {
        Plateau[balleX][balleY] = ' ';
        balleX++;
        balleY++;
        Plateau[balleX][balleY] = 'B';
    }

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
            if(SnoopyX+1<Longueur-2){
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
            if(SnoopyY+1<Largeur-2){
                Plateau[SnoopyX][SnoopyY] = ' ';
                SnoopyY++;
                Plateau[SnoopyX][SnoopyY] = 'S';
            }
            break;
    }
}
}
void oiseau(){
    int compteur;
    if(Plateau[SnoopyX][SnoopyY]== Plateau[oiseauX][oiseauY]){
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
int main() {
    plateau();
    while (1){
        affichage();
        oiseau();
        deplacementBalle();
        char commande = _getch();
        touches(commande);
    }

}
