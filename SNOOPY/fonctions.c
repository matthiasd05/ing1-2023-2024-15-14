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
int droit_casser;
int droit_bouger=1;
int droit_pousser;

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

                break;
            }
        }
    }
}
