#include <stdio.h>
#include <stdlib.h>

typedef struct celula{
    int dado;
    struct celula *prox;
}celula;

//protótipos
void instrucoes(void);

celula *criar_no(int);

void empilha(celula *, int);
int desempilha(celula *, int *);

void imprime(celula *);

int main(){
    int escolha, conteudo;
   
    celula *p = criar_no(0);
    celula *aux = p;

    instrucoes();
    printf( "? " );
    scanf("%d", &escolha);

    while (escolha != 0)
    {
        switch (escolha)
        {
        case 1:
            printf( "Digite o elemento a ser adicionado na pilha: " );
            scanf( "%d", &conteudo );
            empilha(p, conteudo);
            imprime(p);
            break;
        
        case 2:
            int elemento;
            printf( "desempilhando o último elemento adicionado.\n" );
            if(desempilha(p ,&elemento)) printf("Elemento %d, desempilhado com sucesso.\n", elemento);
            else printf( "falha ao desempilhar" );
            imprime(p);
            break;
        default:
            printf( "Escolha inválida.\n\n" );
            instrucoes();
            break;
        }

        printf( "? " );
        scanf( "%d", &escolha );
    }

    return 0;
}

void instrucoes (void){
    printf( " 0 para encerrar.\n" 
            " 1 para empilhar um novo elemento.\n"
            " 2 para desempilhar um elemento.\n" );
}

celula *criar_no(int x)
{
    celula *no = malloc(sizeof(celula));
    no->prox = NULL;
    no->dado = x;
}

void empilha(celula *p, int x)
{
    celula *aux = (celula *)malloc(sizeof(celula));
    aux->dado = x;
    aux->prox = p->prox;
    p->prox = aux;
}

int desempilha(celula *p, int *y){
    //verificando se a pilha está vazia
    if (p->prox == 0){
        return 0;
    }

    celula *aux = p->prox;
    *y = aux->dado;
    p->prox = aux->prox;
    free(aux);
    return 1;
}

void imprime(celula *p)
{
   celula *aux = p->prox;

   if( aux == NULL ){
    printf("NULL\n\n");
    return;
   }

   while ( aux != NULL ){
    printf("%3d", aux->dado);
    if (aux->prox != NULL) printf(" -> ");
    else printf(" -> NULL\n");

    aux = aux->prox;
   }
}