#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct noPessoa{
    char nome[21];
    char cpf[12];
    int idade;
    char sexo;
    char telefone[12];
    
    struct noPessoa *proximo;
}noPessoa;

noPessoa *head = NULL;

void limparBuffer();
void cadastrarPessoa();
void removerCadastro();
int buscar(char cpf[12]);

int main(void){
    int opt=0;
    printf(">> CADASTRO DE PESSOAS <<\n");
    do{
        printf("cadastrar pessoa ------ 1\n");
        printf("remover uma pesosa ---- 2\n");
        printf("alterar registro ------ 3\n");
        printf("exibir registro unico - 4\n");
        printf("exibir todos ---------- 5\n");
        printf("sair do programa ------ 0\n");
        scanf(" %i", &opt);

        switch (opt){
            case 1:
                cadastrarPessoa();
                break;
            case 2:
                //removerPessoas();
                break;
            case 3:
                //alterarPessoas();
                break;
            case 4:
                //exibirUmRegistro();
                break;
            case 5:
                //exibirTodosRegistros();
                break;
            case 0:
                break;
            default:
                printf("insira uma opcao valida\n");
    
        }
    }while(opt!=0);
}

void limparBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF){}
}
void cadastrarPessoa(){
    do{
        noPessoa *novoNode = malloc(sizeof(noPessoa));
        if(novoNode==NULL){
            printf("falha catastrofica, erro ao alocar memoria!\b");
            return;
        }
        printf("node criado com sucesso");

        inputInformacao(novoNode);

        novoNode->proximo=NULL; //node inserido é sempre o ultimo

        //verificando se a lista esta vazia
        if(head==NULL){
            head=novoNode;
        }
        else{
            noPessoa *ultimo = head;
            while(ultimo->proximo!=NULL){
                ultimo=ultimo->proximo;
            }
            ultimo->proximo=novoNode;
        }

        
        
    }while(tolower(tempC)=='S');
}
void inputInformacao(noPessoa **novoNode){
    
}
int buscar(char cpf[12]){
    int con=1;
    noPessoa *noAtual = head;
    while(noAtual!=NULL){
        if(strcmp(cpf, *noAtual->cpf)==0)
            return con;
        noAtual = noAtual->proximo;
    }
}
void removerCadastro(){
    if(head==NULL){
        printf("lista vazia, nada a remover. \n");
        return;
    }
}
int controleRepetir(){
    char tempC;
    do{
        printf("deseja repetir a operacao?\n");
        scanf(" %c", &tempC);
        limparBuffer();
        if(tolower(tempC)=='s'||tolower(tempC)=='n')
            printf("numero invalido, digite novamente!\n");

        if(tolower(tempC)=='s')
            return 1;
        if(tolower(tempC)=='n')
            return 0;
    }while(!(tolower(tempC)=='s'||tolower(tempC)=='n'));
}