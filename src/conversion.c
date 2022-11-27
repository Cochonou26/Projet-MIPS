#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int bin_to_hexa(char *binaire, char *tab){
  int coef[8]={0};
  int Ascii=48;
  coef[7] = 1*(binaire[31]-Ascii)+2*(binaire[30]-Ascii)+4*(binaire[29]-Ascii)+8*(binaire[28]-Ascii);
  coef[6] = 1*(binaire[27]-Ascii)+2*(binaire[26]-Ascii)+4*(binaire[25]-Ascii)+8*(binaire[24]-Ascii);
  coef[5] = 1*(binaire[23]-Ascii)+2*(binaire[22]-Ascii)+4*(binaire[21]-Ascii)+8*(binaire[20]-Ascii);
  coef[4] = 1*(binaire[19]-Ascii)+2*(binaire[18]-Ascii)+4*(binaire[17]-Ascii)+8*(binaire[16]-Ascii);
  coef[3] = 1*(binaire[15]-Ascii)+2*(binaire[14]-Ascii)+4*(binaire[13]-Ascii)+8*(binaire[12]-Ascii);
  coef[2] = 1*(binaire[11]-Ascii)+2*(binaire[10]-Ascii)+4*(binaire[9]-Ascii)+8*(binaire[8]-Ascii);
  coef[1] = 1*(binaire[7]-Ascii)+2*(binaire[6]-Ascii)+4*(binaire[5]-Ascii)+8*(binaire[4]-Ascii);
  coef[0] = 1*(binaire[3]-Ascii)+2*(binaire[2]-Ascii)+4*(binaire[1]-Ascii)+8*(binaire[0]-Ascii);


  for (int i=0; i<=7; i++){

    if (coef[i]==0){
      tab[i]='0';
    }
    else if (coef[i]==1){
      tab[i]='1';
    }
    else if (coef[i]==2){
      tab[i]='2';
    }
    else if (coef[i]==3){
      tab[i]='3';
    }
    else if (coef[i]==4){
      tab[i]='4';
    }
    else if (coef[i]==5){
      tab[i]='5';
    }
    else if (coef[i]==6){
      tab[i]='6';
    }
    else if (coef[i]==7){
      tab[i]='7';
    }
    else if (coef[i]==8){
      tab[i]='8';
    }
    else if (coef[i]==9){
      tab[i]='9';
    }
    else if (coef[i]==10){
      tab[i]='a';
    }
    else if (coef[i]==11){
      tab[i]='b';
    }
    else if (coef[i]==12){
      tab[i]='c';
    }
    else if (coef[i]==13){
      tab[i]='d';
    }
    else if (coef[i]==14){
      tab[i]='e';
    }
    else if (coef[i]==15){
      tab[i]='f';
    }
    
  }
  return 0;
}

int binaireToDecimal(char* binaire){
  int decimal=0;
  int compteur=0;
  int puissance=1;
  if (!strcmp(binaire, "Error") || !strcmp(binaire, "")) {
        perror("OpCode non existant");
        decimal=-1;
        exit(1);
    }
  while (binaire[compteur]!='\0'){
    compteur++;
  }
  compteur--;
  while (compteur>=0){
    decimal+=(binaire[compteur]-48)*puissance;
    compteur--;
    puissance*=2;
  }
  return decimal;
}

void decToBin(int dec, char* binaire){
  int puissance=1;
  int compteur=0;
  while(puissance<dec){
    puissance*=2;
  }
  while(puissance>=1){
    if ((dec/puissance)<1){
      binaire[compteur]='0';
      puissance/=2;
      compteur++;
    }
    else {
      dec-=puissance;
      binaire[compteur]='1';
      puissance/=2;
      compteur++;
    }
  }
  binaire[compteur]='\0';
}

int strToDec (char* chaine){
  int resultat=0;
  int compteur=0;
  int puissance=1;
  while (chaine[compteur]!='\0'){
    compteur++;
  }
  compteur--;
  while(compteur>=0){
    resultat+=(puissance*(chaine[compteur]-48));
    compteur-=1;
    puissance*=10;
  }
  return resultat;
}


void remplirBinaire(char *mot, char *tab, int taille){
  int compteur =0;
  tab[taille]='\0';
  taille--;
  while (mot[compteur] != '\0'){
    compteur ++;
  }
  compteur --;
  while (compteur >=0){
    tab[taille] = mot[compteur];
    taille --;
    compteur --;
  }
  while(taille>=0){
    tab[taille]='0';
    taille--;
  }
}