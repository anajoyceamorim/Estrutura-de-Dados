#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int *v; //vetor que contêm os elementos da pilha
    int N; //tamanho de v
    int topo; //indicador do topo

}pilha;

//protótipos
void instrucoes(void);

void empilha(pilha *, int);
int empilha02(pilha *, int);
int desempilha(pilha *, int *);

void imprime(pilha *);

int main(){
    int escolha, conteudo;
    pilha pilha;
    pilha.N = 10;
    pilha.topo = 0;
    pilha.v = (int *)malloc(pilha.N * sizeof(int));

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
            empilha(&pilha, conteudo);
            imprime(&pilha);
            break;
        
        case 2:
            printf( "Digite o elemto a ser adicionado na pilha: " );
            scanf( "%d", &conteudo );
            if(empilha02(&pilha, conteudo)) printf("Adicionado com sucesso!\n");
            else printf("falha ao empilhar.\n");
            imprime(&pilha);
            break;

        case 3:
            int elemento;
            printf( "desempilhando o último elemento adicionado.\n" );
            if(desempilha(&pilha ,&elemento)) printf("Elemento %d, desempilhado com sucesso.\n", elemento);
            else printf( "falha ao desempilhar" );
            imprime(&pilha);
            break;
        default:
            printf( "Escolha inválida.\n\n" );
            instrucoes();
            break;
        }

        printf( "? " );
        scanf( "%d", &escolha );
    }
    
    free(pilha.v);

    return 0;
}

void instrucoes (void){
    printf( " 0 para encerrar.\n" 
            " 1 para empilhar um novo elemento.\n"
            " 2 para empilhar verificando a possibilidade.\n"
            " 3 para desempilhar um elemento.\n" );
}

void empilha(pilha *p, int x){
    //verificando se a pilha está cheia
    if (p->topo == p->N){
        int dobraTAM = p->N * 2;
        int *novoVET = (int *)malloc(dobraTAM * sizeof(int));

        for (int i = 0; i < p->N; i++){
            novoVET[i] = p->v[i];
        }

        free(p->v);

        p->v = novoVET;
        p->N = dobraTAM;
    }

    //empilhando o elemento
    p->v[p->topo] = x;
    p->topo++;
}

int empilha02(pilha *p, int x)
{
    //verificando se a pilha está cheia
    if (p->topo == p->N){
        int dobraTAM = p->N * 2;
        int *novoVET = (int *)malloc(dobraTAM * sizeof(int));

        if (novoVET == 0) return 0;

        for (int i = 0; i < p->N; i++){
            novoVET[i] = p->v[i];
        }

        free(p->v);

        p->v = novoVET;
        p->N = dobraTAM;
    }

    //empilhando o elemento
    p->v[p->topo] = x;
    p->topo++;
    return 1;
}

int desempilha(pilha *p, int *y){
    //verificando se a pilha está vazia
    if (p->topo == 0){
        return 0;
    }

    p->topo--;
    *y = p->v[p->topo];
    return 1;
}

void imprime(pilha *p)
{
    if (p->topo == 0){
        printf("A pilha está vazia.\n");
        return;
    }

    for(int i = 0; i < p->topo; i++){
        printf("%d ->", p->v[i]);
    }
    printf("\n");
}