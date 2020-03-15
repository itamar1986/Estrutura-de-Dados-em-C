/* Com essa modificação, quando i atingir 50, que é um acima do ultimo indice da
matriz, a mensagem "BUFFER LOTADO" sera impressa e o comando break fará com
que o controle saia do laço de-while e passe para a segunda parte do programa. */
do
{
	if(i >= TAMANHO)
	{
		printf("BUFFER LOTADO.\n";)
		i++;
		break;/* Sai do laço do-while */
	}
	printf("Digite a nota do aluno %d ", i+1);
	scanf("%f",&notas[i]);
} whilw(notas[i++] >= 0.0);
