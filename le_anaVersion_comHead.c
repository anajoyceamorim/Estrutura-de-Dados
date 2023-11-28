#include <stdio.h>
#include <stdlib.h>

//tipo node
typedef struct celula
{
    int dado;
    struct celula *prox;
}celula;

//tipo cabeça
typedef struct cabeca
{
    int num_itens;
    celula *prox;
    celula *ultimo;
}head;

//protótipos
void instrucoes(void);

head *criar_lista();
celula *criar_no(int);

int vazia(head *);
int tamanho_lista(head *);

void insere_inicio(head *, celula *);

void imprime(head *);
void imprime_rec(head *);

int main()
{
    int escolha, conteudo;

    head *le = criar_lista();
    
    instrucoes();
    printf( "? " );
    scanf( "%d", &escolha );

    while ( escolha != 0 ){
        switch ( escolha ){
        case 1:
            printf( "Digite um número a ser inserido: ");
            scanf( "\n%d", &conteudo );
                celula *novo = criar_no(conteudo);
                insere_inicio(le, novo);
                imprime(le);
            break;
        case 2:
            printf( "Imprimir a lista de forma recursiva ");
            imprime_rec(le);
            break;
        default:
            printf( "Escolha inválida.\n\n" );
            instrucoes();
            break;
        }

        printf( "?" );
        scanf( "%d", &escolha );
    }
    

    return 0;
}

void instrucoes( void )
{
    printf( "Digite sua escolha:\n"
            " 0 para encerrar.\n"
            " 1 para inserir um elemento na lista.\n");
}

head *criar_lista()
{
    head *le = malloc(sizeof(head));
    le->num_itens = 0;
    le->prox = NULL;
    le->ultimo = NULL;

    return le;
}

celula *criar_no(int x)
{
    celula *no = malloc(sizeof(celula));
    no->prox = NULL;
    no->dado = x;

    return no;
}

int vazia( head *p )
{
    return ( p->prox == NULL ); //retorna 1 se a lista estiver vazia, 0 se estiver cheia
}

int tamanho_lista(head *le)
{
    //para listas com cabeça
    return le->num_itens;

    //para listas sem cabeça
    /*
        int tam = 0;
        celula *aux = busca_inicio(le); //precisa da função busca_inicio
        while( aux != NULL && aux->prox != NULL ){
            aux = aux->prox;
            tam++;
        }
        return tam;
    */
}

void insere_inicio(head *le, celula *novo)
{
    //lista com cabeça
    if(vazia(le)) le->ultimo = novo;
    le->num_itens++;

    novo->prox = le->prox;
    le->prox = novo;
}

void imprime(head *le)
{
    if ( le == NULL ){
        printf( "Lista está vazia.\n\n" );
    }else{
        celula *atual;
        printf( "A lista é:\n" );
        for( atual = le->prox; atual != NULL; atual = atual->prox )
        printf ( "%3d ->", atual->dado );

        printf( " NULL\n\n" );
    }
}
