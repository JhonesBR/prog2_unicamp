#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main(){
    int escolha, num, qnt, i, cadastro_mercadoria, cadastro_estoque, num_cliente;
    int estoque[MAX], mercadoria[MAX];
    int qnt_total = 0;

    for (;;){
        escolha = 0;
        printf("Menu de opcões:\n");
        printf("\t1. Entrada de Dados\n");
        printf("\t2. Fazer pedido\n");
        printf("\t3. Listagem do Estoque\n");
        printf("\t4. Sair\n");
        scanf("%d", &escolha);

        switch(escolha){
            case 1:
                i = cadastro_mercadoria = 0;
                printf("\n\nInsira o numero de cadastro das mercadorias (ENTER):\n(-1 para finalizar)\n");
                while (cadastro_mercadoria != -1){
                    scanf("%d", &cadastro_mercadoria);
                    if (cadastro_mercadoria != -1){
                        mercadoria[i] = cadastro_mercadoria;
                        i++;
                        qnt_total++;
                    }
                }
                printf("\n\nInsira a quantidade das mercadorias em estoque (ENTER):\n");
                for (i=0; i<qnt_total; i++){
                    scanf("%d", &cadastro_estoque);
                    estoque[i] = cadastro_estoque;
                }
                break;

            case 2:
                printf("\n\nNumero do cliente: ");
                scanf("%d", &num_cliente);
                printf("Numero da mercadoria: ");
                scanf("%d", &num);
                printf("Quantidade desejada: ");
                scanf("%d", &qnt);

                for (i=0; i<qnt_total; i++){
                    if (num == mercadoria[i]){
                        if (qnt <= estoque[i]){
                            estoque[i] = estoque[i] - qnt;
                            printf("\nPedido realizado com sucesso\n");
                            printf("Restam %d unidades da mercadoria %d", estoque[i], mercadoria[i]);
                            break;
                        } else{
                            printf("\nNAO TEMOS A MERCADORIA EM ESTOQUE SUFICIENTE\n");
                            break;
                        }
                    }
                }
                break;

            case 3:
                printf("\n\n");
                for (i=0; i<qnt_total; i++){
                    printf("%d - %d unidades\n", mercadoria[i], estoque[i]);
                }
                break;

            case 4:
                return 0;
        }
        printf("\n\n");
    }
    
    return 0;
}