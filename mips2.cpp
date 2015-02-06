#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "decodificador.h"
#include "bin2dec.h"
#include "functionTipoR.h"
#include "teste.h"

//Trabalho de Arquitetura de Computadores - PROCESSADOR MIPS

typedef struct binary{
	char data[34];
	char text[34];

}celula;

// Variáveis

celula bin[1024]; //Memoria principal,  onde fica os .data do .text
int endereco = 8192; //Endereco para ser subtraido da memoria
int registrador[32]; // Registradores
char IR[33]; //Usando nas execuções das instruções
int PC; // Guarda o endereço das instruções a serem executadas.
FILE *arquivo = fopen("binary","r+"); // aponta para o arquivo que contem as instrunções e dados.
int tamData = 0, tamText = 0, tamRegister = 32; // Tamanho.
int ciclo; // Guarda um inteiro que significa se a execução sera passo a passo.
// Funções

void map();
void ULA(char IR2[]);
int converte(int TAM, char *bin);
void executar();
void functionTipoI (char IR[33], int numeroInstrucao );
void functionTipoR (char IR[33], int numeroInstrucao );
void functionTipoJ (char IR[33], int numeroInstrucao );


int main(){
	int i = 0;
	system("clear");
	inicializa();
	printf("Deseja executar as instrucoes passo a passo: \n1 - Sim\n0 - Nao\n");
	scanf("%d", &ciclo);
	map();

	PC = 0;
	while( PC/4 <= (tamText)){
		bin[PC/4].text[32] = '\0';
		PC += 4;
		ULA(bin[(PC-4)/4].text);

	}

	executar();

	return 0;

}

void map(){
	int i = 0,t = 0;
	char a;

/* Separa text do data */
	while(!feof(arquivo)){
		if(t==0){
			fgets(bin[i].data, sizeof(bin[i].data),arquivo);
			tamData++; //Contador de celulas (Padrão é 1024)

			if(bin[i].data[0] == 'f'){
				t++;
				i=-1;
			}

		}
		else{
			fgets(bin[i].text, sizeof(bin[i].text),arquivo);
			tamText++;
		}

		i++;

	}
}

void ULA(char *IR){

	char tInstrucao;
	int iInstrucao;

	tInstrucao = decodificador(IR);

	if(ciclo == 1){
		system("clear");
		printf("Instrucao: %s\n", IR);
	}
	if(tInstrucao == 'R'){
		iInstrucao = decodificaInstrucaoR(IR, ciclo);
		functionTipoR(registrador, IR,iInstrucao, &PC);
    }

    if (tInstrucao == 'I'){

    	iInstrucao = decodificaInstrucaoI(IR, ciclo);
    	functionTipoI(IR,iInstrucao);

    }

    if (tInstrucao == 'J'){

    	iInstrucao = decodificaInstrucaoJ(IR, ciclo);
    	functionTipoJ(IR,iInstrucao);
    }
    if(ciclo == 1){
		for(int i = 0; i < 16; i++){
            printf("Registrador[%.2d] = %.2d           Registrador[%.2d] = %.2d\n", i, registrador[i],i+16, registrador[i+16]);
		}
		printf("\n");
		for (int i = 0; i < tamData/2; i++){
            printf("Memory[%.2d] = %.2d                Memory[%.2d] = %.2d\n", i, bin2dec(32,bin[i].data),i+5, bin2dec(32,bin[i+5].data));
		}
    }
    if ( ciclo == 1)
    	getchar();
}


void executar(){
	int menu,i;

	while(1){
		system("clear");
		printf(" =========================\n");
		printf("|Simulador MIPS           |\n");
		printf(" =========================\n");
		printf("|1) Data                  |\n");
		printf("|2) Text                  |\n");
		printf("|3) Registers             |\n");
		printf("|4) Estatistica           |\n");
		printf("|0) Sair                  |\n");
		printf(" -------------------------\n");
		printf("Digite uma opcao: ");
		scanf("%d", &menu);

		if(menu == 1){
			for(i = 0; i < tamData-1; i++){
				printf("Data[%d] = %s (%d)\n", i, bin[i].data, bin2dec(32,bin[i].data));
			}
			getchar();
		}
		if(menu == 2){
			system("clear");
			for(i = 0; i < tamText; i++){
				printf("Text[%d] = %s\n", i, bin[i].text);
			}
			getchar();
		}
		if(menu == 3){
			system("clear");
			printf("Registradores\n");
			for(int i = 0; i < 16; i++){
            	printf("Registrador[%.2d] = %.2d           Registrador[%.2d] = %.2d\n", i, registrador[i],i+16, registrador[i+16]);
			}
			getchar();
		}

		if(menu == 4){
			system("clear");
			imprimirEstatistica();
			getchar();
		}

		if(menu == 0)
			break;
	}

}

 void functionTipoI (char IR[33], int numeroInstrucao ) {

	char rs[6],rt[6],imm[17];
	int count = 0,count2 = 0;
	rs[5] = '\0';
	rt[5] = '\0';
	imm[16] = '\0';

	for ( int i = 0 ; i < 5 ; i++ ){
		rs[i] = IR[6 + i];
		rt[i] = IR[11 + i];
	}
	for ( int i = 0 ; i < 16 ; i++ )
	{
		imm[i] = IR[16 + i];
	}
	 int rs1, rt1, imm1,imm2, sig_extend;

	rs1 = bin2dec(5,rs); // destino
	rt1 = bin2dec(5,rt);
	imm1 = bin2dec(16,imm);


    if(imm[0] == '1'){
        sig_extend = bin2dec(16,imm) | 0xFFFF0000;
    }
    else{
        sig_extend = bin2dec(16,imm);
    }

    imm2 = (registrador[rs1] + sig_extend - endereco)/4;

	if ( numeroInstrucao == 4 ) { //lw
		int x = bin2dec(32,bin[imm2].data);
		registrador[rt1] = x ;
	}

	if ( numeroInstrucao == 5 ) { //sw
		dec2bin(registrador[rt1], bin[imm2].data);
	}

	if ( numeroInstrucao == 11 ) { //li
		registrador[rt1] = imm1;
	}

	if ( numeroInstrucao == 1 ){ //addi
		registrador[rt1] = registrador[rs1] + sig_extend;
	}

	if ( numeroInstrucao == 3 ){ //ori
		registrador[rt1] = registrador[rs1] | imm1;
	}

	if ( numeroInstrucao == 7){ //beq
		if( registrador[rs1] == registrador[rt1]){
			PC += (sig_extend << 2) ;
		}

	}

	if ( numeroInstrucao == 8 ){ //bne
		if( registrador[rs1] != registrador[rt1])
			PC += (sig_extend << 2) ;
	}

	if ( numeroInstrucao == 6 ){ //lui
		registrador[rt1]  = imm1 << 16;
	}

	if ( numeroInstrucao == 9 ){ //slti
		if (registrador[rs1] < imm1)
	        registrador[rt1] = 1;
		else
	        registrador[rt1] = 0;
    }
}

 void functionTipoJ (char IR[33], int numeroInstrucao ) {
	char address[27];
	address[26] = '\0';

	for(int i = 0; i < 26; i++)
		address[i] = IR[6 + i];

	int address1 = bin2dec(26,address);

    if(numeroInstrucao == 1){ //jump
        PC = (PC)&(0xF0000000) | (address1<<2);
    }
    if(numeroInstrucao == 2){ //jal
        registrador[31] =   PC + 4;
        PC = (PC)&(0xF0000000) | (address1<<2);
    }
}
