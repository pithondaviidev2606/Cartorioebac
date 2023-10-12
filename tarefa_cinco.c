#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação em espaço de memória
#include <locale.h> // Biblioteca de alocações de texto por região
#include <string.h> // Biblioteca de strings

int registro() // Função responsável por criar cadastro dos usuários
{
	char arquivo[40]; // Criação das variáveis que queremos do usuário
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Fim da criação de variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informações do usuário
	scanf("%s", cpf); // Armazenando informações do usuário nas variáveis de tipo string
	
	strcpy(arquivo,cpf); // Responsável por copiar os valores da string do cpf para o arquivo
	
	FILE *file; // Cria arquivo
	file = fopen(arquivo, "w"); // Cria arquivo("w" significa escrever/criar um novo arquivo)
	fprintf(file,cpf); // Salva o valor da variável(chave principal)
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre o arquivo para atualizar ("a" significa atualizar arquivo)
	fprintf(file, ","); // Salva dentro do arquivo a vírgula para separar infos do usuário
	fclose(file); // Fecha arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coleta informações
	scanf("%s", nome); // Armazena nome na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, nome); // Armazena nome no arquivo
	fclose(file); // Fecha arquivo
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, ","); // Insere vírgula para separar dados
	fclose(file); // Fecha arquivo
	
	printf("Digite o sobrenome a ser cadastrado: "); // Coleta informações
	scanf("%s", sobrenome); // Armazena sobrenome na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, sobrenome); // Armazena sobrenome no arquivo
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, ","); // Insere vírgula para separar dados
	fclose(file); // Fecha arquivo
	
	printf("Digite o cargo a ser cadastrado :"); // Coleta informações
	scanf("%s", cargo); // Armazena cargo na string
	
	file = fopen(arquivo, "a"); // Abre arquivo para atualizar
	fprintf(file, cargo); // Armazena cargo no arquivo
	fclose(file); // Fecha arquivo
	
	system("pause"); // Dar pausa entre etapas do programa ao rodar
	
}

int consulta() // Cria função responsável por consultar usuários no sistema
{
	setlocale(LC_ALL, "Portuguese"); // Definindo Linguagem
	
	char cpf[40]; // Criando variável chave primária
	char conteudo[100]; // Variável onde dados cadastrados no processo de registro ficarão.
	
	printf("Digite o CPF a ser consultado:"); // Coletando informações
	scanf("%s", cpf); // Armazena informações na string
	
	FILE *file; // Procura função de arquivo em bibliotecas
	file = fopen(cpf,"r"); // Lendo o arquivo
	
	if(cpf == NULL) // Condicional caso chame uma variável de valor nulo
	{
		printf("Não foi possível abrir o arquivo. Não localizado! \n"); // Resposta o usuário
	}
	
	while(fgets(conteudo,100, file) !=NULL) // Ler informações que estiverem na variável até valor ser inexistente/nulo
	{
		printf("\n Essas são as informações do usuário:\n"); // Mostrar essa mensagem para quem está acessando sistema
		printf("%s", conteudo); // Armazena contéudo na string
		printf("\n\n"); // Dando espaçamento
	}
	
}

int deletar() // Cria função para deletar usuário do sistema
{
	char cpf[40]; // Cria variável
	
	printf("Digite o CPF do usuário a ser deletado:"); // Coleta info
	scanf("%s",cpf); // Salva info na string
	
	remove(cpf); // Para excluir
	
	FILE *file; // Chama arquivo
	file = fopen(cpf,"r"); // Lê arquivo
	
	if(file == NULL) // Validação
	{
		printf("O usuário não se encontra no sistema! \n"); // Mensagem para quem está acessando o sistema
		system("pause"); // Pausa 
	}

}

int main() // criando função principal
    {
	int opcao=0; // Dando valor às variáveis
	int laco=1; 
	
	for(laco=1;laco=1;) // Criando Laço de repetição com valores de entrada e saída
	{
		
		system("cls"); 
		
		setlocale(LC_ALL, "Portuguese"); // Definição de linguagem
		
		printf("###Cartório EBAC### \n \n"); // Início do menu que aparecerá para o usuário
		printf("Escolha a opção desejada no menu: \n \n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar os nomes \n");
		printf("\t3 - Deletar nomes \n\n");
		printf("\t4 - Sair do sistema\n");
		printf("Opção:"); // Fim do menu
		
		scanf("%d", &opcao); // Salva escolha selecionada pelo usuário
		
		system("cls"); // Após escolha, por questão de qualidade visual, limpar a tela
		
		switch (opcao) // Chamada de funções
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
			printf("Você escolheu retornar ao menu!");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!");
			system("pause");
		}
		
	}
} // Fim do programa

