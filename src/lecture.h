#ifndef _LECTURE
#define _LECTURE

int getOpCode(char* fileName, char* instructionList, char* opCodeBin, char* opCodeStr);
int translateCommand(char* fileName, char* OpCodeStr, int opCodeDec, int filePointer);
int binaireToDecimal(char* binaire);
int bin_to_hexa(int *binaire, char *tab);

#endif