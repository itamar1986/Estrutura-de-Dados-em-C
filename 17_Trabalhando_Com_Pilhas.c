/* Comentario: Trabalhando com a Estrutura de Dados Pilha Linear */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Comentario: Declaração da Estrutura de Dados Pilha */
struct Pilha
{
	int topo;
	int capa;
	int *pElem;
};
int capacidade;
/* Comentario: Criar Pilha */
void criarpilha( struct Pilha *p, int c )
{
	p->topo = -1;
	p->capa = c;
	p->pElem = (int*) malloc (c * sizeof(int));
}
/* Comentario: Pilha Vazia */
int estavazia ( struct Pilha *p )
{
	if( p-> topo == -1 )
	return 1;
	else
	return 0;
}
/* Comentario: Pilha Cheia */
int estacheia ( struct Pilha *p )
{
	if (p->topo == p->capa - 1)
	return 1;
	else
	return 0;
}
/* Comentario: Inserir Elemento na Pilha - Empilhar */
void empilhar ( struct Pilha *p, int v)
{
	p->topo++;
	p->pElem [p->topo] = v;
}
/* Comentario: Remover Elemento da Pilha - Desempilhar */
float desempilhar ( struct Pilha *p )
{
	int aux = p->pElem [p->topo];
	p->topo--;
	return aux;
}
/* Comentario: Direciona ao Topo da Pilha */
int retornatopo ( struct Pilha *p )
{
	return p->pElem [p->topo];
}
/* Comentario: Programa Principal */
int main()
{
	struct Pilha minhapilha;
	int op;
	int valor;
	setlocale(LC_ALL, "portuguese");
	system("CLS");
	printf( "Capacidade da Pilha?" );
	scanf( "%d", &capacidade );
	criarpilha (&minhapilha, capacidade);
	while( 1 )
	{
		system("CLS");
		printf(" * * * FAÇA SUA ESCOLHA * * * \n\n");
		printf(" 1- Inserir Elemento na Pilha [Empilhar] \n");
		printf(" 2- Remover Elemento da Pilha [Desempilhar] \n");
		printf(" 3- Mostrar Elemento do Topo da Pilha \n");
		printf(" 0- Sair \n\n");
		printf("Opção?");
		scanf("%d", &op);
		switch (op)
		{
			case 0:
			exit(0);
			break;
			case 1:
			if( estacheia( &minhapilha ) == 1 )
			printf("\nA Pilha está Cheia. \n");
			else
			{
				printf("\nValor ? ");
				scanf("%d", &valor);
				empilhar (&minhapilha, valor);
			}
			break;
			case 2:
			if ( estavazia(&minhapilha) == 1 )
			printf( "\nA Pilha está Vazia. \n" );
			else
			{
				valor = desempilhar (&minhapilha);
				printf ( "\nO Elemento %d foi Desempilhado.\n", valor );
			}
			break;
			case 3:
			if ( estavazia (&minhapilha) == 1 )
			printf( "\nA Pilha está Vazia. \n" );
			else
			{
				valor = retornatopo (&minhapilha);
				printf( "\nElemento do Topo da Pilha: %d\n", valor );
			}
			break;
			default: printf( "\nOpção Inválida. \n" );
		}
		system("PAUSE");
	}
}
