#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

int main() {
	setlocale(LC_ALL, "Portuguese");
	int escolha1, escolha2, qnt_cliente, qnt_veiculo, qnt_max_cliente, qnt_cliente_excluido, qnt_max_veiculo, qnt_veiculo_excluido;
	escolha1 = escolha2 = qnt_cliente = qnt_veiculo = qnt_cliente_excluido = qnt_veiculo_excluido = 0;
	qnt_max_cliente = qnt_max_veiculo = 100;
	
	struct clientes* cliente;
    cliente = (struct clientes*) malloc(100*sizeof(struct clientes));
	struct veiculos* veiculo;
    veiculo = (struct veiculos*) malloc(100*sizeof(struct veiculos));
	
	clearScreen();
	for(;escolha1 != 4;){
		printf("1 - Clientes (A FAZER)\n");
		printf("2 - Loca��o (A FAZER)\n");
		printf("3 - Ve�culos (A FAZER)\n");
		printf("4 - Sair (A FAZER)\n");
		scanf("%d", &escolha1);
		clearScreen();

		switch(escolha1){
			case 1:
			printf("1. Novo cliente (FEITO)\n");
			printf("2. Editar cadastro (FEITO)\n");
			printf("3. Excluir cadastro (FEITO)\n");
			printf("4. Consulta de cliente (A FAZER)\n");
			printf("5. Listagem de clientes (FEITO)\n");
			printf("6. Voltar\n");
			scanf("%d", &escolha2);
			clearScreen();
			switch(escolha2){
				case 1:
					novoCliente(cliente, &qnt_cliente, &qnt_max_cliente);
				break;
				
				case 2:
					editarCliente(cliente, &qnt_cliente, &qnt_max_cliente);
				break;
				
				case 3:
					excluirCliente(cliente, &qnt_cliente, &qnt_max_cliente, &qnt_cliente_excluido);
				break;
				
				case 4:
					consultarCliente(cliente, &qnt_cliente, &qnt_max_cliente, &qnt_cliente_excluido, &qnt_veiculo, &qnt_max_veiculo);
				break;
				
				case 5:
					listarCliente(cliente, &qnt_cliente, &qnt_max_cliente, &qnt_cliente_excluido);
				break;
				
				case 6:
				break;
				
				default:
				break;
			}
			break;

			case 2:
			printf("1. Loca��o de ve�culo (A FAZER)\n");
			printf("2. Devolu��o de ve�culo (A FAZER)\n");
			printf("3. Relat�rio de loca��es (A FAZER)\n");
			printf("4. Voltar\n");
			scanf("%d", &escolha2);
			clearScreen();
			switch(escolha2){
				case 1:
					locacaoVeiculo();
				break;
				
				case 2:
					devolucaoVeiculo();
				break;
				
				case 3:
					relatorioLocacao();
				break;
				
				case 4:
				break;
				
				default:
				break;
			}
			break;

			case 3:
			printf("1. Cadastrar ve�culo (A FAZER)\n");
			printf("2. Excluir cadastro de ve�ulo (A FAZER)\n");
			printf("3. Consulta de cadastro de ve�culo (A FAZER)\n");
			printf("4. Listagem de frota (A FAZER)\n");
			printf("5. Voltar\n");
			scanf("%d", &escolha2);
			clearScreen();
			switch(escolha2){
				case 1:
					cadastrarVeiculo(veiculo, qnt_veiculo, qnt_max_veiculo);
				break;
				
				case 2:
					excluirVeiculo(veiculo, qnt_veiculo, qnt_max_veiculo, qnt_veiculo_excluido);
				break;
				
				case 3:
					consultarVeiculo(veiculo, qnt_veiculo, qnt_max_veiculo, qnt_veiculo_excluido);
				break;
				
				case 4:
					listarVeiculo(veiculo, qnt_veiculo, qnt_max_veiculo, qnt_veiculo_excluido);
				break;
				
				case 5:
				break;
				
				default:
				break;
			}
			break;

			case 4:
			break;

			default:
				escolha1 = 4;
			break;
		}
	}

	return 0;
}
