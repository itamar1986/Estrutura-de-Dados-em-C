/* Comentario: Solução Rotinas Lista Duplamente Encadeada */
void inserir(No * lista, char * senha_alfa) // Habilitar senha na lista duplamente
encadeada
{
	if (is_vazia(lista))
	{
		strncpy(lista->senha, (const char *) nome_senha, strlen(nome_senha));
	} else
	{
		No * tmp = lista;
		while(tmp->proximo != NULL)
		{
			tmp = tmp->proximo;
		}
		No * e = criar_elemento();
		strncpy(e->senha, (const char *) nome_senha, strlen(nome_senha));
		e->anterior = tmp;
		e->proximo = NULL;
		tmp->proximo = e;
	}
}
No * remover(No * lista, No * elemento) // Desabilitar senha na lista duplamente
encadeada
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
