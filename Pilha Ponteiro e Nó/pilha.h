#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
    int novoValor;
    int tamanhoDaPilha;
    struct Stack *proximo;
}stack;

void tamanhoPilha(stack *pilha){
    printf("Tamanho da Pilha : %d\n", pilha->tamanhoDaPilha);
}

void criaPilha(stack *pilha)
{
    pilha->proximo = NULL;
    pilha->tamanhoDaPilha = 0;
}

void exibirTodosElementos(stack *pilha)
{
    if (empty(pilha))
    {
        puts("Pilha vazia!");
        return;
    }
    stack *atualPilha;
    atualPilha = pilha->proximo;
    puts("Pilha :");
    while (atualPilha != NULL)
    {
        printf("%d\n", atualPilha->novoValor);
        atualPilha = atualPilha->proximo;
    }
    
}

void liberarPilha(stack *pilha)
{
    stack *proximaPilha, *atualPilha;
    atualPilha = pilha->proximo;

    while (atualPilha != NULL)
    {
        proximaPilha = atualPilha->proximo;
        free(atualPilha);
        atualPilha = proximaPilha;
    }
}

stack *alocaNovoValor()
{
    stack *novo = (stack *) malloc(sizeof(stack));
    if (!novo)
    {
        puts("Erro de Alocacao!");;
        exit(1);
    }
    printf("Digite o novo elemento: ");
    scanf("%d", &novo->novoValor);
    return novo;
}

int empty(stack *pilha)
{
    if (pilha->proximo == NULL)
        return 1;
    else
        return 0;
};

void push(stack *pilha)
{
    stack *novo = alocaNovoValor();
    novo->proximo = NULL;
    if (empty(pilha))
        pilha->proximo = novo;
    else{
        stack *tmp = pilha->proximo;
        while (tmp->proximo != NULL)
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
    }
    pilha->tamanhoDaPilha++;
};

void pop(stack *pilha)
{
    if (pilha->proximo == NULL)
    {
        puts("A pilha esta vazia");
        return;
    }
    stack *ultimo = pilha->proximo;
    stack *penultimo = pilha;
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