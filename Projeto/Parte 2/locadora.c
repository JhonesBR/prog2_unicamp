#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

// Função de limpar a tela
void clearScreen(){
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}

// Função de realocação de memória para clientes
void reallocSizeCliente(struct clientes p[], int n){
    p = (struct clientes*) realloc(p, n*sizeof(struct clientes));
    if (!p){
        printf("\nErro de realocação de memória\n");
    }
}

// Função de realocação de memória para veículos
void reallocSizeVeiculo(struct veiculos p[], int n){
    p = (struct veiculos*) realloc(p, n*sizeof(struct veiculos));
    if (!p){
        printf("\nErro de realocação de memória\n");
    }
}

// Função de realocação de memória para locações
void reallocSizeLocacao(struct locacoes p[], int n){
    p = (struct locacoes*) realloc(p, n*sizeof(struct locacoes));
    if (!p){
        printf("\nErro de realocação de memória\n");
    }
}

// Função de verificação de existência para clientes
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

// Função de verificação de existência para veículos
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

// Função de organização de lista para clientes
void organizeListCliente(struct clientes cliente[], int qnt_cliente, int *qnt_cliente_excluido){
    int i, j;
    char auxName[100], auxCpf[15], auxCnh[15], auxTelefone[20];

    // "Bubble sort" com struct passando os 0s pra frente
    for (i=0; i<(qnt_cliente+*qnt_cliente_excluido); i++){
        for (j=0; j<(qnt_cliente+*qnt_cliente_excluido-1); j++){
            if (strcmp(cliente[j].cpf, "0") == 0){
                strcpy(auxName, cliente[j].name);
                strcpy(auxCpf, cliente[j].cpf);
                strcpy(auxCnh, cliente[j].cnh);
                strcpy(auxTelefone, cliente[j].telefone);

                strcpy(cliente[j].name, cliente[j+1].name);
                strcpy(cliente[j].cpf, cliente[j+1].cpf);
                strcpy(cliente[j].cnh, cliente[j+1].cnh);
                strcpy(cliente[j].telefone, cliente[j+1].telefone);

                strcpy(cliente[j+1].name, auxName);
                strcpy(cliente[j+1].cpf, auxCpf);
                strcpy(cliente[j+1].cnh, auxCnh);
                strcpy(cliente[j+1].telefone, auxTelefone);
            }
        }
    }
    (*qnt_cliente_excluido) = 0;
}

// Função de organização de lista para veiculos
void organizeListVeiculo(struct veiculos veiculo[], int qnt_veiculo, int *qnt_veiculo_excluido){
    int i, j, auxState, auxAno;
    char auxMarca[50], auxModelo[75], auxPlaca[10];

    // "Bubble sort" com struct passando os 0s pra frente
    for (i=0; i<(qnt_veiculo+*qnt_veiculo_excluido); i++){
        for (j=0; j<(qnt_veiculo+*qnt_veiculo_excluido-1); j++){
            if (strcmp(veiculo[j].placa, "0") == 0){
                strcpy(auxMarca, veiculo[j].marca);
                strcpy(auxModelo, veiculo[j].modelo);
                strcpy(auxPlaca, veiculo[j].placa);
                auxAno = veiculo[j].ano;
                auxState = veiculo[j].state;

                strcpy(veiculo[j].marca, veiculo[j+1].marca);
                strcpy(veiculo[j].modelo, veiculo[j+1].modelo);
                strcpy(veiculo[j].placa, veiculo[j+1].placa);
				veiculo[j].ano = veiculo[j+1].ano;
				veiculo[j].state = veiculo[j+1].state;

                strcpy(veiculo[j+1].marca, auxMarca);
                strcpy(veiculo[j+1].modelo, auxModelo);
                strcpy(veiculo[j+1].placa, auxPlaca);
                veiculo[j+1].ano = auxAno;
                veiculo[j+1].state = auxState;
            }
        }
    }
    (*qnt_veiculo_excluido) = 0;
}
