#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

// Função para cadastrar novos veículos
void novoVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo){
	int i, ano;
	char placa[10], marca[50], modelo[75];

	// Verifica se existe espaço e aloca caso não tenha
	if (*qnt_max_veiculo - *qnt_veiculo <= 10){
		reallocSizeVeiculo(veiculo, *qnt_max_veiculo + 20);
		(*qnt_max_veiculo) = (*qnt_max_veiculo) + 20;
	}

	// Verifica o index a ser cadastrado
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, "0") == 0){
			break;
		}
	}

	// Obtem a placa
	printf("Insira a placa (sem hífen): ");
	fflush(stdin);
	gets(placa);
	// Verifica a existência do veiculo
	if (verifyExistVeiculo(veiculo, placa, *qnt_veiculo) == 1){
		clearScreen();
		printf("Veículo já cadastrado\n\n");
	} else{
		// Obtem os dados e cadastra
		strcpy(veiculo[i].placa, placa);

		printf("Insira a marca: ");
		gets(marca);
		strcpy(veiculo[i].marca, marca);

		printf("Insira o modelo: ");
		gets(modelo);
		strcpy(veiculo[i].modelo, modelo);
		
		printf("Insira o ano: ");
		scanf("%d", &veiculo[i].ano);

		veiculo[i].state = 1;
		strcpy(veiculo[i].cpfAluguel, "0");

		(*qnt_veiculo)++;

		clearScreen();
		printf("\n\nVeículo cadastrado com sucesso\n\n");
	}
}

// Função para excluir um veículo
void excluirVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_veiculo_excluido){
	int i;
	int found = 0;
	char placa[10], conf;

	// Obtem a placa
	printf("Insira a placa do veículo a ser excluído: ");
	fflush(stdin);
	gets(placa);

	// Verifica a existência do veiculo
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, placa) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		// Veículo não encontrado
		clearScreen();
		printf("Veiculo não encontrado\n\n");
	} else{
		if (veiculo[i].state == 0){
			// Veículo está alugado e não pode ser excluido
			printf("Veiculo está alugado no momento\n\n");
		} else {

			// Confirmação de exclusão
			printf("Tem certeja que deseja excluir o veículo de placa %s (S/N): ", veiculo[i].placa);
			scanf(" %c", &conf);
			clearScreen();
			
			if (toupper(conf) == 'S'){
				strcpy(veiculo[i].placa, "0");
				printf("\n\nVeículo excluído com sucesso\n\n");
				(*qnt_veiculo)--; 
				(*qnt_veiculo_excluido)++;
			} else{
				printf("\n\nOperação cancelada\n\n");
			}
		}
	}
}

// Função para consultar um veículo
void consultarVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo, int *qnt_cliente, int *qnt_max_cliente, struct clientes cliente[]){
	int i, j;
	int found = 0;
	char placa[10];

	// Obtem a placa
	printf("Insira a placa do veículo a ser exibido: ");
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
		printf("Veículo não encontrado\n\n");
	}  else{
		printf("\n\nMarca: %s\n", veiculo[i].marca);
		printf("Modelo: %s\n", veiculo[i].modelo);
		printf("Ano: %d\n", veiculo[i].ano);
		printf("Placa: %s\n", veiculo[i].placa);
		if (veiculo[i].state == 1){
			printf("Estado: Disponível\n\n");
		} else{
			printf("Estado: Alugado\n");
			printf("\nDados do Contratante:\n");
			for (j=0; j<*qnt_cliente; j++){
				if (strcmp(cliente[j].cpf, veiculo[i].cpfAluguel) == 0){
					printf("Nome: %s\n", cliente[j].name);
					printf("CPF: %s\n", cliente[j].cpf);
					printf("CNH: %s\n", cliente[j].cnh);
					printf("Telefone: %s\n\n", cliente[j].telefone);
					break;
				}
			}
		}
	}
}

// Função para listar todos os veículos
void listarVeiculo(struct veiculos veiculo[], int *qnt_veiculo){
	int i;
	clearScreen();

	for (i=0; i<(*qnt_veiculo); i++){
		if (strlen(veiculo[i].placa) > 2){
			printf("Marca: %s\n", veiculo[i].marca);
			printf("Modelo: %s\n", veiculo[i].modelo);
			printf("Ano: %d\n", veiculo[i].ano);
			printf("Placa: %s\n", veiculo[i].placa);
			if (veiculo[i].state == 1){
				printf("Estado: Disponível\n\n");
			} else{
				printf("Estado: Alugado pelo cliente de CPF: %s\n\n", veiculo[i].cpfAluguel);
			}
		}
	}
}

// Função para salvar os veículos em binário
void saveVeiculo(struct veiculos veiculo[], int *qnt_veiculo){
	FILE *data;
	int n_veiculos = *qnt_veiculo;
	
	// Grava todos os registros da memória no arquivo
	data = fopen("veiculos.dat", "wb"); // Cria o arquivo para escrita
	if (data == NULL)
		printf("\nErro na criacao do arquivo. Não foi possível gravar os registros.");
	else {
		fwrite(&n_veiculos, sizeof(int), 1, data);
		fwrite(veiculo, sizeof(struct veiculos), n_veiculos, data);
		fclose(data);
	}
	*qnt_veiculo = n_veiculos;
}

// Função para carregar os veículos do binário
void loadVeiculo(struct veiculos veiculo[], int *qnt_veiculo, int *qnt_max_veiculo){
	FILE *data;
	int n_veiculos;
	
	data = fopen("veiculos.dat", "rb"); // Abre o arquivo para leitura
	if (data != NULL){ // Já existe o arquivo
		fread(&n_veiculos, sizeof(int), 1, data);
		
		// Verifica se existe espaço e aloca caso não tenha
		if (*qnt_max_veiculo - n_veiculos <= 10){
			reallocSizeVeiculo(veiculo, *qnt_max_veiculo + 20);
			(*qnt_max_veiculo) = (*qnt_max_veiculo) + 20;
		}
		
		fread(veiculo, sizeof(struct veiculos), n_veiculos, data);
		fclose(data);
	} else
		n_veiculos = 0;
	*qnt_veiculo = n_veiculos;
}
