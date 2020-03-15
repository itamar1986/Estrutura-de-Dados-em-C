/* Comentario: Trabalhando com a Estrutura de Dados Fila Linear */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Comentario: Declaração da Estrutura Fila */
struct Fila
{
	int capacidade;
	int *dados;
	int primeiro;
	int ultimo;
	int nItens;
};
/* Comentario: Criar Fila */
void criarFila( struct Fila *f, int c )
{
	f->capacidade = c;
	f->dados = (int*) malloc (f->capacidade * sizeof(int));
	f->primeiro = 0;
	f->ultimo = -1;
	f->nItens = 0;
}
/* Comentario: Inserir Elemento na Fila */
void inserir(struct Fila *f, int v)
{
	if(f->ultimo == f->capacidade-1)
	f->ultimo = -1;
	f->ultimo++;
	f->dados[f->ultimo] = v;
	f->nItens++;
}
/* Comentario: Remover Elemento da Lista */
int remover( struct Fila *f )
{
	int temp = f->dados[f->primeiro++];
	if(f->primeiro == f->capacidade)
	f->primeiro = 0;
	f->nItens--;
	return temp;
}
/* Comentario: Fila Vazia */
int estaVazia( struct Fila *f )
{
	return (f->nItens==0);
}
/* Comentario: Fila Cheia */
int estaCheia( struct Fila *f )
{
	return (f->nItens == f->capacidade);
}
/* Comentario: Mostrar Elementos da Fila */
void mostrarFila(struct Fila *f)
{
	int cont, i;
	for ( cont=0, i= f->primeiro; cont < f->nItens; cont++)
	{
		printf("%d ",f->dados[i++]);
		if (i == f->capacidade)
		i=0;
	}
	printf("\n");
}
/* Comentario: Programa Principal */
int main ()
{
	int opcao, capa;
	int valor;
	struct Fila umaFila;
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf("Capacidade da Fila?");
	scanf("%d",&capa);
	criarFila(&umaFila, capa);
	while( 1 )
	{
		system("CLS");
		printf(" * * * FAÇA SUA ESCOLHA * * * \n\n");
		printf(" 1- Inserir elemento na Fila \n");
		printf(" 2- Remover elemento da Fila \n");
		printf(" 3- Mostrar elementos da Fila \n");
		printf(" 0- Sair \n\n");
		printf("Opção? ");
		scanf("%d", &opcao);
		switch(opcao){
		case 0: exit(0);
		case 1:
			if (estaCheia(&umaFila))
			{
				printf("\nA Fila está Cheia.\n");
				system("PAUSE");
			}
			else
			{
				printf("\nElemento a ser inserido?");
				scanf("%d", &valor);
				inserir(&umaFila,valor);
			}
			break;
		case 2:
			if (estaVazia(&umaFila))
			{
				printf("\nA Fila está Vazia.\n");
				system("PAUSE");
			}
			else
			{
				valor = remover(&umaFila);
				printf("\nO Elemento %d foi removido com sucesso.\n", valor) ;
				system("PAUSE");
			}
			break;
		case 3:
			if (estaVazia(&umaFila))
			{
				printf("\nA Fila está Vazia.\n");
				system("PAUSE");
			}
			else
			{
				printf("\nElementos da Fila: ");
				mostrarFila(&umaFila);
				printf("\n");
				system("PAUSE");
			}
			break;
		default:
			printf("\nOpção Inválida.\n");
			system("PAUSE");
		}
	}
}
