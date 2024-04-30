#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int novoValor;
    int tamanhoDaPilha;
    struct Fila *proximo;
}Fila;

void tamanhoPilha(Fila *pilha){
    printf("Tamanho da Pilha : %d\n", pilha->tamanhoDaPilha);
}

void criaPilha(Fila *pilha)
{
    pilha->proximo = NULL;
    pilha->tamanhoDaPilha = 0;
}

void exibirTodosElementos(Fila *pilha)
{
    if (empty(pilha))
    {
        puts("Pilha vazia!");
        return;
    }
    Fila *atualPilha;
    atualPilha = pilha->proximo;
    puts("Pilha :");
    while (atualPilha != NULL)
    {
        printf("%d\n", atualPilha->novoValor);
        atualPilha = atualPilha->proximo;
    }
    
}

void liberarPilha(Fila *pilha)
{
    Fila *proximaPilha, *atualPilha;
    atualPilha = pilha->proximo;

    while (atualPilha != NULL)
    {
        proximaPilha = atualPilha->proximo;
        free(atualPilha);
        atualPilha = proximaPilha;
    }
}

Fila *alocaNovoValor()
{
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    if (!novo)
    {
        puts("Erro de Alocacao!");;
        exit(1);
    }
    printf("Digite o novo elemento: ");
    scanf("%d", &novo->novoValor);
    return novo;
}

int empty(Fila *pilha)
{
    if (pilha->proximo == NULL)
        return 1;
    else
        return 0;
};

void push(Fila *pilha)
{
    Fila *novo = alocaNovoValor();
    novo->proximo = NULL;
    if (empty(pilha))
        pilha->proximo = novo;
    else{
        Fila *tmp = pilha->proximo;
        while (tmp->proximo != NULL)
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
    }
    pilha->tamanhoDaPilha++;
};

void pop(Fila *pilha)
{
    if (pilha->proximo == NULL)
    {
        puts("A pilha esta vazia");
        return;
    }
    Fila *ultimo = pilha->proximo;
    Fila *penultimo = pilha;
    while (ultimo->proximo !=NULL)
    {
        penultimo = ultimo;
        ultimo = ultimo->proximo;
    }
    free(ultimo);
    penultimo->proximo = NULL;
    pilha->tamanhoDaPilha--;
    puts("Ultimo elemento removido!");
    return;
};