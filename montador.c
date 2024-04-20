#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "montador.h"


//gera a representação binária do registrador
void ConvReg(char* entrada, char* saida){
    if((strcmp(entrada, "x0,")==0) || (strcmp(entrada, "x0")==0)) strcpy(saida, "00000");
    else if((strcmp(entrada, "x1,")==0) || (strcmp(entrada, "x1")==0)) strcpy(saida, "00001");
    else if((strcmp(entrada, "x2,")==0) || (strcmp(entrada, "x2")==0)) strcpy(saida, "00010");
    else if((strcmp(entrada, "x3,")==0) || (strcmp(entrada, "x3")==0)) strcpy(saida, "00011");
    else if((strcmp(entrada, "x4,")==0) || (strcmp(entrada, "x4")==0)) strcpy(saida, "00100");
    else if((strcmp(entrada, "x5,")==0) || (strcmp(entrada, "x5")==0)) strcpy(saida, "00101");
    else if((strcmp(entrada, "x6,")==0) || (strcmp(entrada, "x6")==0)) strcpy(saida, "00110");
    else if((strcmp(entrada, "x7,")==0) || (strcmp(entrada, "x7")==0)) strcpy(saida, "00111");
    else if((strcmp(entrada, "x8,")==0) || (strcmp(entrada, "x8")==0)) strcpy(saida, "01000");
    else if((strcmp(entrada, "x9,")==0) || (strcmp(entrada, "x9")==0)) strcpy(saida, "01001");
    else if((strcmp(entrada, "x10,")==0) || (strcmp(entrada, "x10")==0)) strcpy(saida, "01010");
    else if((strcmp(entrada, "x11,")==0) || (strcmp(entrada, "x11")==0)) strcpy(saida, "01011");
    else if((strcmp(entrada, "x12,")==0) || (strcmp(entrada, "x12")==0)) strcpy(saida, "01100");
    else if((strcmp(entrada, "x13,")==0) || (strcmp(entrada, "x13")==0)) strcpy(saida, "01101");
    else if((strcmp(entrada, "x14,")==0) || (strcmp(entrada, "x14")==0)) strcpy(saida, "01110");
    else if((strcmp(entrada, "x15,")==0) || (strcmp(entrada, "x15")==0)) strcpy(saida, "01111");
    else if((strcmp(entrada, "x16,")==0) || (strcmp(entrada, "x16")==0)) strcpy(saida, "10000");
    else if((strcmp(entrada, "x17,")==0) || (strcmp(entrada, "x17")==0)) strcpy(saida, "10001");
    else if((strcmp(entrada, "x18,")==0) || (strcmp(entrada, "x18")==0)) strcpy(saida, "10010");
    else if((strcmp(entrada, "x19,")==0) || (strcmp(entrada, "x19")==0)) strcpy(saida, "10011");
    else if((strcmp(entrada, "x20,")==0) || (strcmp(entrada, "x20")==0)) strcpy(saida, "10100");
    else if((strcmp(entrada, "x21,")==0) || (strcmp(entrada, "x21")==0)) strcpy(saida, "10101");
    else if((strcmp(entrada, "x22,")==0) || (strcmp(entrada, "x22")==0)) strcpy(saida, "10110");
    else if((strcmp(entrada, "x23,")==0) || (strcmp(entrada, "x23")==0)) strcpy(saida, "10111");
    else if((strcmp(entrada, "x24,")==0) || (strcmp(entrada, "x24")==0)) strcpy(saida, "11000");
    else if((strcmp(entrada, "x25,")==0) || (strcmp(entrada, "x25")==0)) strcpy(saida, "11001");
    else if((strcmp(entrada, "x26,")==0) || (strcmp(entrada, "x26")==0)) strcpy(saida, "11010");
    else if((strcmp(entrada, "x27,")==0) || (strcmp(entrada, "x27")==0)) strcpy(saida, "11011");
    else if((strcmp(entrada, "x28,")==0) || (strcmp(entrada, "x28")==0)) strcpy(saida, "11100");
    else if((strcmp(entrada, "x29,")==0) || (strcmp(entrada, "x29")==0)) strcpy(saida, "11101");
    else if((strcmp(entrada, "x30,")==0) || (strcmp(entrada, "x30")==0)) strcpy(saida, "11110");
    else if((strcmp(entrada, "x31,")==0) || (strcmp(entrada, "x31")==0)) strcpy(saida, "11111");
}

//gera a representação binária do imediato em complemento de 2
void IntBin(int num, char *str) {
    int mask = 1 << 11;
    for (int i = 11; i >= 0; --i) {
        str[11 - i] = (num & mask) ? '1' : '0';
        mask >>= 1;
    }
    str[12] = '\0';
}

void SepararImm(char* Caux, char* Cimm, char* Crs1){
//ler o imediato em decimal e guardar em Cimm
    int i = 0;
    while(Caux[i] != '('){
        Cimm[i] = Caux[i];
        i++;
    }
    i++;
//pular o parenteses e ler o registrador até chegar no fechamento de parenteses    
    int j = 0;
    while(Caux[i] != ')'){
        Crs1[j] = Caux[i];
        i++;
        j++;
    }
    Crs1[j] = '\0';
    Cimm[i] = '\0';
}



