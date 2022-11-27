#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

int translateCommand(char* opCodeStr, char instructionsList[1000][100], int opCodeDec, int ligne, char value[100]){
    int colonne=0;
    char translate[33];
    char reg1[20];
    char reg2[20];
    char reg3[20];
    if (opCodeDec<0) {
        perror("OpCode non existant");
        exit(1);
    }
    switch (opCodeDec) {

        case 0:
            if (!strcmp(opCodeStr, "NOP")){
                strcpy(translate,"0000000000000000000000000000000");
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
            }
            else {
                strcpy(translate,"00000000000");
                colonne=getRegister(instructionsList, ligne, 4, reg1);
                colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
                getRegister(instructionsList, ligne, colonne+1, reg3);
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
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);

            }
            break;


        case 2:
            if (!strcmp(opCodeStr, "ROTR")){
                strcpy(translate, "00000000001");
                colonne=getRegister(instructionsList, ligne, 5, reg1);
                colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
                getRegister(instructionsList, ligne, colonne+1, reg3);
                decToBin(strToDec(reg3),reg3);
                decToBin(strToDec(reg2),reg2);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 5);
                remplirBinaire(reg2, reg2, 5);
                remplirBinaire(reg3, reg3, 5);
                strcat(translate, reg2);
                strcat(translate, reg1);
                strcat(translate, reg3);
                strcat(translate, "000010");
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
            }
            else if (!strcmp(opCodeStr, "SRL")){
                strcpy(translate, "00000000000");
                colonne=getRegister(instructionsList, ligne, 4, reg1);
                colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
                getRegister(instructionsList, ligne, colonne+1, reg3);
                decToBin(strToDec(reg3),reg3);
                decToBin(strToDec(reg2),reg2);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 5);
                remplirBinaire(reg2, reg2, 5);
                remplirBinaire(reg3, reg3, 5);
                strcat(translate, reg2);
                strcat(translate, reg1);
                strcat(translate, reg3);
                strcat(translate, "000010");
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);

            }
            else {
                strcpy(translate, "000010");
                getRegister(instructionsList, ligne, 2, reg1);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 26);
                strcat(translate, reg1);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
            }
            break;


        case 3:
            strcpy(translate, "000011");
            getRegister(instructionsList, ligne, 4, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 26);
            strcat(translate, reg1);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 4:
            strcpy(translate, "000100");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg3),reg3);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 16);
            strcat(translate, reg1);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 5:
            strcpy(translate, "000101");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg3),reg3);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 16);
            strcat(translate, reg1);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 6:
            strcpy(translate, "000110");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg3),reg3);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg3, reg3, 16);
            strcat(translate, reg1);
            strcat(translate, "00000");
            strcat(translate, reg3);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 7:
            strcpy(translate, "000111");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg3),reg3);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg3, reg3, 16);
            strcat(translate, reg1);
            strcat(translate, "00000");
            strcat(translate, reg3);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;


        case 8:
            if (!strcmp(opCodeStr, "ADDI")){
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
            }
            else {
                strcpy(translate, "000000");
                getRegister(instructionsList, ligne, 3, reg1);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 5);
                strcat(translate, reg1);
                strcat(translate, "000000000000000001000");
                strcat(translate, "001000");
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
            }
            break;


        case 12:
            strcpy(translate, "00000000000000000000000000001100");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 15:
            strcpy(translate, "00111100000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 16);
            strcat(translate, reg1);
            strcat(translate, reg2);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 16:
            strcpy(translate, "0000000000000000");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            strcat(translate, reg1);
            strcat(translate, "00000010000");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;                 
        case 18:
            strcpy(translate, "0000000000000000");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            strcat(translate, reg1);
            strcat(translate, "00000010010");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 24:
            strcpy(translate, "000000");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            strcat(translate, reg1);
            strcat(translate, reg2);
            strcat(translate, "0000000000011000");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 26:
            strcpy(translate, "000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            strcat(translate, reg1);
            strcat(translate, reg2);
            strcat(translate, "0000000000011010");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
            break;
        case 32:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000100000");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;  
        case 34:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000100010");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);  
            break;
        case 35:
            printf("LW\n");
            /*
                Pas encore implémenté
            */
            break;
        case 36:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000100100");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 37:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 3, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000100101");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 38:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000100110");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 42:
            strcpy(translate,"000000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            getRegister(instructionsList, ligne, colonne+1, reg3);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            decToBin(strToDec(reg3),reg3);      
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 5);
            remplirBinaire(reg3, reg3, 5);
            strcat(translate, reg2);
            strcat(translate, reg3);
            strcat(translate, reg1);
            strcat(translate, "00000101010");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            break;
        case 43:
            printf("SW\n");
            /*
                Non implémenté (Comme LW)
            */
            break;
        
    }
    return 0;
}