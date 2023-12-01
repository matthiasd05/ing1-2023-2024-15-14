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
void plateau(){
    //On ouvre le fichier contenant notre plateau que l'on va associer à un tableau
    if(compteur<4){
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
    else if(compteur<8){
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

}

