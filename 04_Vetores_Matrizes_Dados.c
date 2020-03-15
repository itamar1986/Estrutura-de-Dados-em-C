/* Comentario: Exemplo de MATRIZ */
#include <stdio.h>
#define LIN 2
#define COL 2
void main ( )
{
	int
	mat [LIN][COL],
	i, j;
	for ( i=1; i<3; i++ )
	for ( j=1; j<3; j++ )
	{
		printf ("\nEntre com o elemento[%d][%d]", i, j);
		scanf ("%d", &mat[ i ][ j ]);
	}
	for ( i=1; i<3; i++ )
	for ( j=1; j<3; j++ )
	if ( i == j )
	printf ("\n%d", mat[ i ][ j ]);
}
