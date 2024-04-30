#include <stdio.h>
#include <stdlib.h>
#define max 10

int pilhaIncial[max];
int pilhaAuxiliar[max];
int pilhaFinal[max];
int inicio, final;

int empty(){
    return (final == inicio);
}

int full(){
    return (final == max);
}

void push(int valor){
    if (full()){
        puts("Pilha cheia");
        return;
    }
    pilhaIncial[final] = valor;
    final++;
    puts("Numero inserido com Sucesso!");
}

void pop(){
    if (empty())
    {
        puts("Pilha vazia");
        return;
    }
    final--;
    puts("Numero removido com Sucesso!");

}

void exibe(){
    if (empty())
    {
        puts("Pilha Vazia");
        return;
    }
    puts("Pilha:");
    for (int i = final - 1; i > -1; i--)
    {
        printf("%d\n", pilhaIncial[i]);
    }
}

