/* Comentario: Lista Circular */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Comentario: Declaração da Estrutura da Lista Circular */
struct no
{
	int info;
	struct no *prox;
};
/* Comentario: Descrição das Funções */
void addinicio(struct no *head, int valor);
void addfim(struct no *head, int valor);
void remover(struct no *head, int valor);
void buscar(struct no *head, int valor);
void imprimir(struct no *head);
void menu();
/* Comentario: Inserir Elemento no Início da Lista Circular */
void addinicio(struct no *head, int valor)
{
	struct no *p;
	printf("\nValor do Elemento: ");
	scanf("%d",&valor);
	if((p = malloc(sizeof(struct no))) == NULL)
	{
		printf("\nErro de Memória\n");
	}
	else
	{
		p->info = valor;
		p->prox = head->prox;
		head->prox = p;
	}
}
/* Comentario: Inserir no Final da Lista Circular */
void addfim(struct no *head, int valor)
{
	struct no *pNow, *pNext;
	printf("\nValor do elemento: ");
	scanf("%d",&valor);
	if((pNow = malloc(sizeof(struct no))) == NULL)
	{
		printf("\nErro de Memória\n");
	}
	else
	{
		pNow->info = valor;
		pNext = head->prox;
		while(pNext->prox != head)
		{
			pNext = pNext->prox;
		}
		pNow->prox = pNext->prox;
		pNext->prox = pNow;
	}
}
/* Comentario: Remover Elemento da Lista Circular */
void remover(struct no *head, int valor)
{
	struct no *p, *aux;
	printf("\nValor a Remover: ");
	scanf("%d",&valor);
	p = head->prox;
	aux = head;
	head->info = valor;
	while(p->info != valor)
	{
		aux = p;
		p = p->prox;
	}
	if(p == head)
	{
		printf("\nElemento não encontrado\n");
	}
	else
	{
		aux->prox = p->prox;
		free(p);
		printf("\nElemento removido com Sucesso!\n");
	}
}
/* Comentario: Imprimir Elementos da Lista Circular */
void imprimir(struct no *head)
{
	struct no *p;
	int okay = 0;
	p = head->prox;
	while(p!=head)
	{
		printf("\n%d",p->info);
		p = p->prox;
		okay = 1;
	}
	if(okay == 0)
	{
		printf("\nLista Vazia\n");
	}
}
/* Comentario: Pesquisar Elemento na Lista Circular */
void buscar(struct no *head, int valor)
{
	struct no *p;
	printf("\nBuscar elemento: ");
	scanf("%d",&valor);
	p = head->prox;
	head->info = valor;
	while(p->info != valor)
	{
		p = p->prox;
	}
	if(p == head)
	{
		printf("\nElemento não encontrado!\n");
	}
	else
	{
		printf("\nElemento encontrado com sucesso!\n");
	}
}
/* Comentario: Menu de Escolhas */
void menu()
{
	printf("\n1) Inserir no Início");
	printf("\n2) Inserir no Final");
	printf("\n3) Buscar Elemento");
	printf("\n4) Remover Elemento");
	printf("\n5) Imprimir Lista");
	printf("\n\n0) Sair: ");
	}
/* Comentario: Programa Principal */
int main(int argc, char *argv)
{
	struct no *head;
	int op, valor;
	setlocale(LC_ALL, "portuguese");
	if((head = malloc(sizeof (struct no))) == NULL)
	{
		printf("\nErro de Memória\n");
	}
	else
	{
		head->prox = head;
		do
		{
			system("CLS");
			menu();
			scanf("%d",&op);
			switch(op)
			{
				case 0:
				break;
				case 1:
				addinicio(head, valor);
				break;
				case 2:
				addfim(head, valor);
				break;
				case 3:
				buscar(head, valor);
				break;
				case 4:
				remover(head, valor);
				break;
				case 5:
				imprimir(head);
				break;
				default:
				printf("\nOpçção Inválida!\n");
				break;
			}
			printf("\n");
			system("PAUSE");
		}
		while(op!=0);
		return 0;
	}
}
