#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];

	printf("Qual CPF a ser consultado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo!\n\n");
	}

	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("%s", conteudo);
	}

	printf("\n");
	system("pause");

	return 0;
}