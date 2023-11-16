#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/// definição dqa estrutura do nodo a ser utilizado na leitura]
/// o nodo é um tipo de dado definindo pelo usuário(não é um TAD pois não estamos trabalhando com POO)

struct nodo
{
    char info[128];
    struct nodo *elo;
};
//descrição da estrutura do descritor da lista

struct desc_lista
{
    struct nodo *inicio;
    struct nodo *fim;
    int tamanho;

};

///função que busca um determinado valor na lista, retornando seu endereço de memória ou NULL, caso não exista
struct nodo *busca(struct desc_lista lista, char VALOR[128])
{
    struct nodo *endereco;

    endereco = lista.inicio;//começa no inicio

    while(endereco != NULL)//continua até o fim
    {
        if (strcmp(VALOR, endereco->info)==0)//se chegou no fim
        {
            break;
        }
        endereco = endereco->elo;
    }
    return endereco;
}

int main(void)
{
    char opcao, opcao2, VALOR[128];
    struct desc_lista lista;
    struct nodo *endereco, *novo, *anterior;
    int existe;

    ///inicialização da lista (do descritor da lista)
    lista.inicio = NULL;
    lista.fim    = NULL;
    lista.tamanho= NULL;

    do
    {
        puts("\n\n M E N U");
        puts("\n--------");
        puts("I - Incluir");
        puts("C - Consulta");
        puts("R - Retirar");
        puts("M - Mostrar");
        puts("F - Fim");
        puts("\nSua opcao:");
        fflush(stdin);
        scanf("%c", &opcao);
        opcao = toupper(opcao);// transforma qualquer letra em maiuscula / tolower() faz o contrário
        system("cls");//cls limpa a tela em DOS

        switch(opcao)
        {
        case 'I':
            puts("\n INCLUSAO");
            do
            {
                puts("I - Inclusao no inicio");
                puts("F - Inclusao no fim");
                puts("\nSua opcao:");
                fflush(stdin);
                scanf("%c", &opcao2);
                opcao2 = toupper(opcao2);
            }
            while (opcao2 != 'F' && opcao2 != 'I');

            printf("Digite o valor a ser incluido: ");
            fflush(stdin);
            scanf("%s", VALOR);

            ///obter um novo nodo na memória para adicionar o índice
            novo = malloc(sizeof(struct nodo));

            if (novo == NULL)
            {
                puts("\n *** Erro na alocação de memória");
            }
            else
            {
                strcpy(novo->info, VALOR);
                if (opcao2 == 'F')///inclusão no fim
                {
                    novo->elo = NULL;
                    if (lista.inicio == NULL)//testa se a lista está vazia
                    {
                        lista.inicio = novo;//se estiver, atualiza o início
                    }
                    lista.fim = novo;//atualiza o fim da lista
                    lista.tamanho++;
                    puts("\n ***Inclusao realizada com sucesso");
                    system("pause");
                }
                else///inclusao no inicio
                {
                    novo->elo = lista.inicio;
                    if (lista.inicio == NULL)//testa se a lista está vazia
                        lista.fim = novo;//se estiver, atualiza o início

                    lista.inicio = novo;
                    lista.tamanho++;
                    puts("\n ***Inclusao realizada com sucesso");
                    system("pause");
                }
            }


            system("pause");//"Pressione qualquer tecla para continuar..."
            break;

        case 'C':
            puts("\n CONSULTA");

            printf("Digite o valor a ser consultado: ");
            fflush(stdin);
            scanf("%s", VALOR);
            ///Chama a função "busca" dentro do if
            ///Igual a:
            ///endereco = busca(lista, VALOR);
            ///
            if (busca(lista, VALOR) != NULL)
                puts("\nInformacao existente");
            else
                puts("\nInformacao inexistente");

            if (lista.inicio==NULL)
                puts("\n***Lista vazia");

            system("pause");
            break;

        case 'R':
            puts("\n RETIRAR");
            if (lista.inicio == NULL)
            {
                puts("\n***Lista vazia\n");
            }
            else
            {
                printf("\n Digite o valor a ser retirado: ");
                fflush(stdin);
                scanf("%s", VALOR);
                endereco = busca(lista, VALOR);
                if (endereco == NULL)
                    puts("\n Valor nao encontrado");
                else
                {
                    if (lista.inicio == lista.fim)///Único
                    {
                        lista.inicio == lista.fim == NULL;
                    }
                    else
                    {
                        if (endereco == lista.inicio)///Primeiro
                            lista.inicio = lista.inicio->elo;
                        else
                        {
                            /// como tanto ptanto para o caso ultimo quanto para o intermediario
                            ///eh necessario saber quem é o anterior do  nodo
                            anterior = lista.inicio;
                            while(anterior->elo != endereco)
                                anterior = anterior->elo;

                            if (endereco == lista.fim)///Último
                            {
                                lista.fim = anterior;
                                lista.fim->elo = NULL;
                            }
                            else ///Intermediário
                                anterior->elo = endereco->elo;
                        }
                    }
                    lista.tamanho--;
                    free(endereco);
                    puts("\nRetirada realizada com sucesso");
                }
            }
            system("pause");
            break;

        case 'M':
            puts("\n MOSTRAR");
            if (lista.inicio==NULL)
                puts("\n***Lista vazia");
            else
            {
                endereco = lista.inicio;
                while(endereco!= NULL)
                {
                    printf("\n%s\n", endereco->info);//Quando a variável é um endereço não se usa "." , mas sim "->"
                    endereco = endereco->elo;//ex.: (endereço.info)!=(endereço->
                }
            }

            system("pause");
            break;

        case 'F':
            puts("\n FINALIZAR");
            break;
        }
    }
    while(opcao != 'F');
    printf("\nTschuss\n");
    return 0;
}
