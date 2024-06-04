#include <stdlib.h>
#include <stdio.h>

typedef struct Lista
{
    int valor;
    int tamanhoLista;
    struct Lista *proximoNo;
    struct Lista *noAnterior;
}list;

void tamanhoLista(list *lista){
    printf("Tamanho da Lista : %d\n\n", lista->tamanhoLista);
}

void iniciaLista(list *lista){
    lista->proximoNo = NULL;
    lista->tamanhoLista = 0;
}

list* alocaNovoValor(){
    list *novo = (list *) malloc(sizeof(list));
    if(!novo){
        puts("Erro de alocacao!");
        exit(1);
    }
    novo->proximoNo = NULL;
    puts("Digite um novo valor para lista:");
    scanf("%d", &novo->valor);
    return novo;
}

int empty(list *lista){
    if (lista->tamanhoLista == 0)
        return 1;
    else
        return 0;
}

void imprimirLista(list *lista){
    if (empty(lista)){
        puts("Lista vazia\n");
        return;
    }
    
    list *auxiliar = lista->proximoNo;
    while (auxiliar != NULL)
    {
        printf("%d ", auxiliar->valor);
        auxiliar = auxiliar->proximoNo;
    }
    puts("\n");
}

void push_fim(list *lista){
    list *novo = alocaNovoValor();
    if (empty(lista))
    {
        lista->proximoNo = novo;
        lista->noAnterior = NULL;
    }
    else
    {
        list *temp = lista->proximoNo;
        while (temp->proximoNo !=NULL)
        {
            temp = temp->proximoNo;
        }
        novo->noAnterior = temp;
        temp->proximoNo = novo;
    }
    lista->tamanhoLista++;
    puts("Elemento adicionado com sucesso!\n");
}

void push_inicio(list *lista){
    list *novo = alocaNovoValor();
    if (empty(lista))
    {
        lista->proximoNo = novo;
        lista->noAnterior = NULL;
    }
    else
    {
        novo->proximoNo = lista->proximoNo;
        novo->noAnterior = NULL;
        lista->proximoNo = novo;
    }
    lista->tamanhoLista++;
    puts("Elemento adicionado com sucesso!\n");
}

void pop_posicao(list *lista){
    if (empty(lista))
    {
        puts("Lista Vazia!\n");
        return ;
    }
    int posicao;
    puts("Digite a posicao do elemento que deseja retirar");
    scanf("%d", &posicao);
    while (posicao < 1 || posicao > lista->tamanhoLista)
    {
        printf("Posicao Invalida! Digite novamente: [1 - %d]\n", lista->tamanhoLista);
        scanf("%d", &posicao);
    }
    
    list *temp = lista, *removido, *proximo;
    int valorRemovido;
    for (int i = 0; temp!=NULL && i < posicao - 1; i++)
    {
        temp = temp->proximoNo;
    }

    if (temp->proximoNo->proximoNo != NULL) // verifica se existe proximo elemento do excluido 
    {
        proximo = temp->proximoNo->proximoNo;
        removido = temp->proximoNo;
        valorRemovido = removido->valor;
        free(removido);
        temp->proximoNo = proximo;
    }
    else
    {
        removido = temp->proximoNo;
        valorRemovido = removido->valor;
        free(removido);
        temp->proximoNo = NULL;
    }
    lista->tamanhoLista--;
    printf("Elemento Removido com Sucesso :%d!\n", valorRemovido);
}

void pop_inicio(list *lista){
    if (empty(lista))
    {
        puts("Lista Vazia!\n");
        return ;
    }

    list *temp = lista, *removido, *proximo;
    int valorRemovido;
    
    // Exclui
    proximo = temp->proximoNo->proximoNo;
    removido = temp->proximoNo;
    valorRemovido = removido->valor;
    free(removido);
    temp->proximoNo = proximo;
    
    lista->tamanhoLista--;
    printf("Elemento Removido com Sucesso :%d!\n", valorRemovido);
}

void pop_fim(list *lista){
    if (empty(lista))
    {
        puts("Lista Vazia!\n");
        return ;
    }
    
    list *temp = lista, *removido, *proximo;
    int valorRemovido;
    for (int i = 0; temp->proximoNo->proximoNo !=NULL; i++)
    {
        temp = temp->proximoNo;
    }

    removido = temp->proximoNo;
    valorRemovido = removido->valor;
    free(removido);
    temp->proximoNo = NULL;
    
    lista->tamanhoLista--;
    printf("Elemento Removido com Sucesso :%d!\n", valorRemovido);
}

void buscaNumero(list *lista){
    if (empty(lista))
    {
        puts("Lista Vazia!");
        return;
    }
    int numero;
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &numero);
    list *temp = lista->proximoNo;
    while (temp != NULL)
    {
        if (temp->valor == numero)
        {
            printf("Valor presente na lista : %d\n", temp->valor);
            return;
        }
        temp = temp->proximoNo;
    }

    puts("Valor nao encontrado!");   
}