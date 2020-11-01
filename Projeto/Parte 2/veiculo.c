#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

void cadastrarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo){
	int i, ano;
	char marca[50], modelo[75], cnh[15], placa[10];
	int state = 0;

	
	// Verifica se existe espaço e aloca caso não tenha
	if (*qnt_max_veiculo - *qnt_veiculo <= 10){
		reallocSizeVeiculo(veiculo, *qnt_max_veiculo + 20);
		(*qnt_max_veiculo) = (*qnt_max_veiculo) + 20;
	}

	printf("\nFoi até aqui\n");

	// Verifica o index a ser cadastrado
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, "0") == 0){
			break;
		}
	}

	// Obtem a placa
	printf("Insira a placa do veículo (sem hífen): ");
	fflush(stdin);
	gets(placa);
	// Verifica a existência do veiculo
	if (verifyExistVeiculo(veiculo, placa, *qnt_veiculo) == 1){
		printf("Veículo ja cadastrado");
	} else{
		strcpy(veiculo[i].placa, placa);

		printf("Insira o modelo: ");
		gets(modelo);
		strcpy(veiculo[i].modelo, modelo);

		printf("Insira a marca: ");
		gets(marca);
		strcpy(veiculo[i].marca, marca);
		
		printf("Insira o ano: ");
		scanf("%d", &veiculo[i].ano);

		veiculo[i].state = 0;

		(*qnt_veiculo)++;

		clearScreen();
		printf("\n\nVeículo cadastrado com sucesso\n\n");
	}
}

void excluirVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido){
	int i;
	int found = 0;
	char placa[10], conf;

	printf("Insira a placa do veiculo a ser excluido: ");
	fflush(stdin);
	gets(placa);

	// Verifica a existência do cliente
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, placa) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		clearScreen();
		printf("Veículo não encontrado\n\n");
	}  else{
		printf("Tem certeja que deseja excluir o veículo de placa %s (S/N): ", veiculo[i].placa);
		scanf(" %c", &conf);
		clearScreen();
		
		if (conf == 'S'){
			strcpy(veiculo[i].placa, "0");
			printf("\n\nCliente excluido com sucesso\n\n");
			(*qnt_veiculo)--; 
			(*qnt_veiculo_excluido)++;
		} else{
			printf("\n\nOperação cancelada\n\n");
		}
	}
}

void consultarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido){
	int i;
	int found = 0;
	char placa[10];

	printf("Insira a placa do veículo a ser consultado: ");
	fflush(stdin);
	gets(placa);

	// Verifica a existência do veículo
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, placa) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		clearScreen();
		printf("Cliente não encontrado\n\n");
	}  else{
		printf("Modelo: %s\n", veiculo[i].modelo);
		printf("Marca: %s\n", veiculo[i].marca);
		printf("Ano: %d\n", veiculo[i].ano);
		printf("Placa: %s\n", veiculo[i].placa);
		printf("Estado atual: ");
		if (veiculo[i].state == 1){
			printf("Alugado\n\n");
		} else{
			printf("Disponível\n\n");
		}
	}
}

void listarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido){
	int i, contExibido;
	contExibido = 0;
	clearScreen();
	printf("\n\n%d\n\n", *qnt_veiculo);

	for (i=0; i<(*qnt_veiculo+ *qnt_veiculo_excluido); i++){
		if (strlen(veiculo[i].placa) > 2){
			printf("Modelo: %s\n", veiculo[i].modelo);
			printf("Marca: %s\n", veiculo[i].marca);
			printf("Ano: %d\n", veiculo[i].ano);
			printf("Placa: %s\n", veiculo[i].placa);
			printf("Estado atual: ");
			if (veiculo[i].state == 1){
				printf("Alugado\n\n");
			} else{
				printf("Disponível\n\n");
			}
		}
	}
}