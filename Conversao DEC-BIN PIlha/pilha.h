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

int criaPilha(PILHA *pilha){
    pilha = (PILHA*)malloc(sizeof(PILHA));
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
    puts("Numero inserido com Sucesso!");
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
    puts("Pilha:");
    for (int i = pilha->final - 1; i > -1; i--)
    {
        printf("%d\n", pilha[i]);
    }
}

PILHA* decimalToBinario(int decimal){
    PILHA *pilha;
    criaPilha(pilha);
    int resto, quociente, divisor=2;
    while (decimal !=0)
    {
        decimal = decimal/divisor;
        resto = decimal%divisor;
        printf("resto: %d \n", resto);
        push(resto, pilha);
    }
    
}

