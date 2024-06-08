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

int menu(){
    int opcao;
    puts("1 - Adicionar Elemento");
    puts("2 - Listar Lista");
    puts("3 - Tamanho da Lista");
    puts("4 - Remover");
    puts("5 - Rotacionar Lista ->");
    puts("0 - Sair");
    printf("Digite a opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(){
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
        
        default:
            break;
        }
        opcao = menu();
    }
}
