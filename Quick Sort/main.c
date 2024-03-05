#include <stdio.h>
#define max 10
int vet[max];
int partition(int vetor[], int posicaoInicial, int posicaoFinal){
    int ultimoElemento, i , j, auxiliar;
    
    ultimoElemento = vetor[posicaoFinal - 1];
    i = posicaoInicial - 1;
    
    for ( j = posicaoInicial; j < posicaoFinal; j++)
    {
        if (vetor[j] <= ultimoElemento)
        {
            i = i + 1;
            auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
        }
    }
    
    auxiliar = vetor[i + 1];
    vetor[i + 1] = vetor[posicaoFinal-1];
    vetor[posicaoFinal - 1] = auxiliar;

    
    return i + 1;
}

void quickSort(int vetor[], int posicaoInicial, int posicaoFinal){
    int metadeVetor;

    if (posicaoInicial < posicaoFinal)
    {
        
        metadeVetor = partition(vetor, posicaoInicial, posicaoFinal);
        quickSort(vetor, posicaoInicial , metadeVetor - 1);
        quickSort(vetor, metadeVetor + 1 ,posicaoFinal);
    } 
}

int main(){
    int tamanhoVetor, i;
    tamanhoVetor = max;
    int aux = tamanhoVetor;

    for ( i = 0; i < tamanhoVetor; i++)
    {
        vet[i] = aux;
        aux--;
    }
    
    quickSort(vet, 0, tamanhoVetor);

    for ( i = 0; i < tamanhoVetor; i++)
    {
        printf("VET[%d] = %d ",i,vet[i]);
    }
    puts("Acabou");
}