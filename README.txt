Processador MIPS criado em C.

Criadores: Diogo Nunes Gonçalves
           Joao Victor Souza Paes
     	   Lucas Abreu da Silva
	   Reinaldo Felipe Araújo


Compile o arquivo mips2.cpp.

Para modificar o programa a ser simulado, edite o arquivo binary.

Modelo de executável: ( binary )

00000000000000000000000000001010 |
00000000000000000000000000010100 |- .data
00000000000000000000000000001010 |
f			 	                 |- f significa parada.
10001100000001010010000000000000 |
10001100000001110010000000000100 |
00010000101001010000000000000001 |- .text 
00000000101001011000100000100000 |

ps: Para obter esse tipo, será necessário dar dump o arquivo em modo Binary Text. Utilize o programa Mars.

Passo 1 - Colocar o binário do dump dos dados. (.data)
Passo 2 - Colocar a letra f, que significa parada para o programa.
Passo 3 - Colocar o binário do dump de instruões. (.text)
Passo 4 - Salvar o executável com o nome binary e colocar na pasta local.
