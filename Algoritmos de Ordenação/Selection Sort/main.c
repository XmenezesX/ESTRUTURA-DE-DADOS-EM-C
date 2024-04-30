#include <stdio.h>

void selectionSort(int *vet, int tamanhoVetor){
    int i, j, minimo, auxiliar;
    for ( i = 0; i < tamanhoVetor; i++)
    {
        minimo = i;
        for ( j = i + 1; j < tamanhoVetor; j++)
        {
            if (vet[j] < vet[minimo])
            {
                minimo = j;
            }
            
        }
        if (i != minimo)
        {
            auxiliar = vet[i];
            vet[i] = vet[minimo];
            vet[minimo] = auxiliar;
        } 
    }
}

int main(){
    int tamanhoVetor, i, aux;
    aux = tamanhoVetor = 20;
    int vet[tamanhoVetor];
    for (i = 0; i < tamanhoVetor; i++)
    {
        vet[i] = aux;
        aux--; 
    }
    
    selectionSort(vet, tamanhoVetor);
    for ( i = 0; i < tamanhoVetor; i++)
    {
        printf("%d ", vet[i]);
    }
    
    puts("acabou");
}