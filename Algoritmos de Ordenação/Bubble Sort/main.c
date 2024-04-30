#include <stdio.h>

void bubbleSort(int *vet, int tamanhoVetor){
    int i,j, aux;
    for ( i = 0; i < tamanhoVetor; i++)
    {
        for ( j = i + 1; j < tamanhoVetor; j++)
        {
            if (vet[i]>vet[j])
            {
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

int main(){
    int tamanhoVetor, i, aux;
    aux = tamanhoVetor = 100000;
    int vet[tamanhoVetor];
    for (i = 0; i < tamanhoVetor; i++)
    {
        vet[i] = aux;
        aux--; 
    }
    
    bubbleSort(vet, tamanhoVetor);
    puts("acabou");
}