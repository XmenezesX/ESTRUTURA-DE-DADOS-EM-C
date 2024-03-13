#include <stdio.h>
#include <stdlib.h>

void merge(int vet[], int p, int q, int r){
    int i,j,k,*w;
    w = malloc((r-p) * sizeof(int));
    i = p;
    j = q;
    k = 0;
    while (i < q && j < r)
    {
        if (vet[i] <= vet[j])
        {
            w[k++] = vet[i++];
        }
        else
        {
            w[k++] = vet[j++];
        }
    }
    while (i < q)
        w[k++] = vet[i++];

    while (j < r)
        w[k++] = vet[j++];
    
    for(i = p; i < r; i++)
        vet[i] = w[i-p];
    
    free(w);
    
}
//a = vetor
//p = posição inicial
// r = posição final
// q = metade
void merge_sorte(int vet[], int p, int r){
    int q;
    if (p<r-1)
    {
        q = (p+r)/2;
        merge_sorte(vet,p,q);
        merge_sorte(vet,q,r);
        merge(vet,p,q,r);
    } 
}

int main(){
    int n, i;
    puts("Digite o tamanho do vetor:");
    scanf("%d", &n);
    int *vet= malloc(n * sizeof(int));
    int aux = 0;
    for ( i = 0; i < n; i++)
    {
        vet[i] = aux;
        aux++;
    }
    puts(".");
    merge_sorte(vet, 0, n);
    puts("Acabou");
    
}