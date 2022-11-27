#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lecture.h"

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
                strcpy(translate,"0000000000000000000000000000000");
                strcpy(value, "00000000");
                bin_to_exa(translate, value);
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
                printf("Valeur binaire : %s\n", translate);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("Valeur hexa : %s\n", value);
            }
            else if (!strcmp(opCodeStr, "SRL")){
                printf("SRL\n");
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
                printf("Valeur binaire : %s\n", translate);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("Valeur hexa : %s\n", value);

            }
            else {
                printf("J\n");
                strcpy(translate, "000010");
                getRegister(instructionsList, ligne, 2, reg1);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 26);
                strcat(translate, reg1);
                printf("Valeur binaire : %s\n", translate);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("Valeur hexa : %s\n", value);
            }
            break;


        case 3:
            printf("JAL\n");
            strcpy(translate, "000011");
            getRegister(instructionsList, ligne, 4, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 26);
            strcat(translate, reg1);
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 4:
            printf("BEQ\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 5:
            printf("BNE\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 6:
            printf("BLEZ\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 7:
            printf("BGTZ\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
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
                strcpy(translate, "000000");
                getRegister(instructionsList, ligne, 3, reg1);
                decToBin(strToDec(reg1),reg1);
                remplirBinaire(reg1, reg1, 5);
                strcat(translate, reg1);
                strcat(translate, "000000000000000001000");
                strcat(translate, "001000");
                printf("Valeur binaire : %s\n", translate);
                strcpy(value, "00000000");
                bin_to_hexa(translate, value);
                printf("Valeur hexa : %s\n", value);
            }
            break;


        case 12:
            printf("SYSCALL\n");
            strcpy(translate, "00000000000000000000000000001100");
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 15:
            printf("LUI\n");
            strcpy(translate, "00111100000");
            colonne=getRegister(instructionsList, ligne, 4, reg1);
            colonne=getRegister(instructionsList, ligne, colonne+1, reg2);
            decToBin(strToDec(reg1),reg1);
            decToBin(strToDec(reg2),reg2);
            remplirBinaire(reg1, reg1, 5);
            remplirBinaire(reg2, reg2, 16);
            strcat(translate, reg1);
            strcat(translate, reg2);
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 16:
            printf("MFHI\n");
            strcpy(translate, "0000000000000000");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            strcat(translate, reg1);
            strcat(translate, "00000010000");
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;                 
        case 18:
            printf("MFLO\n");
            strcpy(translate, "0000000000000000");
            colonne=getRegister(instructionsList, ligne, 5, reg1);
            decToBin(strToDec(reg1),reg1);
            remplirBinaire(reg1, reg1, 5);
            strcat(translate, reg1);
            strcat(translate, "00000010010");
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 24:
            printf("MULT\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
        case 26:
            printf("DIV\n");
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
            printf("Valeur binaire : %s\n", translate);
            strcpy(value, "00000000");
            bin_to_hexa(translate, value);
            printf("Valeur hexa : %s\n", value);
            break;
            break;
        case 32:
            printf("ADD\n");
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
            printf("%s\n", value);
            break;  
        case 34:
            printf("SUB\n");
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
            printf("%s\n", value);            
            break;
        case 35:
            printf("LW\n");
            /*
                Pas encore implémenté
            */
            break;
        case 36:
            printf("AND\n");
            
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
            printf("%s\n", value);
            break;
        case 37:
            printf("OR\n");
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
            printf("%s\n", value);
            break;
        case 38:
            printf("XOR\n");
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
            printf("%s\n", value);
            break;
        case 42:
            printf("SLT\n");
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
            printf("%s\n", value);
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