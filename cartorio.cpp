#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar os usu�rios no sistema
{
    // in�cio da cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da cria��o de vari�veis/string

    printf("Digite o CPF para ser cadastrado: "); // coletando informa��es do usu�rio
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // respons�vel por copiar valores das strings

    FILE *file;                // cria um ponteiro para o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    if (file != NULL) // verifica se o arquivo foi criado com sucesso
    {
        fprintf(file, cpf); // salva o valor da vari�vel CPF no arquivo
        fclose(file);       // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, ","); // adiciona uma v�rgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o nome a ser cadastrado: "); // coletando o nome do usu�rio
        scanf("%s", nome);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, nome); // adiciona o nome no arquivo
        fclose(file); // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, ","); // adiciona uma v�rgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o sobrenome a ser cadastrado: "); // coletando o sobrenome do usu�rio
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, sobrenome); // adiciona o sobrenome no arquivo
        fclose(file); // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, ","); // adiciona uma v�rgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o cargo a ser cadastrado: "); // coletando o cargo do usu�rio
        scanf("%s", cargo);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adi��o
        fprintf(file, cargo); // adiciona o cargo no arquivo
        fclose(file); // fecha o arquivo
    }

    {
        printf("Erro ao criar o arquivo.\n");
    }

    system("pause"); // pausa o sistema para que o usu�rio possa ver as mensagens
}

int consulta() // fun��o respons�vel por consultar os usu�rios no sistema
{
    setlocale(LC_ALL, "Portuguese"); // define o local para suporte a portugu�s
    
    // in�cio da cria��o de vari�veis/string
    char cpf[40];
    char conteudo[200];
    // fim da cria��o de vari�veis/string

    printf("Digite o CPF a ser consultado: "); // coletando o CPF para consulta
    scanf("%s", cpf);

    FILE *file; // cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // abre o arquivo em modo de leitura

    if (file == NULL) // verifica se o arquivo foi aberto com sucesso
    {
        printf("N�o foi poss�vel abrir o arquivo, n�o localizado.\n"); // mensagem de erro
    }
    
    {
        while (fgets(conteudo, 200, file) != NULL) // l� o conte�do do arquivo
        {
            printf("\nEssas s�o as informa��es do usu�rio: ");
            printf("%s", conteudo); // exibe o conte�do do arquivo
            printf("\n\n");
        }
        fclose(file); // fecha o arquivo
    }

    system("pause"); // pausa o sistema para que o usu�rio possa ver as mensagens
}

int deletar() // fun��o respons�vel por deletar os usu�rios no sistema
{
    char cpf[40]; // cria��o de vari�veis

    printf("Digite o CPF a ser deletado: "); // coletando o CPF para deletar
    scanf("%s", cpf);

    remove(cpf); // remove o arquivo associado ao CPF

    FILE *file; // cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // tenta abrir o arquivo para verificar se foi removido

    if (file == NULL) // verifica se o arquivo foi removido com sucesso
    {
        printf("O usu�rio n�o se encontra no sistema!.\n"); // mensagem de sucesso
        system("pause"); // pausa o sistema para que o usu�rio possa ver as mensagens
    }
}

int main() // fun��o principal que controla o fluxo do programa
{
    int opcao = 0; // definindo vari�veis
    int laco = 1; // vari�vel de controle do loop

    while (laco == 1) // loop principal do programa
    {
        system("cls"); // limpa a tela

        setlocale(LC_ALL, "Portuguese"); // define o local para suporte a portugu�s

        // in�cio do menu
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Op��o: "); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usu�rio

        system("cls"); // respons�vel por limpar a tela

        switch (opcao) // in�cio da sele��o do menu
        {
            case 1:
                registro(); // chamada da fun��o registro
                break;

            case 2:
                consulta(); // chamada da fun��o consulta
                break;

            case 3:
                deletar(); // chamada da fun��o deletar
                break;
            
            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;

            default: // caso o usu�rio escolha uma op��o inv�lida
                printf("Essa op��o n�o est� dispon�vel!\n");
                system("pause"); // pausa o sistema para que o usu�rio possa ver as mensagens
                break;
        }
    }
}
