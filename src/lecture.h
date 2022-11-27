#ifndef _LECTURE
#define _LECTURE

void getOpCode(int compteur, char instructionsList[1000][100], char* opCodeBin, char* opCodeStr);
int translateCommand(char* opCodeStr, char instructionsList[1000][100], int opCodeDec, int ligne, char value[100]);
int binaireToDecimal(char* binaire);
int bin_to_hexa(char *binaire, char *tab);
int getInstructions(char* fileName, char instructionsList[1000][100]);
int getRegister(char instructionsList[1000][100], int ligne, int colonne, char* value);
void decToBin(int dec, char* binaire);
int strToDec (char* chaine);
void remplirBinaire(char *mot, char *tab, int taille);

#endif