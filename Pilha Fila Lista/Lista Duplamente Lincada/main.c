#include "lista.h"

int menu(){
    int opcao;
    puts("1 - Adicionar Elemento Inicio");
    puts("2 - Adicionar Elemento Fim");
    puts("3 - Listar Lista");
    puts("4 - Tamanho da Lista");
    puts("5 - Remover Inicio");
    puts("6 - Remover Fim");
    puts("7 - Remover Posicao");
    puts("8 - Buscar Numero");
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
            push_inicio(lista);
            break;

        case 2:
            push_fim(lista);
            break;
        
        case 3:
            imprimirLista(lista);
            break;
        
        case 4:
            tamanhoLista(lista);
            break;

        case 5:
            pop_inicio(lista);
            break;

        case 6:
            pop_fim(lista);
            break;
        
        case 7:
            pop_posicao(lista);
            break;

        case 8:
            buscaNumero(lista);
            break;
        
        default:
            break;
        }
        opcao = menu();
    }
    
}