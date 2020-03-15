/* programa exemplo de vetor */
#define DIM 5
#include <stdio.h>
/* Corpo principal do programa */
void main ()
{
	int i, vetor1[DIM], vetor2[DIM];
	for ( i=0; i<DIM; i++ )
	{
		printf ("vetor1[%d]=", i);
		scanf ("%d", &vetor1[ i ]);
	}
	for ( i=0; i<DIM; i++ )
	{
		printf ("vetor2[%d]=", i);
		scanf ("%d", &vetor2[ i ]);
	}
	for ( i=0; i<DIM; i++ )
	printf ("vetor1[%d] + vetor2[%d] = %d\n", i, i, vetor1[ i ] + vetor2[ i ]);
}
