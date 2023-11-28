#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *v; //vetor que representa a fila
    int N; //tamanho da fila
    int inicio, fim; //indicador de início e final da fila

}fila;

//protótipos
void instrucoes(void);

int enfileira(fila*, int);
int desenfileira(fila *, int *);

void imprime(fila *);

int main ()
{
    int escolha, conteudo;
    fila fila;
    fila.N = 10;
    fila.inicio = 0;
    fila.fim = 0;
    fila.v = (int *)malloc(fila.N * sizeof(int));

    instrucoes();
    printf( "? " );
    scanf("%d", &escolha);

    while (escolha != 0)
    {
        switch (escolha)
        {
        case 1:
            printf( "Digite o elemento a ser adicionado na fila: " );
            scanf( "%d", &conteudo );
            if(enfileira(&fila, conteudo)) printf("Adicionado com sucesso!\n");
            else printf("falha ao enfileirar.\n");
            imprime(&fila);
            break;

        case 2:
            int elemento;
            printf( "desenfileirando o 1° elemento adicionado.\n" );
            if(desenfileira(&fila ,&elemento)) printf("Elemento %d, desenfileirado com sucesso.\n", elemento);
            else printf( "falha ao desenfileirar" );
            imprime(&fila);
            break;

        default:
            printf( "Escolha inválida.\n\n" );
            instrucoes();
            break;
        }

        printf( "? " );
        scanf( "%d", &escolha );
    }
    
    free(fila.v);

    return 0;
}

void instrucoes(void)
{
    printf( " 0 para encerrar.\n" 
            " 1 para enfileirar um elemento.\n"
            " 2 para desenfileirar um elemento.\n");
}

int enfileira(fila *f, int x)
{
    if ((f->fim + 1) % f->N == f->inicio){
        return 0;
    }

    f->v[f->fim] = x;
    f->fim = (f->fim + 1) % f->N;
    return 1;
}

int desenfileira (fila *f, int *y)
{
    if (f->inicio == f->fim){
        return 0;
    }

    *y = f->v[f->inicio];
    f->inicio = (f->inicio + 1) % f->N;
    return 1;
}

void imprime(fila *f)
{
    int i = f->inicio;
    while (i != f->fim){
        printf("%d ->", f->v[i]);
        i = (i + 1) % f->N;
    }
    printf("\n");
}