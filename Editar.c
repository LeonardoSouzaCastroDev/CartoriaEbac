#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int editar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char delete[40];
	char arquivo[40];
	char conteudo[200];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser editado: ");
	scanf("%s", cpf);

	strcpy(delete, cpf);

	system("cls");
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Nao foi possivel abrir o arquivo\n\n");
		system("pause");
	}

	else
	{
		printf("Dados atuais:\n\n");

		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("%s", conteudo);
		}

		printf("\nNovos dados:\n\n");

		fclose(file);

		printf("CPF: ");
		scanf("%s", cpf);
	
		strcpy(arquivo, cpf);
			
		FILE *file;
		file = fopen(arquivo, "w");
		fprintf(file, "CPF: ");
		fprintf(file, cpf);
		fprintf(file, "\n");
		fclose(file);

		printf("Nome: ");
		scanf("%s", nome);
	
		file = fopen(arquivo, "a");
		fprintf(file, "Nome: ");
		fprintf(file, nome);
		fprintf(file, "\n");
		fclose(file);
	
		printf("Sobrenome: ");
		scanf("%s", sobrenome);

		file = fopen(arquivo, "a");
		fprintf(file, "Sobrenome: ");
		fprintf(file, sobrenome);
		fprintf(file, "\n");
		fclose(file);
	
		printf("Cargo: ");
		scanf("%s", cargo);
	
		file = fopen(arquivo, "a");
		fprintf(file, "Cargo: ");
		fprintf(file, cargo);
		fprintf(file, "\n");
		fclose(file);
	
		system("cls");
		
		file = fopen(cpf, "r");

		printf("Dados atualizados:\n\n ");

		while(fgets(conteudo, 200, file) != NULL)
		{
			printf("%s", conteudo);
		}

		printf("\n");
		system("pause");
	}

	remove(delete);

	return 0;
}