#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define tamString 100

struct produtos{
    int codigo;
    int qnt;
    char desc[tamString];
};

void reallocSize(struct produtos mercadoria[], int n);
int verifyExist(struct produtos mercadoria[], int cod, int qnt_mercadoria);
int findCod(struct produtos mercadoria[], int cod, int qnt_mercadoria);
int attEstoque(struct produtos mercadoria[], int q, int index, char desc[tamString], int opcao);

int main(){
    int escolha, i, codigo, index, q;
    int qnt_mercadoria = 0;
    char descricao[tamString];

    struct produtos* mercadoria;
    mercadoria = (struct produtos*) malloc(100*sizeof(struct produtos));

    for(;;){
        printf("\n1. Cadastrar novas mercadorias\n");
        printf("2. Pedido de mercadorias\n");
        printf("3. Listagem de estoque\n");
        printf("4. Atualização de dados\n");
        printf("5. Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                printf("\nInsira o codigo 0 para parar\n\n");
                i = qnt_mercadoria;
                for(;;){
                    printf("Insira o codigo da mercadoria: ");
                    scanf("%d", &codigo);
                    if (codigo == 0){
                        break;
                    }
                    if (verifyExist(mercadoria, codigo, qnt_mercadoria) == 1){
                        printf("O produto ja esta cadastrado\n\n");
                    } else{
                        printf("Insira a quantidade da mercadoria %d: ", codigo);
                        scanf("%d", &mercadoria[qnt_mercadoria].qnt);
                        mercadoria[qnt_mercadoria].codigo = codigo;
                        printf("Insira a descrição da mercadoria %d: ", codigo);
                        fflush(stdin);
                        gets(mercadoria[qnt_mercadoria].desc);
                        qnt_mercadoria += 1;
                        reallocSize(mercadoria, qnt_mercadoria+1);
                        i++;
                        printf("Produto cadastrado com sucesso!\n\n");
                    }
                }
                break;

            case 2:
                printf("\nInsira o número da mercadoria a ser vendida: ");
                scanf("%d", &codigo);
                index = findCod(mercadoria, codigo, qnt_mercadoria);
                if (index == -1){
                    printf("Mercadoria não cadastrada\n");
                } else{
                    printf("Insira a quantidade da mercadoria: ");
                    scanf("%d", &q);
                    attEstoque(mercadoria, q, index, "", -1);
                }
                break;

            case 3:
                printf("\n");
                for(i=0; i<qnt_mercadoria; i++){
                    printf("%d - %d unidades (\"%s\")\n", mercadoria[i].codigo, mercadoria[i].qnt, mercadoria[i].desc);
                }
                break;

            case 4:
                printf("\nInsira o número da mercadoria a ser atualizada: ");
                scanf("%d", &codigo);
                index = findCod(mercadoria, codigo, qnt_mercadoria);
                if (index == -1){
                    printf("Mercadoria não cadastrada\n");
                } else{
                    printf("Insira a nova quantidade da mercadoria: ");
                    scanf("%d", &q);
                    printf("Insira a nova descrição da mercadoria: ");
                    fflush(stdin);
                    gets(descricao);
                    attEstoque(mercadoria, q, index, descricao, 1);
                }
                break;

            case 5:
                free(mercadoria);
                return 0;

            default:
                free(mercadoria);
                return 0;
        }
    }
}

int verifyExist(struct produtos mercadoria[], int cod, int qnt_mercadoria){
    int found = -1;
    int i;
    for (i=0; i<qnt_mercadoria; i++){
        if (mercadoria[i].codigo == cod){
            found = 1;
        }
    }
    return found;
}

int findCod(struct produtos mercadoria[], int cod, int qnt_mercadoria){
    int i;
    for (i=0; i<qnt_mercadoria; i++){
        if (mercadoria[i].codigo == cod){
            return i;
        }
    }
    return -1;
}

void reallocSize(struct produtos p[], int n){
    p = (struct produtos*) realloc(p, n*sizeof(struct produtos));
    if (!p){
        printf("\nErro de realocação de memória\n");
    }
}

int attEstoque(struct produtos mercadoria[], int q, int index, char desc[tamString], int opcao){
    if (opcao == -1){
        if (q > mercadoria[index].qnt){
            printf("Estoque insuficiente da mercadoria\n");
        } else{
            mercadoria[index].qnt -= q ;              
            printf("Pedido realizado com sucesso!\n\n");
        }
    }
    if (opcao == 1){
        mercadoria[index].qnt = q ;
        strcpy(mercadoria[index].desc, desc);             
        printf("Mercadoria atualizada com sucesso!\n\n");
    }
}