#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int registrar()
{
	setlocale(LC_ALL, "Portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf);
	
	FILE *file;
	file = fopen(arquivo, "w");
	fprintf(file, "CPF: ");
	fprintf(file, cpf);
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Nome: ");
	fprintf(file, nome);
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite  o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Sobrenome: ");
	fprintf(file, sobrenome);
	fprintf(file, "\n");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, "Cargo: ");
	fprintf(file, cargo);
	fprintf(file, "\n");
	fclose(file);
	
	printf("\n");
	system("pause");

	return 0;
}