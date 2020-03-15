/* Comentario: Declaração da Estrutura Pilha */
struct Pilha
{
	int topo;
	int capa;
	int *pElem;
};
/* Comentario: Procedimento de Empilhamento */
void empilhar ( struct Pilha *p, int v)
{
	p->topo++;
	p->pElem [p->topo] = v;
}
/* Comentario: Procedimento de Desempilhamento */
float desempilhar ( struct Pilha *p )
{
	int aux = p->pElem [p->topo];
	p-> topo--;
	return aux;
}
