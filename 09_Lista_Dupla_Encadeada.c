/* Comentario: Lista Duplamente Encadeada */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
enum OpcoesMenu{SAIR=0,CRIAR_LISTA,INSERIR_AMIGO,IMPRIMIR_LISTA,REMOVER_AMIGO,VERIFICAR_LISTA_VAZIA,LIBERAR_MEMORIA};
#define TAMMAX_AMIGO 40
/* Comentario: Define Estrutura da lista */
struct no
{
	char amigo[TAMMAX_AMIGO];
	struct no * anterior;
	struct no * proximo;
};
/* Comentario: Criar Lista Duplamente Encadeada */
No * criar_elemento()
{
	No * e = (No*) malloc(sizeof(No));
	e->anterior = e->proximo = NULL;
	e->amigo[0] = '\0';
	return e;
}
/* Comentario: Incluir Amigo no Final da Lista */
void inserir(No * lista, char * nome_amigo)
{
	if (is_vazia(lista))
{
	strncpy(lista->amigo, (const char *) nome_amigo, strlen(nome_amigo));
} else
	{
	No * tmp = lista;
	while(tmp->proximo != NULL)
		{
		tmp = tmp->proximo;
		}
	No * e = criar_elemento();
		strncpy(e->amigo, (const char *) nome_amigo, strlen(nome_amigo));
	e->anterior = tmp;
	e->proximo = NULL;
	tmp->proximo = e;
	}
}
/* Comentario: Pesquisar Amigo */
No * pesquisar (No * inicio_lista, char * nome_amigo)
{
	No * tmp;
	if (is_vazia(inicio_lista))
	{
		tmp = NULL;
	} else
	{
		tmp = inicio_lista;
		while(tmp != NULL)
		{
			if (strcasecmp(tmp->amigo, nome_amigo) == 0)
			return tmp;
			tmp = tmp->proximo;
		}
	}
	return tmp;
}
/* Comentario: Imprimir Lista de Amigos */
void imprimir(No * lista)
{
	if (is_vazia(lista))
	{
		puts("\nSua lista de amigos está vazia.\n");
	} else
	{
		No * tmp = lista;
		printf("\n* * * Lista de Amigos * * *\n");
		while(tmp != NULL)
		{
			printf("%s\n", tmp->amigo);
			tmp = tmp->proximo;
		}
	}
}
/* Comentario: Remover Amigo da Lista */
No * remover(No * lista, No * elemento)
{
	No * tmp_inicio;
	if (elemento == lista)
	{
		tmp_inicio = lista;
		tmp_inicio = elemento->proximo;
		tmp_inicio->anterior = NULL;
	} else
	{
		tmp_inicio = elemento->anterior;
		tmp_inicio->proximo = elemento->proximo;
		tmp_inicio = lista;
	}
	free(elemento);
	return tmp_inicio;
}
/* Comentario: Apagar Lista Duplamente Encadeada */
void liberar_memoria(No * lista)
{
	if (lista->proximo == NULL)
	{
		free(lista);
	} else
	{
		return liberar_memoria(lista->proximo);
	}
}
/* Comentario: Menu de Escolhas */
void menu_escolha()
{
	printf("\n* * * M E N U * * *\n\n");
	printf("%d) Sair\n", SAIR);
	printf("%d) Criar lista\n", CRIAR_LISTA);
	printf("%d) Inserir amigo\n", INSERIR_AMIGO);
	printf("%d) Imprimir lista de amigos\n", IMPRIMIR_LISTA);
	printf("%d) Remover amigo\n", REMOVER_AMIGO);
	printf("%d) Verificar se lista está vazia\n", VERIFICAR_LISTA_VAZIA);
	printf("%d) Apagar lista\n", LIBERAR_MEMORIA);
}
/* Comentario: Leitura do Nome do Amigo */
char * ler_amigo()
{
	char nome[TAMMAX_AMIGO];
	printf("\nQual o nome do Amigo: ");
	fgets(nome, TAMMAX_AMIGO, stdin);
	(*strrchr(nome, '\n')) = '\0';
	return strdup(nome);
}
/* Comentario: Programa Principal */
int main()
{
	int opcao;
	char * nome_amigo;
	No * lista = NULL;
	setlocale(LC_ALL, "portuguese");
	while(1)
	{
		system("CLS");
		menu_escolha();
		printf("\nOpção: ");
		scanf("%d%*c", &opcao);
		if (opcao == SAIR) break;
		if (lista == NULL && opcao != CRIAR_LISTA)
		{
			puts("\nA lista não foi criada.\n");
		} else
		{
			switch(opcao)
			{
				case CRIAR_LISTA:
				lista = criar_elemento();
				printf("\nLista criada com sucesso.\n");
				break;
				case INSERIR_AMIGO:
				puts("\n* * * INCLUSÃO * * *");
				nome_amigo = ler_amigo();
				if (pesquisar(lista, nome_amigo) == NULL)
				{
					inserir(lista, nome_amigo);
				} else
				{
					puts("\nAmigo já consta na lista.\n");
				}
				break;
				case IMPRIMIR_LISTA:
				imprimir(lista);
				break;
				case REMOVER_AMIGO:
				puts("\n* * * REMOÇÃO * * *");
				nome_amigo = ler_amigo();
				No * registro = pesquisar(lista, nome_amigo);
				if (registro == NULL)
				{
					puts("\nAmigo não encontrado.\n");
				} else
				{
					lista = remover(lista, registro);
				}
				break;
				case VERIFICAR_LISTA_VAZIA:
				printf("\nA lista%sestá vazia\n", is_vazia(lista)? " " : " não ");
				break;
				case LIBERAR_MEMORIA:
				liberar_memoria(lista);
				lista = NULL;
				printf("\nLista apagada.\n");
				break;
				default:
				printf("\nDigite uma opção válida.\n");
			}
		}
		system("PAUSE");
	}
	/* Comentario: Liberar a Lista Duplamente Encadeada da Memória */
	if (lista != NULL) liberar_memoria(lista);
	return 0;
}

