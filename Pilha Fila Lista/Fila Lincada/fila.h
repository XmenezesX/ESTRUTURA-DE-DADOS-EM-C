#include <stdio.h>
#include <stdlib.h>

typedef struct Fila
{
    int numero;
    int tamanhoDaFila;
    struct Fila *proximo;
}Fila;

void tamanhoFila(Fila *fila){
    printf("Tamanho da Fila : %d\n", fila->tamanhoDaFila);
}

void criaFila(Fila *fila)
{
    fila->proximo = NULL;
    fila->tamanhoDaFila = 0;
}

Fila *alocaNovoValor()
{
    Fila *novo = (Fila *) malloc(sizeof(Fila));
    if (!novo)
    {
        puts("Erro de Alocacao!");
        exit(1);
    }
    printf("Digite o novo elemento: ");
    scanf("%d", &novo->numero);
    return novo;
}

int empty(Fila *fila)
{
    if (fila->proximo == NULL)
        return 1;
    else
        return 0;
};

void exibirTodosElementos(Fila *fila)
{
    if (empty(fila))
    {
        puts("Filha vazia!");
        return;
    }
    Fila *atualFila;
    atualFila = fila->proximo;
    puts("Fila:");
    while (atualFila != NULL)
    {
        printf("%d ", atualFila->numero);
        atualFila = atualFila->proximo;
    }
}

void liberarFila(Fila *fila)
{
    Fila *proximaFila, *atualFila;
    atualFila = fila->proximo;

    while (atualFila != NULL)
    {
        proximaFila = atualFila->proximo;
        free(atualFila);
        atualFila = proximaFila;
    }
}

void push(Fila *fila)
{
    Fila *novo = alocaNovoValor();
    novo->proximo = NULL;
    if (empty(fila))
        fila->proximo = novo;
    else{
        Fila *tmp = fila->proximo;
        while (tmp->proximo != NULL)
        {
            tmp = tmp->proximo;
        }
        tmp->proximo = novo;
    }
    fila->tamanhoDaFila++;
};

void pop(Fila **fila)
{
    if ((*fila)->proximo == NULL)
    {
        puts("A fila esta vazia");
        return;
    }
    Fila *tmp = (*fila)->proximo;
    (*fila)->proximo = tmp->proximo;
    free(tmp);
    puts("Primeiro elemento removido!");
    return;
}