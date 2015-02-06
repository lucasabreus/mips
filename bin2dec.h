#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/*
 =================================================================
|Função para conversão de binário em decimal e decimal e binário. |
 =================================================================

--------------------------------------------------------------------------------------------------------------------
Para utilizar a função bin2dec você vai passar como parametro o tamanho de bits que vc quer converter e a string.
Exemplo:

int num;	
bin[1].data = "00000000000000000000000000001010"
num = bin2dec(32,bin[1].data);
Lembrando que em um vetor que armazena 32 bits a [33] = '\0' e não pode ser passada como parametro;
--------------------------------------------------------------------------------------------------------------------



*/



//Converte binario em char para decimal em int.
int bin2dec(int tamanho, char *bin)
{
   int resultado = 0; 
    for ( int i = 0 ; i < tamanho ; i ++ )
   {
      resultado = resultado << 1;
      resultado  = resultado | (bin[i] - '0');
   }
	return resultado;
}

//Converte de decimal para binario em char.

void dec2bin(int num, char *bin)
{
	int i;
    unsigned int mask;

   for ( i = 0 ; i < 32; i ++ )
   {
      mask = 1<<(32 -1 -i);
      bin[i] = ((num & mask)>>(32 -1 -i)) + '0';
   }
   bin[i] = '\0';
}
