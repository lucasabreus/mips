
char decodificador(char codigoBinario[33]);
int decodificaInstrucaoR(char codigoBinario[33], int ciclo);
int decodificaInstrucaoJ(char codigoBinario[33], int ciclo);
int decodificaInstrucaoI(char codigoBinario[33], int ciclo);
void mostrarInstrucao(int i,char tipo);

int nR, nJ, nI;
int contadorR[10],contadorJ[3],contadorI[12];

void barrinhas ( int qtdBarrinhas );
void imprimirEstatistica();

/*
	****  INSTRUCOES DO TIPO R  ****

	return 1 - add
	return 2 - subtract
	return 3 - and
	return 4 - or
	return 5 - nor
	return 6 - shift left logical
	return 7 - shift right logical
	return 8 - set on less than
	return 9 - jump register

	****  INSTRUCOES DO TIPO J  ****

	return 1 - jump
	return 2 - jump and link

	****  INSTRUCOES DO TIPO I  ****

	return 1 - add immediate
	return 2 - and immediate
	return 3 - or immediate
	return 4 - load word
	return 5 - store word
	return 6 - load upper immediate
	return 7 - branch on equal
	return 8 - branch on not eqqal
	return 9 - set on less than immediate
	return 11 - load immediate
*/

char decodificador(char codigoBinario[33]){
	char codigo[7];
	int i;
	for(i=0; i<6; i++){
		codigo[i] = codigoBinario[i];
	}



	int soma = 0;

	for(i=0; i<6;i++){
		 codigo[i] = codigo[i] - '0';
	}

	int numero = 0;
	int j = 5;

	for(i = 0; i < 6; i++){
		numero += (int)(codigo[i]*pow(2.0,j));
		j--;
	}

	if(numero == 0){
		return 'R';
	}
	else if( numero == 2 || numero == 3){
		return 'J';
	}
	else{
		return 'I';
	}

}

int decodificaInstrucaoR(char codigoBinario[33], int ciclo){
	char codigo[7];
	codigo[6] = '\0';

	int i;
	int count = 0;

	if ( ciclo == 1)
	printf("Tipo: R\n");

	for(i=26; i<32; i++){
		codigo[count] = codigoBinario[i];
		count++;
	}

	for(i=0; i<6;i++){
		 codigo[i] = codigo[i] - '0';
	}

	int numero = 0;
	int j = 5;

	for(i = 0; i < 6; i++){
		numero += (int)(codigo[i]*pow(2.0,j));
		j--;
	}
	nR++;

	if(numero == 32){
		contadorR[1]++;
		if(ciclo == 1){
			printf("Instrucao : ADD\n\n");
			
		}
		return 1;
	}
	else if( numero == 34){
		contadorR[2]++;
		if(ciclo == 1){
			printf("Instrucao : SUB\n");
			
		}
		return 2;
	}
	else if (numero == 36){
		contadorR[3]++;
		if(ciclo == 1){
			printf("Instrucao : AND\n");
			
		}
		return 3;
	}
	else if(numero == 37){
		contadorR[4]++;
		if(ciclo == 1){
			printf("Instrucao : OR\n");
			
		}
		return 4;
	}
	else if(numero == 39){
		contadorR[5]++;
		if(ciclo == 1){
			printf("Instrucao : NOR\n");
			
		}
		return 5;
	}
	else if(numero == 0){
		contadorR[6]++;
		if(ciclo == 1){
			printf("Instrucao : SHIFT LEFT LOGICAL\n");
			
		}
		return 6;
	}
	else if(numero == 2){
		contadorR[7]++;
		if(ciclo == 1){
			printf("Instrucao : SHIFT RIGHT LOGICAL\n\n");
			
		}
		return 7;
	}
	else if(numero == 42){
		contadorR[8]++;
		if(ciclo == 1){
			printf("Instrucao : SET ON LESS THAN\n");
			
		}
		return 8;
	}
	else if(numero == 8){
		contadorR[9]++;
		if(ciclo == 1){
			printf("Instrucao : JUMP REGISTER\n");
			
		}
		return 9;
	}
	return -1;
}

int decodificaInstrucaoJ(char codigoBinario[33], int ciclo){
	char codigo[7];
	int i;
	for(i=0; i<6; i++){
		codigo[i] = codigoBinario[i];
		codigoBinario++;
	}

	if ( ciclo == 1)
	printf("Tipo: J\n");

	for(i=0; i<6;i++){
		 codigo[i] = codigo[i] - '0';
	}

	int numero = 0;
	int j = 5;

	for(i = 0; i < 6; i++){
		numero += (int)(codigo[i]*pow(2.0,j));
		j--;
	}
	nJ++;

	if(numero == 2){
		contadorJ[1]++;
		if(ciclo == 1){
			printf("Instrucao : JUMP\n");
			
		}
		return 1;
	}
	else{
		contadorJ[2]++;
		if(ciclo == 1){
			printf("Instrucao : JUMP AND LINK\n");
			
		}
		return 2;
	}

}

int decodificaInstrucaoI(char codigoBinario[33], int ciclo){
	char codigo[7];
	int i;
	for(i=0; i<6; i++){
		codigo[i] = codigoBinario[i];
	}

	if ( ciclo == 1)
	printf("Tipo: I\n");

	for(i=0; i<6;i++){
		 codigo[i] = codigo[i] - '0';
	}

	int numero = 0;
	int j = 5;

	for(i = 0; i < 6; i++){
		numero += (int)(codigo[i]*pow(2.0,j));
		j--;
	}

	nI++;

	if(numero == 8){
		contadorI[1]++;
		if(ciclo == 1){
			printf("Instrucao : ADD IMMEDIATE\n");
			
		}
		return 1;
	}
	else if(numero == 12){
		contadorI[2]++;
		if(ciclo == 1){
			printf("Instrucao : AND IMMEDIATE\n");
			
		}
		return 2;
	}
	else if(numero == 13){
		contadorI[3]++;
		if(ciclo == 1){
			printf("Instrucao : OR IMMEDIATE\n");
			
		}
		return 3;
	}
	else if(numero == 35 || numero == 6 ){
		contadorI[4]++;
		if(ciclo == 1){
			printf("Instrucao : LOAD WORD\n");
			
		}
		return 4;
	}
	else if(numero == 43){
		contadorI[5]++;
		if(ciclo == 1){
			printf("Instrucao : STORE WORD\n");
			
		}
		return 5;
	}
	else if(numero == 15){
		contadorI[6]++;
		if(ciclo == 1){
			printf("Instrucao : LOAD UPPER IMMEDIATE\n");
			
		}
		return 6;
	}
	else if(numero == 4){
		contadorI[7]++;
		if(ciclo == 1){
			printf("Instrucao : BRANCH ON EQUAL\n");
			
		}
		return 7;
	}
	else if(numero == 5){
		contadorI[8]++;
		if(ciclo == 1){
			printf("Instrucao : BRANCH ON NOT EQUAL\n");
			
		}
		return 8;
	}
	else if(numero == 9){
		contadorI[11]++;
        if(ciclo == 1){
            printf("Instrucao : LOAD IMMEDIATE\n");
            
        }
        return 11;
	}
	else {
		contadorI[9]++;
		if(ciclo == 1){
			printf("Instrucao : SET ON LESS THAN IMMEDIATE\n");
			
		}
		return 9;
	}

}

void imprimirEstatistica(){
	int nTotal;
	int opcao=0;
	nTotal = nR + nJ + nI;
	
	printf("\nNumero total de Instrucoes executadas: %d\n",nTotal);
	
	printf("Tipo R: %d\n",nR);
	printf("Tipo J: %d\n",nJ);
	printf("Tipo I: %d\n\n",nI);


	printf(" Tipo - [ Quantidade ] - Nome da Funcao\n");
	for(int i=1;i<=9;i++){
		if ( contadorR[i] > 0 ){
			printf("   R  - ");printf("     [%.3d]     - ",contadorR[i]); mostrarInstrucao(i,'r');printf("\n");
		}
	}
	for(int i=1;i<=2;i++){
		if ( contadorJ[i] > 0 ){
			printf("   J  - ");printf("     [%.3d]     - ",contadorJ[i]); mostrarInstrucao(i,'j');printf("\n");
		}
	}
	for(int i=1;i<=11;i++){
		if ( contadorI[i] > 0 ){
			printf("   I  - ");printf("     [%.3d]     - ",contadorI[i]); mostrarInstrucao(i,'i');printf("\n");
		}
	}
	printf("\n\nPorcentagem:\n\n"); 
	printf("             10%%  20%%  30%%  40%%  50%%  60%%  70%%  80%%  90%%  100%%\n");
	printf("Tipo R: "); printf("%.2d%% - ",(nR*100/nTotal)); barrinhas((nR*10/nTotal));
	printf("Tipo J: "); printf("%.2d%% - ",(nJ*100/nTotal)); barrinhas((nJ*10/nTotal)); 
	printf("Tipo I: "); printf("%.2d%% - ",(nI*100/nTotal)); barrinhas((nI*10/nTotal)); 
}

void barrinhas ( int qtdBarrinhas ) {
	int i;
	for(i=0;i<qtdBarrinhas;i++){
		printf("|    ");
	}
	printf("\n");
}

void mostrarInstrucao(int i,char tipo) {
	if ( tipo == 'r' || tipo == 'R'){
		if ( i == 1 ) printf("ADD");
		if ( i == 2 ) printf("SUB");
		if ( i == 3 ) printf("AND");
		if ( i == 4 ) printf("OR");
		if ( i == 5 ) printf("NOR");
		if ( i == 6 ) printf("SHIFT LEFT LOGICAL");
		if ( i == 7 ) printf("SHIFT RIGHT LOGICAL");
		if ( i == 8 ) printf("SET ON LESS THAN");
		if ( i == 9 ) printf("JUMP REGISTER");	
	} 
	if ( tipo == 'j' || tipo == 'J'){
		if ( i == 1 ) printf("JUMP");
		if ( i == 2 ) printf("JUMP AND LINK");
	}
	if ( tipo == 'i' || tipo == 'I'){
		if ( i == 1 ) printf("ADD IMMEDIATE");
		if ( i == 2 ) printf("AND IMMEDIATE");
		if ( i == 3 ) printf("OR IMMEDIATE");
		if ( i == 4 ) printf("LOAD WORD");
		if ( i == 5 ) printf("STORE WORD");
		if ( i == 6 ) printf("LOAD UPPER IMMEDIATE");
		if ( i == 7 ) printf("BRANCH ON EQUAL");
		if ( i == 8 ) printf("BRANCH ON NOT EQUAL");
		if ( i == 9 ) printf("SET ON LESS THAN IMMEDIATE");	
		if ( i == 11) printf("LOAD IMMEDIATE");
	}
}
