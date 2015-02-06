void Add ( int * registrador, int r1, int r2, int r3 );
void Sub ( int * registrador, int r1, int r2, int r3 );
void And ( int * registrador, int r1, int r2, int r3 );
void Or ( int * registrador, int r1, int r2, int r3 );
void Nor ( int * registrador, int r1, int r2, int r3 );
void Sll (int * registrador,int r1, int r2, int shamt1 );
void Srl (int * registrador,int r1, int r2, int shamt1 );
void Slt (int * registrador,int r1, int r2, int r3);
void Jr ( int * registrador,int rs, int *PC);

void functionTipoR (int * registrador, char IR[33], int numeroInstrucao,int *PC) {

	char rs[6],rt[6],rd[6],shamt[6];
	int r1, r2, r3, shamt1,i;

	rs[5] = '\0';
	rt[5] = '\0';
	rd[5] = '\0';
	shamt[5] = '\0';

	for (i = 0 ; i < 5 ; i++ ){
		rs[i] = IR[6 + i];
		rt[i] = IR[11 + i];
		rd[i] = IR[16 + i];
		shamt[i] = IR[21 + i];
	}

	r1 = bin2dec(5,rd); // RD em Decimal
	r2 = bin2dec(5,rs); // RS em Decimal
	r3 = bin2dec(5,rt); // RT em Decimal
	shamt1 = bin2dec(5,shamt); // Imediato em Decimal


	if ( numeroInstrucao == 1 ) Add ( registrador, r1, r2, r3 );
	if ( numeroInstrucao == 2 ) Sub ( registrador, r1, r2, r3 );
	if ( numeroInstrucao == 3 ) And ( registrador, r1, r2, r3 );
	if ( numeroInstrucao == 4 ) Or  ( registrador, r1, r2, r3 );
	if ( numeroInstrucao == 5 ) Nor ( registrador, r1, r2, r3 );
	if ( numeroInstrucao == 6 ) Sll( registrador, r1,r3,shamt1);
	if ( numeroInstrucao == 7 ) Srl(registrador, r1,r3,shamt1);
	if ( numeroInstrucao == 8 ) Slt(registrador,r1,r2,r3);
	if ( numeroInstrucao == 9 ) Jr(registrador,r2, PC);
    if ( numeroInstrucao == 33) Add ( registrador, r1, r2, r3 );
}

void Add ( int * registrador, int r1, int r2, int r3 ){
	registrador[r1] = registrador[r2] + registrador[r3];
}

void Sub ( int * registrador, int r1, int r2, int r3 ){
	registrador[r1] = registrador[r2] - registrador[r3];
}

void And ( int * registrador,int r1, int r2, int r3 ){
	registrador[r1] = registrador[r2] & registrador[r3];
}

void Or ( int * registrador,int r1, int r2, int r3 ){
	registrador[r1] = registrador[r2] | registrador[r3];
}

void Nor ( int * registrador,int r1, int r2, int r3 ){
	int Or = registrador[r2] | registrador[r3];
	registrador[r1] = !Or;
}

void Sll (int * registrador,int r1, int r3, int shamt1 ){
	registrador[r1] = registrador[r3] << shamt1;
}
void Srl (int * registrador,int r1, int r3, int shamt1 ){
	registrador[r1] = registrador[r3] >> shamt1;
}

void Slt (int * registrador,int r1, int r2, int r3){
	if ( registrador[r2] < registrador[r3] ) registrador[r1] = 1;
	else registrador[r1] = 0;
}

void Jr ( int * registrador,int rs, int *PC){

    *PC = registrador[rs];

}
