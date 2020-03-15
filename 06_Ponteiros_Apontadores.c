/* Comentario: Outro exemplo de ponteiro/apontador */
#include <stdio.h>
#include <conio.h>
#include <dos.h>
int main(void)
{
	int
	num = 13;
	// Declaracao do ponteiro
	int
	*ptr;
	// Atribuicao do endereco da variavel num ao ponteiro ptr
	ptr = &num;
	//system("CLS");
	printf ("\nUtilizando ponteiros");
	printf ("\n\nConteudo da variavel num: %d", num);
	printf ("\nEndereco da variavel num: %x", &num);
	printf ("\nConteudo da variavel ponteiro ptr: %x", ptr);
	//system("PAUSE");
	return(0);
}
