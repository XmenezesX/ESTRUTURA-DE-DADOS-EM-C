#include <stdio.h>
#include <stdlib.h>
#define max 100

typedef struct Pilha
{
    int vetor[max];
    int inicio, final;
}PILHA;

int empty(PILHA *pilha){
    return (pilha->final == pilha->inicio);
}

void criaPilha(PILHA *pilha){
    pilha->final = pilha->inicio = 0;
}

int full(PILHA *pilha){
    return (pilha->final == max);
}

void push(int valor, PILHA *pilha){
    if (full(pilha)){
        puts("Pilha cheia");
        return;
    }
    pilha->vetor[pilha->final] = valor;
    pilha->final++;
}

void pop(PILHA *pilha){
    if (empty(pilha))
    {
        puts("Pilha vazia");
        return;
    }
    pilha->final--;
    puts("Numero removido com Sucesso!");

}

void exibe(PILHA *pilha){
    if (empty(pilha))
    {
        puts("Digite o numero Decimal primeiro!");
        return;
    }
    puts("Numero Binario:");
    for (int i = pilha->final - 1; i >= 0; i--)
    {
        printf("%d", pilha->vetor[i]);
    }
    printf("\n");
}

PILHA* decimalToBinario(int decimal){
    PILHA *pilha = malloc(sizeof(PILHA));
    criaPilha(pilha);
    int resto, divisor=2;
    while (decimal > 0)
    {
        resto = decimal%divisor;
        decimal = decimal/divisor;
        push(resto, pilha);
    }
    exibe(pilha);
    return pilha;
}
