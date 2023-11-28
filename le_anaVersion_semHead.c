#include <stdio.h>
#include <stdlib.h>

/*Arrumar possíveis erros dos usuários e postar no git hub*/

//tipo node
typedef struct celula
{
    int dado;
    struct celula *prox;
}celula;

//protótipos
void instrucoes(void);

celula *criar_no(int);

void insere_inicio(celula *, int);
void insere_antes(celula *, int, int);

void imprime(celula *);
void imprime_rec(celula *);

celula *busca(celula *, int);
celula *busca_rec(celula *, int);

int remove_depois(celula *);
void remove_elemento(celula *, int);
void remove_todos_elementos(celula *, int);

int main()
{
    int escolha, conteudo, antes_de_mim, retorno;
    celula *achei;

    celula *le = criar_no(0);
    celula *aux = le;

    instrucoes();
    printf( "? " );
    scanf( "%d", &escolha );

    while ( escolha != 0 ){
        switch ( escolha ){
        case 1:
            printf( "Digite um número para ser inserido ao final da lista: ");
            scanf( "%d", &conteudo );
            aux->prox = criar_no(conteudo);
            aux = aux->prox;
            imprime(le);
            break;
        
        case 2:
            printf( "Digite um número a ser inserido no ínicio: ");
            scanf( "%d", &conteudo );
            insere_inicio(le, conteudo);
            imprime(le);
            break;

        case 3:
            printf( "Digite um número que você deseja inserir antes: " );
            scanf( "%d", &conteudo);
            printf( "Deseja inserir antes de qual número: " );
            scanf( "%d", &antes_de_mim );
            insere_antes(le, conteudo, antes_de_mim);
            imprime(le);
            break;

        case 4:
            printf( "Imprimindo a lista de forma recursiva\n\n ");
            imprime_rec(le);
            break;

        case 5:
            printf( "Digite o elemento a ser procurado: " );
            scanf( "%d", &conteudo );
            achei = busca(le, conteudo);
            printf("%d pertence a lista", achei->dado);
            break;
        
        case 6:
            printf( "Digite o elemento a ser procurado recursivamente: ");
            scanf( "%d", &conteudo );
            achei = busca_rec(le->prox, conteudo);
            printf("%d pertence a lista", achei->dado);
            break;

        case 7:
            printf( "Digite o elemento anterior ao desejado, para ser excluido: " );
            scanf( "%d", &conteudo );
            achei = busca_rec(le->prox, conteudo);
            retorno = remove_depois(achei);
            if(retorno){
                printf( "elemento removido com sucesso!" );
                imprime(le);
            }else{
                printf( "falha no procedimento, elemento não encontrado." );
                imprime(le);
            }
            break;

        case 8:
            printf( "Digite o elemento que você deseja remover sua 1ª incidência: " );
            scanf( "%d", &conteudo );
            remove_elemento(le, conteudo);
            imprime(le);
            break;

        case 9:
            printf( "Digite o elemento que você deseja remover todas as suas incidência: " );
            scanf( "%d", &conteudo );
            remove_todos_elementos(le, conteudo);
            imprime(le);
            break;

        default:
            printf( "Escolha inválida.\n\n" );
            instrucoes();
            break;
        }

        printf( "\n? " );
        scanf( "%d", &escolha );
    }

    return 0;
}

void instrucoes( void )
{
    printf( "Digite sua escolha:\n"
            " 0 para encerrar.\n"
            " 1 para inserir um elemento ao final da lista.\n"
            " 2 para inserir um elemento no ínicio da lista.\n"
            " 3 para inserir um número antes de outro da lista.\n"
            " 4 para imprimir a lista recursivamente.\n"
            " 5 para buscar um elemento.\n"
            " 6 para buscar um elemento recursivamente.\n"
            " 7 para remover o elemento seguinte ao ponteiro.\n"
            " 8 para remover a primeira incidência de um elemento.\n"
            " 9 para remover todas as incidência de um elemento na lista.\n");
}

celula *criar_no(int x)
{
    celula *no = malloc(sizeof(celula));
    no->prox = NULL;
    no->dado = x;

    return no;
}

void insere_inicio(celula *le, int x)
{
    celula *aux = (celula *)malloc(sizeof(celula));
    aux->dado = x;
    aux->prox = le->prox;
    le->prox = aux;
}

void insere_antes(celula *le, int x, int y)
{
    celula *aux = (celula *)malloc(sizeof(celula));
    celula *atual = le->prox;
    celula *anterior = le;

    while (atual != NULL && atual->dado != y){
        anterior = atual;
        atual = atual->prox;
    }

    aux->dado = x;
    aux->prox = atual;

    anterior->prox = aux;
}

void imprime(celula *le)
{
    celula *aux = le->prox;

    if( aux == NULL ){
        printf("NULL\n\n");
        return;
    }

    while ( aux != NULL ){
        printf("%3d", aux->dado);
        if (aux->prox != NULL){
            printf(" -> ");
        } else {
            printf(" -> NULL\n");
        }
        aux = aux->prox;
    }
}
void imprime_rec(celula *le)
{
    celula *aux = le->prox;
    if( aux == NULL ){
        printf(" NULL\n");
        return;
    }
    printf("%3d", aux->dado);
    if (aux->prox != NULL){
        printf(" -> ");
    }else{
        printf(" -> NULL\n");
        return;
    }

    imprime_rec(aux);
}

celula *busca (celula *le, int x)
{
    celula *aux = le->prox;
    while ( aux != NULL ){
        if (aux->dado == x) return aux;

    aux = aux->prox;
    }
    return NULL;
}

celula *busca_rec (celula *le, int x)
{
    if(le == NULL)return NULL;    
    if(le->dado == x)return le;
    return busca_rec(le->prox, x);
}

int remove_depois (celula *p)
{
    if(p == NULL || p->prox == NULL){
        return 0;
    }

    celula *temp = p->prox;
    p->prox = p->prox->prox;
    free(temp);
    return 1;
}

void remove_elemento (celula *le, int x)
{
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL)
    {
        if (atual->dado == x){
            anterior->prox = atual->prox;
            free(atual);
            return;
        }
        anterior = atual;
        atual = atual->prox;
    }
}

void remove_todos_elementos (celula *le, int x)
{
    celula *anterior = le;
    celula *atual = le->prox;

    while (atual != NULL){
        if (atual->dado == x){
            anterior->prox = atual->prox;
            free(atual);
            atual = anterior->prox;
        }else{
            anterior = atual;
            atual = atual->prox;
        }
    }
}