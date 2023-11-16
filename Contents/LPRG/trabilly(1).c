#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <Windows.h>

typedef struct 
{
    char *produto;
    char *locr;
    char *loca;
    struct nodo *elo;
}nodo;

typedef struct
{
    struct nodo *frente;
    struct nodo *re;
    int tamanho;
}desc_fila;

int main(int argc, char **argv){

    FILE *src, *dest;
    char *c, *l, linha[36];
    nodo *endereco, *novo;
    desc_fila fila;
    char data[9], hora[9];

    fila.frente = NULL;
    fila.re     = NULL;
    fila.tamanho = 0;

    if(argc!=3){
        fprintf(stderr, "Parametros Invalidos");
        exit(1);
    }

    src = fopen(argv[1], "r+t");
    if(src==NULL){
       fprintf(stderr, "Erro ao abrir o arquivo de origem");
       exit(1);
    }

    dest = fopen(argv[2], "w+t");
    if(dest==NULL){
       fprintf(stderr, "Erro ao abrir o arquivo de destino");
       exit(1);
    }

    do{
        c = fgets(linha, 36, src);
        
        novo = malloc(sizeof(nodo));

        if (novo == NULL)
        {
            puts("Erro na alocação de memória\n");
            exit(1);
        }
        else
        {
            l = strtok (linha," ");
        
            for(int i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    novo->produto = l;
                    // printf("Produto: %s\n", novo->produto);
                }
                if (i == 1)
                {
                    novo->locr = l;
                    // printf("Local de retirada: %s\n", novo->locr);
                    fprintf(dest, "%s   %s\tProduto: %s\tLocal de retirada: %s\n", _strdate(data), _strtime(hora), novo->produto, novo->locr);
                }
                if (i == 2)
                {
                    novo->loca = l;
                    // printf("Local de alocacao: %s\n", novo->loca);
                    fprintf(dest, "%s   %s\tProduto: %s\tLocal de alocacao: %s\n", _strdate(data), _strtime(hora), novo->produto, novo->loca);
                    fila.tamanho ++;
                }
                /*novo->elo = NULL;
                if (fila.frente == NULL)
                {
                    fila.frente = novo;
                }
                else
                    fila.re = novo; */
                // printf ("%s\n",l);   
                // fprintf(dest, "Linha: %s\n", l);
                l = strtok (NULL, " ");
            }  
        }
        if(c == NULL) break;
        // fprintf(dest, "Linha: %s\n", c);
    }
    while(1);

    // if (fila.frente == NULL)
    //     puts("\n***fila vazia");
    // else
    // {
    //     endereco = fila.frente;
    //     while(endereco != NULL)
    //     {
    //         fprintf(dest, "Produto: %s\tLocal de retirada: %s\n", endereco->produto, endereco->locr);//Quando a vari�vel � um endere�o n�o se usa "." , mas sim "->"
    //         fprintf(dest, "Produto: %s\tLocal de alocacao: %s\n", endereco->produto, endereco->loca);
    //         endereco = endereco->elo;
    //     }
    // }
    fclose(src);
    fclose(dest);
    free(novo);

    char opcao;
    puts("Exibir log? (S/N)");
    scanf("%c", &opcao);

    if (opcao == 'S' || opcao == 's')
    {
        system(argv[2]);
        exit(0);

    }
    if (opcao == 'N' || opcao == 'n')
        return 0;
}
