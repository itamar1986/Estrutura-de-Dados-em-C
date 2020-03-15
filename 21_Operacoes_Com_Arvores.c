void exibirPreOrdem(No **pRaiz) 
{
	if((*pRaiz) != NULL) 
	{
		printf("%i\n", (*pRaiz)->numero);
		exibirPreOrdem(&(*pRaiz)->esquerda);
		exibirPreOrdem(&(*pRaiz)->direita); 
	}
}
void exibirEmOrdem(No **pRaiz) 
{
	if((*pRaiz) != NULL) 
	{
		exibirEmOrdem(&(*pRaiz)->esquerda);
		printf("%i\n", (*pRaiz)->numero);
		exibirEmOrdem(&(*pRaiz)->direita); 
	}
}
void exibirPosOrdem(No **pRaiz) 
{
}
if((*pRaiz) != NULL) 
{
	exibirPosOrdem(&(*pRaiz)->esquerda);
	exibirPosOrdem(&(*pRaiz)->direita);
	printf("%i\n", (*pRaiz)->numero);
}
