#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct pacientes{
    char nome[100];
    long int telefone;
    char tipoSanguineo[5];
};

int main(){ 
    FILE *data;      
    struct pacientes a;
  
    data = fopen("dadosbin.dat", "ab+");
    if (data == NULL)
        printf("\nErro na criacao ou abertura do arquivo.");
    else {	
		printf("\nPacientes cadastrados:\n");
		fread(&a, sizeof(struct pacientes), 1, data);
		while (!feof(data)){
		   printf("\n%s    %ld     %s", a.nome, a.telefone, a.tipoSanguineo);
	       fread(&a, sizeof(struct pacientes), 1, data);
		}
    }
    fclose(data);

    return 0;
}