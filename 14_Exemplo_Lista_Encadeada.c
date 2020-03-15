/* Exemplo Prático */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
int *p,*tos,*bos;
void push(int i)
{
	if (p > bos)
	{
		printf("Pilha cheia !\n");
		return;
	}
	
	*p = i;
	p++;
}
	int pop( )
	{
		p--;
		if (p < tos)
		{
			printf("Underflow da pilha\n");
			return(0);
		}
		return(*p);
	}
	void mostraresult(int result)
	{
		printf("Resultado e Novo Elemento da Pilha : %10.2f\n",result);
	}
void main( )
{
	int a,b;
	char s[80];
	p = (int*) malloc(100);
	tos = p;
	bos = p + (100/sizeof(int)) – sizeof(int);
	clrscr( );
	printf("Calculadora com 4 operações básicas (Digite s para Sair)\n");
	do
	{
		printf("Elemento da Pilha ou Operação (+,-,*,/) : ");
		gets(s);
		*s = toupper(*s);
		switch(*s)
		{
			case '+' :
			a = pop();
			b = pop();
			mostraresult(a + b);
			push(a + b);
			break;
			case '-' :
			a = pop();
			b = pop();
			mostraresult(a – b);
			push(a – b);
			break;
			case '*' :
			a = pop();
			b = pop();
			mostraresult(a * b);
			push(a * b);
			break;
			case '/' :
			a = pop( );
			b = pop( );
			if (a == 0)
			{
				printf("Infinito !\n");
				break;
			}
			mostraresult(b / a);
			push(b / a);
			break;
			default :
			push(atoi(s));
		}
	} while(*s != 'S');
}
