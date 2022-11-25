// Projet MIPS 2022-2023
// Auteurs: AbrialSimon_RenierValentin

#include <stdio.h>
#include <string.h>
#include "lecture.h"

int main(int argc, char **argv)
{
   FILE* fr=NULL;
   FILE* fw1=NULL;
   FILE* fw2=NULL; 

   if (argc==1){
      printf("Lancement du mode interactif\n");
      char opCodeStr[100];
      char opCodeBin[100];
      int opCodeDec=0;
      int compteur=0;
      int filePointer=0;
     
      filePointer=getOpCode("./tests/arithmetic.s","./tests/opCodes.txt",opCodeBin, opCodeStr);
      opCodeDec=binaireToDecimal(opCodeBin);
      translateCommand("./tests/arithmetic.s", opCodeStr, opCodeDec, filePointer);
      printf("On sort");
      readInstruction("./tests/arithmetic.s", filePointer);
      compteur++;

      
   }

   if (argc==3){
      printf("Lancement du mode automatique pas à pas\n");
      printf("Nom du programme: %s\n", argv[1]);
      fr=fopen(argv[1], "r");
      fclose(fr);
   }

   if (argc==4){
      printf("Lancement du mode automatique\n");
      printf("Nom du programme: %s\n", argv[1]);
      printf("Fichier d'enregistrement du code assemblé : %s\n", argv[2]);
      printf("Fichier de sortie : %s\n", argv[3]);
      fr=fopen(argv[1], "r");
      fw1=fopen(argv[2], "w");
      fw2=fopen(argv[3], "w");
      fclose(fr);
      fclose(fw1);
      fclose(fw2);
   }

   printf("Hello émulateur MIPS!\n");

   return 0;
}