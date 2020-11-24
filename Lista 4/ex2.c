#include <stdlib.h>
#include <stdio.h>

int main(){
    char texto[100];
    FILE *data;

    data = fopen("dados.txt", "r");
    if (data != 0){
        fscanf(data, "%s", texto);
        printf("\n%s\n", texto);
    } else{
        printf("Falha em abrir/encontrar o arquivo dados.txt\n");
    }
    fclose(data);

    return 0;
}