/* Comentario: Estrutura de Dados Fila Circular */
#include<stdio.h>
#include<stdlib.h>
#include <locale.h>
#define MAX 5
/* Comentario: Declaração da Estrutura Fila Circular */
struct circular
{ 
	int com;
	int fim;
	int total;
	int memo[MAX];
};
typedef struct circular circular;
void enfileirar(struct circular *F, int x);
int desenfileirar(struct circular *F);
void listar(struct circular A);
int busca(struct circular B, int x);
/* Comentario: Inserir Elemento na Fila Circular */
void enfileirar(struct circular *F, int x)
{
	F->fim++;
	if(F->fim == MAX)
	F->fim = 0;
	F->memo[F->fim] = x;
	F->total++;
}
/* Comentario: Remover Elemento da Fila Circular */
int desenfileirar(struct circular *F)
{
	int aux;
	aux = F->memo[F->com];
	F->com++;
	if(F->com == MAX)
	{
		F->com = 0;
	}
	F->total --;
	return aux;
}
/* Comentario: Listar os Elementos da Fila Circular */
void listar(struct circular A)
{
	printf("\nElementos da Fila Circular \n\n");
	while(A.total!=0)
	{
		printf("%d ", desenfileirar(&A));
	}
	printf("\n");
}
/* Comentario: Buscar um Elemento na Fila Circular */
int busca(struct circular B, int x)
{
	int achou;
	while(B.total!=0)
	{
		if(x == desenfileirar(&B))
		{
			achou = 1;
		}
	}
	return achou;
}
/* Comentario: Menu de Opções */
int menu()
{
	int opc;
	system("CLS");
	printf("* * * FAÇA SUA ESCOLHA * * *\n\n");
	printf(" 1- Enfileirar Elemento \n");
	printf(" 2- Desenfileirar Elemento \n");
	printf(" 3- Listar Elementos \n");
	printf(" 4- Buscar Elemento na Fila \n");
	printf(" 0- Sair \n\n");
	printf(" Opção: ");
	scanf("%d", &opc);
	return opc;
}
/* Comentario: Programa Principal */
int main ()
{
	struct circular F;
	F.com = 0;
	F.total = 0;
	F.fim = -1;
	int opc,x,pos,num;
	setlocale(LC_ALL, "portuguese");
	do
	{
		opc = menu();
		switch(opc)
		{
			case 0:
			exit (0);
			break;
			case 1:
			if(F.fim==MAX-1)
			{
				printf("\nA Fila está Cheia. ");
			}
			else
			{
				printf("\n Elemento (número) a ser inserido na Fila: ");
				scanf("%d", &x);
				if(busca(F,x) == 1)
				{
					printf("Não é possível inserir elementos repetidos ");
				}
				else
				{
					enfileirar(&F, x);
				}
			}
			break;
			case 2:
			if(F.total == 0)
			printf("\nA Fila está Vazia. ");
			else
			printf("\nElemento retirado da Fila Circular => %d",
			desenfileirar(&F));
			break;
			case 3:
			if(F.fim == -1)
			printf("\nA Fila está Vazia. ");
			else
			listar(F);
			break;
			case 4:
			printf("\nQual é o elemento que deseja localizar?");
			scanf("%d", &x);
			if((busca(F,x)==1))
			printf("\nO elemento %d está na Fila. ", x);
			else
			printf("\nO elemento %d não está na Fila. ", x);
			break;
			default: printf("\nOpção Inválida. \n");
		}
		printf("\n");
		system("PAUSE");
	}while(opc!=0);
}

