/* Comentario: Lista Simplesmente Encadeada */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Comentario: Declaracao da Estrutura Nodo */
typedef struct sNodo
{
	int info;
	struct sNodo *prox;
} Nodo;
/* Comentario: Declaracao da Estrutura Lista Simplesmente Encadeada */
typedef struct sListaSimplesEnc
{
	Nodo *prim;
} ListaSimplesEnc;
/* Comentario: Criar Lista Vazia */
void criarLista(ListaSimplesEnc *pList)
{
	pList->prim = NULL;
}
/* Comentario: Mostrar Elementos da Lista */
void mostrarLista(ListaSimplesEnc *pList)
{
	Nodo *p;
	printf("Lista: ");
	for (p = pList->prim; p != NULL; p = p->prox)
	{
		printf("%d -> ", p->info);
	}
	printf("NULL\n");
}
/* Comentario: Inserir no Inicio da Lista */
void inserirIni(ListaSimplesEnc *pList, int v)
{
	Nodo *novo;
	novo = (Nodo*)malloc(sizeof(Nodo));
	if (novo != NULL)
	{
	novo->info = v;
		novo->prox = pList->prim;
		pList->prim = novo;
	}	
	else
	{
		printf("Mem�ria Insuficiente\n");
	}
}
/* Comentario: Remover no Inicio da Lista */
void removerIni(ListaSimplesEnc *pList)
{
	Nodo *pAux = pList->prim;
	if (pAux != NULL)
	{
		pList->prim = pList->prim->prox;
		free(pAux);
		printf("Valor Removido\n");
	}
	else
	{
		printf("Lista Vazia\n");
	}
}
/* Comentario: Inserir Elemento em Ordem na Lista */
void inserirOrd(ListaSimplesEnc *pList, int v)
{
	Nodo *novo;
	novo = (Nodo*)malloc(sizeof(Nodo));
	if (novo != NULL)
	{
		novo->info = v;
		Nodo *pAtu, *pAnt;
		pAnt = NULL;
		pAtu = pList->prim;
		while (pAtu != NULL && pAtu->info < v)
		{
			pAnt = pAtu;
			pAtu = pAtu->prox;
		}
		novo->prox = pAtu;
		if (pAnt != NULL)
		{
			pAnt->prox = novo;
		}
		else
		{
			pList->prim = novo;
		}
	}
	else
	{
		printf("Mem�ria Insuficiente\n");
	}
}
/* Comentario: Remover um Elemento Especifico da Lista */
void removerEle(ListaSimplesEnc *pList, int v)
{
	Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList->prim;
	while (pAtu != NULL && pAtu->info != v)
	{
		pAnt = pAtu;
		pAtu = pAtu->prox;
	}
	if (pAnt != NULL)
	{
		if (pAtu != NULL) {
			pAnt->prox = pAtu->prox;
			free(pAtu);
			printf("Valor Removido\n");
		}
		else
		{
			printf("Valor n�o encontrado\n");
		}
	}
	else
	{
		printf("Lista Vazia\n");
	}
}
/* Comentario: Remover Todos os Elementos da Lista */
void removerTudo(ListaSimplesEnc *pList)
{
	Nodo *pAux = pList->prim;
	if (pAux != NULL)
	{
		while (pAux != NULL)
		{
			pList->prim = pAux->prox;
			free(pAux);
			pAux = pList->prim;
		}
		printf("Todos os elementos foram removidos!\n");
	}
	else
	{
		printf("Lista Vazia\n");
	}
}
/* Comentario: Alterar Elemento da Lista */
void alterarEle(ListaSimplesEnc *pList, int v1, int v2)
{
	Nodo *pAtu, *pAnt;
	pAnt = NULL;
	pAtu = pList->prim;
	while (pAtu != NULL && pAtu->info != v1)
	{
		pAnt = pAtu;
		pAtu = pAtu->prox;
	}
	if (pAnt != NULL)
	{
		if (pAtu != NULL)
		{
			pAtu->info = v2;
			printf("Valor alterado\n");
		}
		else
		{
			printf("Valor n�o encontrado\n");
		}
	}
	else
	{
		printf("Lista Vazia\n");
	}
}
/* Comentario: Lista Vazia */
int estaVazia(ListaSimplesEnc *pList) {
	return(pList->prim == NULL);
}
/* Comentario: Programa Principal */
int main()
{
	setlocale(LC_ALL, "portuguese");
	ListaSimplesEnc minhaLista;
	int valor, op, valorAlt;
	criarLista(&minhaLista);
	printf("Escolha uma op��o:\n");
while (1) {
	printf("\n(1) Inserir elemento no in�cio da Lista\n");
	printf("(2) Inserir elemento em ordem (verifique se a lista est� ordenada)\n");
	printf("(3) Remover elemento no in�cio da Lista\n");
	printf("(4) Remover elemento espec�fico da Lista\n");
	printf("(5) Mostrar Lista\n");
	printf("(6) Apagar todos os elementos da Lista\n");
	printf("(7) Alterar elemento da Lista\n");
	printf("(0) Sair\n");
	printf(" ? ");
	scanf("%d", &op);
	system("cls");
	switch (op) {
	case 1: // inserir elemento no inicio
			printf("Valor? ");
			scanf("%d", &valor);
			inserirIni(&minhaLista, valor);
			break;
	case 2: // inserir elemento ordenado
			printf("Valor? ");
			scanf("%d", &valor);
			inserirOrd(&minhaLista, valor);
			break;
	case 3: // remover o primeiro
			removerIni(&minhaLista);
			break;
	case 4: // remover determinado elemento
			printf("Valor? ");
			scanf("%d", &valor);
			removerEle(&minhaLista, valor);
			break;
	case 5: // mostrar lista
			if (estaVazia(&minhaLista)) {
				printf("Lista vazia\n");
			}
			else {
				mostrarLista(&minhaLista);
			}
			break;
	case 6: // apagar todos os elementos da Lista
			removerTudo(&minhaLista);
			break;
	case 7: // alterar um elemento
			printf("Valor a ser alterado? ");
			scanf("%d", &valor);
			printf("Novo valor? ");
			scanf("%d", &valorAlt);
			alterarEle(&minhaLista, valor, valorAlt);
			break;
	case 0: // abandonar o programa
			removerTudo(&minhaLista);
			exit(0);
		default:
			printf("Op��o inexistente!\n");
		}
	}
}
