#include <stdio.h>
#include <stdlib.h>
#define max 10

int fila[max];
int inicio, final;

int empty(){
    return (final == inicio);
}

int full(){
    return (final == max);
}

void push(int valor){
    if (full()){
        puts("Fila cheia");
        return;
    }
    fila[final] = valor;
    final++;
    puts("Numero inserido com Sucesso!");
}

void pop(){
    if (empty())
    {
        puts("Fila vazia");
        return;
    }
    if (final > 1)
    {
        for (int i = 0; i < final; i++)
        {
            fila[i] = fila[i + 1];
        }
    }
    final--;
    
    puts("Numero removido com Sucesso!");

}

void exibe(){
    if (empty())
    {
        puts("Fila Vazia");
        return;
    }
    puts("Fila:");
    for (int i = 0; i < final; i++)
    {
        printf("%d ", fila[i]);
    }
    puts(" ");
}

