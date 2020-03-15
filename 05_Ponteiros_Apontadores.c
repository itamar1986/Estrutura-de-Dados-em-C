/* Comentario: alocacao de memoria dinamica */
#include <stdio.h>
#include <malloc.h>
#include <dos.h>

void main ()
{
// Declaracao do ponteiro
	int
	*ptr;
	
	ptr = ( int * ) malloc( sizeof( int ));
	*ptr = 3;
	
	system("CLS");
	printf ("Conteudo do ponteiro: %d\n\n", *ptr);
	system("PAUSE");
}
