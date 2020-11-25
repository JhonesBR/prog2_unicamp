#include <stdlib.h>
#include <stdio.h>

int main(){
    char nome[100], tipoSanguineo[5];
    long long int telefone;
    FILE *data;

    data = fopen("dados.txt", "w+");
    if (data != 0){
        fflush(stdin);
        printf("Insira o nome: ");
        gets(nome);
        printf("Insira o telefone: ");
        scanf("%lld", &telefone);
        fflush(stdin);
        printf("Insira o tipo sanguíneo: ");
        gets(tipoSanguineo);

        fprintf(data, "%s,%lld,%s", nome, telefone, tipoSanguineo);
        printf("\nDados armazenados em dados.txt\n");
    } else{
        printf("Falha em abrir o arquivo dados.txt\n");
    }
    fclose(data);

    return 0;
}