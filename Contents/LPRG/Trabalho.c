//Nomes: Homero M. V. Kemmerich e Wesley de Oliveira T.
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ide, idp;
    float temperatura;
    struct sistema *elo;
    struct sistema *anterior;
} sistema;

typedef struct
{
    sistema *inicio;
    sistema *fim;
    int tamanho;
} descritor;

sistema *busca( descritor lista, int posicao)
{
    int cont = 1;
    sistema *anterior;
    anterior = lista.inicio;
    while(cont != posicao-1)
    {
        anterior = anterior->elo;
        cont ++;
    }
    return anterior->elo;
}

sistema *consulta (descritor lista, int id, int opcao)
{
    sistema *anterior;
    int cont = 1;
    anterior = lista.inicio;

    while(anterior!=lista.fim)
    {
        if((opcao == 1)&&(id == anterior->ide))
            printf("\n%d\t %.1f\t %d\t %d\n", cont, anterior->temperatura, anterior->ide, anterior->idp);

        else if ((opcao == 2)&&(id == anterior->idp))
            printf("\n%d\t %.1f\t %d\t %d\n", cont, anterior->temperatura, anterior->ide, anterior->idp);

        anterior = anterior->elo;
        cont++;
    }
}

int main()
{
    sistema item;
    int opcao, opcao2, opcao3, posicao, cont=1, aux, id;
    sistema *endereco, *novo, *anterior;
    descritor lista;

    lista.inicio = NULL;
    lista.fim = NULL;
    lista.tamanho = 0;

    do
    {
        system("cls");
        puts("\nM E N U");
        puts("--------");
        puts("1 - Incluir no fim");
        puts("2 - Mostrar");
        puts("3 - Inserir na posicao n");
        puts("4 - Remover");
        puts("5 - Consulta");
        puts("0 - Finalizar");
        printf("\nSua opcao: ");

        fflush(stdin);
        scanf("%d", &opcao);
        system("cls");

        switch (opcao)
        {
        case 1:
            puts("Incluir\n");
            printf("Digite\nTemperatura: ");
            scanf("%f", &item.temperatura);

            printf("ID do equipamento: ");
            scanf("%d", &item.ide);

            printf("ID da propriedade: ");
            scanf("%d", &item.idp);

            novo = malloc(sizeof(sistema));
            if (novo == NULL)
                puts("\n***Bah, nao deu");
            else
            {
                novo->ide         = item.ide;
                novo->idp         = item.idp;
                novo->temperatura = item.temperatura;

                if(lista.inicio == NULL)///UNICO
                {
                    lista.inicio = lista.fim = novo;
                    novo->elo = NULL;
                    novo->anterior = NULL;
                }
                else
                {
                    novo->elo = NULL;
                    lista.fim->elo = novo;
                    lista.fim = novo;
                }
                lista.tamanho++;
                puts("\n Item incluido com sucesso");
                system("pause");
            }
            break;
        case 2:
            puts("Mostrar\n");

            if( lista.inicio == NULL )
            {
                puts("\n*** Lista vazia\n");
                system("pause");
                break;
            }
            else
            {
                endereco = lista.inicio;
                aux = 1;
                while( endereco != NULL )
                {
                    printf("\n%d\t%.1f\t %d\t %d\t", aux, endereco->temperatura, endereco->ide, endereco->idp);
                    endereco = endereco->elo;
                    aux++;
                }
            }
            puts("\n");
            system("pause");
            break;

        case 3:
            puts("Incluir\n");
            puts("Insira a posicao desejada: ");
            scanf("%d", &posicao);

            printf("Digite\nTemperatura: ");
            scanf("%f", &item.temperatura);

            printf("ID do equipamento: ");
            scanf("%d", &item.ide);

            printf("ID da propriedade: ");
            scanf("%d", &item.idp);

            novo = malloc(sizeof(sistema));

            if ((novo == NULL)||(posicao > lista.tamanho + 1))
                puts("\n***Posicao invalida");
            else
            {
                novo->ide         = item.ide;
                novo->idp         = item.idp;
                novo->temperatura = item.temperatura;

                if(lista.inicio == NULL)//unico - lista vazia
                {
                    lista.inicio = lista.fim = novo;
                    novo->elo = NULL;
                    novo->anterior = NULL;
                }
                else
                {
                    if (posicao == 1)
                    {
                        novo->elo = lista.inicio;
                        lista.inicio = novo;
                    }
                    else
                    {
                        if(posicao == lista.tamanho+1)
                        {
                            novo->elo = NULL;
                            lista.fim->elo = novo;
                            lista.fim = novo;
                        }
                        else
                        {
                            anterior = lista.inicio;
                            while(cont != posicao-1)
                            {
                                anterior = anterior->elo;
                                cont ++;
                            }
                            novo->elo = anterior->elo;
                            anterior->elo = novo;
                        }
                    }
                }
                lista.tamanho ++;
                puts("\n Item incluido com sucesso");
                system("pause");
                break;

        case 4:
                puts("Remover\n");
                if( lista.inicio == NULL )
                    puts("\n***Lista vazia \n");
                else
                {
                    if(lista.inicio == lista.fim)//unico
                        lista.inicio = lista.fim = NULL;
                    else
                    {
                        puts("\n Digite o indice a ser removido:");
                        scanf("%d", &posicao);
                        if(posicao == 1)
                            lista.inicio = lista.inicio->elo;
                        else
                        {
                            endereco = busca(lista, posicao);
                            if (endereco == NULL)
                                puts("\n Valor nao encontrado");
                            else
                            {
                                anterior = lista.inicio;//inicio o "anterior no inicio da lista
                                while(anterior->elo != endereco)//percorre a lista at� chegar no anterior ao endereco
                                    anterior = anterior->elo;

                                if (endereco == lista.fim)//ultimo
                                {
                                    lista.fim = anterior;
                                    lista.fim->elo = NULL;
                                }
                                else//intermediario
                                    anterior->elo = endereco->elo;
                            }
                        }
                    }
                    free(endereco);
                }
                lista.tamanho --;
                puts("\nItem Removido com sucesso");
                system("pause");
                break;
        case 5:
                puts("Consulta\n");
                puts("Consultar por:\n 1 - ID de equipamento\n 2 - ID de propriedade");
                fflush(stdin);
                scanf("%d", &opcao2);

                if (opcao2 == 1)
                {
                    puts("\nDigite o ID do equipamento:");
                    scanf ("%d", &id);
                    (consulta(lista, id, 1));
    
                    system("pause");
                }
                if (opcao2 == 2)
                {
                    puts("\nDigite o ID da propriedade:");
                    scanf ("%d", &id);
                    (consulta(lista, id, opcao2));

                    system("pause");
                }
                break;
            }
        }
    }
    while (opcao != 0);
    free(novo);
    puts("\nEncerrando...");
    return 0;
}
