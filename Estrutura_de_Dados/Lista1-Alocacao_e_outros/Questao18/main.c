#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int valor;
    struct Node* proximo;
}Node;

void inserirNode(Node** head, int valor);
void imprimirLista(Node* head);
void liberarLista(Node** head);


int main(void){
    Node* head = NULL;
    int opt;
    int tempValor;
    
    do{
        printf("\nInserir node inicio - 1\n");
        printf("Imprimir lista ------ 2\n");
        printf("Limpar lista -------- 3\n");
        printf("sair ---------------- 0\n");
        scanf("%i", &opt);
        
        switch(opt){
            case 1:
                printf("Insira o valor do node\n");
                scanf(" %i", &tempValor);
                inserirNode(&head, tempValor);
                break;
            case 2:
                imprimirLista(head);
                break;
            case 3:
                liberarLista(&head);
                break;
            case 0: 
                break;
            default:
                printf("Opcao invaida");
        }
    }while(opt!=0);

    return 0;
}
void inserirNode(Node** head, int valor){
    Node* novoNode = malloc(sizeof(Node));
    if(novoNode==NULL){
        printf("falha ao alocar memoria\n");
        return;
    }
    novoNode->valor = valor;
    novoNode->proximo = *head;
    *head = novoNode;
    printf("node de valor %i criado com sucesso", novoNode->valor);
    
}

void imprimirLista(Node* head){
    Node* atual = head;
    if(atual==NULL){
        printf("lista vazia\n");
        return; 
    } 
    while(atual!=NULL){
        printf("%i ", atual->valor);
        atual = atual->proximo;
    }
}

void liberarLista(Node** head){
    Node* atual = *head;
    Node* proximo;
    
    while(atual!=NULL){
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    printf("lista liberada\n");
    *head = NULL;
}

