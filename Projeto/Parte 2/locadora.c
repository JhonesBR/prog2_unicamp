#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

void clearScreen(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

void makeRight(char *s[]){
    int i = 0;
    for (i=0; i<strlen(*s); i++){
        (*s)[i] = toupper((*s)[i]);
    }
}

void reallocSizeCliente(struct clientes p[], int n){
    p = (struct clientes*) realloc(p, n*sizeof(struct clientes));
    if (!p){
        printf("\nErro de realoca��o de mem�ria\n");
    }
}

void reallocSizeVeiculo(struct veiculos p[], int n){
    p = (struct veiculos*) realloc(p, n*sizeof(struct veiculos));
    if (!p){
        printf("\nErro de realoca��o de mem�ria\n");
    }
}

int verifyExistCliente(struct clientes cliente[], char cpf[15], int qnt_cliente){
	int found = -1;
	int i;
	for (i=0; i<qnt_cliente; i++){
		if (strcmp(cpf, cliente[i].cpf) == 0){
            found = 1;
        }
	}
    return found;
}

int verifyExistVeiculo(struct veiculos veiculo[], char placa[10], int qnt_veiculo){
	int found = -1;
	int i;
	for (i=0; i<qnt_veiculo; i++){
		if (strcmp(placa, veiculo[i].placa) == 0){
            found = 1;
        }
	}
    return found;
}

