/* Comentario: Uma possivel solucao */
#include <stdio.h>

int codigo[50], quantidade[50];
char mercadoria[10][50];
float preco_unitario[50], preco_total[50];
int i;

int main( )
{
/* Entrada de Dados */
for(i=1; i<=50; i++)
	{
		printf("\nCodigo ? "); scanf("%d", &codigo[i]);
		printf("\nMercadoria ? "); scanf("%s", &mercadoria[ i ]);
		printf("\nQuantidade ? "); scanf("%d", &quantidade[ i ]);
		printf("\nPreco Unitario ? "); scanf("%f", &preco_unitario[ i ]);
		preco_total[ i ] = quantidade[ i ] * preco_unitario[ i ];
	}
	/* Saida de Informacoes */
	for(i=1; i<=50; i++)
	if(quantidade[ i ] >= 100)
	printf("\nCodigo: %d Preco Total: %.2f ", codigo[ i ], preco_total[ i ]);
}
