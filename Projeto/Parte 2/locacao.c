#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"
#include <time.h>

// Função para locação de veículos
void locacaoVeiculo(struct clientes cliente[], struct veiculos veiculo[], struct locacoes locacao[], int *qnt_cliente, int *qnt_veiculo, int *qnt_locacao, int *qnt_max_locacao){
	int i, j, found, found2;
	char placa[10], cpf[15], dataDev[20], data[20];
	strcpy(data, "");
	
	// Verifica se existe espaço e aloca caso não tenha
	if (*qnt_max_locacao - *qnt_locacao <= 10){
		reallocSizeLocacao(locacao, *qnt_max_locacao + 20);
		(*qnt_max_locacao) = (*qnt_max_locacao) + 20;
	}

	printf("Insira a placa do veículo a ser locado: ");
	fflush(stdin);
	gets(placa);

	// Procura o veículo
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, placa) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		// Não encontrou o veículo
		clearScreen();
		printf("Veículo não encontrado\n\n");
	}  else{
		// Encontrou o veículo
		if (veiculo[i].state == 0){
			printf("Veículo já se encontra locado\n\n");
		} else{
			// Veículo está disponível
			printf("Insira o CPF do contratante (apenas números): ");
			fflush(stdin);
			gets(cpf);

			// Procura o cliente
			for (j=0; j<*qnt_cliente; j++){
				if (strcmp(cliente[j].cpf, cpf) == 0){
					found2 = 1;
					break;
				}
			}
			if (found2 == 0){
				// Não encontrou o cliente
				clearScreen();
				printf("Cliente não encontrado\n\n");
				
			} else{
				// Encontrou o cliente
				printf("Insira a data de devolução (dd/mm/aaaa): ");
				gets(dataDev);
				strcpy(locacao[(*qnt_locacao)].dataDev, dataDev);

				strcpy(veiculo[i].cpfAluguel, cliente[j].cpf);
				locacao[(*qnt_locacao)].id = (*qnt_locacao) + 1;
				locacao[(*qnt_locacao)].tipo = 1;
				strcpy(locacao[(*qnt_locacao)].cpf, cliente[j].cpf);
				strcpy(locacao[(*qnt_locacao)].name, cliente[j].name);
				strcpy(locacao[(*qnt_locacao)].placa, veiculo[i].placa);
				strcpy(locacao[(*qnt_locacao)].marca, veiculo[i].marca);
				strcpy(locacao[(*qnt_locacao)].modelo, veiculo[i].modelo);
				strcpy(locacao[(*qnt_locacao)].telefone, cliente[j].telefone);
				locacao[(*qnt_locacao)].ano = veiculo[i].ano;
				veiculo[i].state = 0;

				// Pega a data atual do sistema e define como data de locação
				time_t mytime;
				mytime = time(NULL);
				struct tm tm = *localtime(&mytime);
				snprintf(data, 20, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
				strcpy(locacao[(*qnt_locacao)].data, data);

				(*qnt_locacao)++;
				clearScreen();
				printf("Locação efetuada com sucesso\n\n");
			}
		}
	}
}

// Função para devolução de veículos
void devolucaoVeiculo(struct clientes cliente[], struct veiculos veiculo[], struct locacoes locacao[], int *qnt_cliente, int *qnt_veiculo, int *qnt_locacao, int *qnt_max_locacao){
	int i, j, found, found2;
	char placa[10], cpf[15], dataDev[20], data[20];
	strcpy(data, "");
	
	// Verifica se existe espaço e aloca caso não tenha
	if (*qnt_max_locacao - *qnt_locacao <= 10){
		reallocSizeLocacao(locacao, *qnt_max_locacao + 20);
		(*qnt_max_locacao) = (*qnt_max_locacao) + 20;
	}

	printf("Insira a placa do veículo a ser devolvido: ");
	fflush(stdin);
	gets(placa);

	// Procura o veículo
	for (i=0; i<*qnt_veiculo; i++){
		if (strcmp(veiculo[i].placa, placa) == 0){
			found = 1;
			break;
		}
	}

	if (found == 0){
		// Não encontrou o veículo
		clearScreen();
		printf("Veículo não encontrado\n\n");
	}  else{
		if (veiculo[i].state == 1){
			printf("Veículo não está locado\n\n");
		} else{
			// Encontrou o veículo
			printf("Insira o CPF do contratante (apenas números): ");
			fflush(stdin);
			gets(cpf);

			// Procura o cliente
			for (j=0; j<*qnt_cliente; j++){
				if (strcmp(cliente[j].cpf, cpf) == 0){
					found2 = 1;
					break;
				}
			}
			if (found2 == 0){
				// Não encontrou o cliente
				clearScreen();
				printf("Cliente não encontrado\n\n");
				
			} else{
				// Encontrou o cliente
				// Define os dados da devolução
				strcpy(veiculo[i].cpfAluguel, "0");
				locacao[(*qnt_locacao)].id = (*qnt_locacao) + 1;
				locacao[(*qnt_locacao)].tipo = 0;
				strcpy(locacao[(*qnt_locacao)].cpf, cliente[j].cpf);
				strcpy(locacao[(*qnt_locacao)].name, cliente[j].name);
				strcpy(locacao[(*qnt_locacao)].placa, veiculo[i].placa);
				strcpy(locacao[(*qnt_locacao)].marca, veiculo[i].marca);
				strcpy(locacao[(*qnt_locacao)].modelo, veiculo[i].modelo);
				strcpy(locacao[(*qnt_locacao)].telefone, cliente[j].telefone);
				locacao[(*qnt_locacao)].ano = veiculo[i].ano;
				veiculo[i].state = 1;
				strcpy(locacao[(*qnt_locacao)].dataDev, "0");

				// Pega a data atual do sistema e define como data de devolução
				time_t mytime;
				mytime = time(NULL);
				struct tm tm = *localtime(&mytime);
				snprintf(data, 20, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);
				strcpy(locacao[(*qnt_locacao)].data, data);

				(*qnt_locacao)++;
				clearScreen();
				printf("Devolução efetuada com sucesso\n\n");
			}
		}
	}
}

// Função para listar o histórico de operações
void relatorioLocacao(struct locacoes locacao[], int *qnt_locacao){
	int i;
	clearScreen();

	for (i=0; i<(*qnt_locacao); i++){
		if (locacao[i].tipo == 1){
			printf("Locação (id = %d)\n", locacao[i].id);
		} else{
			printf("Devolução (id = %d)\n", locacao[i].id);
		}
		printf("%s %s %d\n", locacao[i].marca, locacao[i].modelo, locacao[i].ano);
		printf("Data: %s\n", locacao[i].data);
		printf("CPF: %s\n", locacao[i].cpf);
		printf("Nome: %s (Tel: %s)\n\n", locacao[i].name, locacao[i].telefone);
	}
}
