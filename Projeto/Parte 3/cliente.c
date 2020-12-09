#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

// Função para cadastrar novos clientes
void novoCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente){
	int i;
	char cpf[15], name[100], cnh[15], telefone[20];

	// Verifica se existe espaço e aloca caso não tenha
	if (*qnt_max_cliente - *qnt_cliente <= 10){
		reallocSizeCliente(cliente, *qnt_max_cliente + 20);
		(*qnt_max_cliente) = (*qnt_max_cliente) + 20;
	}

	// Verifica o index a ser cadastrado
	for (i=0; i<*qnt_cliente; i++){
		if (strcmp(cliente[i].cpf, "0") == 0){
			break;
		}
	}

	// Obtem o CPF
	printf("Insira o CPF (apenas números): ");
	fflush(stdin);
	gets(cpf);
	// Verifica a existência do cliente
	if (verifyExistCliente(cliente, cpf, *qnt_cliente) == 1){
		// Cliente já está cadastrado
		clearScreen();
		printf("Cliente já cadastrado\n\n");
	} else{
		// Cliente não está cadastrado
		// Coleta os dados e armazena
		strcpy(cliente[i].cpf, cpf);

		printf("Insira o nome: ");
		gets(name);
		strcpy(cliente[i].name, name);

		printf("Insira a CNH (apenas números): ");
		gets(cnh);
		strcpy(cliente[i].cnh, cnh);
		
		printf("Insira o telefone (apenas números): ");
		gets(telefone);
		strcpy(cliente[i].telefone, telefone);

		(*qnt_cliente)++;

		clearScreen();
		printf("\n\nCliente cadastrado com sucesso\n\n");
	}
}

// Função para editar clientes
void editarCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente){
	int i;
	int found = 0;
	char cpf[15], name[100], cnh[15], telefone[20];

	// Obtem o CPF
	printf("Insira o CPF do cliente a ser alterado: ");
	fflush(stdin);
	gets(cpf);

	// Verifica a existência do cliente
	for (i=0; i<*qnt_cliente; i++){
		if (strcmp(cliente[i].cpf, cpf) == 0){
			found = 1;
			break;
		}
	}

	// Altera os dados do cliente ou exibe o erro
	if (found == 0){
		clearScreen();
		printf("Cliente não encontrado\n\n");
	}  else{
		strcpy(cliente[i].cpf, cpf);

		printf("Insira o nome: ");
		gets(name);
		strcpy(cliente[i].name, name);

		printf("Insira a CNH (apenas numeros): ");
		gets(cnh);
		strcpy(cliente[i].cnh, cnh);
		
		printf("Insira o telefone (apenas numeros): ");
		gets(telefone);
		strcpy(cliente[i].telefone, telefone);

		clearScreen();
		printf("\n\nCliente alterado com sucesso\n\n");
	}
}

// Função para excluir um cliente
void excluirCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente, int *qnt_cliente_excluido, struct veiculos veiculo[], int *qnt_veiculo){
	int i, j;
	int found = 0;
	int possuiAluguel = 0;
	char cpf[15], conf;

	// Obtem o CPF
	printf("Insira o CPF do cliente a ser excluído: ");
	fflush(stdin);
	gets(cpf);

	// Verifica a existência do cliente
	for (i=0; i<*qnt_cliente; i++){
		if (strcmp(cliente[i].cpf, cpf) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		// Cliente não encontrado
		clearScreen();
		printf("Cliente não encontrado\n\n");
	} else{
		
		// Verifica se o cliente está alugando um carro
		for (j=0; j<(*qnt_veiculo); j++){
			if (strcmp(veiculo[j].cpfAluguel, cliente[i].cpf) == 0)
				possuiAluguel = 1;
		}
		if (possuiAluguel == 1){
			// Cliente está alugando um carro no momento
			printf("Cliente está alugando um carro no momento\n\n");

		} else{
			// Confirmação adicional
			printf("Tem certeja que deseja excluir o cliente de CPF %s (S/N): ", cliente[i].cpf);
			scanf(" %c", &conf);
			clearScreen();
			
			if (toupper(conf) == 'S'){
				strcpy(cliente[i].cpf, "0");
				printf("\n\nCliente excluido com sucesso\n\n");
				(*qnt_cliente)--; 
				(*qnt_cliente_excluido)++;
			} else{
				printf("\n\nOperação cancelada\n\n");
			}
		}
	}
}

// Função para consultar o cliente
void consultarCliente(struct clientes cliente[], struct veiculos veiculo[] ,int *qnt_cliente, int *qnt_max_cliente, int *qnt_veiculo, int *qnt_max_veiculo){
	int i, j;
	int found2 = 0;
	int found = 0;
	char cpf[15], name[100], cnh[15], telefone[20];

	// Obtem o CPF
	printf("Insira o CPF do cliente a ser consultado: ");
	fflush(stdin);
	gets(cpf);

	// Verifica a existência do cliente
	for (i=0; i<*qnt_cliente; i++){
		if (strcmp(cliente[i].cpf, cpf) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		// Cliente não encontrado
		clearScreen();
		printf("Cliente não encontrado\n\n");
	} else{
		// Exibe os dados do cliente
		printf("Nome: %s\n", cliente[i].name);
		printf("CPF: %s\n", cliente[i].cpf);
		printf("CNH: %s\n", cliente[i].cnh);
		printf("Telefone: %s\n", cliente[i].telefone);
			
		// Procura e exibe os dados das locações do cliente (se houver)
		for (j=0; j<*qnt_veiculo; j++){
			if (strcmp(veiculo[j].cpfAluguel, cpf) == 0){
				found2++;
				if (found2 == 1){
					printf("\nO cliente possui os seguintes veículos alugados:\n");
				}
				printf(" - %s %s %d (%s)\n", veiculo[j].marca, veiculo[j].modelo, veiculo[j].ano, veiculo[j].placa);
			}
		}
		if (found2 == 0){
			printf("O cliente não possui veículos alugados");
		}
		printf("\n\n");
	}
}

// Função para listar todos clientes
void listarCliente(struct clientes cliente[], int *qnt_cliente){
	int i;
	clearScreen();

	for (i=0; i<(*qnt_cliente); i++){
		if (strlen(cliente[i].cpf) > 2){
			printf("Nome: %s\n", cliente[i].name);
			printf("CPF: %s\n", cliente[i].cpf);
			printf("CNH: %s\n", cliente[i].cnh);
			printf("Telefone: %s\n\n", cliente[i].telefone);	
		}
	}
}

// Função para salvar os clientes em binário
void saveCliente(struct clientes cliente[], int *qnt_cliente){
	FILE *data;
	int n_clientes = *qnt_cliente;
	
	// Grava todos os registros da memória no arquivo
	data = fopen("clientes.dat", "wb"); // Cria o arquivo para escrita
	if (data == NULL)
		printf("\nErro na criacao do arquivo. Não foi possível gravar os registros.");
	else {
		fwrite(&n_clientes, sizeof(int), 1, data);
		fwrite(cliente, sizeof(struct clientes), n_clientes, data);
		fclose(data);
	}
	*qnt_cliente = n_clientes;
}

// Função para carregar os clientes do binário
void loadCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente){
	FILE *data;
	int n_clientes;
	
	data = fopen("clientes.dat", "rb"); // Abre o arquivo para leitura
	if (data != NULL){ // Já existe o arquivo
		fread(&n_clientes, sizeof(int), 1, data);
		
		// Verifica se existe espaço e aloca caso não tenha
		if (*qnt_max_cliente - n_clientes <= 10){
			reallocSizeCliente(cliente, *qnt_max_cliente + 20);
			(*qnt_max_cliente) = (*qnt_max_cliente) + 20;
		}
		
		fread(cliente, sizeof(struct clientes), n_clientes, data);
		fclose(data);
	} else
		n_clientes = 0;
	*qnt_cliente = n_clientes;
}
