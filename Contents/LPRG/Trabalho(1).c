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

sistema *busca( descritor lista , sistema item )
{
    sistema *endereco;

    endereco = lista.inicio;
    while( endereco->elo != NULL )
    {
        if((item->ide == endereco->ide)||(item->idp == endereco->idp)||(item->temperatura == endereco->temperatura)){
            break;
        endereco = endereco->elo;
        }
    }
    return endereco;
}


int main()
{
    sistema item, aux;
    int opcao, opcao2, opcao3, posicao, cont, status;
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
            puts("\nIncluir\n");
            printf("Digite\n Temperatura: ");
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
            }
            break;
        case 2:
            puts("\nMOSTRA\n");

            if( lista.inicio == NULL )
            {
                puts("\n*** Lista vazia\n");
                break;
            }
            else
            {
                endereco = lista.inicio;
                while( endereco != NULL )
                {
                    printf("\n%.1f\t %d\t %d\t", endereco->temperatura, endereco->ide, endereco->idp);
                    endereco = endereco->elo;
                }
            }
            puts("\n");
            system("pause");
            break;

        case 3:
            puts("Inserir na posicao n\n");
            puts("Insira a posicao desejada: ");
            scanf("%d", &posicao);
            //posicao -= 1;

            //aux = item[posicao];

            endereco = lista.inicio;
            do{
                if(cont == posicao-1){
                    endereco->elo = novo;
                    status=0;
                }else{
                endereco = endereco->elo;
                }
            }while(status != 0);
            novo->elo = endereco->elo;

            printf("Digite\n Temperatura: ");
            scanf("%f", &item.temperatura);

            printf("ID do equipamento: ");
            scanf("%d", &item.ide);

            printf("ID da propriedade: ");
            scanf("%d", &item.idp);

            lista.tamanho ++;
        }
        case 4:
            puts("REMOVER\n")
            if( lista.inicio == NULL )
                       {
                           puts("\n*** ERRO Underflow\n");
                       }
                       else
                       {
                           printf("\nDigite o valor a ser retirado : ");
                           fflush( stdin );
                           scanf("%s" , valor );
                           endereco = busca( lista , item );
                           if( endereco == NULL )
                               puts("\nERRO Valor nao encontrado");
                           else
                           {
                               if( lista.inicio == lista.fim ) /// UNICO
                                   lista.inicio = lista.fim = NULL;
                               else
                               {
                                   if( endereco == lista.inicio ) /// INICIO
                                       lista.inicio = lista.inicio->elo;
                                   else
                                   {
                                       /// para o caso do 'fim' e do 'intermediario'
                                       /// eh necessario saber quem eh o anterior do nodo
                                       anterior = lista.inicio;
                                       while( anterior->elo != endereco )
                                           anterior = anterior->elo;

                                       if( endereco == lista.fim ) /// FIM
                                       {
                                           lista.fim = anterior;
                                           lista.fim->elo = NULL;
                                       }
                                       else /// INTERMEDIARIO
                                           anterior->elo = endereco->elo;
                                   }
                               }
                               lista.tamanho--;
                               free( endereco );
                               puts("\n*** Retirada realizada com sucesso");
                           }
                       }
                       system("pause");
                       break;
    }
    while (opcao != 0);
}

