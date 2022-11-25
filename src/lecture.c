#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getOpCode(char* fileName, char* instructionList, char* opCodeBin, char* opCodeStr){
    FILE* fr1=NULL;
    FILE* fr2=NULL;
    char instruction[100];
    int filePointer=0;
    fr1=fopen(fileName,"r");
    if(fr1 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    fr2=fopen(instructionList,"r");
    if(fr2 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    fscanf(fr1, "%s", instruction);
    fscanf(fr2, "%s", opCodeStr);
    while (strcmp(instruction,opCodeStr)!=0 && !feof(fr2)){
        fscanf(fr2, "%s", opCodeStr);
    }
    if (!feof(fr2)){
        fscanf(fr2, "%s",opCodeBin);
        filePointer=ftell(fr1);        
        printf("Code opératoire de %s : %s\n", instruction, opCodeBin);
        printf("%s\n",opCodeStr);
    }
    else {
        strcpy(opCodeBin, "Error");
    }
    fclose(fr1);
    fclose(fr2);
    return filePointer;
}

int translateCommand(char* fileName, char* opCodeStr, int opCodeDec, int filePointer){
    FILE* fr1=NULL;
    char instruction[100];
    char register1[20];
    char register2[20];
    char value[20];

    printf("On entre \n");
    printf("On entre dans : %s \n", fileName);
    fr1=fopen(fileName,"r");
    /*
        Gestion des erreurs
    */
    printf("On sors de : %s \n", fileName);
    if(fr1 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    if (opCodeDec<0) {
        perror("OpCode non existant");
        exit(1);
    }
    fseek(fr1,filePointer,SEEK_SET);
    switch (opCodeDec) {

        case 0:
            printf("SLL or NOP\n");
            if (!strcmp(opCodeStr, "NOP")){
                printf("NOP\n");
            }
            else {
                printf("SLL\n");
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
            printf("JR or ADDI\n"); 
            if (!strcmp(opCodeStr, "ADDI")){
                printf("ADDI\n");
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
    fclose(fr1);
    return 0;
}


void readOperation(char* fileName, char* value, char* result){
    FILE* fr1=NULL;
    fr1=fopen(fileName,"r");

    if(fr1 == NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }

    fscanf(fr1, "%s", result);
    int stockage=0;
    if (value[1]=='a' || value[1]=='t' || value[1]=='s'){
        stockage=(value[2]-48);
        value[2]='\n';
    }
    while(strcmp(value, result) && !feof(fr1)){
        fscanf(fr1, "%s", result);
    }
    if (!feof(fr1)){
        fscanf(fr1, "%s", result);
        if (value[1]=='a' || value[1]=='t' || value[1]=='s'){
            result[2]+=stockage;
        }
        printf("Registe : %s", result);
    }
    else {
        printf("Error, no register found");
    }
    fclose(fr1);
}


void readInstruction(char* fileName,  int filePointer){
    FILE* fr1=NULL;
    char value[20];
    char result[20];
    int compteur=0;
    printf("On entre");
    printf("fileName : %s", fileName);
    fr1=fopen(fileName,"r");

    printf("On sort");
    if(fr1==NULL) {
        perror("Probleme ouverture fichier");
        exit(1);
    }
    printf("On sort");
    printf("Value : ");

    fseek(fr1,filePointer,SEEK_SET);
    fscanf(fr1, "%s", value);
    while(value[compteur]!='\n'){
        compteur++;
    }
    compteur--;
    if (value[compteur]==','){
        value[compteur]='\0';
    }
    compteur=0;
    printf("Value : %s", value);
    readOperation("./tests/registers.txt", value, result);
    fclose(fr1);
}