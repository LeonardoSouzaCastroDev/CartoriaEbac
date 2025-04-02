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
	
	system("pause");

	return 0;
}

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

	system("pause");

	return 0;
}

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

		system("pause");
	}

	remove(delete);

	return 0;
}

int main()
{
	int opcao = 0;
	int x = 1;
	char senha[10]="a";
	int comparacao;

	setlocale(LC_ALL,"Portuguse");

	system("cls");

	printf("Cartorio da EBAC\n\n");
	printf("\t---LOGIN ADM---\n\nDigite a sua senha: ");
	scanf("%s", senha);

	comparacao = strcmp(senha, "admin");

	if (comparacao == 0)
	{
		for (x=1; x==1;)
		{
			system("cls");
		
			printf("Cartorio da EBAC\n\n");  
			printf("Escolha a opcao desejada do menu:\n\n");
			printf("\t1 - Registrar nomes\n");
			printf("\t2 - Consultar nomes\n");
			printf("\t3 - Deletar nomes\n");
			printf("\t4 - Editar nomes\n\n");
			printf("Opcao: "); 
			scanf("%d", &opcao); 
	
			system("cls");
	
			switch (opcao)
			{
				case 1:
					registrar();
				break;

				case 2:
					consulta();
				break;
			
				case 3:
					deletar();
				break;
			
				case 4:
					editar();
				break;

				default:
					printf("Numero invalido\n");
					system("pause");
			}			
		}
	}
	
	else
	{
		printf("\nSenha incorreta!\n\n");
		system("pause");
		main();
	}	
}
