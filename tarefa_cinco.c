#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o em espa�o de mem�ria
#include <locale.h> // Biblioteca de aloca��es de texto por regi�o
#include <string.h> // Biblioteca de strings

int registro() // Fun��o respons�vel por criar cadastro dos usu�rios
{
	char arquivo[40]; // Cria��o das vari�veis que queremos do usu�rio
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��es do usu�rio
	scanf("%s", cpf); // Armazenando informa��es do usu�rio nas vari�veis de tipo string
	
	strcpy(arquivo,cpf); // Respons�vel por copiar os valores da string do cpf para o arquivo
	
	FILE *file; // Cria arquivo
	file = fopen(arquivo, "w"); // Cria arquivo("w" significa escrever/criar um novo arquivo)
	fprintf(file,cpf); // Salva o valor da vari�vel(chave principal)
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualizar ("a" significa atualizar arquivo)
	fprintf(file, ","); // Salva dentro do arquivo a v�rgula para separar infos do usu�rio
	fclose(file); // Fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coleta informa��es
	scanf("%s", nome); // Armazena nome na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, nome); // Armazena nome no arquivo
	fclose(file); // Fecha arquivo
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, ","); // Insere v�rgula para separar dados
	fclose(file); // Fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coleta informa��es
	scanf("%s", sobrenome); // Armazena sobrenome na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, sobrenome); // Armazena sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, ","); // Insere v�rgula para separar dados
	fclose(file); // Fecha arquivo
	
	printf("Digite o cargo a ser cadastrado :"); // Coleta informa��es
	scanf("%s", cargo); // Armazena cargo na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, cargo); // Armazena cargo no arquivo
	fclose(file); // Fecha arquivo
	
	system("pause"); // Dar pausa entre etapas do programa ao rodar
	
}

int consulta() // Cria fun��o respons�vel por consultar usu�rios no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	char cpf[40]; // Criando vari�vel chave prim�ria
	char conteudo[100]; // Vari�vel onde dados cadastrados no processo de registro ficar�o.
	
	printf("Digite o CPF a ser consultado:"); // Coletando informa��es
	scanf("%s", cpf); // Armazena informa��es na string
	
	FILE *file; // Procura fun��o de arquivo em bibliotecas
	file = fopen(cpf,"r"); // Lendo o arquivo
	
	if(cpf == NULL) // Condicional caso chame uma vari�vel de valor nulo
	{
		printf("N�o foi poss�vel abrir o arquivo. N�o localizado! \n"); // Resposta o usu�rio
	}
	
	while(fgets(conteudo,100, file) !=NULL) // Ler informa��es que estiverem na vari�vel at� valor ser inexistente/nulo
	{
		printf("\n Essas s�o as informa��es do usu�rio:\n"); // Mostrar essa mensagem para quem est� acessando sistema
		printf("%s", conteudo); // Armazena cont�udo na string
		printf("\n\n"); // Dando espa�amento
	}
	
}

int deletar() // Cria fun��o para deletar usu�rio do sistema
{
	char cpf[40]; // Cria vari�vel
	
	printf("Digite o CPF do usu�rio a ser deletado:"); // Coleta info
	scanf("%s",cpf); // Salva info na string
	
	remove(cpf); // Para excluir
	
	FILE *file; // Chama arquivo
	file = fopen(cpf,"r"); // L� arquivo
	
	if(file == NULL) // Valida��o
	{
		printf("O usu�rio n�o se encontra no sistema! \n"); // Mensagem para quem est� acessando o sistema
		system("pause"); // Pausa 
	}

}

int main() // criando fun��o principal
    {
	int opcao=0; // Dando valor �s vari�veis
	int laco=1; 
	
	for(laco=1;laco=1;) // Criando La�o de repeti��o com valores de entrada e sa�da
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Defini��o de linguagem
		
		printf("###Cart�rio EBAC### \n \n"); // In�cio do menu que aparecer� para o usu�rio
		printf("Escolha a op��o desejada no menu: \n \n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar os nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Op��o:"); // Fim do menu
		
		scanf("%d", &opcao); // Salva escolha selecionada pelo usu�rio
		
		system("cls"); // Ap�s escolha, por quest�o de qualidade visual, limpar a tela
		
		switch (opcao) // Chamada de fun��es
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Voc� escolheu retornar ao menu!");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!");
			system("pause");
		}
		
	}
} // Fim do programa

