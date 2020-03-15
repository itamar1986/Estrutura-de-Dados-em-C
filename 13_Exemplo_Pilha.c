#define MAX_EVENT 100
//char *p(MAX_EVENT);
int spos;
int rpos;
//qstore(q)
char *q;
{
	if(spos == MAX_EVENT)
{
	printf("Estrutura Cheia\n");
	return;
}
	p(spos)=q;
	spos++;
}
	qretrieve( )
{
	if(rpos == spos)
	prtinf("Nao ha eventos para executar\n");
	rpos++;
	return p(rpos-1);
}
