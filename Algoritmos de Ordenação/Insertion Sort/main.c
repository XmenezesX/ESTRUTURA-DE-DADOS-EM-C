#include <stdio.h>
#include <stdlib.h>
#define max 100000000
int vet[max];

void insertionSort(int *vet, int n){
    int i,j, chave;
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
    
}

int main(){
    int i, n;
    n = 100000000;
    int aux;
    aux = 0;  //ordena de forma crescente
    //aux = n;  //ordena de forma decrescente
    for ( i = 0; i < n; i++)
    {
       vet[i] = aux;
       
       //ordena de forma decrescente
       //aux = aux - 1;

       //ordena de forma crescente
       aux = aux + 1;
    }

    insertionSort(vet, n);
    printf("Acabou\n");
}