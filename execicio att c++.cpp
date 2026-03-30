//bibliotecas são pequenos conjuntos de códigos que ja contem programações prontas
//include é usada para incluir arquivos de cabeçalho em um programa 
//tudo que se encontra em "" é texto
//int = inteiro, int main = é a função principal de um programa é obrigatório ter ela
//os () mostram que é uma função = conjunto de instruções que iremos programar
//os {} tudo aquilo que esta dentro da int...
//os [] significa que é uma string
//o \n pula 1 linha deixa o programa organizado e melhor vizivelmente
//o ; encerra um comando 
//o \t da um espaço no começo do texto bom pra alinhar e deixar melhor vizivelmente o programa
//%s armazena dentro da string

//inicio da biblioteca de códigos
#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória 
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string 
//final da biblioteca de códigos

int registro() //função responsavel por cadastrar os usuários no sistema
{
	//inicio criação de variáveis/string
	char arquivo[40]; //responsavel por definir quantidade de variáveis permitidas no arquivo
	char cpf[40]; //responsavel por definir quantidade de variáveis permitidas no cpf
	char nome[40]; //responsavel por definir quantidade de variáveis permitidas no nome
	char sobrenome[40]; //responsavel por definir quantidade de variáveis permitidas no sobrenome
	char cargo[40]; //responsavel por definir quantidade de variáveis permitidas no cargo
	//final criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //armazena o valor dentro da variavel cpf, %s no caso de salvar na string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel no arquivo(file)
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abrindo arquivo ja salvo na maquina o "a" é de atualizar o arquivo  
	fprintf(file,","); //salva a informação atualizada
	fclose(file); 
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s",nome); 
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file); 
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file); 
	 
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file); 
	
	system("pause"); //pausa o programa para que não rode sem a confirmação do usuário
	
}

int consulta() //função responsavel por consultar se a ou não um usuário cadastrado
{
	setlocale(LC_ALL, "portuguese"); //definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: "); 
	scanf("%s",cpf); //armazena o valor dentro da variavel cpf
	
	FILE *file;
	file = fopen(cpf,"r"); // abre e le o arquivo o "r" é de ler 
	
	if(file == NULL) //caso o arquivo não seja localizado ou seja NULL(nulo)
	{
		printf("Não foi possivel abrir o arquivo, não localizado!.\n");	//responsavel por trazer o texto que o programador digita ao usuário
	}
	
	while(fgets(conteudo, 200, file) != NULL) //um laço de loop enquanto estiver dentro das exigencias do programa e quando não acahar os 200 sera NULL
	{
		printf("\nEssas são as inormações do usuário: "); 
		printf("%s", conteudo); 
		printf("\n\n"); //apenas serve pra pular linhas pra deixar vizualmente melhor
	}
	
	system("pause");
	
	
}

int deletar() //função reponsavel por deletar um usuário cadastrado
{
	char cpf[40];
	
	printf("Digitar o CPF do usuário a ser deletado: "); 
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL) //se refere ao arquivo(file) e compara (==)
    {
    	printf("O usuário não se encontra no sistema! .\n"); 
	}
	
	while(fgets(cpf, 40, file) != NULL)
	{
		printf("\nO usuário foi removido do sistema! .\n"); 
	}
	system("pause"); 
}


int main() //função principal é nela que a execução do programa começa
 { 
	int opcao=0; //definindo variaveis 
	int laco=1; //definindo variaveis 
	char senhadigitada[10]="a";
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de adminstrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
    {
	     system ("cls");
       	for(laco=1;laco==1;)
    	{
	
	     system("cls"); //responsavel por limpar a tela
	
	     setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	
	      printf("### Cartório da EBAC ###\n\n"); //inicio do menu 
	     printf("Escolha a opção desejada do menu\n\n"); //traz o texto a tela para fazer o usúario escolher uma opção
	     printf("\t1 - Resgistrar nomes\n"); //responsavel por trazer a opção de registrar
         printf("\t2 - Consultar nomes\n"); //responsavel por trazer a opção de consulta
         printf("\t3 - Deletar nomes\n\n"); //responsavel por deletar as açoes feitas a partir do primeiro (t1)
         printf("\t4 - Sair do sistema\n\n");
         printf("Opção: "); //fim do menu
    
          scanf("%d", &opcao); //armazenando a escolha do usuario "%d" 
	
	     system("cls"); // responsavel por limpar a tela
	
	
	     switch(opcao) //inicio da seleção do menu
	         {
	         case 1: //se caso o valor seja 1 ira executar as opções disponiveis
	         registro(); //chamada de funções, registrar
		     break; //encerra a comando em andamento
	 
		     case 2: 
		     consulta(); //chamada de funções, consultar
		     break;	
		
		     case 3: 
		     deletar(); //chamada de funções, deletar
		     break; 
		 
		     case 4:
		     printf("obrigado por utilizar nosso sistema!\n");
		
		     return 0;
		     break;
		
		     default: //caso não tenha a opção que no caso o valor é 0 sera executado de imediato
		     printf("Essa opção não está disponivel!\n"); 
             system("pause"); 
             break; 
	        } //fim da seleção do menu
 	    }
    }
    
    else
        printf("senha incorreta!");
 }

