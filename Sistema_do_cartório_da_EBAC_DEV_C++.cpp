#include <stdio.h>// Biblioteca de comunicação com o usuário
#include <stdlib.h>// Biblioteca de alocação de espaço
#include <locale.h>// Biblioteca de alocação de texto por região
#include <string.h>// Bibliotéca responsável pelas Strings


int cadastro()// Função responsável pelos cadastros
{
	char arquivo[40];//Char são os caracteres e o número sua quantidade
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // fim da criação de variáveis
	
	printf("Digite o CPF que deseja cadastrar: \n\n");
	scanf("%s",cpf); // %s Se refere as Strings
	
	strcpy(arquivo,cpf); // Responsável pela cópia dos valores das strings
	
	FILE *file; // Criação do arquivo
	file = fopen(arquivo,"w"); // w= Write/escrever
	fprintf(file, cpf); //fprintf = responsável por salvar o arquivo
	fclose(file); //Fecha o arquivo
	
	file= fopen(arquivo, "a");// a=atualizar o cadastro
	fprintf(file,","); // respnsável por separar os dados
	fclose(file);
	
	printf("\nDigite o nome que deseja cadastrar: \n\n");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite seu sobrenome: \n\n");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("\nDigite o cargo que deseja cadastrar: \n\n");
	scanf("%s",cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}


int consulta()// Função responsável pelas consultas
{
	setlocale(LC_ALL, "portuguese");// Sempre colocar a linguagem na consulta
	
	char cpf[40];
	char conteudo[200]; // Caracteres do conteúdo em geral
	
	printf("Digite o CPF que deseja cosultar: \n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r= Read | Ler
	
	if (file==NULL)// Se caso for um dado inválido
	{
	printf("\nNão foi possível abrir o arquivo! O arquivo não foi localizado! \n\n");
	}
	while(fgets(conteudo, 200, file) !=NULL);// != Diferente de... Enquanto o conteúdo receber 200 caracteres, e estar dentro do arquivo, ele é diferente
	{
	printf("\nAqui estão os dados solicitados! \n\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
}

int deletar()// Função responsável pela deleta de dados
{
	char cpf[40];
	
	printf("Digite o CPF do usuário que deseja deletar: \n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)// Se os dados forem inválidos
	{
	printf("Nenhum usuário foi encontrado! \n\n");
	system("pause");
	return 0; // Comando que retorna à tela inicial
	}
	
	fclose(file); // Feche o arquivo após verificar sua exstência
	
	printf("Deseja deletar esse usuário do sistema? \n\n");
	printf("%s",cpf);
	printf("\n\nDigite (s) para sim e digite (n) para não! \n\n");
	
	getchar(); // opção utilizada para conseguir caracteres para opção
	
	char opcao;
	opcao = getchar();
	
	if (opcao == 's' || opcao == 'S') // para caso for s maiúsculo ou minúsculo
	{
	
	if (remove(cpf) == 0)
	{
	printf("O usuário foi deletado com sucesso! \n\n");
	}
	system("pause");
	
	}
	else if (opcao == 'n' || opcao == 'N') // para caso for n maiúsculo ou minúsculo
	{
	printf("Retorne ao menu principal! \n");
	system("pause");
	}
	else
	{
	printf("Opção inválida! \n");
	system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo variáveis
	int laco =1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//strcmp = String de comparação
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)// Repetição
		{
		system("cls");//Limpeza do enunciado após a resposta.
		
		setlocale(LC_ALL, "Portuguese");// Atribuição de linguagem e acentos// LC= Linguagem de categoria
		
		printf("### Cartório da EBAC ### \n\n");//Início do Menu
		printf("Seja bem vindo! \n\n");
		printf("O que deseja realizar em nosso sistema? \n\n");
		printf("\tAperte 1 para cadastrar no sistema: \n");
		printf("\tAperte 2 para carregar conta: \n");
		printf("\tAperte 3 para deletar conta: \n");
		printf("\tAperte 4 para saír do sistema: \n\n");
		printf("Digite a opção que deseja: ");//Fim do Menu
		
		scanf("%d", &opcao);// Armazenamento da escolha do usuário
		
		system("cls");
		
		switch(opcao)
		{
		
		case 1:
			cadastro();//Chamada de funções
			break;
			
		case 2:
			consulta();
			break;
			
		case 3:
			deletar();
			break;
			
		case 4:
		printf("Obrigado por utilizar nosso sistema! \n");
		return 0;
		break;
			
		default:
			printf("Essa opção está indisponível");
			system("pause");//Para pausar o sistema após a seleção
			break;//Fim da seleção
			
		}
		}
	}
	else
	printf("Senha incorreta! ");
}
	
