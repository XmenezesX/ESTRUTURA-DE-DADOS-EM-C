#include <stdio.h>

void merge(int a[], int p, int q, int r){
    int n1 = q - p + 1;
    int n2 = r - q;
    // sejam L[n1+1] e R[n2+1] novos vetores
    int L[n1], R[n2];
    int i,j,k;
    for ( i = 0; i < n1; i++)
    {
        L[i] = a[p+i-1];
    }
    for ( j = 0; j < n2; j++)
    {
        R[j] = a[q+j];
    }
    L[n1] = -2;//até o final do vetor
    R[n2]= -2; // até o final do vetor
    i = 0;
    j = 0;
    for ( k = p; k <= r; k++)
    {
        if (L[i]<=R[j])
        {
            a[k] = L[i];
            i = i+1;
        }
        else
        {
            a[k] = R[j];
            j = j+1;
        }
    }
    
    
}
//a = vetor
//p = posição inicial
// r = posição final
// q = metade
void merge_sorte(int a[], int p, int r){
    int q;
    if (p<r)
    {
        q = (p+r)/2;
        merge_sorte(a,p,q);
        merge_sorte(a,q+1,r);
        merge(a,p,q,r);
    } 
}

int main(){
    int n, i;
    puts("Digite o tamanho do vetor:");
    scanf("%d", &n);
    int vet[n];
    int aux = n;
    for ( i = 0; i < n; i++)
    {
        vet[i] = aux;
        aux--;
    }
    for ( i = 0; i < n; i++)
    {
        printf("VET[%d] = %d ",i,vet[i]);
    }
    puts(".");
    merge_sorte(vet, 0, n);
    for ( i = 0; i < n; i++)
    {
        printf("VET[%d] = %d ",i,vet[i]);
    }
    
}