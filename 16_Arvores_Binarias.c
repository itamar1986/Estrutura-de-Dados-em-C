/* Exemplo de Árvore Binária */
struct tree
{
	char info;
	struct tree *left;
	struct tree *right;
} t;
struct tree *root; /* primeiro nó da árvore */
void main ( )
{
	char s[80];
	struct tree *stree( );
	root = 0; /* inicializa a árvore*/
	do
	{
		printf ("Entre com uma letra:");
		gets(s);
		if ( !root )
		root = stree( root, root, *s );
		else
		stree( root, root, *s );
	} while( *s );
	printf_tree( root, 0 );
}
struct tree *stree(root, r, info);
struct tree *root;
struct tree *r;
char info;
{
	if ( r == 0 )
	{
		r = malloc(sizeof( t )); /*primeiro nó da sub-árvore */
		if ( r == 0 )
		{
			printf ("Estouro de memoria\n");
			exit ( 0 );
		}
		r -> left = 0;
		r -> right = 0;
		r -> info = info;
		if ( info < root -> info )
		root -> left = r;
		else
		root -> right = r;
		return r;
	}
	if ( info < r -> info )
	stree(r, r -> left, info);
	else
	if ( info > r -> info )
	stree(r, r -> right, info);
}
print_tree( r, l )
struct tree *r;
int l;
{
	int i;
	if ( r == 0 )
	return;
	print_tree( r -> left, l + 1 );
	for ( i =0; i < l; ++i )
	printf (" ");
	printf ("%c\n", r -> info);
	printf_tree(r -> right, l + 1);
}

