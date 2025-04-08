#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "Registrar.c"
#include "Consulta.c"	
#include "Deletar.c"
#include "Editar.c"

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
