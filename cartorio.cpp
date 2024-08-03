#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar os usuários no sistema
{
    // início da criação de variáveis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    // fim da criação de variáveis/string

    printf("Digite o CPF para ser cadastrado: "); // coletando informações do usuário
    scanf("%s", cpf); // %s refere-se a string

    strcpy(arquivo, cpf); // responsável por copiar valores das strings

    FILE *file;                // cria um ponteiro para o arquivo
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    if (file != NULL) // verifica se o arquivo foi criado com sucesso
    {
        fprintf(file, cpf); // salva o valor da variável CPF no arquivo
        fclose(file);       // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, ","); // adiciona uma vírgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o nome a ser cadastrado: "); // coletando o nome do usuário
        scanf("%s", nome);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, nome); // adiciona o nome no arquivo
        fclose(file); // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, ","); // adiciona uma vírgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o sobrenome a ser cadastrado: "); // coletando o sobrenome do usuário
        scanf("%s", sobrenome);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, sobrenome); // adiciona o sobrenome no arquivo
        fclose(file); // fecha o arquivo

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, ","); // adiciona uma vírgula no arquivo
        fclose(file); // fecha o arquivo

        printf("Digite o cargo a ser cadastrado: "); // coletando o cargo do usuário
        scanf("%s", cargo);

        file = fopen(arquivo, "a"); // abre o arquivo em modo de adição
        fprintf(file, cargo); // adiciona o cargo no arquivo
        fclose(file); // fecha o arquivo
    }

    {
        printf("Erro ao criar o arquivo.\n");
    }

    system("pause"); // pausa o sistema para que o usuário possa ver as mensagens
}

int consulta() // função responsável por consultar os usuários no sistema
{
    setlocale(LC_ALL, "Portuguese"); // define o local para suporte a português
    
    // início da criação de variáveis/string
    char cpf[40];
    char conteudo[200];
    // fim da criação de variáveis/string

    printf("Digite o CPF a ser consultado: "); // coletando o CPF para consulta
    scanf("%s", cpf);

    FILE *file; // cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // abre o arquivo em modo de leitura

    if (file == NULL) // verifica se o arquivo foi aberto com sucesso
    {
        printf("Não foi possível abrir o arquivo, não localizado.\n"); // mensagem de erro
    }
    
    {
        while (fgets(conteudo, 200, file) != NULL) // lê o conteúdo do arquivo
        {
            printf("\nEssas são as informações do usuário: ");
            printf("%s", conteudo); // exibe o conteúdo do arquivo
            printf("\n\n");
        }
        fclose(file); // fecha o arquivo
    }

    system("pause"); // pausa o sistema para que o usuário possa ver as mensagens
}

int deletar() // função responsável por deletar os usuários no sistema
{
    char cpf[40]; // criação de variáveis

    printf("Digite o CPF a ser deletado: "); // coletando o CPF para deletar
    scanf("%s", cpf);

    remove(cpf); // remove o arquivo associado ao CPF

    FILE *file; // cria um ponteiro para o arquivo
    file = fopen(cpf, "r"); // tenta abrir o arquivo para verificar se foi removido

    if (file == NULL) // verifica se o arquivo foi removido com sucesso
    {
        printf("O usuário não se encontra no sistema!.\n"); // mensagem de sucesso
        system("pause"); // pausa o sistema para que o usuário possa ver as mensagens
    }
}

int main() // função principal que controla o fluxo do programa
{
    int opcao = 0; // definindo variáveis
    int laco = 1; // variável de controle do loop

    while (laco == 1) // loop principal do programa
    {
        system("cls"); // limpa a tela

        setlocale(LC_ALL, "Portuguese"); // define o local para suporte a português

        // início do menu
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n");
        printf("\t2 - Consultar nomes\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("Opção: "); // fim do menu

        scanf("%d", &opcao); // armazenando a escolha do usuário

        system("cls"); // responsável por limpar a tela

        switch (opcao) // início da seleção do menu
        {
            case 1:
                registro(); // chamada da função registro
                break;

            case 2:
                consulta(); // chamada da função consulta
                break;

            case 3:
                deletar(); // chamada da função deletar
                break;
            
            case 4:
            	printf("Obrigado por utilizar o sistema!\n");
            	return 0;
            	break;

            default: // caso o usuário escolha uma opção inválida
                printf("Essa opção não está disponível!\n");
                system("pause"); // pausa o sistema para que o usuário possa ver as mensagens
                break;
        }
    }
}
