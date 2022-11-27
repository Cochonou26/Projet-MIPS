#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

void getOpCode(int compteur, char instructionsList[1000][100], char* opCodeBin, char* opCodeStr){
    FILE* fr1=NULL;
    char value[20];
    int compteur2=0;
    fr1=fopen("./tests/opCodes.txt","r");
    if(fr1 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    while(instructionsList[compteur][compteur2]!=' ' && instructionsList[compteur][compteur2]!='\0'){
        value[compteur2]=instructionsList[compteur][compteur2];
        compteur2++;
    }
    value[compteur2]='\0';
    fscanf(fr1, "%s", opCodeStr);
    while (strcmp(value,opCodeStr) && !feof(fr1)){
        fscanf(fr1, "%s", opCodeStr);
    }
    if (!feof(fr1)){
        printf("valeur : %s", opCodeStr);
        fscanf(fr1, "%s",opCodeBin);
        printf("Code opératoire : %s\n", opCodeBin);
        printf("%s\n",opCodeStr);
    }
    else {
        printf("%s\n", value);
        strcpy(opCodeBin, "Error");
    }
    fclose(fr1);
}

int getInstructions(char* fileName, char instructionsList[1000][100]){
    FILE* fr1=NULL;
    int nbLines=0;
    int compteur=0;
    fr1=fopen(fileName,"r");

    if(fr1 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }   
    
    while (!feof(fr1) && compteur<1000){
        fgets(instructionsList[compteur], 100, fr1);
        printf("Valeur contenue à la position %d : %s", compteur, instructionsList[compteur]);
        if (instructionsList[compteur][0]!='#' && instructionsList[compteur][0]!='\n'){
            compteur++;
            nbLines++;
        }
        else {
            instructionsList[compteur][0]='\0';
        }
    }
    fclose(fr1);
    return nbLines;
}

int getRegister(char instructionsList[1000][100], int ligne, int colonne, char* value){
    int compteur=0;
    while (instructionsList[ligne][colonne]!=',' && instructionsList[ligne][colonne]!='\0' && instructionsList[ligne][colonne]!='\n'){
        value[compteur]=instructionsList[ligne][colonne];
        if (value[compteur]!='$' && value [compteur]!=' '){
            colonne++;
            compteur++;
        }
        else {
            colonne++;
        }

    }
    value[compteur]='\0';
    return colonne;
}