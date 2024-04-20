#include "montador.h"
#include <getopt.h>

int main(int argc, char *argv[]) {

    int ImprimeArquivo = 0;

    FILE* arqsaida;
    if (argc>2) {
        arqsaida = fopen(argv[3], "w");
        ImprimeArquivo = 1;
    }

    FILE* arquivo;
    arquivo = fopen(argv[1], "r");
    
    if (arquivo == NULL){
        printf("erro\n");
        exit(0);
    }

    char comando[100];

    while((fscanf(arquivo, "%s", comando)) == 1){//passar pelo arquivo

//Tipo R

        if((strcmp(comando, "add")==0) || (strcmp(comando, "and")==0) || (strcmp(comando, "sll")==0) || (strcmp(comando, "sub")==0) || (strcmp(comando, "or")==0) || (strcmp(comando, "xor")==0) || (strcmp(comando, "srl")==0)){
            
            char Crs1[10];
            char Crs2[10];
            char Crd[10];

            char opcode[10];
            char funct7[10];
            char funct3[5];
            char rs1[6];
            char rs2[6];
            char rd[6];
            fscanf(arquivo, "%s %s %s", Crd, Crs1, Crs2);

            ConvReg(Crs1, rs1);
            ConvReg(Crs2, rs2);
            ConvReg(Crd, rd);   
            strcpy(opcode, "0110011");  

            if(strcmp (comando, "add") == 0){
                strcpy(funct3, "000");  
                strcpy(funct7, "0000000");  
            }
            else if(strcmp (comando, "and") == 0){
                strcpy(funct3, "111");  
                strcpy(funct7, "0000000");  
            }
            else if(strcmp (comando, "sll") == 0){
                strcpy(funct3, "001");  
                strcpy(funct7, "0000000");  
            }
            else if(strcmp (comando, "sub") == 0){
                strcpy(funct3, "000");  
                strcpy(funct7, "0100000");  
            }
            else if(strcmp (comando, "or") == 0){
                strcpy(funct3, "110");  
                strcpy(funct7, "0000000");  
            }
            else if(strcmp (comando, "xor") == 0){
                strcpy(funct3, "100");  
                strcpy(funct7, "0000000");  
            }
            else if(strcmp (comando, "srl") == 0){
                strcpy(funct3, "101");  
                strcpy(funct7, "0000000");  
            }

            if(ImprimeArquivo == 1){
                fprintf(arqsaida, "%s%s%s%s%s%s\n", funct7, rs2, rs1, funct3, rd, opcode);
            }
            else{
                printf("%s%s%s%s%s%s\n", funct7, rs2, rs1, funct3, rd, opcode);
            }

        }    

//Tipo I
        else if((strcmp(comando, "lb")==0) || (strcmp(comando, "ori")==0) || (strcmp(comando, "addi")==0) || (strcmp(comando, "mv")==0)) {
                char Crd[10];
                char Crs1[10];
                char Cimm[10];

                char opcode[10];
                char funct3[5];
                char rs1[6];
                char rd[6];
                char imm[15];

            if(strcmp(comando, "lb")==0){
                char Caux[15];
                fscanf(arquivo, "%s %s ", Crd, Caux);

                SepararImm(Caux, Cimm, Crs1);

                int num = atoi(Cimm);
                IntBin(num, imm);   

                ConvReg(Crs1, rs1);
                ConvReg(Crd, rd);   
                strcpy(opcode, "0000011");  
                strcpy(funct3, "000");  

            }
            else if(strcmp(comando, "ori")==0){

                fscanf(arquivo, "%s %s %s", Crd, Crs1, Cimm);

                int num = atoi(Cimm);
                IntBin(num, imm);   

                ConvReg(Crs1, rs1);
                ConvReg(Crd, rd);   
                strcpy(opcode, "0010011");  
                strcpy(funct3, "110");  
            }

            else if(strcmp(comando, "addi")==0){

                fscanf(arquivo, "%s %s %s", Crd, Crs1, Cimm);

                int num = atoi(Cimm);
                IntBin(num, imm);   
                ConvReg(Crs1, rs1);            
                ConvReg(Crd, rd);               
                strcpy(opcode, "0010011");  
                strcpy(funct3, "000");  
            }
            else if(strcmp(comando, "mv")==0){
                fscanf(arquivo, "%s %s", Crd, Crs1);

                IntBin(0, imm);   

                ConvReg(Crs1, rs1);
                ConvReg(Crd, rd);   
                strcpy(opcode, "0010011");  
                strcpy(funct3, "000");  
            }


            if(ImprimeArquivo == 1){
                fprintf(arqsaida, "%s%s%s%s%s\n", imm, rs1, funct3, rd, opcode);
            }
            else{
                printf("%s%s%s%s%s\n", imm, rs1, funct3, rd, opcode);
            }
        }  

//Tipo S
        else if(strcmp(comando, "sb")==0){
            char Crs1[10];
            char Caux[15];
            char Crs2[10];
            char Cimm[10];

            char opcode[10];
            char funct3[5];
            char rs1[6];
            char rs2[6];
            char imm[15];

            fscanf(arquivo, "%s %s", Crs1, Caux);

            SepararImm(Caux, Cimm, Crs2);    

            int num = atoi(Cimm);
            IntBin(num, imm);   
            ConvReg(Crs1, rs1);
            ConvReg(Crs2, rs2);  
            strcpy(opcode, "0100011");  
            strcpy(funct3, "000");  

            //exibição de função tipo S
            if(ImprimeArquivo ==1){
                for(int i = 0; i<7; i++){
                    fprintf(arqsaida, "%c", imm[i]);
                }
                fprintf(arqsaida, "%s%s%s", rs2, rs1, funct3);
                for(int i = 7; i<12; i++){
                    fprintf(arqsaida, "%c", imm[i]);
                }
                fprintf(arqsaida, "%s\n", opcode);
            }
            else{
                for(int i = 0; i<7; i++){
                    printf("%c", imm[i]);
                }
                printf("%s%s%s", rs2, rs1, funct3);
                for(int i = 7; i<12; i++){
                    printf("%c", imm[i]);
                }
                printf("%s\n", opcode);
            }
                
            
        }     

//Tipo SB
        else if(strcmp(comando, "bne")==0){
            char Crs1[10];
            char Crs2[10];
            char Cimm[10];

            char opcode[10];
            char funct3[5];
            char rs1[6];
            char rs2[6];
            char imm[15];

            fscanf(arquivo, "%s %s %s", Crs1, Crs2, Cimm);

            int num = atoi(Cimm);
            IntBin(num, imm);   
            ConvReg(Crs1, rs1);
            ConvReg(Crs2, rs2);  
            strcpy(opcode, "1100111");  
            strcpy(funct3, "001");  

            //exibição de função tipo SB

            if(ImprimeArquivo == 1){
                for(int i = 0; i<1; i++){
                    fprintf(arqsaida, "%c", imm[i]);
                }
                for(int i = 2; i<8; i++){
                    fprintf(arqsaida, "%c", imm[i]);
                }
                fprintf(arqsaida, "%s%s%s", rs2, rs1, funct3);
                for(int i = 8; i<12; i++){
                    printf("%c", imm[i]);
                }
                for(int i = 1; i<2; i++){
                    fprintf(arqsaida, "%c", imm[i]);
                }
                fprintf(arqsaida, "%s\n", opcode);
            }
            else{
                for(int i = 0; i<1; i++){
                    printf("%c", imm[i]);
                }
                for(int i = 2; i<8; i++){
                    printf("%c", imm[i]);
                }
                printf("%s%s%s", rs2, rs1, funct3);
                for(int i = 8; i<12; i++){
                    printf("%c", imm[i]);
                }
                for(int i = 1; i<2; i++){
                    printf("%c", imm[i]);
                }
                printf("%s\n", opcode);                
            }

        }

    }

    fclose(arquivo);
    fclose(arqsaida);
    return 0;
}