#include "lista.h"

int menu(){
    int opcao;
    puts("1 - Adicionar Elemento");
    puts("2 - Listar Lista");
    puts("3 - Tamanho da Lista");
    puts("4 - Remover");
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
        
        default:
            break;
        }
        opcao = menu();
    }
}