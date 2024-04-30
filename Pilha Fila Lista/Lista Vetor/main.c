#include "lista.h"

int menu(){
    int opcao;
    puts("----- Menu Lista -----");
    puts("1 - Inserir na posicao");
    puts("2 - Retirar na posicao");
    puts("3 - Ordenar");
    puts("4 - Listar");
    puts("5 - Buscar na posicao");
    puts("0 - Sair");
    puts("----------------------");
    puts("Digite sua opcao:");
    scanf("%d", &opcao);
    return opcao;
}

void menuOpcoes(int opcao){
    int posicao, numeroBuscado;
    switch(opcao){
        case 0:
            return;
            break;

        case 1:
            puts("Digite a posicao para inserir na lista:[1 - 10]");
            scanf("%d", &posicao);
            push( posicao);
            break;

        case 2:
            puts("Digite a posicao para retirar na lista:[1 - 10]");
            scanf("%d", &posicao);
            pop(posicao);
            break;

        case 3:
            insertionSort(lista, final);
            break;

        case 4:
            exibe();
            break;
        
        case 5:
            puts("Digite a posicao para buscar na lista:[1 - 10]");
            scanf("%d", &posicao);
            numeroBuscado = busca(posicao);
            if (numeroBuscado != 0)
            {
                printf("Esse e o valor buscado: %d\n", numeroBuscado);
            }
            break;

        default:
            printf("Comando invalido\n\n");
            break;
    }
}

int main(){
    int opcao;
    inicio = final = 0;

    do{
        opcao = menu();
        menuOpcoes(opcao);
    }while (opcao);

    puts("Programa Encerrado");
    return 0;
}