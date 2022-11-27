#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int translateCommand(char* opCodeStr, char instructionsList[1000][100], int opCodeDec, int ligne){
    int colonne=0;
    char value[9]={'0'};
    char translate[32];
    char reg1[20];
    char reg2[20];
    char reg3[20];
    if (opCodeDec<0) {
        perror("OpCode non existant");
        exit(1);
    }
    switch (opCodeDec) {

        case 0:
            printf("SLL or NOP\n");
            if (!strcmp(opCodeStr, "NOP")){
                opCodeStr="0000000000000000000000000000000";
            }
            else {
                strcpy(translate,"00000000000");
                colonne=getRegister(instructionsList, ligne, 4, reg1);
                colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
                getRegister(instructionsList, ligne, colonne+1, reg3);;
                decToBin(strToDec(reg3),reg3);
                decToBin(strToDec(reg2),reg2);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 5);
                remplirBinaire(reg2, reg2, 5);
                remplirBinaire(reg3, reg3, 5);
                strcat(translate, reg2);
                strcat(translate, reg1);
                strcat(translate, reg3);
                strcat(translate, "000000");
                printf("Valeur binaire : %s\n", translate);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("Valeur hexa : %s\n", value);

            }
            break;


        case 2:
            printf("J or SRL or ROTR\n");
            if (!strcmp(opCodeStr, "ROTR")){
                printf("ROTR\n");
            }
            else if (!strcmp(opCodeStr, "SRL")){
                printf("SRL\n");
            }
            else {
                printf("J\n");
            }
            break;


        case 3:
            printf("JAL\n");
            break;
        case 4:
            printf("BEQ\n");
            break;
        case 5:
            printf("BNE\n");
            break;
        case 6:
            printf("BLEZ\n");
            break;
        case 7:
            printf("BGTZ\n");
            break;


        case 8:
            if (!strcmp(opCodeStr, "ADDI")){
                printf("ADDI\n");
                strcpy(translate,"001000");
                colonne=getRegister(instructionsList, ligne, 5, reg1);
                colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
                getRegister(instructionsList, ligne, colonne+1, reg3);
                decToBin(strToDec(reg1),reg1);
                decToBin(strToDec(reg2),reg2);
                decToBin(strToDec(reg3),reg3);      
                remplirBinaire(reg1, reg1, 5);
                remplirBinaire(reg2, reg2, 5);
                remplirBinaire(reg3, reg3, 16);
                strcat(translate, reg2);
                strcat(translate, reg1);
                strcat(translate, reg3);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("%s\n", value);



            }
            else {
                printf("JR\n");
            }
            break;


        case 12:
            printf("SYSCALL\n");
            break;
        case 15:
            printf("LUI\n");
            break;
        case 16:
            printf("MFHI\n");
            break;                 
        case 18:
            printf("MFLO\n");
            break;
        case 24:
            printf("MULT\n");
            break;
        case 26:
            printf("DIV\n");
            break;
        case 32:
            printf("ADD\n");
            break;  
        case 34:
            printf("SUB\n");
            break;
        case 35:
            printf("LW\n");
            break;
        case 36:
            printf("AND\n");
            break;
        case 37:
            printf("OR\n");
            break;
        case 38:
            printf("XOR\n");
            break;
        case 42:
            printf("SLT\n");
            break;
        case 43:
            printf("SW\n");
            break;
        
    }
    return 0;
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