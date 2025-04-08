#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int deletar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	printf("\n");
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)
	
	{
		printf("Usuario nao encontrado!\n\n");
		system("pause");
	}
	
	else
	{
		printf("Usuario deletado!\n\n");
		system("pause");
	}

	remove(cpf);

	return 0;
}
