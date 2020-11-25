#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

struct pacientes{
    char nome[100];
    long long int telefone;
    char tipoSanguineo[5];
};

int main(){ 
    FILE *data;      
    struct pacientes a, b;
    char resp;
  
    data = fopen("dadosbin.dat", "ab+");
    if (data == NULL)
        printf("\nErro na criacao ou abertura do arquivo.");
    else {
	    do {
       	    printf("\n\nDigite o nome do paciente a ser cadastrado: ");
            fflush(stdin);
            gets(a.nome);
            // Verifica se o nome ja esta cadastrado
       		fread(&b, sizeof(struct pacientes), 1, data);
       		while ((!feof(data)) && (strcmp(a.nome, b.nome) != 0))
	        	fread(&b, sizeof(struct pacientes), 1, data);
       		if (feof(data)){
          		printf("Digite o telefone do paciente: ");
          		scanf("%lld", &a.telefone);
          		printf("Digite o tipo sanguineo do paciente: ");
                fflush(stdin);
          		gets(a.tipoSanguineo);
                // Cadastra os novos dados
          		fwrite(&a, sizeof(struct pacientes), 1, data);
	      		printf("\nPaciente cadastrado com sucesso!");
       		}
       		else
          		printf("\nPaciente ja cadastrado.");

    		printf("\nDeseja cadastrar mais pacientes (S/N)? ");
			resp = getchar();
			rewind(data);
		} while	(toupper(resp) == 'S');
		
    }
    fclose(data);

    return 0;
}
