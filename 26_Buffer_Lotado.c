/* Com essa modifica��o, quando i atingir 50, que � um acima do ultimo indice da
matriz, a mensagem "BUFFER LOTADO" sera impressa e o comando break far� com
que o controle saia do la�o de-while e passe para a segunda parte do programa. */
do
{
	if(i >= TAMANHO)
	{
		printf("BUFFER LOTADO.\n";)
		i++;
		break;/* Sai do la�o do-while */
	}
	printf("Digite a nota do aluno %d ", i+1);
	scanf("%f",&notas[i]);
} whilw(notas[i++] >= 0.0);
