#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <alloc.h>
#include <stdlib.h>
struct prs{
	char titulo[30];
	char autor[30];
	int regnum;
	double preco;
	struct prs *ptrprox;
};
	struct prs *ptrprim, *ptrnovo, *ptratual;
	void novonome( )
{
	char numstr[81],prcstr[10];
	ptrnovo = (struct prs*) malloc(sizeof(struct prs));
	if (ptrprim == (struct prs*) NULL)
	ptrprim = ptratual = ptrnovo;
	else
	{
		ptratual = ptrprim;
		while (ptratual->ptrprox != (struct prs*) NULL)
		ptratual = ptratual->ptrprox;
		ptratual->ptrprox = ptrnovo; // recebe o endere�o da nova posi��o
		ptratual = ptrnovo;
	}
	printf("\n");
	printf("\nDigite o t�tulo: ");
	gets(ptratual->titulo);
	printf("\nDigite o autor : ");
	gets(ptratual->autor);
	printf("\nDigite n�mero de registro: ");
	gets(numstr);
	ptratual->regnum = atoi(numstr);
	printf("\nDigite o pre�o: ");
	gets(prcstr);
	ptratual->preco = atof(prcstr);
	ptratual->ptrprox = (struct prs*) NULL;
}
void listatudo( )
{
	if (ptrprim == (struct prs*) NULL)
	{
		printf("\nLista vazia\n");
		return;
		}
	ptratual = ptrprim;
	do
	{
		printf("\n");
		printf("\nT�tulo: %s \n",ptratual->titulo);
		printf("\nAutor: %s\n",ptratual->autor);
		printf("\nN�mero do Reg: %03d\n",ptratual->regnum);
		printf("\nPre�o: %4.2f\n",ptratual->preco);
		ptratual = ptratual->ptrprox;
	} while(ptratual != (struct prs*) NULL);
}
void main( )
{
	char ptrprim = (char) (struct prs *) NULL;
	char op,ch;
	do
	{
		clrscr( );
		printf("\nOp��es : (N)ovo livro, (L)istar livros, (S)air ");
		op = getch( );
		op = toupper(op);
		switch(op)
		{
			case 'N' :
			novonome( );
			break;
			case 'L' :
			listatudo( );
			printf("\nPressione qualquer tecla !\n");
			ch = getch( );
			break;
			case 'S' :
			break;
			default :
			puts("\nDigite somente op��es v�lidas");
			printf("\nPressione qualquer tecla !\n");
			ch = getch( );
			break;
		}
	} while (op != 'S');
}
