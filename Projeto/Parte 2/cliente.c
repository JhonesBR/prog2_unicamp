#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

void novoCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente){
	int i;
	char cpf[15], name[15], cnh[15], telefone[20];

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
	printf("Insira o CPF (apenas numeros): ");
	fflush(stdin);
	gets(cpf);
	// Verifica a existência do cliente
	if (verifyExistCliente(cliente, cpf, *qnt_cliente) == 1){
		printf("Cliente ja cadastrado");
	} else{
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

		(*qnt_cliente)++;

		clearScreen();
		printf("\n\nCliente cadastrado com sucesso\n\n");
	}
}

void editarCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente){
	int i;
	int found = 0;
	char cpf[15], name[15], cnh[15], telefone[20];

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
		printf("Cliente não encontrado\n");
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

void excluirCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente, int *qnt_cliente_excluido){
	int i;
	int found = 0;
	char cpf[15], conf;

	printf("Insira o CPF do cliente a ser excluido: ");
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
		clearScreen();
		printf("Cliente não encontrado\n\n");
	}  else{
		printf("Tem certeja que deseja excluir o cliente de CPF %s (S/N): ", cliente[i].cpf);
		scanf(" %c", &conf);
		clearScreen();
		
		if (conf == 'S'){
			strcpy(cliente[i].cpf, "0");
			printf("\n\nCliente excluido com sucesso\n\n");
			(*qnt_cliente)--; 
			(*qnt_cliente_excluido)++;
		} else{
			printf("\n\nOperação cancelada\n\n");
		}
	}
}

void consultarCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_cliente_excluido, int *qnt_max_cliente, int *qnt_veiculo, int *qnt_max_veiculo){
	int i;
	int found = 0;
	char cpf[15], name[15], cnh[15], telefone[20];

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
		clearScreen();
		printf("Cliente não encontrado\n\n");
	}  else{
		
	}
}

void listarCliente(struct clientes cliente[], int *qnt_cliente, int *qnt_max_cliente, int *qnt_cliente_excluido){
	int i, contExibido;
	contExibido = 0;
	clearScreen();


	for (i=0; i<(*qnt_cliente+ *qnt_cliente_excluido); i++){
		if (strlen(cliente[i].cpf) > 2){
			printf("Nome: %s\n", cliente[i].name);
			printf("CPF: %s\n", cliente[i].cpf);
			printf("CNH: %s\n", cliente[i].cnh);
			printf("Telefone: %s\n\n", cliente[i].telefone);	
		}
	}
}
