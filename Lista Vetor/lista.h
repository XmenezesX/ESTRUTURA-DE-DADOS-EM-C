#include <stdio.h>
#include <stdlib.h>
#define max 10

int lista[max], verificaPosicao[max] =  {0};
int inicio, final;

int empty(){
    return (final == inicio);
}

int full(){
    return (final == max);
}

void insertionSort(int *vet, int n){
    int i,j, chave;
    if (empty())
    {
        puts("Lista vazia!");
    }
    
    for ( j = 1; j < n; j++)
    {
        chave = vet[j];
        i = j - 1;
        while (i >= 0 && vet[i]>chave)
        {
            vet[i+1] = vet[i];
            i = i - 1;
        }
        vet[i + 1] = chave;
    }
    puts("Vetor Ordenado com Sucesso!");
}

int busca(int posicao){
    if (final<=posicao)
    {
        puts("Quantidade de elementos inferior a posicao desejada\n");
        return 0;
    }
    return lista[posicao-1];
}

void push(int posicao){
    int novoNumero;
    if (full()){
        puts("Lista cheia\n");
        return;
    }
    if (final < posicao - 1)
    {
        puts("Quantidade de elementos inferior a posicao desejada\n");
        return;
    }
    puts("Digite o numero para inserir:");
    scanf("%d", &novoNumero);
    if (!verificaPosicao[posicao])
    {
        for (int i = final; i > posicao - 1; i--)
        {
            lista[i] = lista[i - 1];
        }
    }
    
    lista[posicao - 1] = novoNumero;
    verificaPosicao[posicao - 1] = 1;
    final++;
    puts("Numero inserido com Sucesso!\n");
}

void pop(int posicao){
    if (empty())
    {
        puts("Lista vazia\n");
        return;
    }
    
    if (final < posicao - 1)
    {
        puts("Quantidade de elementos inferior a posicao desejada\n");
        return;
    }
    
    for (int i = posicao - 1; i < final; i++)
    {
        lista[i] = lista[i + 1];
    }
    final--;
    
    puts("Numero removido com Sucesso!");

}

void exibe(){
    if (empty())
    {
        puts("Lista Vazia");
        return;
    }
    puts("Lista:");
    for (int i = 0; i < final; i++)
    {
        printf("%d ", lista[i]);
    }
    puts(" ");
}

