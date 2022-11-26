#include <stdio.h>
#include <stdlib.h>


//char i= *mot;
// *mot = 1ere lettre de la chaine
// mot = l'adresse de la 1ere lettre


int main(){
  char *hexa=malloc(8*sizeof(char));
  int binaire[32]={1,1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,1,1,1,0,0,0,1,1};

  char tab[32]={'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','1'};
  char mot[16]={'a','2','3','4','5','6','7','8','9'};
  bin_to_hexa(binaire, hexa);
  taille_32(mot,tab);


  for (int k=0; k<=7; k++){
    printf("%c",hexa[k]);
  }
  printf("\n");

  for (int l=0; l<=32; l++){
    printf("%c",tab[l]);
  }
  printf("\n");

  free(hexa);


  return 0;
}

int bin_to_hexa(int *binaire, char *tab){
  int coef[8]={0};
  coef[7] = 1*binaire[31]+2*binaire[30]+4*binaire[29]+8*binaire[28];
  coef[6] = 1*binaire[27]+2*binaire[26]+4*binaire[25]+8*binaire[24];
  coef[5] = 1*binaire[23]+2*binaire[22]+4*binaire[21]+8*binaire[20];
  coef[4] = 1*binaire[19]+2*binaire[18]+4*binaire[17]+8*binaire[16];
  coef[3] = 1*binaire[15]+2*binaire[14]+4*binaire[13]+8*binaire[12];
  coef[2] = 1*binaire[11]+2*binaire[10]+4*binaire[9]+8*binaire[8];
  coef[1] = 1*binaire[7]+2*binaire[6]+4*binaire[5]+8*binaire[4];
  coef[0] = 1*binaire[3]+2*binaire[2]+4*binaire[1]+8*binaire[0];


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
  return (*tab);
}


int taille_32(char *mot, char *tab){
  int compteur =0;
  int i = 31;

  while (mot[compteur] != '\0'){
    compteur ++;
  }
  compteur --;
  while (compteur >=0){
    tab[i] = mot[compteur];
    i --;
    compteur --;
  }
  return (*tab);
}