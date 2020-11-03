#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include "locadora.h"
#include "locacao.h"
#include "cliente.h"
#include "veiculo.h"

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	// Declaração inicial de variáveis
	int escolha1, escolha2, qnt_cliente, qnt_max_cliente, qnt_cliente_excluido, qnt_veiculo, qnt_max_veiculo, qnt_veiculo_excluido, qnt_locacao, qnt_max_locacao, conf;
	escolha1 = escolha2 = qnt_cliente = qnt_cliente_excluido = qnt_veiculo = qnt_veiculo_excluido = qnt_locacao = qnt_max_locacao = 0;
	qnt_max_cliente = qnt_max_veiculo = 100;
	
	// Inicialização das structs utilizadas
	struct clientes* cliente;
    cliente = (struct clientes*) malloc(100*sizeof(struct clientes));
	struct veiculos* veiculo;
	veiculo = (struct veiculos*) malloc(100*sizeof(struct veiculos));
	struct locacoes* locacao;
	locacao = (struct locacoes*) malloc(100*sizeof(struct locacoes));

	// Menus e submenus
	clearScreen();
	for(;escolha1 != 4;){
		printf("1 - Clientes\n");
		printf("2 - Locação\n");
		printf("3 - Veículos\n");
		printf("4 - Sair\n");
		scanf("%d", &escolha1);
		clearScreen();

		switch(escolha1){
			case 1:
			printf("1. Novo cliente\n");
			printf("2. Editar cadastro\n");
			printf("3. Excluir cadastro\n");
			printf("4. Consulta de cliente\n");
			printf("5. Listagem de clientes\n");
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
					organizeListCliente(cliente, qnt_cliente, &qnt_cliente_excluido);
				break;
				
				case 4:
					consultarCliente(cliente, veiculo, &qnt_cliente, &qnt_max_cliente, &qnt_veiculo, &qnt_max_veiculo);
				break;
				
				case 5:
					listarCliente(cliente, &qnt_cliente);
				break;
				
				case 6:
				break;
				
				default:
				break;
			}
			break;

			case 2:
			printf("1. Locação de veículo \n");
			printf("2. Devolução de veículo\n");
			printf("3. Relatório de locações\n");
			printf("4. Voltar\n");
			scanf("%d", &escolha2);
			clearScreen();
			switch(escolha2){
				case 1:
					locacaoVeiculo(cliente, veiculo, locacao, &qnt_cliente, &qnt_veiculo, &qnt_locacao, &qnt_max_locacao);
				break;
				
				case 2:
					devolucaoVeiculo(cliente, veiculo, locacao, &qnt_cliente, &qnt_veiculo, &qnt_locacao, &qnt_max_locacao);
				break;
				
				case 3:
					relatorioLocacao(locacao, &qnt_locacao);
				break;
				
				case 4:
				break;
				
				default:
				break;
			}
			break;

			case 3:
			printf("1. Cadastrar veículo\n");
			printf("2. Excluir cadastro de veíulo\n");
			printf("3. Consulta de veículo\n");
			printf("4. Listagem de frota\n");
			printf("5. Voltar\n");
			scanf("%d", &escolha2);
			clearScreen();
			switch(escolha2){
				case 1:
					novoVeiculo(veiculo, &qnt_veiculo, &qnt_max_veiculo);
				break;
					
				case 2:
					excluirVeiculo(veiculo, &qnt_veiculo, &qnt_max_veiculo, &qnt_veiculo_excluido);
					organizeListVeiculo(veiculo, qnt_veiculo, &qnt_veiculo_excluido);
				break;
				
				case 3:
					consultarVeiculo(veiculo, &qnt_veiculo, &qnt_max_veiculo, &qnt_cliente, &qnt_max_cliente, cliente);	
				break;
				
				case 4:
					listarVeiculo(veiculo, &qnt_veiculo);
				break;
				
				case 5:
				break;
				
				default:
				break;
			}
			break;

			case 4:
				clearScreen();
				printf("Tem certeja que deseja finalizar o programa (S/N): ");
				scanf(" %c", &conf);
				clearScreen();
				if (conf == 'S'){
					break;
				} else{
					escolha1 = 0;
				}
			break;

			default:
				escolha1 = 4;
			break;
		}
	}

	return 0;
}
