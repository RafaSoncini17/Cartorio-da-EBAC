#include <stdio.h>// Biblioteca de comunica��o com o usu�rio
#include <stdlib.h>// Biblioteca de aloca��o de espa�o
#include <locale.h>// Biblioteca de aloca��o de texto por regi�o
#include <string.h>// Bibliot�ca respons�vel pelas Strings


int cadastro()// Fun��o respons�vel pelos cadastros
{
	char arquivo[40];//Char s�o os caracteres e o n�mero sua quantidade
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40]; // fim da cria��o de vari�veis
	
	printf("Digite o CPF que deseja cadastrar: \n\n");
	scanf("%s",cpf); // %s Se refere as Strings
	
	strcpy(arquivo,cpf); // Respons�vel pela c�pia dos valores das strings
	
	FILE *file; // Cria��o do arquivo
	file = fopen(arquivo,"w"); // w= Write/escrever
	fprintf(file, cpf); //fprintf = respons�vel por salvar o arquivo
	fclose(file); //Fecha o arquivo
	
	file= fopen(arquivo, "a");// a=atualizar o cadastro
	fprintf(file,","); // respns�vel por separar os dados
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


int consulta()// Fun��o respons�vel pelas consultas
{
	setlocale(LC_ALL, "portuguese");// Sempre colocar a linguagem na consulta
	
	char cpf[40];
	char conteudo[200]; // Caracteres do conte�do em geral
	
	printf("Digite o CPF que deseja cosultar: \n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r"); // r= Read | Ler
	
	if (file==NULL)// Se caso for um dado inv�lido
	{
	printf("\nN�o foi poss�vel abrir o arquivo! O arquivo n�o foi localizado! \n\n");
	}
	while(fgets(conteudo, 200, file) !=NULL);// != Diferente de... Enquanto o conte�do receber 200 caracteres, e estar dentro do arquivo, ele � diferente
	{
	printf("\nAqui est�o os dados solicitados! \n\n");
	printf("%s", conteudo);
	printf("\n\n");
	}
	
	system("pause");
}

int deletar()// Fun��o respons�vel pela deleta de dados
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio que deseja deletar: \n\n");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL)// Se os dados forem inv�lidos
	{
	printf("Nenhum usu�rio foi encontrado! \n\n");
	system("pause");
	return 0; // Comando que retorna � tela inicial
	}
	
	fclose(file); // Feche o arquivo ap�s verificar sua exst�ncia
	
	printf("Deseja deletar esse usu�rio do sistema? \n\n");
	printf("%s",cpf);
	printf("\n\nDigite (s) para sim e digite (n) para n�o! \n\n");
	
	getchar(); // op��o utilizada para conseguir caracteres para op��o
	
	char opcao;
	opcao = getchar();
	
	if (opcao == 's' || opcao == 'S') // para caso for s mai�sculo ou min�sculo
	{
	
	if (remove(cpf) == 0)
	{
	printf("O usu�rio foi deletado com sucesso! \n\n");
	}
	system("pause");
	
	}
	else if (opcao == 'n' || opcao == 'N') // para caso for n mai�sculo ou min�sculo
	{
	printf("Retorne ao menu principal! \n");
	system("pause");
	}
	else
	{
	printf("Op��o inv�lida! \n");
	system("pause");
	}
}


int main()
{
	int opcao=0;//Definindo vari�veis
	int laco =1;
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");//strcmp = String de compara��o
	
	if(comparacao == 0)
	{
		system("cls");
		for(laco=1;laco=1;)// Repeti��o
		{
		system("cls");//Limpeza do enunciado ap�s a resposta.
		
		setlocale(LC_ALL, "Portuguese");// Atribui��o de linguagem e acentos// LC= Linguagem de categoria
		
		printf("### Cart�rio da EBAC ### \n\n");//In�cio do Menu
		printf("Seja bem vindo! \n\n");
		printf("O que deseja realizar em nosso sistema? \n\n");
		printf("\tAperte 1 para cadastrar no sistema: \n");
		printf("\tAperte 2 para carregar conta: \n");
		printf("\tAperte 3 para deletar conta: \n");
		printf("\tAperte 4 para sa�r do sistema: \n\n");
		printf("Digite a op��o que deseja: ");//Fim do Menu
		
		scanf("%d", &opcao);// Armazenamento da escolha do usu�rio
		
		system("cls");
		
		switch(opcao)
		{
		
		case 1:
			cadastro();//Chamada de fun��es
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
			printf("Essa op��o est� indispon�vel");
			system("pause");//Para pausar o sistema ap�s a sele��o
			break;//Fim da sele��o
			
		}
		}
	}
	else
	printf("Senha incorreta! ");
}
	
