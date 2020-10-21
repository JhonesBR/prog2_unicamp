#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM_volume 50

typedef struct livro{
    int codigo;
    char obra[100];
    char autor[100];
    char editora[100];
    int paginas;
};

int main(){

    int escolha, n_humanas, n_exatas, n_biomedicas, n_search, cod, j, i;
    escolha = n_humanas = n_exatas = n_biomedicas = 0;
    
    struct livro exatas[50];
    struct livro humanas[50];
    struct livro biomedicas[50];

    for (;;){
        escolha = 0;
        printf("Menu de opcões:\n");
        printf("\t1. Cadastrar obras\n");
        printf("\t2. Consulta as informacoes de uma obra\n");
        printf("\t3. Alteracao das informacoes de uma obra\n");
        printf("\t4. Excluir uma obra\n");
        printf("\t5. Sair\n");
        scanf("%d", &escolha);

        switch (escolha){
        case 1:
            printf("\n\nInsira o numero 0 como codigo de catalogacao para prosseguir\n\n");
            printf("** Cadastro de obras de EXATAS **\n\n");
            for (i = n_exatas; i < 50; i++){
                printf("\nCodigo de catalogacao: ");
                scanf("%d", &cod);
                if (cod == 0){
                    break;
                }
                else{
                    exatas[i].codigo = cod;
                    n_exatas++;
                }
                printf("Nome da obra: ");
                scanf("%s", &exatas[i].obra);
                printf("Nome do autor: ");
                scanf("%s", &exatas[i].autor);
                printf("Editora: ");
                scanf("%s", &exatas[i].editora);
                printf("Numero de paginas: ");
                scanf("%d", &exatas[i].paginas);
            }

            printf("\n\n** Cadastro de obras de HUMANAS **\n\n");
            for (i = n_humanas; i < 50; i++){
                printf("\nCodigo de catalogacao: ");
                scanf("%d", &cod);
                if (cod == 0){
                    break;
                }
                else{
                    humanas[i].codigo = cod;
                    n_humanas++;
                }
                printf("Nome da obra: ");
                scanf("%s", &humanas[i].obra);
                printf("Nome do autor: ");
                scanf("%s", &humanas[i].autor);
                printf("Editora: ");
                scanf("%s", &humanas[i].editora);
                printf("Numero de paginas: ");
                scanf("%d", &humanas[i].paginas);
            }

            printf("\n\n** Cadastro de obras de CIENCIAS BIOMEDICAS **\n\n");
            for (i = n_biomedicas; i < 50; i++){
                printf("\nCodigo de catalogacao: ");
                scanf("%d", &cod);
                if (cod == 0){
                    break;
                }
                else{
                    biomedicas[i].codigo = cod;
                    n_biomedicas++;
                }
                printf("Nome da obra: ");
                scanf("%s", &biomedicas[i].obra);
                printf("Nome do autor: ");
                scanf("%s", &biomedicas[i].autor);
                printf("Editora: ");
                scanf("%s", &biomedicas[i].editora);
                printf("Numero de paginas: ");
                scanf("%d", &biomedicas[i].paginas);
            }
            break;

        case 2:
            printf("\n\nInsira o numero de catalogacao da obra: ");
            scanf("%d", &n_search);
            for (i = 0; i < 50; i++){
                if (n_search == exatas[i].codigo){
                    printf("Nome da obra: %s\n", exatas[i].obra);
                    printf("Nome do autor: %s\n", exatas[i].autor);
                    printf("Editora: %s\n", exatas[i].editora);
                    printf("Numero de paginas: %d\n", exatas[i].paginas);
                }
                if (n_search == humanas[i].codigo){
                    printf("Nome da obra: %s\n", humanas[i].obra);
                    printf("Nome do autor: %s\n", humanas[i].autor);
                    printf("Editora: %s\n", humanas[i].editora);
                    printf("Numero de paginas: %d\n", humanas[i].paginas);
                }
                if (n_search == biomedicas[i].codigo){
                    printf("Nome da obra: %s\n", biomedicas[i].obra);
                    printf("Nome do autor: %s\n", biomedicas[i].autor);
                    printf("Editora: %s\n", biomedicas[i].editora);
                    printf("Numero de paginas: %d\n", biomedicas[i].paginas);
                }
            }
            break;

        case 3:
            printf("\n\nInsira o numero de catalogacao da obra a ser alterada: ");
            scanf("%d", &n_search);
            for (i = 0; i < 50; i++){
                if (n_search == exatas[i].codigo){
                    printf("Novo codigo de catalogacao: ");
                    scanf("%d", &exatas[i].codigo);
                    printf("Novo nome da obra: ");
                    scanf("%s", &exatas[i].obra);
                    printf("Novo nome do autor: ");
                    scanf("%s", &exatas[i].autor);
                    printf("Nova editora: ");
                    scanf("%s", &exatas[i].editora);
                    printf("Novo numero de paginas: ");
                    scanf("%d", &exatas[i].paginas);
                }
                if (n_search == humanas[i].codigo){
                    printf("Novo codigo de catalogacao: ");
                    scanf("%d", &humanas[i].codigo);
                    printf("Novo nome da obra: ");
                    scanf("%s", &humanas[i].obra);
                    printf("Novo nome do autor: ");
                    scanf("%s", &humanas[i].autor);
                    printf("Nova editora: ");
                    scanf("%s", &humanas[i].editora);
                    printf("Novo numero de paginas: ");
                    scanf("%d", &humanas[i].paginas);
                }
                if (n_search == biomedicas[i].codigo){
                    printf("Novo codigo de catalogacao: ");
                    scanf("%d", &biomedicas[i].codigo);
                    printf("Novo nome da obra: ");
                    scanf("%s", &biomedicas[i].obra);
                    printf("Novo nome do autor: ");
                    scanf("%s", &biomedicas[i].autor);
                    printf("Nova editora: ");
                    scanf("%s", &biomedicas[i].editora);
                    printf("Novo numero de paginas: ");
                    scanf("%d", &biomedicas[i].paginas);
                }
            }
            break;

        case 4:
            printf("\n\nInsira o numero de catalogacao da obra a ser excluída: ");
            scanf("%d", &n_search);

            for (i = 0; i < 50; i++){
                if (n_search == exatas[i].codigo){
                    exatas[i].codigo = 0;
                    exatas[i].paginas = 0;
                }

                if (n_search == humanas[i].codigo){
                    humanas[i].codigo = 0;
                    humanas[i].paginas = 0;
                }

                if (n_search == biomedicas[i].codigo){
                    exatas[i].codigo = 0;
                    biomedicas[i].paginas = 0;
                }
            }
            break;
            
        case 5:
            return 0;
        }
        printf("\n\n");
    }
}