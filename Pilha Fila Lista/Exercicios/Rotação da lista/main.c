#include "lista.h"

void rotacionarLista(list *lista){
    list *penultimoNo = lista->No, *primeiro = lista->No, *ultimoNo;
    while (penultimoNo->No->No !=NULL)
    {
        penultimoNo = penultimoNo->No;
    }
    ultimoNo = penultimoNo->No;

    // No do ultimo recebendo o primeiro elemento da lista;
    ultimoNo->No = lista->No;

    //Ultimo sendo colocado na primeira posição
    lista->No = ultimoNo;

    //Faz com que o penultimo seja o ultimo
    penultimoNo->No = NULL;
}

int verificaListaPalindromica(list *lista){
    int array[lista->tamanhoLista];
    int tamanhoLista = lista->tamanhoLista;
    list *temp = lista->No;
    for (int i = 0; i < lista->tamanhoLista && lista != NULL; i++)
    {
        array[i] = temp->valor;
        temp = temp->No;
    }
    
    for (int i = 0; i < tamanhoLista/2; i++)
    {
        if (array[i] != array[tamanhoLista - i - 1])
            return 0;
    }
    return 1;
}
int menu(){
    int opcao;
    puts("1 - Adicionar Elemento");
    puts("2 - Listar Lista");
    puts("3 - Tamanho da Lista");
    puts("4 - Remover");
    puts("5 - Rotacionar Lista ->");
    puts("6 - E palindrona?");
    puts("0 - Sair");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
    int bool;
    int opcao = menu();
    list *lista = (list *)malloc(sizeof(list));
    if (lista == NULL)
    {
        puts("Erro de alocação");
        exit(1);
    }
    iniciaLista(lista);
    while (opcao != 0)
    {
        switch (opcao)
        {
        case 1:
            push(lista);
            break;
        
        case 2:
            imprimirLista(lista);
            break;
        
        case 3:
            tamanhoLista(lista);
            break;
        
        case 4:
            pop(lista);
            break;
        
        case 5:
            rotacionarLista(lista);
            break;

        case 6:
            bool = verificaListaPalindromica(lista);
            if (bool)
            {
                puts("A Lista e palindrona!\n");
            }
            else
            {
                puts("A Lista nao e palindrona!\n");
            }
            
            break;
        
        default:
            break;
        }
        opcao = menu();
    }
}
