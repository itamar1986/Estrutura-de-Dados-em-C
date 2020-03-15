/* Comentario: Calculo de media de 3 notas COM vetor */
# include "stdio.h"

float notas[3], media;
int i;

void main()
{
	for (i=1; i<=3; i++)
	{
		printf ("Digite a nota %d: ", i);
		scanf ("%f", notas[i]);
		media += notas[i];
	}
	media /= 3;
	printf ("Media = %.2f\n", media);
}	
